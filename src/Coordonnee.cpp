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

float Coordonnee::distance(const Coordonnee& autre) const {
    return sqrt(pow(this->x - autre.x, 2) + pow(this->y - autre.y, 2));
}

Coordonnee Coordonnee::direction(const Coordonnee& autre) const {
    Coordonnee d = *this - autre;
    float cos = d.x/distance(autre);
    if (cos > (1/sqrt(2))) {
        return Coordonnee(-1, 0); // Gauche
    } else if (cos < -(1/sqrt(2))) {
        return Coordonnee(1, 0); // Droite
    } else if (d.y > 0) {
        return Coordonnee(0, 1); // Bas
    } else {
        return Coordonnee(0, -1); // Haut
    }
}

int Coordonnee::getX() const {
    return this->x;
}

int Coordonnee::getY() const {
    return this->y;
}