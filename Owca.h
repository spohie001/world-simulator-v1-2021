#pragma once
#include "Zwierze.h"
class Owca :
    public Zwierze
{
public:

	Owca(Swiat* swiatWokol);
	void rozmnazaj(xy zakochany, xy obiekt_uczuc)override;
	bool sprawdzGatunek(xy atakujacy, xy atakowany)override;

	~Owca();
};

