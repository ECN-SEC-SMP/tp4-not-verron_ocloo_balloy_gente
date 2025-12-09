#include <cassert>
#include <iostream>

#include "ZAU.hpp"
#include "Polygone.hpp"
#include "Point2D.hpp"

int main()
{
    using namespace std;

    cout << "\n---------------------------------------------------------------\n";
    cout << "---|                    Tests ZAU                           |--- \n";
    cout << "---------------------------------------------------------------\n";

    // Creation d'un polygone pour la parcelle ZAU
    Polygone<int> poly;
    poly.addPoints(Point2D<int>(0, 0));
    poly.addPoints(Point2D<int>(20, 0));
    poly.addPoints(Point2D<int>(20, 10));
    poly.addPoints(Point2D<int>(0, 10));
    
    // Creation d'une zone agricole urbaine ZAU
    ZAU zau(2, "Marie Martin", poly);
    
    // Test: verifier la surface totale (200 m²)
    assert(zau.getSurface() == 200.0f);
    cout << "[OK] test_ZAU: Creation et surface totale \n";

    // Test: verifier le pourcentage constructible par defaut
    assert(zau.getPConstructible() == 50);
    cout << "[OK] test_ZAU: Pourcentage constructible par defaut \n";

    // Test: verifier la surface constructible (50% de 200 = 100)
    float surfaceConstructible = zau.surfaceConstructible();
    assert(surfaceConstructible == 100.0f);
    cout << "[OK] test_ZAU: Surface constructible (50% de 200m²) \n";

    // Test: verifier le type
    assert(zau.getType() == "ZAU");
    cout << "[OK] test_ZAU: Type de zone \n";

    // Test: changement du pourcentage constructible
    zau.setPConstructible(30);
    surfaceConstructible = zau.surfaceConstructible();
    assert(surfaceConstructible == 60.0f);
    cout << "[OK] test_ZAU: Surface constructible apres changement de pourcentage (30% de 200m²) \n";

    // Test: autre parcelle avec pourcentage different
    Polygone<int> poly2;
    poly2.addPoints(Point2D<int>(0, 0));
    poly2.addPoints(Point2D<int>(10, 0));
    poly2.addPoints(Point2D<int>(10, 10));
    poly2.addPoints(Point2D<int>(0, 10));
    
    ZAU zau2(3, "Pierre Durand", poly2);
    zau2.setPConstructible(75);
    
    assert(zau2.getSurface() == 100.0f);
    assert(zau2.getPConstructible() == 75);
    surfaceConstructible = zau2.surfaceConstructible();
    assert(surfaceConstructible == 75.0f);
    cout << "[OK] test_ZAU: Surface constructible avec pourcentage 75% (75m²) \n";

    // Test: pourcentage constructible a 100%
    zau2.setPConstructible(100);
    surfaceConstructible = zau2.surfaceConstructible();
    assert(surfaceConstructible == 100.0f);
    cout << "[OK] test_ZAU: Surface constructible avec pourcentage 100% (100m²) \n";

    cout << "Fin de test_ZAU: OK\n";
    return 0;
}
