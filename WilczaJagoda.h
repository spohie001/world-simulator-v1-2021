#pragma once
#include "Roslina.h"
class WilczaJagoda :
    public Roslina
{
public:
    WilczaJagoda(Swiat* swiatWokol);
    void zasiej(xy zasiejTu)override;
    bool czyOtrul(xy atakujacy)override;
    ~WilczaJagoda();
};

