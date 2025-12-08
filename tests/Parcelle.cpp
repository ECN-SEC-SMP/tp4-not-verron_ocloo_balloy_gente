#include <cassert>
#include <cmath>
#include <iostream>

#include "ZN.hpp" // ZN inherits Parcelle
#include "Polygone.hpp"

int main()
{
    using namespace std;
    cout << "\n---------------------------------------------------------------\n";
    cout << "---|                    Tests Parcelle                     |--- \n";
    cout << "---------------------------------------------------------------\n";

    Polygone<int> poly;
    poly.addPoints(Point2D<int>(1,1));
    poly.addPoints(Point2D<int>(-1,1));
    poly.addPoints(Point2D<int>(-1,-1));
    poly.addPoints(Point2D<int>(1,-1));

    ZN zn(42, "owner", poly);

    assert(zn.getNumero() == 42);
    cout << "[OK] test_Parcelle : Verifiation du numero \n";
    assert(zn.getProprietaire() == "owner");
    cout << "[OK] test_Parcelle : Verifiation du proprietaire \n";

    float area = zn.getSurface();

    assert(area == 4.);
    cout << "[OK] test_Parcelle : Verifiation du calcul de la surface \n";

    cout << "Fin de test_Parcelle: OK\n";

    return 0;
}
