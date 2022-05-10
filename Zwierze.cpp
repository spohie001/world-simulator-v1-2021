#include<iostream>
#include"Zwierze.h"
using namespace std;
void Zwierze::rozmnazaj(xy zakochany, xy obiekt_uczuc) {}

bool Zwierze::sprawdzGatunek(xy atakujacy, xy atakowany) { return true; }

void Zwierze::dodajSily(xy atakujacy) {}

xy Zwierze::znajdzWolnyObok(xy obok)
{
	zmianaPolozenia zmiana = NIEZMIENIONY;
	xy wolne = obok;
	if (obok.x != swiatWsk->getX() - 1)//*****************************prawo
	{
		obok.x++;
		if (swiatWsk->getPole(obok) == NULL)
			zmiana = ZMIENIONY;
		else
			obok.x--;
	}
	if (obok.x != 0 && zmiana == NIEZMIENIONY)//*****************************lewo
	{
		obok.x--;
		if (swiatWsk->getPole(obok) == NULL)
			zmiana = ZMIENIONY;
		else
			obok.x++;
	}
	if (obok.y != 0 && zmiana == NIEZMIENIONY)//*****************************gora
	{
		obok.y--;
		if (swiatWsk->getPole(obok) == NULL)
			zmiana = ZMIENIONY;
		else
			obok.y++;
	}
	if (obok.y != swiatWsk->getY() - 1 && zmiana == NIEZMIENIONY)//*****************************dol
	{
		obok.y++;
		if (swiatWsk->getPole(obok) == NULL)
			zmiana = ZMIENIONY;
		else
			obok.y--;
	}
	return obok;
}

void  Zwierze::pokonanyAtakujacy(xy atakujacy, xy atakowany)
{
	string kom = swiatWsk->getPole(atakujacy)->getNazwa() + " zaatakowal " + swiatWsk->getPole(atakowany)->getNazwa()
		+ ". Atakujacy (" + swiatWsk->getPole(atakujacy)->getNazwa() + ") zostal pokonany.";
	swiatWsk->usunOrganizm(swiatWsk->getPole(atakujacy));
	swiatWsk->setPole(atakujacy, NULL);
	cout << kom << endl;

}

void  Zwierze::pokonanyAtakowany(xy atakujacy, xy atakowany)
{
	string kom = swiatWsk->getPole(atakujacy)->getNazwa() + " zaatakowal " + swiatWsk->getPole(atakowany)->getNazwa()
		+ ". Atakowany (" + swiatWsk->getPole(atakowany)->getNazwa() + ") zostal pokonany.";
	swiatWsk->usunOrganizm(swiatWsk->getPole(atakowany));
	swiatWsk->setPole(atakujacy, NULL);
	swiatWsk->setPole(atakowany, this);
	this->setPolozenie(atakowany);
	cout << kom << endl;
}

void  Zwierze::otruj(xy atakujacy, xy atakowany)
{
	string kom = swiatWsk->getPole(atakujacy)->getNazwa() + " zjadl " + swiatWsk->getPole(atakowany)->getNazwa() + " i zostal otruty\n";
	swiatWsk->usunOrganizm(swiatWsk->getPole(atakujacy));
	swiatWsk->setPole(atakujacy, NULL);
	cout << kom << endl;
}

void Zwierze::kolizja(xy atakujacy, xy atakowany)
{
	if (sprawdzGatunek( atakujacy,  atakowany)) {}
	else
	{
		swiatWsk->getPole(atakowany)->dodajSily(atakujacy);

		if (swiatWsk->getPole(atakowany)->sprobujUciec())
			cout << swiatWsk->getPole(atakujacy)->getNazwa() + " zaatakowal " + swiatWsk->getPole(atakowany)->getNazwa()
			+ ". Atakowany (" + swiatWsk->getPole(atakowany)->getNazwa() + ") uciekl.\n";

		else if (swiatWsk->getPole(atakowany)->czyOdbilAtak(atakujacy))
			cout << swiatWsk->getPole(atakujacy)->getNazwa() + " zaatakowal " + swiatWsk->getPole(atakowany)->getNazwa()
			+ ". Atakowany (" + swiatWsk->getPole(atakowany)->getNazwa() + ") odbil atak.\n";

		//jesli sila atakujacego jest wieksza lub równa niz atakowanego
		else if (swiatWsk->getPole(atakujacy)->getSila() >= swiatWsk->getPole(atakowany)->getSila())
		{
			pokonanyAtakowany(atakujacy, atakowany);
			if (swiatWsk->getPole(atakowany)->czyOtrul(atakujacy))
				otruj(atakujacy, atakowany);
		}
		else
			pokonanyAtakujacy(atakujacy, atakowany);
	}
};


bool Zwierze::czyOdbilAtak(xy atakujacy)
{
	return false;
}

bool Zwierze::sprobujUciec()
{
	return false;
}


void Zwierze::idzPrawo(xy& zmien, zmianaPolozenia& zmpol)
{
	zmien.x++;
	if (swiatWsk->getPole(zmien) == NULL)
	{
		zmien.x--;
		swiatWsk->setPole(zmien, NULL);
		zmien.x++;
		swiatWsk->setPole(zmien, this);
		this->setPolozenie(zmien);
		zmpol = ZMIENIONY;
		string kom = this->getNazwa() + " przeskoczyl na pole x: "
			+ to_string(this->getPolozenie().x) + " y: " + to_string(this->getPolozenie().y);
		cout << kom << endl;
	}
	else
	{
		if (sprobujUciec() == false)
		{
			xy stary = this->getPolozenie();
			kolizja(stary, zmien);
			zmpol = ZMIENIONY;
		}
	}
}

void Zwierze::idzLewo(xy& zmien, zmianaPolozenia& zmpol)
{
	zmien.x--;

	if (swiatWsk->getPole(zmien) == NULL)
	{
		zmien.x++;
		swiatWsk->setPole(zmien, NULL);
		zmien.x--;
		swiatWsk->setPole(zmien, this);
		this->setPolozenie(zmien);
		zmpol = ZMIENIONY;
		string kom = this->getNazwa() + " przeskoczyl na pole x: "
			+ to_string(this->getPolozenie().x) + " y: " + to_string(this->getPolozenie().y);
		cout << kom << endl;
	}
	else
	{
		if (sprobujUciec() == false)
		{
			xy stary = this->getPolozenie();
			kolizja(stary, zmien);
			zmpol = ZMIENIONY;
		}
	}
}
void Zwierze::idzGora(xy& zmien, zmianaPolozenia& zmpol)
{
	zmien.y--;
	if (swiatWsk->getPole(zmien) == NULL)
	{
		zmien.y++;
		swiatWsk->setPole(zmien, NULL);
		zmien.y--;
		swiatWsk->setPole(zmien, this);
		this->setPolozenie(zmien);
		zmpol = ZMIENIONY;
		string kom = this->getNazwa() + " przeskoczyl na pole x: "
			+ to_string(this->getPolozenie().x) + " y: " + to_string(this->getPolozenie().y);
		cout << kom << endl;
	}
	else
	{
		if (sprobujUciec() == false)
		{
			xy stary = this->getPolozenie();
			kolizja(stary, zmien);
			zmpol = ZMIENIONY;
		}
	}
}
void Zwierze::idzDol(xy& zmien, zmianaPolozenia& zmpol)
{
	zmien.y++;
	if (swiatWsk->getPole(zmien) == NULL)
	{
		zmien.y--;
		swiatWsk->setPole(zmien, NULL);
		zmien.y++;
		swiatWsk->setPole(zmien, this);
		this->setPolozenie(zmien);
		zmpol = ZMIENIONY;
		string kom = this->getNazwa() + " przeskoczyl na pole x: "
			+ to_string(this->getPolozenie().x) + " y: " + to_string(this->getPolozenie().y);
		cout << kom << endl;
	}
	else
	{
		if (sprobujUciec() == false)
		{
			xy stary = this->getPolozenie();
			kolizja(stary, zmien);
			zmpol = ZMIENIONY;
		}
	}
}
void Zwierze::akcja()
{
	zmianaPolozenia zmpol = NIEZMIENIONY;

	while (zmpol != ZMIENIONY)
	{
		int kierunek = rand() % 4;
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
	}
}
