#include "Parcelle.hpp"

// Constructeurs

Parcelle::Parcelle();

Parcelle::Parcelle(int num, std::string prop, Polygone<int,float> forme){
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

Polygone<int,float> Parcelle::getForme(){
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

// Surcharge d'opérateur

friend std::ostream& operator<<(std::ostream &o)
{
    o << "Parcelle n°" << numero << " :" << endl;
    o << "      Type : " << type << endl;
    o << "      Polygone : " << forme << endl;
    o << "      Proprietaire : " << proprietaire << endl;
    o << "      Surface : " << surface << endl;
    o << "      \% constructible : " << pConstructible << endl;
    return o;
}