#pragma once
#include <iostream>
#include "Zwierze.h"
using namespace std;

class Lis
	: public Zwierze {
public:

	Lis(Swiat* swiatWokol);
	void rozmnazaj(xy zakochany, xy obiekt_uczuc)override;
	bool sprawdzGatunek(xy atakujacy, xy atakowany)override;

	 void idzPrawo(xy& zmien, zmianaPolozenia& zmpol)override;
	 void idzLewo(xy& zmien, zmianaPolozenia& zmpol)override;
	 void idzDol(xy& zmien, zmianaPolozenia& zmpol)override;
	 void idzGora(xy& zmien, zmianaPolozenia& zmpol)override;

	~Lis();
};
