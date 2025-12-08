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

std::ostream& operator<<(std::ostream &o, ZU const& zu)
{
    o << "Parcelle n°" << zu.getNumero() << " :" << std::endl;
    o << "      Type : " << zu.getType() << std::endl;
    o << "      Polygone : " << zu.getForme() << std::endl;
    o << "      Proprietaire : " << zu.getProprietaire() << std::endl;
    o << "      Surface : " << zu.getSurface() << std::endl;
    o << "      \% constructible : " << zu.getPConstructible() << std::endl;
    o << "      surface construite : " << zu.surfaceConstruite << std::endl;
    o << "      surface à construire restante : " << zu.surfaceConstructible() << std::endl;
    return o;
}