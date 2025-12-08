#include <cassert>
#include <iostream>

#include "Point2D.hpp"

int main()
{
    using namespace std;

    cout << "\n---------------------------------------------------------------\n";
    cout << "---|                    Tests Point2D                      |--- \n";
    cout << "---------------------------------------------------------------\n";

    Point2D<int> p(1, 2);
    
    assert(p.getX() == 1);
    assert(p.getY() == 2); 
    cout << "[OK] test_Point2D: Creation de point \n";

    p.translater(3, 4);
    assert(p.getX() == 4);
    assert(p.getY() == 6);
    cout << "[OK] test_Point2D: Translation de point\n";

    p.setX(10);
    p.setY(20);
    assert(p.getX() == 10);
    assert(p.getY() == 20);
    cout << "[OK] test_Point2D: Chgt de coordonnees de point \n";

    cout << "Fin de test_Point2D: OK\n";
    return 0;
}
