#pragma once
#include <iostream>
#include "Zwierze.h"
using namespace std;

class Antylopa
	: public Zwierze {
public:

	Antylopa(Swiat* swiatWokol);
	void rozmnazaj(xy zakochany, xy obiekt_uczuc)override;
	bool sprawdzGatunek(xy atakujacy, xy atakowany)override;

	bool sprobujUciec()override;
	void idzPrawo(xy& zmien, zmianaPolozenia& zmpol)override;
	void idzLewo(xy& zmien, zmianaPolozenia& zmpol)override;
	void idzDol(xy& zmien, zmianaPolozenia& zmpol)override;
	void idzGora(xy& zmien, zmianaPolozenia& zmpol)override;
	void akcja()override;

	void przeskoczNaSasiedniePole();

	~Antylopa();
};

