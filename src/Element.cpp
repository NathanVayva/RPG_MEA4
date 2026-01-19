#include "Element.hpp"

Element::Element(string nom, string abbreviation) {
    this->nom = nom;
    this->abbreviation = abbreviation;
}

string Element::getNom() const{
    return this->nom;
}

string Element::getAbbreviation() const{
    return this->abbreviation;
}
