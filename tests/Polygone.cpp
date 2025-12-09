#include <cassert>
#include <iostream>
#include <vector>

#include "Polygone.hpp"
#include "Point2D.hpp"

int main()
{
    using namespace std;


    cout << "\n---------------------------------------------------------------\n";
    cout << "---|                    Tests Polygone                     |--- \n";
    cout << "---------------------------------------------------------------\n";

    Polygone<int> poly;
    poly.addPoints(Point2D<int>(1, 1));
    poly.addPoints(Point2D<int>(2, 2));

    vector<Point2D<int>> sommets = poly.getSommets();
    assert(sommets.size() == 2);
    assert(sommets[0].getX() == 1 && sommets[0].getY() == 1);
    assert(sommets[1].getX() == 2 && sommets[1].getY() == 2);
    cout << "[OK] test_Polygone: Creation des sommets \n";

    poly.translater(3, 4);
    sommets = poly.getSommets();
    // Translation doit ajouter (3,4) 
    assert(sommets[0].getX() == 4 && sommets[0].getY() == 5);
    assert(sommets[1].getX() == 5 && sommets[1].getY() == 6);
    cout << "[OK] test_Polygone: Translation \n";

    cout << "Fin de test_Polygone: OK\n";
    return 0;
}
