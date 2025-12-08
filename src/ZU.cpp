#include "ZU.hpp"

ZU::ZU(int num, std::string prop, Polygone<int> forme) : Parcelle(num, prop, forme){
    this->setType("ZN");
}

ZU::~ZU(){
}

float ZU::getSurfaceConstruite(){
    return this->surfaceConstruite;
}

void ZU::setSurfaceConstruite(float S) {
    this->surfaceConstruite = S;
}

float ZU::surfaceConstructible(){
    return ((this->getPConstructible()/100)*this->getSurface() - this->surfaceConstruite);
}