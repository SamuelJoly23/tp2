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
// retourne. Si le dresseur n'a pas ete ajoute, true est retourne.
bool PolyLand::ajouterDresseur(const shared_ptr<Dresseur> & dresseur) {
	for (auto& d : dresseurs_) {
		if (d->obtenirNom() == dresseur->obtenirNom()) {
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
	for (auto& c : creatures_) {
		if (c->obtenirNom() == creature->obtenirNom()) {
			return false;
		}
	}
	creatures_.push_back(creature);
	return true;
}

// TODO: Retire une dresseur
bool PolyLand::retirerDresseur(const string& nom) {
	for (auto& dresseur : dresseurs_) {
		if (dresseur->obtenirNom() == nom) {
			dresseur = dresseurs_.back();
			dresseurs_.pop_back();
			return true;
		}
	}
	return false;
}


// TODO: Retire une creature
bool PolyLand::retirerCreature(const string& nom) {
	for (auto& creature : creatures_) {
		// vérifier si le contact est dans le répertoire
		if (creature->obtenirNom() == nom) {
			// Retrait de l'élément du vecteur
			creature = creatures_.back();
			creatures_.pop_back();
			return true;
		}
	}

	return false;
}

// TODO: Retourne une creature choisit aleatoirement
shared_ptr<Creature> PolyLand::choisirCreatureAleatoire() {
	srand(time(NULL));
	int indice = rand() % creatures_.size();
	return creatures_[indice];
}

// TODO: Retourne le pointeur de dresseur en fonction du nom du dresseur
shared_ptr<Dresseur> PolyLand::choisirDresseur(string nom) {
	for (auto& dresseur : dresseurs_) {
		if (dresseur->obtenirNom() == nom) {
			return dresseur;
		}
	}
	return nullptr;
}

// TODO: Retourne le pointeur de creature en fonction du nom de la creature
shared_ptr<Creature> PolyLand::choisirCreature(string nom) {
	for (auto& creature : creatures_) {
		if (creature->obtenirNom() == nom) {
			return creature; 
		}
	}
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
void PolyLand::infoDresseur(const string& nom) const {//****************
	bool present = false;
	for (auto& dresseur : dresseurs_) {
		if (dresseur->obtenirNom() == nom) {
			present = true;
			cout << dresseur;
		}
	}
	if (present == false) {
		cout << "Le dresseur est introuvable." << endl;
	}
}

// TODO: Ajouter un dresseur
PolyLand& PolyLand::operator+= (const shared_ptr<Dresseur> &dresseur) {
	if (ajouterDresseur(dresseur) == true) {
		this->dresseurs_ = dresseurs_;
	}
	return *this;
}

// TODO: Retirer un dresseur
PolyLand& PolyLand::operator-=(const shared_ptr<Dresseur> &dresseur) {
	if (retirerDresseur(dresseur->obtenirNom()) == false) {
		this->dresseurs_ = dresseurs_;
	}
	return *this;
}

// TODO: Ajouter une creature
PolyLand& PolyLand::operator+= (const shared_ptr<Creature>  &creature) {
	if (ajouterCreature(creature) == true) {
		this->creatures_ = creatures_;
	}
	return *this;
}

// TODO: Retirer une creature
PolyLand& PolyLand::operator-=(const shared_ptr<Creature>  &creature) {
	if (retirerCreature(creature->obtenirNom()) == false) {
		this->creatures_ = creatures_;
	}
	return *this;
}

// TODO: Faire l'affichage des dresseurs
ostream& operator<<(ostream& os, const PolyLand& poly) {
	
	for (int i = 0; i < poly.dresseurs_.size(); i++) {
		os << poly.dresseurs_[i];
	}
	return os;
}
