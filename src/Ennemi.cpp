/*
 * Ennemi.cpp
 *
 *  Created on: 16 déc. 2025
 *      Author: nathan
 */

#include "Ennemi.h"

Ennemi::Ennemi( int vm,int mm, int f, int vi)
: vie_max(vm),
  vie(vm),
  force(f),
  vitesse(vi),
  mana_max(mm),
  mana(mm)
{}

Ennemi::~Ennemi() = default;


//actions

void recevoir_degats(int degats)
{

}













