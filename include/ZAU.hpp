#pragma once

#include "Parcelle.hpp"
#include "Constructible.hpp"

class ZAU : public Parcelle, public Constructible
{
public : 
    ZAU(int num, std::string prop, Polygone<int> forme);
    ~ZAU();
    float surfaceConstructible() const override;
    std::string getType() const override;
    friend std::ostream& operator<<(std::ostream &o, ZAU const& zau);
};
