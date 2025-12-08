#pragma once

#include "ZA.hpp"

ZA::ZA(int num, std::string prop, Polygone<int> forme, std::string inTypeCulture) : ZN(num, prop, forme){
    setType("ZA");
    this->typeCulture = inTypeCulture;
}

ZA::~ZA(){

}

std::string ZA::getTypeCulture () {
    return this->typeCulture;
}