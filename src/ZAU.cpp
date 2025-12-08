#include "ZAU.hpp"

ZAU::ZAU(int num, std::string prop, Polygone<int> forme): Parcelle(num, prop, forme){
    this->setType("ZAU");
}

ZAU::~ZAU(){
}

std::string ZAU::getType() const{
    return this->type;
}

float ZAU::surfaceConstructible() const{
    return (this->getPConstructible()/100)*this->getSurface();
}

std::ostream& operator<<(std::ostream &o, ZAU const& zau)
{
    o << "Parcelle n°" << zau.getNumero() << " :" << std::endl;
    o << "      Type : " << zau.getType() << std::endl;
    o << "      Polygone : " << zau.getForme() << std::endl;
    o << "      Proprietaire : " << zau.getProprietaire() << std::endl;
    o << "      Surface : " << zau.getSurface() << std::endl;
    o << "      \% constructible : " << zau.getPConstructible() << std::endl;
    return o;
}