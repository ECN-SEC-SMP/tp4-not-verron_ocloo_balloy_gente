#pragma once

/**
 * @file ZAU.hpp
 * @brief Déclaration de la classe ZAU — zone agricole urbaine constructible.
 */

#include "Parcelle.hpp"
#include "Constructible.hpp"

/**
 * @class ZAU
 * @brief Classe représentant une zone agricole urbaine (ZAU).
 * 
 * Hérite de Parcelle et de Constructible. Représente une zone pouvant être
 * transformée en zone urbaine, avec une capacité de construction limitée
 * selon le pourcentage constructible de la parcelle.
 */
class ZAU : public Parcelle, public Constructible
{
public : 
    /**
     * @brief Constructeur de ZAU.
     * @param num Numéro d'identification de la parcelle.
     * @param prop Propriétaire de la parcelle.
     * @param forme Polygone représentant la géométrie de la parcelle.
     */
    ZAU(int num, std::string prop, Polygone<int> forme);
    
    /**
     * @brief Destructeur de ZAU.
     */
    ~ZAU();
    
    /**
     * @brief Calcule la surface constructible selon le pourcentage autorisé.
     * @return La surface pouvant être construite en m².
     */
    float surfaceConstructible() const override;
    
    /**
     * @brief Retourne le type de la parcelle.
     * @return "ZAU" le type de cette zone agricole urbaine.
     */
    std::string getType() const override;
    
    /**
     * @brief Surcharge de l'opérateur d'affichage pour ZAU.
     * @param o Flux de sortie.
     * @param zau Référence constante à l'objet ZAU à afficher.
     * @return Le flux de sortie modifié.
     */
    friend std::ostream& operator<<(std::ostream &o, ZAU const& zau);
};
