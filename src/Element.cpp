#include "Element.hpp"

Element::Element(string nom, char abbreviation) {
    this->nom = nom;
    this->abbreviation = abbreviation;
}

Element::~Element() {}

string Element::getNom() {
    return this->nom;
}

char Element::getAbbreviation() {
    return this->abbreviation;
}