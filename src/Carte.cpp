#include "Carte.hpp"

Carte::Carte(string file){
    ifstream fichier("../assets/Parcelles_short.txt"); // Ouvre le fichier en lecture
    string ligne;
    string mot;

    if (fichier.is_open()) {
        while (getline(fichier, ligne)) { // Lit la première ligne
            while (getline(fichier, ligne)) { // Lit la deuxième ligne
                std::stringstream ss(ligne);
                while (getline(ss, mot, ' ')){ // Lit jusqu'au premier espace
                    cout << mot << endl;
                }            
            }
        }
        fichier.close(); // Ferme le fichier
    } else {
        cout << "Erreur : Impossible de lire le fichier." << endl;
    }
}   