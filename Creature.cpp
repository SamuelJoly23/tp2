#include "Creature.h"

Creature::Creature():nom_(""), attaque_(0), defense_(0), pointDeVie_(0),
	energie_(0), experience_(0), niveau_(1)
{
	energieTotal_ = 0;
	experienceNecessaire_ = 0;
	pointDeVieTotal_ = 0;
}

Creature::Creature(const std::string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir):
	nom_(nom), attaque_(attaque), defense_(defense), pointDeVie_(pointDeVie),
	energie_(energie), experience_(0), niveau_(1)
{
    pouvoir_ = std::make_unique<Pouvoir>(pouvoir);
	energieTotal_ = energie;
	experienceNecessaire_ = 100;
	pointDeVieTotal_ = pointDeVie;
}
// todo
Creature::Creature (const Creature & c)
 {}
string Creature::obtenirNom() const
{
	return nom_;
}

unsigned int Creature::obtenirAttaque() const
{
	return attaque_;
}

unsigned int Creature::obtenirDefense() const
{
	return defense_;
}

unsigned int Creature::obtenirPointDeVie() const
{
	return pointDeVie_;
}

unsigned int Creature::obtenirPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

unsigned int Creature::obtenirEnergie() const
{
	return energie_;
}

unsigned int Creature::obtenirEnergieTotale() const
{
	return energieTotal_;
}

unsigned int Creature::obtenirExperience() const
{
	return experience_;
}

unsigned int Creature::obtenirExperienceNecessaire() const
{
	return experienceNecessaire_;
}

unsigned int Creature::obtenirNiveau() const
{
	return niveau_;
}

Pouvoir Creature::obtenirPouvoir() const
{
	return *pouvoir_;
}

void Creature::attaquer(Creature & creature)
{
	if (energie_ >= pouvoir_->obtenirEnergieNecessaire()) {
		if (creature.obtenirPointDeVie() >= 0) {
			//Calcul du nombre de degat selon une formule 
			unsigned int degat = (pouvoir_->obtenirNombreDeDegat())* (attaque_ / 2 - creature.defense_);
			int tentative = rand() % 6;
			//l'attaque rate une fois sur 6
			if (tentative != 3) {
				std::cout << nom_ << " lance " << pouvoir_->obtenirNom() << " qui inflige " << degat << " degat a " << creature.obtenirNom() << endl;
				if (degat > creature.obtenirPointDeVie()) {
					creature.modifierPointDeVie(0);
					 int xp = experienceGagnee(creature);
					 cout << nom_ << " a gagne " << xp << " XP" << endl;
				}
				else
					creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
				cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << endl;
				energie_ -= pouvoir_->obtenirEnergieNecessaire();
			}
			else {
				std::cout << "Attaque " << pouvoir_->obtenirNom() << " a echouee" << endl;
			}
		}
		else
			std::cout << "Vous deja avez vaincu " << creature.obtenirNom() << endl;
	}

}

int Creature::experienceGagnee(const Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0) {
		//Calcul de l'experience selon une formule mysterieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) * (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) {
            //Cas ou la creature va monter d'un niveau
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else {
            //Sinon elle recupere juste de l'experience
            experience_ += experience;
		}
		return experience;
	}
	return 0;
}

void Creature::modifierNom(const std::string& nom){
    nom_ = nom;
}

void Creature::modifierAttaque(unsigned int attaque)
{
	attaque_ = attaque;
}

void Creature::modifierDefense(unsigned int defense)
{
	defense_ = defense;
}

void Creature::modifierPointDeVie(unsigned int pointDeVie)
{
	pointDeVie_ = pointDeVie;
}

void Creature::modifierEnergie(unsigned int mana)
{
	energie_ = mana;
}

void Creature::modifierExperience(unsigned int experience)
{
	experience_ = experience;
}

void Creature::modifierNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

// todo: il faut que ce soit appeler à un certain point
void Creature::modifierPouvoir(Pouvoir pouvoir)
{
  
}

// TODO: Faire une copie de l'objet passe en parametre
Creature& Creature::operator=(const Creature& creature)
{
}

// TODO: Comparer les attributs de creature pour verifier
// s'il s'agit bien de la meme creature
bool Creature::operator==(const Creature& creature) const
{
	 return true;
}

// TODO: Verifier si le nom passe en parametre est le meme que l'objet courant
bool Creature::operator==(const std::string& nom) const
{
	return true;
}

// TODO: Verifier que le nom de la creature passe en parametre est le meme
// que le nom passe en parametre.
bool operator==(const std::string& nom, const Creature& creature)
{
	return true;
}

// TODO: Faire l'affichage de la creature en fonction de son nom, son
// attaque, sa defense, ses points de vie, ses points de vie total, son
// energie, son niveau, son experience, son experience ncessaire et son pouvoir
ostream& operator<<(std::ostream& os, const Creature& creature)
{
	
	return os;
}
