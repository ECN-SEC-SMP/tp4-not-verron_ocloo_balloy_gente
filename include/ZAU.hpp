#pragma once

#include "Parcelle.hpp"
#include "Constructible.hpp"

class ZAU : public Parcelle, public Constructible
{
public : 
    ZAU();
    ~ZAU();
    float surfaceConstructible() override;
};
