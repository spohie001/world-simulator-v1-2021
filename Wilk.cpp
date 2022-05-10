#include "Wilk.h"

Wilk::Wilk(Swiat* swiatWokol)
{
	this->sila = 9;
	this->inicjatywa = 5;
	this->symbol = 'W';
	this->symbolDorosly = 'W';
	this->symbolDziecko = 'w';
	this->nazwa = "Wilk";
	this->swiatWsk = swiatWokol;
}

void Wilk::rozmnazaj(xy zakochany, xy obiekt_uczuc)
{
	xy wolne = znajdzWolnyObok(zakochany);
	if (wolne.x!= zakochany.x || wolne.y != zakochany.y)
	{
		Wilk* dziecko = new Wilk(swiatWsk);
		int rozmiar = swiatWsk->getOrganizmy()->size();
		dziecko->setIter(rozmiar);
		dziecko->setPolozenie(wolne);
		dziecko->setSymbolDziecko();
		swiatWsk->getOrganizmy()->push_back(dziecko);
		swiatWsk->sortujOrganizmy(dziecko);
		swiatWsk->aktualizujOrganizmy();
		swiatWsk->setPole(wolne, dziecko);
		cout << "Wilki  rozmnozyly sie" << endl;
	}
	else 
	{
		wolne = znajdzWolnyObok(obiekt_uczuc);
		if (wolne.x != obiekt_uczuc.x || wolne.y != obiekt_uczuc.y)
		{
			Wilk* dziecko = new Wilk(swiatWsk);
			int rozmiar = swiatWsk->getOrganizmy()->size();
			dziecko->setIter(rozmiar);
			dziecko->setPolozenie(wolne);
			dziecko->setSymbolDziecko();
			swiatWsk->getOrganizmy()->push_back(dziecko);
			swiatWsk->sortujOrganizmy(dziecko);
			dziecko->setPolozenie(wolne);
			swiatWsk->setPole(wolne, dziecko);
			cout << "Wilki  rozmnozyly sie" << endl;
		}
		else
			cout << "Wilki nie moga sia rozmnozyc"<<endl;
	}
}
bool  Wilk::sprawdzGatunek(xy atakujacy, xy atakowany)
{
	if (Wilk* d = dynamic_cast<Wilk*>(swiatWsk->getPole(atakowany)))
		if (swiatWsk->getPole(atakowany)->getSymbol() == swiatWsk->getPole(atakowany)->getSymbolDorosly())
		{
			rozmnazaj(atakujacy, atakowany);
			return true;
		}
		else
		{
			cout << "Wilki nie moga sia rozmnozyc" << endl;
			return true;
		}
	else
		return false;
}

Wilk::~Wilk() {};