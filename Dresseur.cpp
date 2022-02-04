/*
Fichier: Dresseur.cpp
Auteur(s): 
Date de creation: 
Date de modification: 
*/
#include "Dresseur.h"

Dresseur::Dresseur(const string& nom):
	nom_(nom) {}

string Dresseur::obtenirNom() const {
	return nom_;
}

void Dresseur::modifierNom(const string& nom) {
	nom_ = nom;
}

ObjetMagique Dresseur::obtenirObjetMagique() const {
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique) {
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(shared_ptr<Creature> creature) {
	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}

unsigned int Dresseur::obtenirNombreCreatures() const {
	return creatures_.size();
}

std::vector<shared_ptr<Creature> >Dresseur::obtenirCreatures() const {
	return creatures_;
}

void Dresseur::modifierCreature(vector<shared_ptr<Creature>>& creatures) {
	creatures_ = creatures;
}

// TODO: Ajouter une creature s'elle n'est pas deja presente
bool Dresseur::ajouterCreature(const shared_ptr<Creature>& creature) {	
	
	return true;
}

// TODO: Supprimer la creature s'elle est presente
bool Dresseur::supprimerCreature(const string& nom) {
	
	return false;
}

// TODO: Afficher le nom du dresseur, le nombre de creature, les creatures et l'objet magique
// indice: utiliser les surcharges des operateur << de creatures_ et d'objetMagique_
ostream& operator<<(ostream& os, const Dresseur& dresseur) {
	
	return os;
}

// TODO: Comparer si les dresseurs ont les memes creatures
bool Dresseur::operator==(const Dresseur& dresseur) const {
	 return true;
}

// TODO: Comparer le nom entre en parametre a l'attribut de l'objet courant
bool Dresseur::operator==(const std::string& nom) const {
	 return  true;
}

// TODO: Comparer le nom du dresseur entre en parametre a l'attribut de l'objet  en paramètre
bool operator==(const std::string& nom, const Dresseur& dresseur) {
	return true;
}
