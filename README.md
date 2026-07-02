# RPG_MEA4 — Text RPG in C++ (OOP project)

A console role-playing game written in C++ for the object-oriented programming course at
Polytech Montpellier (MEA, 4th year). The point of the project is the **class design**, not the
gameplay: inheritance, polymorphism, composition and dynamic memory across a small game world.

> School team project.

## Overview

The player picks a class (**Warrior / Mage / Thief**), then explores a map made of connected rooms,
fights enemies, opens chests, and manages an inventory of weapons, armor and consumables.

## Design

- **`Personnage`** (player) and **`Creature`** base classes, specialized into playable classes
  (`Guerrier`, `Mage`, `Voleur`) and enemies (`Troll`, `Vampire`, `Zombie`, `ChauveSouris`) —
  inheritance + polymorphism (virtual combat behaviour).
- **`Equipement`** hierarchy: `Armes`, `Armures`, `Consommables` sharing a common interface.
- **World**: `Carte` (map) built from `Piece` (rooms) located by `Coordonnee`, with `Coffre` (chests).
- **`Game`** ties the loop together (exploration, combat, inventory), with `utilitaire` helpers.

## Build & run

```bash
g++ -std=c++17 src/*.cpp -o rpg
./rpg
```

## Tech

C++ (STL, dynamic polymorphism), console I/O.
