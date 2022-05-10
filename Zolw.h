#pragma once
#include"Zwierze.h"
class Zolw :
    public Zwierze
{
public:

	Zolw(Swiat* swiatWokol);
	 void akcja()override;
	 void rozmnazaj(xy zakochany, xy obiekt_uczuc)override;
	 bool sprawdzGatunek(xy atakujacy, xy atakowany)override;
	 bool czyOdbilAtak(xy atakujacy)override;

	~Zolw();
};

