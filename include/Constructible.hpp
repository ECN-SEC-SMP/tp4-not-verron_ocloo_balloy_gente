#pragma once

/**
 * @file Constructible.hpp
 * @brief Interface abstraite pour les zones constructibles.
 */

/**
 * @class Constructible
 * @brief Interface abstraite définissant la surface constructible d'une parcelle.
 * 
 * Cette classe fournit une interface pour calculer la surface constructible
 * d'une parcelle selon sa réglementation.
 */
class Constructible
{
public:
    /**
     * @brief Constructeur par défaut.
     */
    Constructible() = default;
    
    /**
     * @brief Destructeur virtuel par défaut.
     */
    ~Constructible() = default;
    
    /**
     * @brief Calcule la surface constructible de la parcelle.
     * @return La surface pouvant être construite en m².
     */
    virtual float surfaceConstructible() const = 0;
};
