#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :
    public Roslina
{
public:
    BarszczSosnowskiego(Swiat* swiatWokol);
    void zasiej(xy zasiejTu)override;
    bool czyOtrul(xy atakujacy)override;
    void zatrujWokol()override;
    void zatruj(xy zatruwa);
    ~BarszczSosnowskiego();
};

