#include <cassert>
#include <iostream>

#include "ZU.hpp"
#include "Polygone.hpp"
#include "Point2D.hpp"

int main()
{
    using namespace std;

    cout << "\n---------------------------------------------------------------\n";
    cout << "---|                    Tests ZU                            |--- \n";
    cout << "---------------------------------------------------------------\n";

    // Creation d'un polygone pour la parcelle ZU
    Polygone<int> poly;
    poly.addPoints(Point2D<int>(0, 0));
    poly.addPoints(Point2D<int>(10, 0));
    poly.addPoints(Point2D<int>(10, 10));
    poly.addPoints(Point2D<int>(0, 10));
    
    // Creation d'une zone urbaine ZU
    ZU zu(1, "Jean Dupont", poly);
    
    // Test: verifier la surface totale (100 m²)
    assert(zu.getSurface() == 100.0f);
    cout << "[OK] test_ZU: Creation et surface totale \n";

    // Test: verifier le pourcentage constructible par defaut
    assert(zu.getPConstructible() == 50);
    cout << "[OK] test_ZU: Pourcentage constructible par defaut \n";

    // Test: verifier la surface construite initiale (0)
    assert(zu.getSurfaceConstruite() == 0.0f);
    cout << "[OK] test_ZU: Surface construite initiale \n";

    // Test: verifier la surface constructible initiale (50% de 100 = 50)
    float surfaceConstructible = zu.surfaceConstructible();
    assert(surfaceConstructible == 50.0f);
    cout << "[OK] test_ZU: Surface constructible initiale (50m² - aucune construction) \n";

    // Test: modifier la surface construite
    zu.setSurfaceConstruite(30.0f);
    assert(zu.getSurfaceConstruite() == 30.0f);
    cout << "[OK] test_ZU: Modification de la surface construite \n";

    // Test: verifier la surface restante constructible (50 - 30 = 20)
    surfaceConstructible = zu.surfaceConstructible();
    assert(surfaceConstructible == 20.0f);
    cout << "[OK] test_ZU: Surface constructible apres construction partielle (20m²) \n";

    // Test: surface construite egale a la surface constructible (0 m² restant)
    zu.setSurfaceConstruite(50.0f);
    surfaceConstructible = zu.surfaceConstructible();
    assert(surfaceConstructible == 0.0f);
    cout << "[OK] test_ZU: Aucune surface restante constructible \n";

    // Test: verifier le type
    assert(zu.getType() == "ZU");
    cout << "[OK] test_ZU: Type de zone \n";

    cout << "Fin de test_ZU: OK\n";
    return 0;
}
