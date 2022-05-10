#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiatWokol)
{
	this->sila = 10;
	this->inicjatywa = 0;
	this->symbolDorosly = 'B';
	this->symbolDziecko = 'b';
	this->symbol = 'B';
	this->nazwa = "Barszcz Sosnowskiego";
	this->swiatWsk = swiatWokol;
}

bool  BarszczSosnowskiego::czyOtrul(xy atakujacy)
{
	return true;
}
void BarszczSosnowskiego::zatruj(xy zatruwa)
{
	cout << "Barszcz Sosnowskiego zatrrul zwierze w poblizu ("
		<< swiatWsk->getPole(zatruwa)->getNazwa() << ")\n";
	swiatWsk->usunOrganizm(swiatWsk->getPole(zatruwa));
	swiatWsk->setPole(zatruwa, NULL);
}
void BarszczSosnowskiego::zatrujWokol()
{
	xy zatruwa = this->getPolozenie();
	if (zatruwa.x != swiatWsk->getX() - 1)//*****************************prawo
	{
		zatruwa.x++;
		if (swiatWsk->getPole(zatruwa) != NULL)
		{
			if (Zwierze* d = dynamic_cast<Zwierze*>(swiatWsk->getPole(zatruwa)))
				zatruj(zatruwa);
			zatruwa.x--;
		}
		else
			zatruwa.x--;
	}
	if (zatruwa.x != 0)//*****************************lewo
	{
		zatruwa.x--;
		if (swiatWsk->getPole(zatruwa) != NULL)
		{
			if (Zwierze* d = dynamic_cast<Zwierze*>(swiatWsk->getPole(zatruwa)))
				zatruj(zatruwa);
			zatruwa.x++;
		}
		else
			zatruwa.x++;
	}
	if (zatruwa.y != 0 )//*****************************gora
	{
		zatruwa.y--;
		if (swiatWsk->getPole(zatruwa) != NULL)
		{
			if (Zwierze* d = dynamic_cast<Zwierze*>(swiatWsk->getPole(zatruwa)))
				zatruj(zatruwa);
			zatruwa.y++;
		}
		else
			zatruwa.y++;
	}
	if (zatruwa.y != swiatWsk->getY() - 1)//*****************************dol
	{
		zatruwa.y++;
		if (swiatWsk->getPole(zatruwa) != NULL)
		{
			if (Zwierze* d = dynamic_cast<Zwierze*>(swiatWsk->getPole(zatruwa)))
				zatruj(zatruwa);
			zatruwa.y--;
		}
		else
			zatruwa.y--;
	}
}

void BarszczSosnowskiego::zasiej(xy zasiejTu)
{
	BarszczSosnowskiego* sadzonka = new BarszczSosnowskiego(swiatWsk);
	int rozmiar = swiatWsk->getOrganizmy()->size();
	sadzonka->setIter(rozmiar);
	sadzonka->setPolozenie(zasiejTu);
	sadzonka->setSymbolDziecko();
	swiatWsk->getOrganizmy()->push_back(sadzonka);
	swiatWsk->setPole(zasiejTu, sadzonka);
	cout << "Mlody Barszcz Sosnowskiego zostala zasiana" << endl;
}

BarszczSosnowskiego::~BarszczSosnowskiego() {}