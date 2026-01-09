#include "Element.hpp"

Element::Element(string nom, char abbreviation) {
    this->nom = nom;
    this->abbreviation = abbreviation;
}

string Element::getNom() const {
    return this->nom;
}

char Element::getAbbreviation() const {
    return this->abbreviation;
}

int Element::getNiveau() const {
    return this->niveau;
}

string Element::description() const {
    return "<" + this->getNom() + ">";
}