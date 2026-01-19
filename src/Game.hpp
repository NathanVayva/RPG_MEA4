#include "Carte.hpp"
#include "Armes.hpp"
#include "Armures.hpp"
#include "Consommables.hpp"
//#include "Coffre.hpp"
#include "Personnage.hpp"
#include <functional>
//#include <conio.h>
#include <random>

#ifndef GAME_HPP_
#define GAME_HPP_

class Game {
private:
    int niveau;
    Personnage* hero;
    vector<string> messages; // Journal des événements du jeu
    Carte carte; // La carte du jeu11

    vector<Creature*> monstres; // Monstres disponibles dans le jeu
    vector<Equipement*> equipements; // Équipements disponibles dans le jeu
    map<char, function<void(Personnage&)>> actions; // Commandes du jeu
public:
    Game(Personnage* hero);
    virtual ~Game();
    void creerCarte();
    void ajouterMessage(const string& message);
    void lireMessages() const;
    Equipement randEquipement() const;
    void placerCoffreAleatoire();
    Creature randMonstre() const;
    void jouer();
};

#endif /* GAME_HPP_ */
