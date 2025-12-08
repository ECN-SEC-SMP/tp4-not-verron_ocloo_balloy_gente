#pragma once

#include <vector>
#include <iostream>
#include "../include/Parcelle.hpp"
#include "../include/Polygone.hpp"
#include "../include/Point2D.hpp"
#include "../include/ZU.hpp"
#include "../include/ZAU.hpp"
#include "../include/ZA.hpp"
#include "../include/ZN.hpp"
#include <string>
#include <sstream>
#include <fstream>

class Carte {
private:
    std::vector<Parcelle*> listeParcelles;
    float surface;
public:
    //Constructeur 
    Carte(std::string file);

    //Méthodes
    void afficherParcelles() const;
    void sauvegarderCarte(const std::string& filename) const;

    //Getters   
    std::vector<Parcelle*> getListeParcelles() const;
    float getSurface() const;

    //Setters
    void setListeParcelles(const std::vector<Parcelle*>& listeParcelles);
    void setSurface(float surface);
};