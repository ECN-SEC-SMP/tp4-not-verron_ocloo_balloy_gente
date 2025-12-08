/**
 * @file Parcelle.cpp
 * @brief Implémentation de la classe Parcelle
 */

#include "Parcelle.hpp"

// Constructeurs

/**
 * @brief Constructeur par défaut
 * 
 * Initialise le numéro à 0 et le propriétaire à une chaîne vide
 */
Parcelle::Parcelle(){
    this->numero = 0;
    this->proprietaire = "";
}

/**
 * @brief Constructeur paramétré
 * @param num Numéro de la parcelle
 * @param prop Nom du propriétaire
 * @param forme Polygone représentant la forme de la parcelle
 */
Parcelle::Parcelle(int num, std::string prop, Polygone<int> forme){
    this->numero = num;
    this->proprietaire = prop;
    this->forme = forme;
}

// Getteurs

/**
 * @brief Obtient le numéro de la parcelle
 * @return Le numéro de la parcelle
 */
int Parcelle::getNumero(){
    return numero;
}

/**
 * @brief Obtient le nom du propriétaire
 * @return Le nom du propriétaire de la parcelle
 */
std::string Parcelle::getProprietaire(){
    return proprietaire;
}

/**
 * @brief Obtient la surface de la parcelle
 * @return La surface de la parcelle en m²
 */
float Parcelle::getSurface(){
    return surface;
}

/**
 * @brief Obtient la forme géométrique de la parcelle
 * @return Le polygone représentant la forme de la parcelle
 */
Polygone<int> Parcelle::getForme(){
    return forme;
}

/**
 * @brief Obtient le pourcentage constructible
 * @return Le pourcentage constructible de la parcelle
 */
int Parcelle::getPConstructible(){
    return pConstructible;
}

// Setteurs

/**
 * @brief Définit le numéro de la parcelle
 * @param n Le nouveau numéro de la parcelle
 */
void Parcelle::setNumero(int n){
    this->numero = n;
}

/**
 * @brief Définit le propriétaire de la parcelle
 * @param prop Le nom du nouveau propriétaire
 */
void Parcelle::setProprietaire(std::string prop){
    this->proprietaire = prop;
}

/**
 * @brief Définit la forme géométrique de la parcelle
 * @param forme Le polygone représentant la nouvelle forme
 */
void Parcelle::setForme(Polygone<int> forme){
    this->forme = forme;
}