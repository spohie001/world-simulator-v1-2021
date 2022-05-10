#include "Antylopa.h"


Antylopa::Antylopa(Swiat* swiatWokol)
{
	this->sila = 4;
	this->inicjatywa = 4;
	this->symbolDorosly = 'A';
	this->symbolDziecko = 'a';
	this->symbol = 'A';
	this->nazwa = "Antylopa";
	this->swiatWsk = swiatWokol;
}

bool  Antylopa::sprawdzGatunek(xy atakujacy, xy atakowany)
{
	if (Antylopa* d = dynamic_cast<Antylopa*>(swiatWsk->getPole(atakowany)))
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
void Antylopa::rozmnazaj(xy zakochany, xy obiekt_uczuc)
{
	xy wolne = znajdzWolnyObok(zakochany);
	if (wolne.x != zakochany.x || wolne.y != zakochany.y)
	{
		Antylopa* dziecko = new Antylopa(swiatWsk);
		int rozmiar = swiatWsk->getOrganizmy()->size();
		dziecko->setIter(rozmiar);
		dziecko->setPolozenie(wolne);
		dziecko->setSymbolDziecko();
		swiatWsk->getOrganizmy()->push_back(dziecko);
		swiatWsk->sortujOrganizmy(dziecko);
		swiatWsk->aktualizujOrganizmy();
		swiatWsk->setPole(wolne, dziecko);
		cout << "Antylopy  rozmnozyly sie" << endl;
	}
	else
	{
		wolne = znajdzWolnyObok(obiekt_uczuc);
		if (wolne.x != obiekt_uczuc.x || wolne.y != obiekt_uczuc.y)
		{
			Antylopa* dziecko = new Antylopa(swiatWsk);
			int rozmiar = swiatWsk->getOrganizmy()->size();
			dziecko->setIter(rozmiar);
			dziecko->setPolozenie(wolne);
			dziecko->setSymbolDziecko();
			swiatWsk->getOrganizmy()->push_back(dziecko);
			swiatWsk->sortujOrganizmy(dziecko);
			dziecko->setPolozenie(wolne);
			swiatWsk->setPole(wolne, dziecko);
			cout << "Antylopy  rozmnozyly sie" << endl;
		}
		else
			cout << "Antylopy nie moga sia rozmnozyc" << endl;
	}
}


void Antylopa::przeskoczNaSasiedniePole()
{
	zmianaPolozenia zmpol = NIEZMIENIONY;

	while (zmpol != ZMIENIONY)
	{
		int kierunek = rand() % 4;
		xy zmien = this->getPolozenie();

		if (kierunek == 0)//********************************************prawo
		{
			if (zmien.x < swiatWsk->getX() - 2)
				idzPrawo(zmien, zmpol);
		}
		else if (kierunek == 1)//******************************************lewo
		{
			if (zmien.x > 1)
				idzLewo(zmien, zmpol);
		}
		else if (kierunek == 2)//******************************************gora
		{
			if (zmien.y > 1)
				idzGora(zmien, zmpol);
		}
		else if (kierunek == 3)//******************************************dol
		{
			if (zmien.y < swiatWsk->getY() - 2)
			idzDol(zmien, zmpol);
		}
	}
}

bool Antylopa::sprobujUciec()
{
	int szansa = rand() % 2;
	if (szansa)
	{
		przeskoczNaSasiedniePole();
		return true;
	}
	else
	return false;
}


void Antylopa::idzPrawo(xy& zmien, zmianaPolozenia& zmpol)
{
	zmien.x+= 2;
	if (swiatWsk->getPole(zmien) == NULL)
	{
		zmien.x-= 2;
		swiatWsk->setPole(zmien, NULL);
		zmien.x+= 2;
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
			zmien.x-= 2;
		}
		else
		{
			cout << this->getNazwa() + " uciekla od walki z " + swiatWsk->getPole(zmien)->getNazwa() + "\n";
			zmpol = ZMIENIONY;
			zmien.x-= 2;
		}
	}
}

void Antylopa::idzLewo(xy& zmien, zmianaPolozenia& zmpol)
{
	zmien.x-= 2;

	if (swiatWsk->getPole(zmien) == NULL)
	{
		zmien.x+= 2;
		swiatWsk->setPole(zmien, NULL);
		zmien.x-= 2;
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
			zmien.x+= 2;
		}
		else
		{
			cout << this->getNazwa() + " uciekla od walki z " + swiatWsk->getPole(zmien)->getNazwa() + "\n";
			zmpol = ZMIENIONY;
			zmien.x+= 2;
		}
	}
}
void Antylopa::idzGora(xy& zmien, zmianaPolozenia& zmpol)
{
	zmien.y-= 2;
	if (swiatWsk->getPole(zmien) == NULL)
	{
		zmien.y+= 2;
		swiatWsk->setPole(zmien, NULL);
		zmien.y-= 2;
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
			zmien.y+= 2;
		}
		else
		{
			cout << this->getNazwa() + " uciekla od walki z " + swiatWsk->getPole(zmien)->getNazwa()+ "\n";
			zmpol = ZMIENIONY;
			zmien.y+= 2;
		}
	}
}
void Antylopa::idzDol(xy& zmien, zmianaPolozenia& zmpol)
{
	zmien.y+=2;
	if (swiatWsk->getPole(zmien) == NULL)
	{
		zmien.y-= 2;
		swiatWsk->setPole(zmien, NULL);
		zmien.y+= 2;
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
			zmien.y-= 2;
		}
		else
		{
			cout << this->getNazwa() + " uciekla od walki z " + swiatWsk->getPole(zmien)->getNazwa() + "\n";
			zmpol = ZMIENIONY;
			zmien.y-= 2;
		}
	}
}

void Antylopa::akcja()
{
	zmianaPolozenia zmpol = NIEZMIENIONY;
	int zabity = 0;

	while (zmpol != ZMIENIONY)
	{
		int kierunek = rand() % 4;
		xy zmien = this->getPolozenie();

		if (kierunek == 0)//********************************************prawo
		{
				if (zmien.x < swiatWsk->getX() - 2)
					idzPrawo(zmien, zmpol);
		}
		else if (kierunek == 1)//******************************************lewo
		{
				if (zmien.x > 1)
					idzLewo(zmien, zmpol);
		}
		else if (kierunek == 2)//******************************************gora
		{
				if (zmien.y > 1)
				idzGora(zmien, zmpol);
		}
		else if (kierunek == 3)//******************************************dol
		{
				if (zmien.y < swiatWsk->getY() - 2)
					idzDol(zmien, zmpol);
		}
	}
}


Antylopa::~Antylopa() {};