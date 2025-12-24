/*
 * personnage.cpp
 *
 *  Created on: 16 déc. 2025
 *      Author: nathan
 */

#include "Personnage.hpp"

Personnage::Personnage(string n, int vm ,int mm,  int f, int vi)
: nom(n),
  vie_max(vm),
  vie(vm),
  force(f),
  vitesse(vi),
  mana_max(mm),
  mana(mm)
{}

Personnage::~Personnage() = default;

//actions
void virtual attaquer(Ennemi* cible){
}

//getters
int Personnage::get_vie(){
	return vie;}
int Personnage::get_force(){
	return force;}
int Personnage::get_vitesse(){
	return vitesse;}
int Personnage::get_mana(){
	return mana;}
string Personnage::get_nom(){
	return nom;}

//setters
void Personnage::set_vie(int new_vie){
	vie = new_vie;}
void Personnage::set_vie_max(int new_vie){
	vie_max = new_vie;}
void Personnage::set_force(int new_force){
	force = new_force;}
void Personnage::set_vitesse(int new_vitesse){
	vitesse = new_vitesse;}
void Personnage::set_mana(int new_mana){
	mana = new_mana;}
void Personnage::set_mana_max(int new_mana){
	mana_max = new_mana;}
void Personnage::set_nom(string new_nom){
	nom = new_nom;}
