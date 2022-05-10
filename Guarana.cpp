#include "Guarana.h"

Guarana::Guarana(Swiat* swiatWokol)
{
	this->sila = 0;
	this->inicjatywa = 0;
	this->symbolDorosly = 'G';
	this->symbolDziecko = 'g';
	this->symbol = 'G';
	this->nazwa = "Guarana";
	this->swiatWsk = swiatWokol;
}

void Guarana::dodajSily(xy atakujacy)
{
	int i = swiatWsk->getPole(atakujacy)->getSila() + 3;
	swiatWsk->getPole(atakujacy)->setSila(i);
	cout << "Guarana dodala zrierzeciu ("<< swiatWsk->getPole(atakujacy)->getNazwa()
		<<") sil\nTeraz jego sila to "<<swiatWsk->getPole(atakujacy)->getSila()<<"\n" ;
}

void Guarana::zasiej(xy zasiejTu)
{
	Guarana* sadzonka = new Guarana(swiatWsk);
	int rozmiar = swiatWsk->getOrganizmy()->size();
	sadzonka->setIter(rozmiar);
	sadzonka->setPolozenie(zasiejTu);
	sadzonka->setSymbolDziecko();
	swiatWsk->getOrganizmy()->push_back(sadzonka);
	swiatWsk->setPole(zasiejTu, sadzonka);
	cout << "Mloda guarana zostala zasiana" << endl;
}

Guarana::~Guarana() {}