/**
 * @file Parcelle.hpp
 * @brief Définition de la classe Parcelle
 */

#pragma once

#include <iostream>
#include "Polygone.hpp"

/**
 * @class Parcelle
 * @brief Classe abstraite représentant une parcelle de terrain
 * 
 * Cette classe définit les propriétés et méthodes communes à toutes les parcelles.
 * Elle contient des informations sur le numéro, le propriétaire, la forme géométrique,
 * la surface et le pourcentage constructible.
 */
class Parcelle{

    private :

        int numero; ///< Numéro d'identification de la parcelle
        std::string proprietaire; ///< Nom du propriétaire de la parcelle
        float surface; ///< Surface de la parcelle en m²
        Polygone <int> forme; ///< Forme géométrique de la parcelle
        int pConstructible; ///< Pourcentage constructible de la parcelle

    protected : 

        std::string type;///< Type de la parcelle

    public :

        /**
         * @brief Constructeur par défaut
         * 
         * Initialise une parcelle avec des valeurs par défaut (numéro = 0, propriétaire = "")
         */
        Parcelle();
        
        /**
         * @brief Constructeur paramétré
         * @param num Numéro de la parcelle
         * @param prop Nom du propriétaire
         * @param forme Polygone représentant la forme de la parcelle
         */
        Parcelle(int num, std::string prop, Polygone<int> forme);

        /**
         * @brief Obtient le numéro de la parcelle
         * @return Le numéro de la parcelle
         */
        int getNumero() const;
        
        /**
         * @brief Obtient le nom du propriétaire
         * @return Le nom du propriétaire
         */
        std::string getProprietaire() const;
        
        /**
         * @brief Obtient la surface de la parcelle
         * @return La surface en m²
         */
        float getSurface() const;
        
        /**
         * @brief Obtient la forme géométrique de la parcelle
         * @return Le polygone représentant la forme
         */
        const Polygone<int>& getForme() const;
        
        /**
         * @brief Obtient le type de la parcelle
         * @return Le type de la parcelle (méthode virtuelle pure)
         */
        virtual std::string getType() const = 0;
        
        /**
         * @brief Obtient le pourcentage constructible
         * @return Le pourcentage constructible de la parcelle
         */
        int getPConstructible() const;

        /**
         * @brief Définit le numéro de la parcelle
         * @param n Le nouveau numéro
         */
        void setNumero(int n);
        
        /**
         * @brief Définit le propriétaire de la parcelle
         * @param prop Le nom du nouveau propriétaire
         */
        void setProprietaire(std::string prop);
        
        /**
         * @brief Définit la forme géométrique de la parcelle
         * @param forme Le polygone représentant la nouvelle forme
         */
        void setForme(Polygone<int> forme);
        
        /**
         * @brief Définit le type de la parcelle
         * @param type Le nouveau type
         */
        void setType(std::string type) {this->type = type;};

        /**
         * @brief Calcule la surface de la parcelle en m²
         * @return La surface calculée
         */
        float calculerSurface();

        /**
         * @brief Surcharge de l'opérateur de flux de sortie
         * @param o Le flux de sortie
         * @param p La parcelle à afficher
         * @return Le flux de sortie modifié
         */
        friend std::ostream& operator<<(std::ostream &o, Parcelle const& p);
};