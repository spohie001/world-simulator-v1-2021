#include<iostream>
#include"Organizm.h"
using namespace std;

bool Organizm::czyOtrul(xy atakujacy) { return false; }

int Organizm::getSila()
{
	return sila;
 }
int Organizm::getInicjatywa()
{
	return inicjatywa;
 }

int Organizm::getIter()
{
	return iter;
}

char Organizm::getSymbol()
{
	return symbol;

 }

string  Organizm::getNazwa()
{
	return nazwa;
}

xy Organizm::getPolozenie()
{
	return polozenie;
 }

void Organizm::setSila(int sil)
{
	this->sila = sil;
 }
void Organizm::setPolozenie(xy pol)
{
	this->polozenie = pol;
 }

void Organizm::setIter(int it)
{
	this->iter = it;
}

void Organizm::setSymbolDorosly()
{
	this->symbol = this->symbolDorosly;
	cout << this->getNazwa() << " dorasta!\n";
}

void Organizm::setSymbolDziecko()
{
	this->symbol = this->symbolDziecko;
}

char Organizm::getSymbolDorosly()
{
	return symbolDorosly;
}

char Organizm::getSymbolDziecko()
{
	return symbolDziecko;
}