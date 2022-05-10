#include<iostream>
#include"Swiat.h"

using namespace std;

int main()
{
	srand(time(NULL));
	int x, y;
	cout << "********************>> Witaj w przygotowaniu do gry! <<********************\n";
	cout << "***********>> Podaj prosze wymiary mapy(Szerokosc x Wysokosc) <<***********\n";
	cin >> x >> y;
	Swiat swiat(x,y);
	swiat.symulatorSwiata(&swiat);

	return 0;
}