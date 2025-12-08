#include "Parcelle.hpp"

// Constructeurs

Parcelle::Parcelle()
{
    this->numero = 0;
    this->proprietaire = "";
}

Parcelle::Parcelle(int num, std::string prop, Polygone<int> forme)
{
    this->numero = num;
    this->proprietaire = prop;
    this->forme = forme;

    // calcul surface
    float area = 0.0;
    std::vector<Point2D<int>> sommets = forme.getSommets();
    int n = sommets.size();

    for (int i = 0; i < n; i++)
    {
        Point2D<int> p1 = sommets[i];
        Point2D<int> p2 = sommets[(i + 1)];

        area += (p1.getX() * p2.getY()) - (p1.getY() * p2.getX());
    }
    area = area / 2.0;

    this->surface = area;
}

// Getteurs

int Parcelle::getNumero() const
{
    return numero;
}

std::string Parcelle::getProprietaire() const
{
    return proprietaire;
}

float Parcelle::getSurface() const
{
    return surface;
}

const Polygone<int> &Parcelle::getForme() const
{
    return forme;
}

int Parcelle::getPConstructible() const
{
    return pConstructible;
}

// Setteurs

void Parcelle::setNumero(int n)
{
    this->numero = n;
}

void Parcelle::setProprietaire(std::string prop)
{
    this->proprietaire = prop;
}

void Parcelle::setForme(Polygone<int> forme)
{
    this->forme = forme;
}

void Parcelle::setPConstructible(int p)
{
    this->pConstructible = p;
}

void Parcelle::display(std::ostream &o) const
{
    o << "Parcelle n°" << numero << " :" << std::endl;
    o << "      Type : " << type << std::endl;
    o << "      Polygone : " << forme << std::endl;
    o << "      Proprietaire : " << proprietaire << std::endl;
    o << "      Surface : " << surface << std::endl;
    o << "      \% constructible : " << pConstructible << std::endl;
}

// Surcharge de <<

std::ostream &operator<<(std::ostream &o, const Parcelle &p)
{
    p.display(o);
    return o;
}
