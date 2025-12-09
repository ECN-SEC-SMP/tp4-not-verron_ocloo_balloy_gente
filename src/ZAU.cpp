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

void ZAU::display(std::ostream& o) const {
    o << "Parcelle n°" << getNumero() << " :" << std::endl;
    o << "      Type : " << getType() << std::endl;
    o << "      Polygone : " << getForme() << std::endl;
    o << "      Proprietaire : " << getProprietaire() << std::endl;
    o << "      Surface : " << getSurface() << std::endl;
    o << "      \% constructible : " << getPConstructible() << std::endl;
}
