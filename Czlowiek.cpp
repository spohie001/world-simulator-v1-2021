#include "Czlowiek.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Czlowiek::Czlowiek(Swiat* swiatWokol)
{
	this->sila = 5;
	this->inicjatywa = 4;
	this->symbol = '&';
	this->symbolDorosly = '&';
	this->symbolDziecko = '*';
	this->nazwa = "Czlowiek";
	this->eliksi = NIEWYPITY;
	this->swiatWsk = swiatWokol;
}

void Czlowiek::rozmnazaj(xy zakochany, xy obiekt_uczuc){}

bool Czlowiek::sprawdzGatunek(xy atakujacy, xy atakowany) { return false; }

void Czlowiek::efektEliksiruSpada()
{
	if (this->eliksi == WYPITY)
	{
		setSila(getSila() - 1);
		if (getSila() == getSilaPrzedEliksirem())
			this->eliksi = NIEWYPITY;
		cout << "Sila gazcza to: " << getSila() << endl;
	}
}

void Czlowiek::wypijEliksir()
{
	if (this->eliksi == NIEWYPITY)
	{
		if (getSila() < 10)
		{
			setSilaPrzedEliksirem(this->sila);
			setSila(10);
			this->eliksi = WYPITY;
			cout << "Wypito magiczny eliksir dodajacy sil!\n";
		}
		else
			cout << "Eliksir nie polepszy juz sily\n";
	}
	else
		cout << "Niedawno wypito eliksir\n";
}

void Czlowiek::setSilaPrzedEliksirem(int silaPrzed)
{
	this->silaPrzedEliksirem = silaPrzed;
}

int Czlowiek::getSilaPrzedEliksirem()
{
	return silaPrzedEliksirem;
}

int Czlowiek::wybierzKierunek(int kier)
{
	while (1) 
	{

		switch (_getch())
		{
		case 71://przycisk HOME
			wypijEliksir();
			break;
		case 72:
			return 2;
			break;
		case 80:
			return 3;
			break;
		case 75:
			return 1;
			break;
		case 77:
			return 0;
			break;
		}
	}
}

void Czlowiek::akcja()
{
	cout << "Kolej gracza!\n";
	cout << "Sterowany jest strzalkami. Pod przyciskiem HOME znajduje sie specjalna umiejetnosc: Magiczny Eliksir\n";
	zmianaPolozenia zmpol = NIEZMIENIONY;
	int kierunek=-1;

	efektEliksiruSpada();
		while (zmpol != ZMIENIONY)
		{
			kierunek = wybierzKierunek(kierunek);
			xy zmien = this->getPolozenie();

			if (kierunek == 0)//********************************************prawo
			{
				if (zmien.x != swiatWsk->getX() - 1)
					idzPrawo(zmien, zmpol);
			}
			else if (kierunek == 1)//******************************************lewo
			{
				if (zmien.x != 0)
					idzLewo(zmien, zmpol);
			}
			else if (kierunek == 2)//******************************************gora
			{
				if (zmien.y != 0)
					idzGora(zmien, zmpol);
			}
			else if (kierunek == 3)//******************************************dol
			{
				if (zmien.y != swiatWsk->getY() - 1)
					idzDol(zmien, zmpol);
			}
		}
	}

Czlowiek::~Czlowiek() {};