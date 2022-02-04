/*
Fichier: Dresseur.h
Auteur(s): 
Date de creation: 
Date de modification: 
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "Creature.h"

using namespace std;

const inline string ROUGE = "\033[1;91m", MAUVE = "\033[1;95m", BLEU = "\033[1;96m", VERT = "\u001b[32;1m", FIN = "\033[0m";

class Dresseur
{
public:

	Dresseur(const string& nom ="");

	string obtenirNom() const;
	void modifierNom(const string& nom);
	
	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(shared_ptr<Creature> creature);

	unsigned int obtenirNombreCreatures() const;

	std::vector<shared_ptr<Creature>>obtenirCreatures() const;
	void modifierCreature(vector<shared_ptr<Creature>>& creatures);
	
	bool ajouterCreature(const shared_ptr<Creature>& creature);
	bool supprimerCreature(const std::string& nom);

	friend std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur);

	bool operator==(const Dresseur& dresseur) const;
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Dresseur& dresseur);

private:
	string nom_;
	vector<shared_ptr<Creature>> creatures_;
	ObjetMagique objetMagique_;

};

#endif