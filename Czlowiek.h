#pragma once
#include <conio.h>
#include "Zwierze.h"

enum eliksir{NIEWYPITY, WYPITY};

class Czlowiek :
    public Zwierze
{
	int silaPrzedEliksirem;
	eliksir eliksi;
public:
	Czlowiek(Swiat* swiatWokol);
	void rozmnazaj(xy zakochany, xy obiekt_uczuc)override;
	bool sprawdzGatunek(xy atakujacy, xy atakowany)override;
	void akcja()override;

	void wypijEliksir();
	void efektEliksiruSpada();
	void setSilaPrzedEliksirem(int silaPrzed);
	int getSilaPrzedEliksirem();
	int wybierzKierunek(int kier);

	~Czlowiek();
};

