#pragma once

#include <vector>
#include "Parcelle.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class Carte {
private:
    std::vector<Parcelle> listeParcelles;
    float surface;
public:
    //Constructeur 
    Carte(string file);

    //Getters   
    std::vector<Parcelle> getListeParcelles() const;
    float getSurface() const;

    //Setters
    void setListeParcelles(const std::vector<Parcelle>& listeParcelles);
    void setSurface(float surface);
};