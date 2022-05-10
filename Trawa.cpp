#include "Trawa.h"

Trawa::Trawa(Swiat* swiatWokol)
{
	this->sila = 0;
	this->inicjatywa = 0;
	this->symbolDorosly = 'T';
	this->symbolDziecko = 't';
	this->symbol = 'T';
	this->nazwa = "Trawa";
	this->swiatWsk = swiatWokol;
}

void Trawa::zasiej(xy zasiejTu)
{
	Trawa* sadzonka = new Trawa(swiatWsk);
	int rozmiar = swiatWsk->getOrganizmy()->size();
	sadzonka->setIter(rozmiar);
	sadzonka->setPolozenie(zasiejTu);
	sadzonka->setSymbolDziecko();
	swiatWsk->getOrganizmy()->push_back(sadzonka);
	swiatWsk->setPole(zasiejTu, sadzonka);
	cout << "Mloda trawa zostala zasiana" << endl;
}

Trawa::~Trawa(){}