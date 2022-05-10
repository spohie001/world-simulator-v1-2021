#include<iostream>
#include <algorithm>
#include <Windows.h>

using namespace std;

#include"Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczaJagoda.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Swiat::Swiat()
	:X(20), Y(20), pola(new Organizm** [20])
{
	for (int i = 0; i < Y; i++)
	{
		pola[i] = new Organizm* [X];
		for (int j = 0; j < X; j++)
			pola[i][j] = NULL;
	}
}

Swiat::Swiat(int N, int M)
	:X(N), Y(M), pola(new Organizm** [M])
{
	for (int i = 0; i < M; i++)
	{
		pola[i] = new Organizm * [N];
		for (int j = 0; j < N; j++)
			pola[i][j] = NULL;
	}
}

bool Swiat::czyCzlowiekZyje(Swiat* swiat)
{
	bool zyje = false;
	for (int i = 0; i < swiat->getOrganizm().size(); i++)
	{
		if (Czlowiek* d = dynamic_cast<Czlowiek*>(swiat->getOrganizm()[i]))
			zyje = true;
	}
	return zyje;
}

void Swiat::wykonajTure(Swiat* swiat) 
{
		for (int i = 0; i < swiat->getOrganizm().size(); i++)
		{
			if (swiat->getOrganizm()[i]->getSymbol() == swiat->getOrganizm()[i]->getSymbolDorosly())
			{
				swiat->getOrganizm()[i]->akcja();
				Sleep(2000);
				system("CLS");
				swiat->rysujSwiat();
				Sleep(2000);
			}
		}
		for (int i = 0; i < swiat->getOrganizm().size(); i++)
			if (swiat->getOrganizm()[i]->getSymbol() == swiat->getOrganizm()[i]->getSymbolDziecko())
				swiat->getOrganizm()[i]->setSymbolDorosly();
};

Organizm* Swiat::initZwierzeta(Swiat* swiat)
{
	int losuj = rand() % 5;
	switch (losuj)
	{
	case 0:
		return new Wilk(swiat);
		break;
	case 1:
		return new Owca(swiat);
		break;
	case 2:
		return new Lis(swiat);
		break;
	case 3:
		return new Zolw(swiat);
		break;
	case 4:
		return new Antylopa(swiat);
		break;
	}
}

Organizm* Swiat::initRosliny(Swiat* swiat)
{
	int losuj = rand() % 5;
	switch (losuj)
	{
	case 0:
		return new Trawa(swiat);
		break;
	case 1:
		return new Mlecz(swiat);
		break;
	case 2:
		return new Guarana(swiat);
		break;
	case 3:
		return new WilczaJagoda(swiat);
		break;
	case 4:
		return new BarszczSosnowskiego(swiat);
		break;
	}
}

void Swiat :: symulatorSwiata(Swiat* swiat)
{
	int iloscZ, iloscR;
	cout << "********************>> Witaj w symulatorze swiata! <<********************\n";
	cout << "***********************>> Autor:Zofia Sosinska <<************************\n";
	cout << "*******************>> Podaj prosze ilosc zwierzat <<*********************\n";
	cin >> iloscZ;
	cout << "********************>> Podaj prosze ilosc roslin <<**********************\n";
	cin >> iloscR;
	cout << "                 Nacisnij dowolny klawisz aby rozpoczac\n";
	cout << "                         lub Escape aby wyjsc\n";
	for (int i = 0; i < iloscZ; i++)
	{
		Organizm* zwierze = initZwierzeta(swiat);
		swiat->dodajOrganizm(zwierze);
	}
	for (int i = 0; i < iloscR; i++)
	{
		Organizm* roslina = initRosliny(swiat);
		swiat->dodajOrganizm(roslina);
	}
	Czlowiek gracz(swiat);
	swiat->dodajOrganizm(&gracz);

	if(_getch() != 27)
	{
		int tura = 0;
		while (_getch() != 27)
		{
			tura++;
			swiat->rysujSwiat();
			wykonajTure(swiat);
			if (czyCzlowiekZyje(swiat))
			{
				cout << "                             Koniec tury " << tura << "\n";
				cout << "                 Nacisnij dowolny klawisz aby kontynuowac\n";
				cout << "                         lub Escape aby zakonczyc\n";
			}
			else
			{
				system("CLS");
				cout << "********************>> Niestety zostales pokonany <<*********************\n";
				cout << "********************>> Dziekuje za wspaniala gre! <<*********************\n";
				cout << "*****************>> Do zobaczenia nastepnym razem :) <<******************\n";
				break;

			}
		}
	}
	if (czyCzlowiekZyje(swiat))
	{
		system("CLS");
		cout << "********************>> Dziekuje za wspaniala gre! <<*********************\n";
		cout << "*****************>> Do zobaczenia nastepnym razem :) <<******************\n";
	}
}

void Swiat::sortujOrganizmy(Organizm* nowy)
{
	for (int i = 1; i <= organizmy.size(); i++)
	{
		if (organizmy[organizmy.size() - i]->getInicjatywa() < organizmy[nowy->getIter()]->getInicjatywa())
		{
			swap(organizmy[organizmy.size() - i], organizmy[nowy->getIter()]);
			nowy->setIter(nowy->getIter() - 1);
		}
	}
}


enum dodaj{NIEDODANY, DODANY};

void Swiat::dodajDoWolnego(Organizm* nowy)
{
	dodaj dod = NIEDODANY;
	while (dod == NIEDODANY)
	{
		int i = rand() % Y;
		int j = rand() % X;
		if (pola[i][j] == NULL)
		{
			xy wolne;
			wolne.x = j;
			wolne.y = i;
			nowy->setPolozenie(wolne);
			pola[i][j] = nowy;
			dod = DODANY;
		}
	}
}

void Swiat::dodajOrganizm(Organizm*nowy)
{
	int rozmiar = organizmy.size();
	nowy->setIter(rozmiar);
	organizmy.push_back(nowy);
	sortujOrganizmy(nowy);
	dodajDoWolnego(nowy);
}

void Swiat::aktualizujOrganizmy()
{
	for (int i = 0; i < organizmy.size(); i++)
		organizmy[i]->setIter(i);
}

void Swiat::usunOrganizm(Organizm* usun)
{
	auto it = 1;
	organizmy.erase(organizmy.begin() + usun->getIter());

	aktualizujOrganizmy();
}

void Swiat :: rysujSwiat()
{
	cout << "+";
	for (int i = 0; i < X; i++)
		cout << "-";
	cout << "+" << endl;
	for (int y = 0; y < Y; y++)
	{
		cout << "|";
		for (int x = 0; x < X; x++)
		{
			if (pola[y][x] != NULL)
				cout << pola[y][x]->getSymbol();
			else
				cout << " ";
		}
		cout << "|" << endl;
	}
	cout << "+";
	for (int i = 0; i < X; i++)
		cout << "-";
	cout << "+" << endl;
}

int Swiat::getX()
{
	return X;
}

int Swiat::getY()
{
	return Y;
}

void Swiat::setPole(xy poloz, Organizm* zmien)
{
	pola[poloz.y][poloz.x] = zmien;
}

Organizm* Swiat::getPole(xy poloz)
{
	return pola[poloz.y][poloz.x];
}

vector <Organizm*>* Swiat::getOrganizmy()
{
	return &organizmy;
}

vector <Organizm*> Swiat::getOrganizm()
{
	return organizmy;
}


Swiat::~Swiat()
{
	for (int j = 0; j < Y; j++)
		delete[] pola[j];
	delete[] pola;

	if (organizmy.size() > 0)
		organizmy.clear();
}