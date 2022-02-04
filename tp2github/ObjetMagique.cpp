#include "ObjetMagique.h"

ObjetMagique::ObjetMagique(const string & nom, int bonus):
	nom_(nom), bonus_(bonus) {}

string ObjetMagique::obtenirNom() const {
	return nom_;
}

int ObjetMagique::obtenirBonus() const {
	return bonus_;
}

void ObjetMagique::modifierNom(const string& nom) {
	nom_ = nom;
}

void ObjetMagique::modifierBonus(int bonus) {
	bonus_ = bonus;
}

// TODO: Afficher le nom et le bonus de l'objet magique
ostream& operator<<(ostream& os, const ObjetMagique& objet) {
	os << "L'objet " << objet.obtenirNom() << " fourni un bonus de " << objet.obtenirBonus() << endl;
	return os ;
}
