#pragma once
#include<iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include<string>
using namespace std;

struct xy {
	int x;
	int y;
};

class Swiat;

class Organizm {
protected:
	int sila;
	int inicjatywa;
	int iter;
	char symbol;
	char symbolDorosly;
	char symbolDziecko;
	string nazwa;
	xy polozenie;
	Swiat* swiatWsk;
public:

	virtual void akcja() = 0;
	virtual void kolizja(xy atakujacy, xy atakowany) = 0;
	virtual bool czyOdbilAtak(xy atakujacy) = 0;
	virtual bool sprobujUciec() = 0;
	virtual void dodajSily(xy atakujacy) = 0;
	virtual bool czyOtrul(xy atakujacy);


	 int getSila() ;
	 int getInicjatywa() ;
	 int getIter() ;
	 char getSymbol() ;
	 char getSymbolDorosly();
	 char getSymbolDziecko();
	 string getNazwa() ;
	 xy getPolozenie() ;

	 void setSila(int sil);
	 void setSymbolDorosly();
	 void setSymbolDziecko();
	 void setIter(int it);
	 void setPolozenie(xy pol) ;

};

#include"Swiat.h"