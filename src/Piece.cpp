#include "Piece.hpp"
#include <random>

Piece::Piece(Coordonnee c1, Coordonnee c2) {
    this->c1 = c1;
    this->c2 = c2;
}

bool Piece::contient(const Coordonnee& c) const {
    return (c.getX() >= c1.getX() && c.getX() <= c2.getX() &&
            c.getY() >= c1.getY() && c.getY() <= c2.getY());
}

bool Piece::intersection(const Piece& autre) const {
    Coordonnee sc3 = Coordonnee(c2.getX(), c1.getY());
    Coordonnee sc4 = Coordonnee(c1.getX(), c2.getY());
    return autre.contient(c1) || autre.contient(c2) || autre.contient(sc3) || autre.contient(sc4) || this->contient(autre.c1);
}

Coordonnee Piece::centre() const {
    int centreX = (c1.getX() + c2.getX()) / 2;
    int centreY = (c1.getY() + c2.getY()) / 2;
    return Coordonnee(centreX, centreY);
}

Coordonnee Piece::randCoordonnee() const {
    // Permet de gérer les nombres aléatoires
    random_device rd;
    mt19937 gen(rd());
    // Nombre aléatoire compris entre c1 et c2
    uniform_int_distribution<> randX(c1.getX(), c2.getX());
    uniform_int_distribution<> randY(c1.getY(), c2.getY());
    return Coordonnee(randX(gen), randY(gen));
}

Coordonnee Piece::getC1() const {
    return this->c1;
}

Coordonnee Piece::getC2() const {
    return this->c2;
}