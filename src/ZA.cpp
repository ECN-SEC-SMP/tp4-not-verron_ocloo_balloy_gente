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

std::ostream& operator<<(std::ostream &o, ZA const& za)
{
    o << "Parcelle n°" << za.getNumero() << " :" << std::endl;
    o << "      Type : " << za.getType() << std::endl;
    o << "      Polygone : " << za.getForme() << std::endl;
    o << "      Proprietaire : " << za.getProprietaire() << std::endl;
    o << "      Surface : " << za.getSurface() << std::endl;
    o << "      type culture : " << za.getTypeCulture() << std::endl;
    return o;
}