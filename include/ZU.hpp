#pragma once

#include "Parcelle.hpp"
#include "Constructible.hpp"

class ZU : public Parcelle, public Constructible
{
private :
    float surfaceConstruite;
public : 
    ZU(int num, std::string prop, Polygone<int> forme);
    ~ZU();
    float getSurfaceConstruite();
    void setSurfaceConstruite(float S);
    float surfaceConstructible() override;
};
