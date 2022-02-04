/*
Fichier: PolyLand.h
Auteur(s): 
Date de creation: 
Date de modification: 
Description: Polyland represente le pays que l'on va explorer, il va contenir les differents elements de jeu
*/
#ifndef POLYLAND_H
#define POLYLAND_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>
#include <vector>
#include "Dresseur.h"
#include "Creature.h"

using namespace std;

class PolyLand
{
public:
	PolyLand();
	
	bool ajouterDresseur(const shared_ptr<Dresseur>  & dresseur);
	bool ajouterCreature(const shared_ptr<Creature> & creature);

	bool retirerDresseur(const string& nom);
	bool retirerCreature(const string& nom);

	shared_ptr<Creature> choisirCreatureAleatoire();

	shared_ptr<Dresseur> choisirDresseur(string nom);
	shared_ptr<Creature> choisirCreature(string nom);

	vector<shared_ptr<Dresseur>> obtenirDresseurs();
	vector<shared_ptr<Creature>> obtenirCreatures();

	bool attraperCreature(const shared_ptr<Dresseur> &dresseur, const shared_ptr <Creature> & creature);
	bool relacherCreature(shared_ptr<Dresseur> & dresseur, const  shared_ptr<Creature> & creature);
	
	void infoDresseur(const string& nom) const;
	PolyLand& operator+=(const shared_ptr<Dresseur> & dresseur);
	PolyLand& operator-=(const shared_ptr<Dresseur> & dresseur);
	PolyLand& operator+=(const shared_ptr<Creature> & creature);
	PolyLand& operator-=(const shared_ptr<Creature> & creature);

	friend ostream& operator<<(ostream& os, const PolyLand& poly);

private:
    vector<shared_ptr<Dresseur>> dresseurs_;
	vector<shared_ptr<Creature>> creatures_;

};
#endif
