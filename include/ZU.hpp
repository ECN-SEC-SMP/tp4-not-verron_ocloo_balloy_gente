#pragma once

/**
 * @file ZU.hpp
 * @brief Déclaration de la classe ZU — zone urbaine avec surface construite.
 */

#include "Parcelle.hpp"
#include "Constructible.hpp"

/**
 * @class ZU
 * @brief Classe représentant une zone urbaine (ZU) avec construction.
 * 
 * Hérite de Parcelle et de Constructible. Représente une zone urbaine
 * où des constructions sont présentes. Gère la surface déjà construite
 * et la surface restante constructible.
 */
class ZU : public Parcelle, public Constructible
{
private :
    /**
     * @brief Surface déjà construite sur la parcelle.
     */
    float surfaceConstruite;
public : 
    /**
     * @brief Constructeur de ZU.
     * @param num Numéro d'identification de la parcelle.
     * @param prop Propriétaire de la parcelle.
     * @param forme Polygone représentant la géométrie de la parcelle.
     */
    ZU(int num, std::string prop, Polygone<int> forme);
    
    /**
     * @brief Destructeur de ZU.
     */
    ~ZU();
    
    /**
     * @brief Retourne la surface déjà construite sur la parcelle.
     * @return La surface construite en m².
     */
    float getSurfaceConstruite();
    
    /**
     * @brief Modifie la surface construite sur la parcelle.
     * @param S La nouvelle surface construite en m².
     */
    void setSurfaceConstruite(float S);
    
    /**
     * @brief Calcule la surface restante constructible.
     * @return La surface pouvant encore être construite en m².
     */
    float surfaceConstructible() const override;
    
    /**
     * @brief Retourne le type de la parcelle.
     * @return "ZU" le type de cette zone urbaine.
     */
    std::string getType() const override;
    
    /**
     * @brief Surcharge de l'opérateur d'affichage pour ZU.
     * @param o Flux de sortie.
     * @param zu Référence constante à l'objet ZU à afficher.
     * @return Le flux de sortie modifié.
     */
    friend std::ostream& operator<<(std::ostream &o, ZU const& zu);
};
