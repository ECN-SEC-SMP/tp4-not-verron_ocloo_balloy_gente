#include <cassert>
#include <iostream>

#include "Carte.hpp"

int main()
{
    using namespace std;
    
    cout << "\n---------------------------------------------------------------\n";
    cout << "---|                    Tests Carte                      |--- \n";
    cout << "---------------------------------------------------------------\n";

    Carte c("assets/Parcelles_short.txt");

    cout << "test_Carte: Construction ok\n";
    return 0;
}
