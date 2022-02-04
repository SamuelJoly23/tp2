/*
Fichier: Dresseur.cpp
Auteur(s): 
Date de creation: 
Date de modification:  
Description:
*/
#include "PolyLand.h"

PolyLand::PolyLand() {}

// TODO: Ajouter des dresseurs a l'attributs dresseurs_.
// Si un dresseur est deja present dans le vecteur des dresseurs, false est
// retourne. Si le dresseur n'a pas ete ajoute, true est retourne.******************** false est retourner???
bool PolyLand::ajouterDresseur(const shared_ptr<Dresseur> & dresseur) { 
	
	/*for (auto& dresseur : dresseurs_) {
		if (dresseur->obtenirNom() == dresseur->obtenirNom()) {
		}
	}*/
	for (int i = 0; i < dresseurs_.size(); i++) {
		if (dresseurs_[i]->obtenirNom() == dresseur->obtenirNom()) {
			return false;
		}
	}
	dresseurs_.push_back(dresseur);
	
	return true;
}

// TODO: Ajouter des creatures a l'attributs creatures_.
// Si une creature est deja present dans le vecteur de creature, false est
// retourne. Si le dresseur n'a pas ete ajoute, true est retourne.
bool PolyLand::ajouterCreature(const shared_ptr<Creature> & creature) {
	
	for (int i = 0; i < creatures_.size(); i++) {
		if (creatures_[i]->obtenirNom() == creature->obtenirNom()) {
			return false;
		}
	}
	creatures_.push_back(creature);
	
	return true;
}

// TODO: Retire un dresseur
bool PolyLand::retirerDresseur(const string& nom) {
	for (auto& dresseur : dresseurs_) {
		if (dresseur->obtenirNom() == dresseur->obtenirNom()) {//******************* pt pas la bonne technique 
			
			dresseur = dresseurs_.back();
			dresseurs_.pop_back();
			return true;
		}
	}
	/*for (int i = 0; i < dresseurs_.size(); i++) {**********************technique charge td
		if (dresseurs_[i]->obtenirNom() == nom) {
			dresseurs_[i].
		}
	}*/



	return false;
}

// TODO: Retire une creature
bool PolyLand::retirerCreature(const string& nom) {
	
	return false;
}

// TODO: Retourne une creature choisit aleatoirement
shared_ptr<Creature> PolyLand::choisirCreatureAleatoire() {
	
		return nullptr;
}

// TODO: Retourne le pointeur de dresseur en fonction du nom du dresseur
shared_ptr<Dresseur> PolyLand::choisirDresseur(string nom) {
	
	return nullptr;
}

// TODO: Retourne le pointeur de creature en fonction du nom de la creature
shared_ptr<Creature> PolyLand::choisirCreature(string nom) {
	
	return nullptr;
}

vector<shared_ptr<Dresseur>> PolyLand::obtenirDresseurs() {
	return dresseurs_;
}

vector<shared_ptr<Creature>> PolyLand::obtenirCreatures() {
	return creatures_;
}

bool PolyLand::attraperCreature(const shared_ptr<Dresseur>& dresseur,const shared_ptr<Creature> & creature) {
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(shared_ptr<Dresseur> & dresseur, const shared_ptr<Creature>& creature) {
	return dresseur->supprimerCreature(creature->obtenirNom());
}

// TODO: Afficher les informations sur les dresseurs
// Lorsqu'un dresseur est present, le nombre de creatures
// est affiche ainsi que ses creatures.
// Lorsque le dresseur n'est pas present, il est necessaire
// d'afficher que le dresseur est introuvable.
// indice: utiliser la surcharge de l'opérateur << pour
// creature et pour dresseur.
void PolyLand::infoDresseur(const string& nom) const {
	
}

// TODO: Ajouter un dresseur
PolyLand& PolyLand::operator+= (const shared_ptr<Dresseur> &dresseur) {

	return ;
}

// TODO: Retirer un dresseur
PolyLand& PolyLand::operator-=(const shared_ptr<Dresseur> & dresseur) {

	return ;
}

// TODO: Ajouter une creature
PolyLand& PolyLand::operator+= (const shared_ptr<Creature>  &creature) {
	
	return ;
}

// TODO: Retirer une creature
PolyLand& PolyLand::operator-=(const shared_ptr<Creature>  &creature) {
	
	return;
}

// TODO: Faire l'affichage des dresseurs
ostream& operator<<(ostream& os, const PolyLand& poly) {
	
	return os;
}
