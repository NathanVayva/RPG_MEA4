#include <iostream>
#include <string_view>
using namespace std;

#ifndef ELEMENT_HPP_
#define ELEMENT_HPP_

class Element {
private:
    string nom;
    char abbreviation;
    int niveau;
public:
    Element(string nom, char abbreviation);
    virtual ~Element() = default;
    string getNom() const;
    char getAbbreviation() const;
    int getNiveau() const;
    string description() const;
};

#endif /* ELEMENT_HPP_ */