#pragma once
#include<iostream>
#include"Organizm.h"
#include"Zwierze.h"
#include <vector>
#include <string>
using namespace std;

class Swiat {
	vector <Organizm*> organizmy;
	Organizm*** pola;
	int X, Y;
public:
	Swiat();
	Swiat(int N, int M);

	void symulatorSwiata(Swiat* swiat);

	void wykonajTure(Swiat* swiat);
	void rysujSwiat();
	void sortujOrganizmy(Organizm* nowy);
	void dodajOrganizm(Organizm* nowy);
	void dodajDoWolnego(Organizm* nowy);
	void usunOrganizm(Organizm* usun);
	void aktualizujOrganizmy();
	Organizm* initZwierzeta(Swiat* swiat);
	Organizm* initRosliny(Swiat* swiat);
	bool czyCzlowiekZyje(Swiat* swiat);

	int getX();
	int getY();
	void setPole( xy poloz, Organizm* zmien);
	Organizm* getPole(xy poloz);
	vector <Organizm*>* getOrganizmy();
	vector <Organizm*> getOrganizm();

	~Swiat();
};
