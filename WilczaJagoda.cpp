#include "WilczaJagoda.h"

WilczaJagoda::WilczaJagoda(Swiat* swiatWokol)
{
	this->sila = 99;
	this->inicjatywa = 0;
	this->symbolDorosly = 'J';
	this->symbolDziecko = 'j';
	this->symbol = 'J';
	this->nazwa = "Wilcza jagoda";
	this->swiatWsk = swiatWokol;
}

bool  WilczaJagoda::czyOtrul(xy atakujacy)
{
	return true;
}

void WilczaJagoda::zasiej(xy zasiejTu)
{
	WilczaJagoda* sadzonka = new WilczaJagoda(swiatWsk);
	int rozmiar = swiatWsk->getOrganizmy()->size();
	sadzonka->setIter(rozmiar);
	sadzonka->setPolozenie(zasiejTu);
	sadzonka->setSymbolDziecko();
	swiatWsk->getOrganizmy()->push_back(sadzonka);
	swiatWsk->setPole(zasiejTu, sadzonka);
	cout << "Mloda wilcza jagoda zostala zasiana" << endl;
}

WilczaJagoda::~WilczaJagoda() {}