#include <iostream>
#include <string_view>
using namespace std;

#ifndef ELEMENT_HPP_
#define ELEMENT_HPP_

class Element {
private:
    string nom;
    char abbreviation;
public:
    Element(string nom, char abbreviation);
    virtual ~Element();
    string getNom();
    char getAbbreviation();
};

#endif /* ELEMENT_HPP_ */