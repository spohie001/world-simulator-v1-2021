#pragma once
#include "Organizm.h"
class Roslina :
    public Organizm
{
public:
	virtual void akcja();
	virtual void zasiej(xy zasiejTu) = 0;
	virtual void kolizja(xy atakujacy, xy atakowany);
	virtual bool czyOdbilAtak(xy atakujacy);
	virtual bool sprobujUciec();
	virtual void dodajSily(xy atakujacy);
	virtual void zatrujWokol();
};

