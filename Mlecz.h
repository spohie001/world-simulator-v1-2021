#pragma once
#include "Roslina.h"
class Mlecz :
    public Roslina
{

public:
    Mlecz(Swiat* swiatWokol);
    void zasiej(xy zasiejTu)override;
    void akcja()override;
    ~Mlecz();
};

