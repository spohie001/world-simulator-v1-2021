#include "Zolw.h"

Zolw::Zolw(Swiat* swiatWokol)
{
	this->sila = 2;
	this->inicjatywa = 1;
	this->symbol = 'Z';
	this->symbolDorosly = 'Z';
	this->symbolDziecko = 'z';
	this->nazwa = "Zolw";
	this->swiatWsk = swiatWokol;
}
bool  Zolw::sprawdzGatunek(xy atakujacy, xy atakowany)
{
	if (Zolw* d = dynamic_cast<Zolw*>(swiatWsk->getPole(atakowany)))
		if (swiatWsk->getPole(atakowany)->getSymbol() == swiatWsk->getPole(atakowany)->getSymbolDorosly())
		{
			rozmnazaj(atakujacy, atakowany);
			return true;
		}
		else
		{
			cout << "Zolwie nie moga sia rozmnozyc" << endl;
			return true;
		}
	else
		return false;
}

void Zolw::rozmnazaj(xy zakochany, xy obiekt_uczuc)
{
	xy wolne = znajdzWolnyObok(zakochany);
	if (wolne.x != zakochany.x || wolne.y != zakochany.y)
	{
		Zolw* dziecko = new Zolw(swiatWsk);
		int rozmiar = swiatWsk->getOrganizmy()->size();
		dziecko->setIter(rozmiar);
		dziecko->setPolozenie(wolne);
		dziecko->setSymbolDziecko();
		swiatWsk->getOrganizmy()->push_back(dziecko);
		swiatWsk->sortujOrganizmy(dziecko);
		swiatWsk->aktualizujOrganizmy();
		swiatWsk->setPole(wolne, dziecko);
		cout << "Zolwie  rozmnozyly sie" << endl;
	}
	else
	{
		wolne = znajdzWolnyObok(obiekt_uczuc);
		if (wolne.x != obiekt_uczuc.x || wolne.y != obiekt_uczuc.y)
		{
			Zolw* dziecko = new Zolw(swiatWsk);
			int rozmiar = swiatWsk->getOrganizmy()->size();
			dziecko->setIter(rozmiar);
			dziecko->setPolozenie(wolne);
			dziecko->setSymbolDziecko();
			swiatWsk->getOrganizmy()->push_back(dziecko);
			swiatWsk->sortujOrganizmy(dziecko);
			dziecko->setPolozenie(wolne);
			swiatWsk->setPole(wolne, dziecko);
			cout << "Zolwie  rozmnozyly sie" << endl;
		}
		else
			cout << "Zolwie nie moga sia rozmnozyc" << endl;
	}
}

bool Zolw::czyOdbilAtak(xy atakujacy)
{
	if (swiatWsk->getPole(atakujacy)->getSila() > 4)
		return false;
	else
		return true;
} 


void Zolw::akcja()
{
	zmianaPolozenia zmpol = NIEZMIENIONY;

	while (zmpol != ZMIENIONY)
	{
		int kierunek = rand() % 16;
		xy zmien = this->getPolozenie();

		if (kierunek == 0)//********************************************prawo
		{
			if (zmien.x != swiatWsk->getX() - 1)
				idzPrawo(zmien, zmpol);
		}
		else if (kierunek == 1)//******************************************lewo
		{
			if (zmien.x != 0)
				idzLewo(zmien, zmpol);
		}
		else if (kierunek == 2)//******************************************gora
		{
			if (zmien.y != 0)
			idzGora(zmien, zmpol);
		}
		else if (kierunek == 3)//******************************************dol
		{
			if (zmien.y != swiatWsk->getY() - 1)
				idzDol(zmien, zmpol);
		}
		else
		{
			zmpol = ZMIENIONY;
			cout << "Zolw nie zmienil polozenia\n";
		}
	}
}

Zolw::~Zolw() {};