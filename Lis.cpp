#include "Lis.h"


Lis::Lis(Swiat* swiatWokol)
{
	this->sila = 3;
	this->inicjatywa = 7;
	this->symbol = 'L';
	this->symbolDorosly = 'L';
	this->symbolDziecko = 'l';
	this->nazwa = "Lis";
	this->swiatWsk = swiatWokol;
}

void Lis::rozmnazaj(xy zakochany, xy obiekt_uczuc)
{
	xy wolne = znajdzWolnyObok(zakochany);
	if (wolne.x != zakochany.x || wolne.y != zakochany.y)
	{
		Lis* dziecko = new Lis(swiatWsk);
		int rozmiar = swiatWsk->getOrganizmy()->size();
		dziecko->setIter(rozmiar);
		dziecko->setPolozenie(wolne);
		dziecko->setSymbolDziecko();
		swiatWsk->getOrganizmy()->push_back(dziecko);
		swiatWsk->sortujOrganizmy(dziecko);
		swiatWsk->aktualizujOrganizmy();
		swiatWsk->setPole(wolne, dziecko);
		cout << "Lisy  rozmnozyly sie" << endl;
	}
	else
	{
		wolne = znajdzWolnyObok(obiekt_uczuc);
		if (wolne.x != obiekt_uczuc.x || wolne.y != obiekt_uczuc.y)
		{
			Lis* dziecko = new Lis(swiatWsk);
			int rozmiar = swiatWsk->getOrganizmy()->size();
			dziecko->setIter(rozmiar);
			dziecko->setPolozenie(wolne);
			dziecko->setSymbolDziecko();
			swiatWsk->getOrganizmy()->push_back(dziecko);
			swiatWsk->sortujOrganizmy(dziecko);
			dziecko->setPolozenie(wolne);
			swiatWsk->setPole(wolne, dziecko);
			cout << "Lisy  rozmnozyly sie" << endl;
		}
		else
			cout << "Lisy nie moga sia rozmnozyc" << endl;
	}
}

bool  Lis::sprawdzGatunek(xy atakujacy, xy atakowany)
{
	if (Lis* d = dynamic_cast<Lis*>(swiatWsk->getPole(atakowany)))
		if (swiatWsk->getPole(atakowany)->getSymbol() == swiatWsk->getPole(atakowany)->getSymbolDorosly())
		{
			rozmnazaj(atakujacy, atakowany);
			return true;
		}
		else
		{
			cout << "Lisy nie moga sia rozmnozyc" << endl;
			return true;
		}
	else
		return false;
}

void Lis::idzPrawo(xy& zmien, zmianaPolozenia& zmpol)
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
		xy stary = this->getPolozenie();
		if (swiatWsk->getPole(stary)->getSila() >= swiatWsk->getPole(zmien)->getSila())
		{
			kolizja(stary, zmien);
			zmpol = ZMIENIONY;
		}
	}
}

void Lis::idzLewo(xy& zmien, zmianaPolozenia& zmpol)
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
		xy stary = this->getPolozenie();
		if (swiatWsk->getPole(stary)->getSila() >= swiatWsk->getPole(zmien)->getSila())//sprawdzanie si³y atakowanefo
		{
			kolizja(stary, zmien);
			zmpol = ZMIENIONY;
		}
	}
}

void Lis::idzGora(xy& zmien, zmianaPolozenia& zmpol)
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
		xy stary = this->getPolozenie();
		if (swiatWsk->getPole(stary)->getSila() >= swiatWsk->getPole(zmien)->getSila())//sprawdzanie si³y atakowanefo
		{
			kolizja(stary, zmien);
			zmpol = ZMIENIONY;
		}
	}
}

void Lis::idzDol(xy& zmien, zmianaPolozenia& zmpol)
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
		xy stary = this->getPolozenie();
		if (swiatWsk->getPole(stary)->getSila() >= swiatWsk->getPole(zmien)->getSila())//sprawdzanie si³y atakowanefo
		{
			kolizja(stary, zmien);
			zmpol = ZMIENIONY;
		}
	}
}

Lis::~Lis() {};