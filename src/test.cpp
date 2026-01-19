#include <iostream>
#include <string>
#include "Armes.hpp"
#include "Armures.hpp"
#include "Piece.hpp"
#include "Creature.hpp"
#include "Personnage.hpp"
#include "Carte.hpp"
#include "Game.hpp"
#include "Guerrier.hpp"

int main() {

	Personnage p = Personnage("p", "p", 1,1,1);
	Creature c = Creature("c","c",1,1,1,1);
	Consommables co = Consommables("co", "co",1, 2, 3, 4, 5,6);
	Consommables co1 = Consommables("co1", "co1",0, 0, 0, 0, 0,0);

	p.addObjet(co);
	p.addObjet(co1);

	p.utiliserObjet(&c);

	p.afficherInventaire();

    return 0;
}

