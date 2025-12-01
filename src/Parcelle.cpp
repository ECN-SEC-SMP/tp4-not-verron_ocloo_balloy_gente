#include "Parcelle.hpp"

// Constructeurs

Parcelle::Parcelle(int num, std::string prop, Polygone<int> forme){
    this->numero = num;
    this->proprietaire = prop;
    this->forme = forme;
}

// Getteurs

int Parcelle::getNumero(){
    return numero;
}

std::string Parcelle::getProprietaire(){
    return proprietaire;
}

float Parcelle::getSurface(){
    return surface;
}

Polygone<int> Parcelle::getForme(){
    return forme;
}

// Setteurs

void Parcelle::setNumero(int n){
    this->numero = n;
}

void Parcelle::setProprietaire(std::string prop){
    this->proprietaire = prop;
}

void Parcelle::setForme(Polygone<int> forme){
    this->forme = forme;
}