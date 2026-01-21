#include "Coffre.hpp"

Coffre::Coffre(string nom, Equipement* contenu) : Element(nom, "⚱️ "){
    this->ouvert = false;
    this->contenu = contenu;
}

bool Coffre::isOuvert() const {
    // Retourne true si le coffre est ouvert, false sinon
    return this->ouvert;
}

Equipement* Coffre::ouvrir() {
    if (ouvert || !contenu) return nullptr;

    ouvert = true;
    Equipement* tmp = contenu;
    contenu = nullptr; //  TRANSFERT DE PROPRIÉTÉ
    return tmp;
}

