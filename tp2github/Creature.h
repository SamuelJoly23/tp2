/*
Fichier: Creature.h
Auteur(s): 
Date de creation: 
Date de modification: 
Description: Les creatures sont des etres destines au combat 
*/
#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <stdio.h>
#include <iostream>
#include "ObjetMagique.h"
#include "Pouvoir.h"

using namespace std;

class Creature {
public:
	Creature();
	Creature(const string& nom, unsigned int attaque, 
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir);
	Creature (const Creature & c);
	string obtenirNom() const;
	unsigned int obtenirAttaque() const;
	unsigned int obtenirDefense() const;
	unsigned int obtenirPointDeVie() const;
	unsigned int obtenirPointDeVieTotal() const;
	unsigned int obtenirEnergie() const;
	unsigned int obtenirEnergieTotale() const;
	unsigned int obtenirExperience() const;
	unsigned int obtenirExperienceNecessaire() const;
	unsigned int obtenirNiveau() const;
	Pouvoir obtenirPouvoir() const;

	void attaquer(Creature& creature);
	int experienceGagnee(const Creature& creature);
	
    void modifierNom(const std::string& nom);
	void modifierAttaque(unsigned int attaque);
	void modifierDefense(unsigned int defense);
	void modifierPointDeVie(unsigned int pointDeVie);
	void modifierEnergie(unsigned int energie);
	void modifierExperience(unsigned int experience);
	void modifierNiveau(unsigned int niveau);
	void modifierPouvoir(Pouvoir pouvoir);

	Creature& operator=(const Creature& creature);

	bool operator==(const Creature& creature) const;
	bool operator==(const string& nom) const;
	
	friend bool operator==(const string& nom, const Creature& creature);
	friend ostream& operator<<(ostream& os, const Creature& creature);

private:

	string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	std::unique_ptr<Pouvoir> pouvoir_;
	
};
#endif
