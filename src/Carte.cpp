#include "../include/Carte.hpp"

Carte::Carte(std::string file) {
    std::ifstream fichier(file); // Ouvre le fichier en lecture
    std::string ligne;
    std::string mot;
    std::string typeParcelle;// type de parcelle
    std::string numero;// numéro de la parcelle
    std::string propriétaire;// propriétaire de la parcelle
    std::string partieConstructible;// poucentage constructible
    std::string surfaceConstructible;// coordonnées de la parcelle
    std::string typeCulture;// type de culture
    std::vector<Point2D<int>> sommets; // liste des sommets du polygone
    std::string x_str, y_str;

    if (fichier.is_open()) {
        while (getline(fichier, ligne)) { // Lit la première ligne

            std::cout<< "Ligne 1/2" << std::endl;
            std::stringstream ss(ligne);

            getline(ss, typeParcelle, ' ');
            
            std::cout << "Enregistrement d'une parcelle de type : " << typeParcelle << std::endl;
            if (typeParcelle == "ZU") {
                getline(ss, numero, ' ');
                getline(ss, propriétaire, ' ');
                getline(ss, partieConstructible, ' ');
                getline(ss, surfaceConstructible, ' ');
            }
            else if (typeParcelle == "ZAU") {
                getline(ss, numero, ' ');
                getline(ss, propriétaire, ' ');
                getline(ss, partieConstructible, ' ');
            }
            else if (typeParcelle == "ZA") {
                getline(ss, numero, ' ');
                getline(ss, propriétaire, ' ');
                getline(ss, typeCulture, ' ');
            }
            else if (typeParcelle == "ZN") {
                getline(ss, numero, ' ');
                getline(ss, propriétaire, ' ');
            }
            else {
                std::cout << "Type de parcelle inconnu" << std::endl;
            }


            std::cout<< "Ligne 2/2" << std::endl;
            getline(fichier, ligne); // Lit la deuxième ligne
            std::stringstream ss2(ligne);
            while (getline(ss2, mot, ' ')) {
                std::cout << "Coordonnée Point string : " << mot << std::endl;
                std::stringstream coord(mot);
                getline(coord, x_str, '[');// enlever le [
                getline(coord, x_str, ';');// lire jusqu'au ;
                getline(coord, y_str, ']');// lire jusqu'au ]

                int x = std::stoi(x_str);
                int y = std::stoi(y_str);
                std::cout << "Coordonnée Point float : " << x << " ; " << y << std::endl;

                Point2D<int> point(x, y);
                sommets.push_back(point);
            }
            Polygone<int> polygone(sommets);


            // Création de la parcelle en fonction du type
            if (typeParcelle == "ZU") {
                ZU* parcelleZU = new ZU(std::stoi(numero), propriétaire, polygone);
                parcelleZU->setPConstructible(std::stof(partieConstructible));
                parcelleZU->setSurfaceConstruite(std::stof(surfaceConstructible));
                this->listeParcelles.push_back(parcelleZU);
            }
            else if (typeParcelle == "ZAU") {
                ZAU* parcelleZAU = new ZAU(std::stoi(numero), propriétaire, polygone);
                parcelleZAU->setPConstructible(std::stof(partieConstructible));
                this->listeParcelles.push_back(parcelleZAU);
            }
            else if (typeParcelle == "ZA") {
                ZA* parcelleZA = new ZA(std::stoi(numero), propriétaire, polygone, typeCulture);
                this->listeParcelles.push_back(parcelleZA);
            }
            else if (typeParcelle == "ZN") {
                ZN* parcelleZN = new ZN(std::stoi(numero), propriétaire, polygone);
                this->listeParcelles.push_back(parcelleZN);
            }
            std::cout<< "============== Fin d'enregistrement d'une parcelle ===============" << std::endl;

            sommets.clear(); // Vide la liste des sommets pour la prochaine parcelle
        }
        fichier.close(); // Ferme le fichier
    } else {
        std::cout << "Erreur : Impossible de lire le fichier." << std::endl;
    }
    // Calcul de la surface totale de la carte
    this->surface = 0.0;
    for (const auto& parcelle : listeParcelles) {
        this->surface += parcelle->getSurface();
    }
}   

void Carte::afficherParcelles() const {
    std::cout << "Surface totale de la carte : " << this->surface << std::endl;
    for (const auto& parcelle : listeParcelles) {
        std::cout << *parcelle << std::endl;
    }
}

void Carte::sauvegarderCarte(const std::string& filename) const {
    std::ofstream fichier(filename);
    if (fichier.is_open()) {
        for (const auto& parcelle : listeParcelles) {
            fichier << *parcelle << std::endl;
        }
        fichier.close();
    } else {
        std::cout << "Erreur : Impossible d'ouvrir le fichier pour sauvegarde." << std::endl;
    }
}

// Setters et Getters
void Carte::setListeParcelles(const std::vector<Parcelle*>& listeParcelles) {
    this->listeParcelles = listeParcelles;
}

std::vector<Parcelle*> Carte::getListeParcelles() const {
    return this->listeParcelles;
}

float Carte::getSurface() const {
    return this->surface;
}

void Carte::setSurface(float surface) {
    this->surface = surface;
}
