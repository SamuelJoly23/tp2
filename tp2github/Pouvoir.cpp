#include "Pouvoir.h"

Pouvoir::Pouvoir(const string& nom, 
	unsigned int nombreDeDegat,	unsigned int energieNecessaire):
	nom_(nom), nombreDeDegat_(nombreDeDegat), energieNecessaire_(energieNecessaire)
{
}

unsigned int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

string Pouvoir::obtenirNom() const
{
	return nom_;
}

void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat)
{
	nombreDeDegat_ = nombreDegat;
}

void Pouvoir::modifierEnergieNecessarie(unsigned int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::modifierNom(const string& nom)
{
	nom_ = nom;
}

unsigned int Pouvoir::obtenirNombreDeDegat() const
{
	return nombreDeDegat_;
}



// TODO: Augmenter le nombre de degats de 10.
Pouvoir& Pouvoir::operator++(int){
	this->nombreDeDegat_ = this->nombreDeDegat_ + 10;
    return  *this;
}

// TODO: Comparer le nom des pouvoirs
bool Pouvoir::operator==(const Pouvoir& pouvoir) const {
	bool egal = false;
	if (nom_ == pouvoir.nom_) {
		egal = true;
	}
	return egal;
}

// TODO: Afficher le nom du pouvoir, le nombre de degats
// et l'energie necessaire.
ostream& operator<<(ostream& os, const Pouvoir& pouvoir)
{
	os << pouvoir.obtenirNom() << " possede un nombre de degats de " << pouvoir.obtenirNombreDeDegat() << " et une energie necessaire de " << pouvoir.obtenirEnergieNecessaire() << endl;
	 return os;
}
