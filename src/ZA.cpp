#include "ZA.hpp"

ZA::ZA (int num, std::string prop, Polygone<int> forme, std::string inTypeCulture) : ZN(num, prop, forme){
    setType("ZA");
    this->typeCulture = inTypeCulture;
}

ZA::~ZA(){

}

std::string ZA::getTypeCulture() const {
    return this->typeCulture;
}

std::string ZA::getType() const {
    return this->type;
}

void ZA::display(std::ostream &o) const{
    o << "Parcelle n°" << getNumero() << " :" << std::endl;
    o << "      Type : " << getType() << std::endl;
    o << "      Polygone : " << getForme() << std::endl;
    o << "      Proprietaire : " << getProprietaire() << std::endl;
    o << "      Surface : " << getSurface() << std::endl;
    o << "      type culture : " << getTypeCulture() << std::endl;
}