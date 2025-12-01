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
    Point2D() : x(0), y(0) {}
    Point2D(T x, T y) : x(x), y(y) {}
    Point2D(Point2D const &p) : x(p.x), y(p.y) {}
    ~Point2D() = default;

    T getX() { return x; }
    T getY() { return y; }
    
    void setX(T x) { x = x; }
    void setY(T y) { y = y; }
    
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