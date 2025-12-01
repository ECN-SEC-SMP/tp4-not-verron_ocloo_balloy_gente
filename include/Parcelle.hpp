#pragma once

#include <iostream>
#include "Polygone.hpp"

class Parcelle{

    private :

        std::string type;
        int numero;
        std::string proprietaire;
        float surface;
        Polygone <int> forme;
        int pConstructible;

    public :

        // Constructeurs
        Parcelle();
        Parcelle(int num, std::string prop, Polygone<int> forme);

        // Getters
        int getNumero();
        std::string getProprietaire();
        float getSurface();
        Polygone<int> getForme();
        virtual std::string getType() = 0;

        // Setters
        void setNumero(int n);
        void setProprietaire(std::string prop);
        void setForme(Polygone<int> forme);
        virtual void setType(std::string type) = 0;

        // Surcharge d'opérateurs
        friend std::ostream& operator<<(std::ostream &o, Parcelle const& p)
        {
            o << "Parcelle n°" << p.numero << " :" << std::endl;
            o << "      Type : " << p.type << std::endl;
            o << "      Polygone : " << p.forme << std::endl;
            o << "      Proprietaire : " << p.proprietaire << std::endl;
            o << "      Surface : " << p.surface << std::endl;
            o << "      \% constructible : " << p.pConstructible << std::endl;
            return o;
        }
};