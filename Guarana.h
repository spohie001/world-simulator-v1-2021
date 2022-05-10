#pragma once
#include "Roslina.h"
class Guarana :
    public Roslina
{
public:
    Guarana(Swiat* swiatWokol);
    void zasiej(xy zasiejTu)override;
    void dodajSily(xy atakujacy)override;
    ~Guarana();
};