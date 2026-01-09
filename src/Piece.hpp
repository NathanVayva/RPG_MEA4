#include "Coordonnee.hpp"

#ifndef PIECE_HPP_
#define PIECE_HPP_

class Piece {
private:
    Coordonnee c1;
    Coordonnee c2;
public:
    Piece(Coordonnee c1, Coordonnee c2);
    bool operator==(const Piece& other) const;
    bool contient(const Coordonnee& c) const;
    bool intersection(const Piece& autre) const;
    Coordonnee centre() const;
    Coordonnee randCoordonnee() const;
    //Coordonnee randCoordonneeVide();
    Coordonnee getC1() const;
    Coordonnee getC2() const;
};

#endif /* PIECE_HPP_ */