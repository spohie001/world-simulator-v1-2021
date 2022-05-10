#pragma once
#include <iostream>
#include "Zwierze.h"
using namespace std;

class Wilk 
	: public Zwierze {
public:

	Wilk(Swiat* swiatWokol);
	void rozmnazaj(xy zakochany, xy obiekt_uczuc)override;
	 bool sprawdzGatunek(xy atakujacy, xy atakowany)override;

	~Wilk();
};
