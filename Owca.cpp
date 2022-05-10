#include "Owca.h"


Owca::Owca(Swiat* swiatWokol)
{
	this->sila = 4;
	this->inicjatywa = 4;
	this->symbol = 'O';
	this->symbolDorosly = 'O';
	this->symbolDziecko = 'o';
	this->nazwa = "Owca";
	this->swiatWsk = swiatWokol;
}
bool  Owca::sprawdzGatunek(xy atakujacy, xy atakowany)
{
	if (Owca* d = dynamic_cast<Owca*>(swiatWsk->getPole(atakowany)))
		if (swiatWsk->getPole(atakowany)->getSymbol() == swiatWsk->getPole(atakowany)->getSymbolDorosly())
		{
			rozmnazaj(atakujacy, atakowany);
			return true;
		}
		else
		{
			cout << "Owce nie moga sia rozmnozyc" << endl;
			return true;
		}
	else
		return false;
}

void Owca::rozmnazaj(xy zakochany, xy obiekt_uczuc)
{
	xy wolne = znajdzWolnyObok(zakochany);
	if (wolne.x != zakochany.x || wolne.y != zakochany.y)
	{
		Owca* dziecko = new Owca(swiatWsk);
		int rozmiar = swiatWsk->getOrganizmy()->size();
		dziecko->setIter(rozmiar);
		dziecko->setPolozenie(wolne);
		dziecko->setSymbolDziecko();
		swiatWsk->getOrganizmy()->push_back(dziecko);
		swiatWsk->sortujOrganizmy(dziecko);
		swiatWsk->aktualizujOrganizmy();
		swiatWsk->setPole(wolne, dziecko);
		cout << "Owce  rozmnozyly sie" << endl;
	}
	else
	{
		wolne = znajdzWolnyObok(obiekt_uczuc);
		if (wolne.x != obiekt_uczuc.x || wolne.y != obiekt_uczuc.y)
		{
			Owca* dziecko = new Owca(swiatWsk);
			int rozmiar = swiatWsk->getOrganizmy()->size();
			dziecko->setIter(rozmiar);
			dziecko->setPolozenie(wolne);
			dziecko->setSymbolDziecko();
			swiatWsk->getOrganizmy()->push_back(dziecko);
			swiatWsk->sortujOrganizmy(dziecko);
			dziecko->setPolozenie(wolne);
			swiatWsk->setPole(wolne, dziecko);
			cout << "Owce  rozmnozyly sie" << endl;
		}
		else
			cout << "Owce nie moga sia rozmnozyc" << endl;
	}
}


Owca::~Owca() {};