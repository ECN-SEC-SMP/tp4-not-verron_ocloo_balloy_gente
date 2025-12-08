/**
 * @file ZN.hpp
 * @brief Déclaration de la classe ZN.
 *
 * La classe ZN représente une zone non-aedificandi (zone où la construction est interdite).
 * Elle hérite de Parcelle et de Constructible.
 *
 * @author Équipe TP
 * @date 2025
 */

#pragma once

#include "Parcelle.hpp"
#include "Constructible.hpp"

/**
 * @brief Classe représentant une ZN.
 *
 * Hérite de Parcelle et de Constructible. Une zone est une
 * zone où la construction est interdite selon les règles d'urbanisme.
 */
class ZN : public Parcelle
{
public:
    /**
     * @brief Constructeur de ZN.
     * @param num Numéro d'identification de la parcelle.
     * @param prop Propriétaire de la parcelle.
     * @param forme Polygone représentant la géométrie de la parcelle.
     */
    ZN(int num, std::string prop, Polygone<int> forme) : Parcelle(num, prop, forme) { setType("ZN"); };

    /**
     * @brief Destructeur de ZN.
     */
    ~ZN() {};

    std::string getType() const override {return this->type;}

    friend std::ostream &operator<<(std::ostream &o, ZN const &zn)
    {
        o << "Parcelle n°" << zn.getNumero() << " :" << std::endl;
        o << "      Type : " << zn.getType() << std::endl;
        o << "      Polygone : " << zn.getForme() << std::endl;
        o << "      Proprietaire : " << zn.getProprietaire() << std::endl;
        o << "      Surface : " << zn.getSurface() << std::endl;
        return o;
    }
};
