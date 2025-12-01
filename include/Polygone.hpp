
/**
 * @file Polygone.hpp
 * @brief Déclaration de la classe template Polygone — représentation d'un polygone
 *        par une liste ordonnée de sommets.
 *
 * @tparam T Type numérique utilisé pour les coordonnées des points (ex : int, double).
 */

# pragma once 

#include "Point2D.hpp"
#include <iostream>
#include <vector>

/**
 * @brief Classe template représentant un polygone défini par une liste de sommets.
 *
 * La classe stocke les sommets dans un std::vector de Point2D<T> et fournit des
 * accesseurs et opérations basiques (ajout de point, translation, ...).
 *
 * @tparam T Type des coordonnées des points.
 */
template <typename T>
class Polygone {
    
    private : 
//----------------------------------------------------------------------------------------------------
// Attribut
//----------------------------------------------------------------------------------------------------
        /// Liste des sommets du polygone (ordre des sommets conservé)
        std::vector <Point2D <T> > sommets;

    public : 

//----------------------------------------------------------------------------------------------------
// Constructeurs 
//----------------------------------------------------------------------------------------------------
        /**
         * @brief Constructeur par défaut — crée un polygone vide.
         */
        Polygone ()                                                         {}

        /**
         * @brief Constructeur à partir d'un vecteur de sommets.
         * @param sommets Vecteur des sommets à utiliser pour initialiser le polygone.
         */
        Polygone (std::vector <Point2D <T> > sommets) : sommets (sommets)   {}

        /**
         * @brief Constructeur de copie.
         * @param p Polygone source à copier.
         */
        Polygone (Polygone<T> & const p) : sommets (p.sommets)              {}

//----------------------------------------------------------------------------------------------------
// Destructeur 
//----------------------------------------------------------------------------------------------------
        /**
         * @brief Destructeur par défaut.
         */
        ~Polygone()                                                         default;

//----------------------------------------------------------------------------------------------------
// Accesseurs 
//----------------------------------------------------------------------------------------------------
        /**
         * @brief Retourne la liste des sommets (copie).
         * @return std::vector<Point2D<T>> Copie du vecteur de sommets.
         */
        std::vector <Point2D <T> > getSommets ()                            {return this->sommets};

        /**
         * @brief Remplace la liste des sommets par une nouvelle liste.
         * @param inSommets Nouveau vecteur de sommets.
         */
        void setSommets (std::vector <Point2D <T> > inSommets)              {this->sommets = inSommets};

//----------------------------------------------------------------------------------------------------
// Methodes 
//----------------------------------------------------------------------------------------------------
        /**
         * @brief Ajoute un point à la fin de la liste des sommets.
         * @param p Point à ajouter.
         */
        void addPoints (Point2D <T> p) {
            std::vector<Point2D <T> > newSommets = this->sommets;
            newSommets.push_back(p);

            setSommets (newSommets);
        }

        /**
         * @brief Translate tous les sommets du polygone.
         * @param x Déplacement en X.
         * @param y Déplacement en Y.
         */
        void translater (T x, T y) {
            std::vector<Point2D <T> > sommetsTranslates = this->sommets;

            for (Point2D <T> p : sommetsTranslates) {
                p.translater (x, y);
            }
            setSommets (sommetsTranslates);
        }
};

/**
 * @brief Surcharge de l'opérateur d'insertion pour afficher un Polygone.
 *
 * Formate le polygone sous la forme : Polygone{(x1, y1), (x2, y2), ...}
 */
template <typename T>
std::ostream &operator<<(std::ostream &os, Polygone<T> const &poly)
{
    std::vector<Point2D<T>> verts = poly.getSommets();
    os << "Polygone{";
    for (Point2D <T> p : poly.getSommets()) {
        os << p << ", ";
    }
    os << "}";
    return os;
}
