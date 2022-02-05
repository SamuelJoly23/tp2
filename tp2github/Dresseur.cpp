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

// TODO: Ajouter une creature s'elle n'est pas deja presente************************************
bool Dresseur::ajouterCreature(const shared_ptr<Creature>& creature) {
	bool ajoute = true;
	for (unsigned int i = 0; i < creatures_.size(); i++) {
		if (creatures_[i]->obtenirNom() == creature->obtenirNom()) {
			ajoute = false;
		}
	}
	if (ajoute == true) {
		creatures_.push_back(creature);
	}
	return ajoute;
}

// TODO: Supprimer la creature s'elle est presente
bool Dresseur::supprimerCreature(const string& nom) {
	for (auto& creature : creatures_) {
		if (creature->obtenirNom() == nom) {
			// Retrait de l'élément du vecteur
			creature = creatures_.back();
			creatures_.pop_back();
			return true;
		}
	}

	return false;
}

// TODO: Afficher le nom du dresseur, le nombre de creature, les creatures et l'objet magique
// indice: utiliser les surcharges des operateur << de creatures_ et d'objetMagique_
ostream& operator<<(ostream& os, const Dresseur& dresseur) {
	os << ROUGE <<dresseur.obtenirNom() << FIN << " possede " << dresseur.obtenirNombreCreatures() << " creature(s) : " << endl;
	for (unsigned int i = 0; i < dresseur.obtenirNombreCreatures(); i++) {
		cout << *dresseur.creatures_[i]; 
	}
	return os;
}

// TODO: Comparer si les dresseurs ont les memes creatures
bool Dresseur::operator==(const Dresseur& dresseur) const {
	bool egal = false;
	int size = 0;
	if (creatures_.size() == dresseur.creatures_.size()) {

		for (int i = 0; i < creatures_.size(); i++) {
			for (int j = 0; j < creatures_.size(); j++) {
				if (creatures_[i]->obtenirNom() == dresseur.creatures_[j]->obtenirNom()) {
					size++;
				}
			}
		}
		if (size == creatures_.size()) {
			egal = true;
		}
	}
	 return true;
}

// TODO: Comparer le nom entre en parametre a l'attribut de l'objet courant
bool Dresseur::operator==(const std::string& nom) const {
	bool egal = false;
	if (this->nom_ == nom) {
		egal = true;
	}
	
	return  egal;
}

// TODO: Comparer le nom du dresseur entre en parametre a l'attribut de l'objet  en paramètre
bool operator==(const std::string& nom, const Dresseur& dresseur) {
	if (nom == dresseur.nom_) {
		return true;
	}
	return false;
}
