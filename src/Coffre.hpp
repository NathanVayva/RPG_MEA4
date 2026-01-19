#include "Element.hpp"
#include "Equipement.hpp"
#include <optional>

#ifndef COFFRE_HPP_
#define COFFRE_HPP_

class Coffre : public Element {
private:
    bool ouvert;
    Equipement* contenu;
public:
    Coffre(string nom, string abbreviation, Equipement* contenu);
    bool isOuvert() const;
    Equipement* ouvrir();
};

#endif /* COFFRE_HPP_ */
