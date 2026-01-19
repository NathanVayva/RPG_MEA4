#include "Coordonnee.hpp"

Coordonnee::Coordonnee() {
    this->x = 0;
    this->y = 0;
}

Coordonnee::Coordonnee(int x, int y) {
    this->x = x;
    this->y = y;
}

bool Coordonnee::operator==(const Coordonnee& autre) const {
    return (this->x == autre.x) && (this->y == autre.y);
}

Coordonnee Coordonnee::operator+(const Coordonnee& autre) const {
    return Coordonnee(this->x + autre.x, this->y + autre.y);
}

Coordonnee Coordonnee::operator-(const Coordonnee& autre) const {
    return Coordonnee(this->x - autre.x, this->y - autre.y);
}

bool Coordonnee::operator<(const Coordonnee& other) const {
    if (y != other.y)
        return y < other.y;
    return x < other.x;
}

bool Coordonnee::operator>(const Coordonnee& other) const {
    return other < *this;
}

float Coordonnee::distance(const Coordonnee& autre) const {
    Coordonnee d = *this - autre;
    return sqrt(d.x * d.x + d.y * d.y);
}

Coordonnee Coordonnee::direction(const Coordonnee& autre) const {
    Coordonnee d = *this - autre;
    float cos = d.x/this->distance(autre);
    float cos45 = 1/sqrt(2);
    if (cos > cos45) {
        return Coordonnee(-1, 0); // Gauche
    } else if (cos < -cos45) {
        return Coordonnee(1, 0); // Droite
    } else if (d.y > 0) {
        return Coordonnee(0, -1); // Haut
    } else {
        return Coordonnee(0, 1); // Bas
    }
}

int Coordonnee::getX() const {
    return this->x;
}

int Coordonnee::getY() const {
    return this->y;
}