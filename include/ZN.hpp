#pragma once

#include "Parcelle.hpp"
#include "Constructible.hpp"

class ZN : public Parcelle, public Constructible
{
public : 
    ZN(int num, std::string prop, Polygone<int> forme) : Parcelle(num, prop, forme) {setType("ZN");};
    ~ZN();  
};
