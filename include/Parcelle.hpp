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
        Parcelle(int num, std::string prop, Polygone<int,float> forme);

        // Getters
        int getNumero();
        std::string getProprietaire();
        float getSurface();
        Polygone<int,float> getForme();
        virtual std::string getType() = 0;

        // Setters
        void setNumero(int n);
        void setProprietaire(std::string prop);
        void setForme(Polygone<int> forme);
        virtual void setType(std::string type) = 0;

        // Surcharge d'opérateurs
        friend std::ostream& operator<<(std::ostream &o);
};