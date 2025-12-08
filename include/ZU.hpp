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
    float surfaceConstructible() const override;
    std::string getType() const override;
    friend std::ostream& operator<<(std::ostream &o, ZU const& zu);
};
