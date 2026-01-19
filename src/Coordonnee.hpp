#include <iostream>
#include <string_view>
#include <cmath>
using namespace std;

#ifndef COORDONNEE_HPP_
#define COORDONNEE_HPP_

class Coordonnee {
private:
    int x;
    int y;
public:
    Coordonnee();
    Coordonnee(int x, int y);
    virtual ~Coordonnee() = default;
    bool operator==(const Coordonnee& autre) const;
    Coordonnee operator+(const Coordonnee& autre) const;
    Coordonnee operator-(const Coordonnee& autre) const;
    bool operator<(const Coordonnee& other) const;
    bool operator>(const Coordonnee& other) const;
    float distance(const Coordonnee& autre) const;
    Coordonnee direction(const Coordonnee& autre) const;
    int getX() const;
    int getY() const;
};

#endif /* COORDONNEE_HPP_ */
    
