#pragma once
#include "Roslina.h"
class Trawa :
    public Roslina
{
public:
    Trawa(Swiat* swiatWokol);
    void zasiej(xy zasiejTu)override;
    ~Trawa();
};

