/**
 * @file Point2D.hpp
 * @brief
 * @version 0.1
 * @date 01-12-2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include <iostream>

using namespace std;

/**
 * @brief Classe représentant un point
 * 
 * @tparam T Type des coordonnées
 */
template <typename T>
class Point2D
{
protected:
    T x;
    T y;

public:
    /**
     * @brief Constructeur par défaut. Initialise x et y à 0.
     */
    Point2D() : x(0), y(0) {}

    /**
     * @brief Constructeur avec coordonnées.
     * @param x Coordonnée en X.
     * @param y Coordonnée en Y.
     */
    Point2D(T x, T y) : x(x), y(y) {}

    /**
     * @brief Constructeur de copie.
     * @param p Point source.
     */
    Point2D(Point2D const &p) : x(p.x), y(p.y) {}

    /**
     * @brief Destructeur par défaut.
     */
    ~Point2D() = default;

    /**
     * @brief Retourne la coordonnée X du point.
     * @return T valeur de x.
     */
    T getX() { return x; }

    /**
     * @brief Retourne la coordonnée Y du point.
     * @return T valeur de y.
     */
    T getY() { return y; }
    
    /**
     * @brief Définit la coordonnée X du point.
     * @param nx Nouvelle valeur de x.
     */
    void setX(T nx) { x = nx; }

    /**
     * @brief Définit la coordonnée Y du point.
     * @param ny Nouvelle valeur de y.
     */
    void setY(T ny) { y = ny; }
    
    /**
     * @brief Translate le point suivant un déplacement dx/dy.
     * @param dx Déplacement en X.
     * @param dy Déplacement en Y.
     */
    void translater(T dx, T dy);

    friend ostream &operator<<(ostream &s, Point2D const &p)
    {
        s << " le point à pour coordonnée x, y : (" << p.x << ", " << p.y << ")";
        return s;
    }
};

template <typename T>
void Point2D<T>::translater(T dx, T dy)   
{
    x += dx;
    y += dy;
}