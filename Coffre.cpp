#include "Coffre.hpp"

Coffre::Coffre(string nom, char abbreviation, Equipement* contenu) : Element(nom, abbreviation){
    this->ouvert = false;
    this->contenu = contenu;
}

bool Coffre::isOuvert() const {
    // Retourne true si le coffre est ouvert, false sinon
    return this->ouvert;
}

Equipement* Coffre::ouvrir() {
    // Ouvre le coffre et retourne son contenu
    this->ouvert = true; // Le coffre est maintenant ouvert
    return this->contenu;
}