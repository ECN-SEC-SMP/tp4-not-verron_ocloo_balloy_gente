#pragma once

#include "Parcelle.hpp"
#include "Constructible.hpp"

class ZU : public Parcelle, public Constructible
{
private :
    float surfaceConstruite;
public : 
    ZU();
    ~ZU();
    float getSurfaceConstruite();
    void setSurfaceConstruite(float S);
    float surfaceConstructible() override;
};
