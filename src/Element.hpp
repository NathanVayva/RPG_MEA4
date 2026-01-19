#include <iostream>
#include <string_view>
using namespace std;

#ifndef ELEMENT_HPP_
#define ELEMENT_HPP_

class Element {
private:
    string nom;
    string abbreviation;
public:
    Element(string nom, string abbreviation);
    virtual ~Element() = default;
    string getNom() const;
    string getAbbreviation() const;
};

#endif /* ELEMENT_HPP_ */
