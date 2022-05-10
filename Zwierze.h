#pragma once
#include<iostream>
#include"Organizm.h"
using namespace std;

enum zmianaPolozenia { NIEZMIENIONY, ZMIENIONY };
class Zwierze : public Organizm {
public:
	virtual void akcja();
	virtual void kolizja(xy atakujacy, xy atakowany);
	virtual void rozmnazaj(xy zakochany, xy obiekt_uczuc);
	virtual bool czyOdbilAtak(xy atakujacy);
	virtual bool sprobujUciec();
	virtual bool sprawdzGatunek(xy atakujacy, xy atakowany);
	virtual void dodajSily(xy atakujacy);
	xy  znajdzWolnyObok(xy obok);
	void otruj(xy atakujacy, xy atakowany);
	void pokonanyAtakowany(xy atakujacy, xy atakowany);
	void pokonanyAtakujacy(xy atakujacy, xy atakowany);

	virtual void idzPrawo(xy& zmien, zmianaPolozenia& zmpol);
	virtual void idzLewo(xy& zmien, zmianaPolozenia& zmpol);
	virtual void idzDol(xy& zmien, zmianaPolozenia& zmpol);
	virtual void idzGora(xy& zmien, zmianaPolozenia& zmpol);
};
