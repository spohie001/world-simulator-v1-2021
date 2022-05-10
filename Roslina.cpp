#include "Roslina.h"

void Roslina::kolizja(xy atakujacy, xy atakowany){}

void Roslina::dodajSily(xy atakujacy) {}

bool Roslina::czyOdbilAtak(xy atakujacy)
{
	return false;
}

bool Roslina::sprobujUciec()
{
	return false;
}

 void Roslina::zatrujWokol() {}

void Roslina::akcja()
{
	zatrujWokol();
	int szansa = rand() % 7;
	if (szansa == 0)
	{
		int kierunek = rand() % 4;
		xy chceZasiac = this->getPolozenie();

		if (kierunek == 0)//********************************************prawo
		{
			if (chceZasiac.x != swiatWsk->getX() - 1)
			{
				chceZasiac.x++;
				if (swiatWsk->getPole(chceZasiac) == NULL)
				zasiej(chceZasiac);
				else
				{
					chceZasiac.x--;
					cout << this->getNazwa() << " rosnie\n";
				}
			}
		}
		else if (kierunek == 1)//******************************************lewo
		{
			if (chceZasiac.x != 0)
			{
				chceZasiac.x--; 
				if (swiatWsk->getPole(chceZasiac) == NULL)
					zasiej(chceZasiac);
				else
				{
					chceZasiac.x++;
					cout << this->getNazwa() << " rosnie\n";
				}
			}
		}
		else if (kierunek == 2)//******************************************gora
		{
			if (chceZasiac.y != 0)
			{
				chceZasiac.y--;
				if (swiatWsk->getPole(chceZasiac) == NULL)
					zasiej(chceZasiac);
				else
				{
					chceZasiac.y++;
					cout << this->getNazwa() << " rosnie\n";
				}
			}
		}
		else if (kierunek == 3)//******************************************dol
		{
			if (chceZasiac.y != swiatWsk->getY() - 1)
			{
				chceZasiac.y++;
				if (swiatWsk->getPole(chceZasiac) == NULL)
					zasiej(chceZasiac);
				else
				{
					chceZasiac.y--;
					cout << this->getNazwa() << " rosnie\n";
				}
			}
		}
		else
			cout << this->getNazwa() << " rosnie\n";
	}
	else
		cout << this->getNazwa() << " rosnie\n";
}