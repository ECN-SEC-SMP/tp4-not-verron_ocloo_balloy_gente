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

    /**
     * @brief Retourne le type de la parcelle.
     * @return "ZN" le type de cette zone non-aedificandi.
     */
    std::string getType() const override {return this->type;}

    /**
     * @brief Surcharge de l'opérateur d'affichage pour ZN.
     * @param o Flux de sortie.
     * @param zn Référence constante à l'objet ZN à afficher.
     * @return Le flux de sortie modifié.
     */
    void display(std::ostream& o) const override
    {
        o << "Parcelle n°" << getNumero() << " :" << std::endl;
        o << "      Type : " << getType() << std::endl;
        o << "      Polygone : " << getForme() << std::endl;
        o << "      Proprietaire : " << getProprietaire() << std::endl;
        o << "      Surface : " << getSurface() << std::endl;
    }
};

