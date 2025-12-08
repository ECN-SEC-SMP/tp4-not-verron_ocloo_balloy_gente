#include "Parcelle.hpp"

// Constructeurs

Parcelle::Parcelle(){
    this->numero = 0;
    this->proprietaire = "";
}

Parcelle::Parcelle(int num, std::string prop, Polygone<int> forme){
    this->numero = num;
    this->proprietaire = prop;
    this->forme = forme;
}

// Getteurs

int Parcelle::getNumero() const{
    return numero;
}

std::string Parcelle::getProprietaire() const{
    return proprietaire;
}

float Parcelle::getSurface() const{
    return surface;
}

const Polygone<int>& Parcelle::getForme() const{
    return forme;
}

int Parcelle::getPConstructible() const{
    return pConstructible;
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

void Parcelle::setPConstructible(int p){
    this->pConstructible = p;
}

// Surcharge de <<

std::ostream& operator<<(std::ostream &o, Parcelle const& p)
{
    o << "Parcelle n°" << p.numero << " :" << std::endl;
    o << "      Type : " << p.type << std::endl;
    o << "      Polygone : " << p.forme << std::endl;
    o << "      Proprietaire : " << p.proprietaire << std::endl;
    o << "      Surface : " << p.surface << std::endl;
    o << "      \% constructible : " << p.pConstructible << std::endl;
    return o;
}

// Méthode

float Parcelle::calculerSurface(){
    float area = 0.0;
    std::vector<Point2D<int>> sommets = forme.getSommets();
    int n = sommets.size();

    for (int i = 0; i < n; i++) {
        Point2D<int> p1 = sommets[i];
        Point2D<int> p2 = sommets[(i + 1)];

        area += (p1.getX() * p2.getY()) - (p1.getY() * p2.getX());
    }
    area = area / 2.0;

    this->surface = area;
    return area;
}