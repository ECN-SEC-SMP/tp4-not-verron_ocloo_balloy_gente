/**
 * @file ZA.hpp
 * @brief Déclaration de la classe ZA — zone agricole avec type de culture.
 * 
 * La classe ZA représente une zone agricole, héritant de ZN
 *   avec un attribut supplémentaire pour spécifier le type de culture.
 *
 * @author Équipe TP
 * @date 2025
 */

#pragma once

#include "ZN.hpp"
#include "Constructible.hpp"

/**
 * @brief Classe représentant une zone agricole (ZA).
 *
 * Hérite de ZN. Ajoute la notion de type de culture
 * (ex : céréales, légumes, vignes, etc.).
 */
class ZA : public ZN
{

private : 

//----------------------------------------------------------------------------------------------------
// Attribut
//----------------------------------------------------------------------------------------------------
    /// Type de culture cultivée dans cette zone agricole
    std::string typeCulture;

public : 

//----------------------------------------------------------------------------------------------------
// Constructeur
//----------------------------------------------------------------------------------------------------
    /**
     * @brief Constructeur de ZA.
     * @param num Numéro d'identification de la parcelle.
     * @param prop Propriétaire de la parcelle.
     * @param forme Polygone représentant la géométrie de la parcelle.
     * @param inTypeCulture Type de culture cultivée dans cette zone agricole.
     */
    ZA(int num, std::string prop, Polygone<int> forme, std::string inTypeCulture);
    
//----------------------------------------------------------------------------------------------------
// Destructeur
//----------------------------------------------------------------------------------------------------
    /**
     * @brief Destructeur de ZA.
     */
    ~ZA(); 
    
//----------------------------------------------------------------------------------------------------
// Methode
//----------------------------------------------------------------------------------------------------
    /**
     * @brief Retourne le type de culture de cette zone agricole.
     * @return std::string Le type de culture.
     */
    std::string getTypeCulture() const;

    /**
     * @brief Retourne le type de la parcelle.
     * @return "ZA" le type de cette zone agricole.
     */
    std::string getType() const override;

    /**
     * @brief Surcharge de l'opérateur d'affichage pour ZA.
     * @param o Flux de sortie.
     * @param za Référence constante à l'objet ZA à afficher.
     * @return Le flux de sortie modifié.
     */
    friend std::ostream& operator<<(std::ostream &o, ZA const& za);
};