#include "Piece.hpp"
#include "Element.hpp"
#include "Personnage.hpp"
#include "Coffre.hpp"
#include <iostream>
#include <string_view>
#include <random>
#include <chrono>
#include <map>
#include <vector>
#include <optional>
#include <stdexcept>
#include <algorithm>
using namespace std;

#ifndef CARTE_HPP_
#define CARTE_HPP_

class Carte {
private:
    vector<vector<char>> matrice;
    vector<Piece> pieces;
    vector<Piece> piecesArelier;
    map<Element*, Coordonnee> elements;
    int size;
    Personnage* hero; // Pointeur vers le personnage principal
public:
    Carte(int size, Personnage* hero); // Ajouter le héros au constructeur
    virtual ~Carte();
    static constexpr char sol = '.';
    static constexpr char vide = ' ';
    static const map<char, Coordonnee> dir;  // déclaration, définition après
    void ajouterPiece(Piece p);
    optional<Piece> getPieceAt(const Coordonnee& c) const;
    optional<Piece> trouverPiece(const Coordonnee& c) const;
    bool pasIntersection(const Piece& p) const;
    void creuser(const Coordonnee& c);
    void couloir(const Coordonnee& depart, const Coordonnee& arrivee);
    void atteindre();
    void atteindreToutesPieces();
    Piece randomPiece() const;
    Piece randomPieceExistante() const;
    void genererPiece(int nbPieces);
    bool contient(const Coordonnee& c) const;
    bool contient(Element* e) const;
    string afficherCarte() const;
    void placerElement(Element* e, const Coordonnee& c);
    optional<Element*> getElementAt(const Coordonnee& c) const;
    optional<Creature*> getCreatureAt(const Coordonnee& c) const;
    Coordonnee getPosition(Element* e) const;
    void enleverElement(const Coordonnee& c);
    void deplacement(Creature* c, const Coordonnee& direction);
    void deplacerTousLesMonstres();
};

#endif /* CARTE_HPP_ */