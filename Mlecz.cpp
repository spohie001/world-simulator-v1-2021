#include "Mlecz.h"

Mlecz::Mlecz(Swiat* swiatWokol)
{
	this->sila = 0;
	this->inicjatywa = 0;
	this->symbolDorosly = 'M';
	this->symbolDziecko = 'm';
	this->symbol = 'M';
	this->nazwa = "Mlecz";
	this->swiatWsk = swiatWokol;
}

void Mlecz::zasiej(xy zasiejTu)
{
	Mlecz* sadzonka = new Mlecz(swiatWsk);
	int rozmiar = swiatWsk->getOrganizmy()->size();
	sadzonka->setIter(rozmiar);
	sadzonka->setPolozenie(zasiejTu);
	sadzonka->setSymbolDziecko();
	swiatWsk->getOrganizmy()->push_back(sadzonka);
	swiatWsk->setPole(zasiejTu, sadzonka);
	cout << "Mlody mlecz zostal zasiany" << endl;
}


void Mlecz::akcja()
{
	for (int i=0; i < 3; i++)
	{
		int szansa = rand() % 10;
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
}

Mlecz::~Mlecz() {}