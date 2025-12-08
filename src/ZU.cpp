#include "ZU.hpp"

ZU::ZU(int num, std::string prop, Polygone<int> forme) : Parcelle(num, prop, forme)
{
    this->type = "ZU";
}

ZU::~ZU(){
}

float ZU::getSurfaceConstruite(){
    return this->surfaceConstruite;
}

void ZU::setSurfaceConstruite(float S) {
    this->surfaceConstruite = S;
}

float ZU::surfaceConstructible() const{
    return ((this->getPConstructible()/100)*this->getSurface() - this->surfaceConstruite);
}

std::string ZU::getType() const {
    return this->type;
}

void ZU::display(std::ostream& o) const
{
    o << "Parcelle n°" << getNumero() << " :" << std::endl;
    o << "      Type : " << getType() << std::endl;
    o << "      Polygone : " << getForme() << std::endl;
    o << "      Proprietaire : " << getProprietaire() << std::endl;
    o << "      Surface : " << getSurface() << std::endl;
    o << "      \% constructible : " << getPConstructible() << std::endl;
    o << "      surface construite : " << surfaceConstruite << std::endl;
    o << "      surface à construire restante : " << surfaceConstructible() << std::endl;
}