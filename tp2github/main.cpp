/*
* @fichier: main.cpp
* @auteurs:
* @date:
* @description: Tests
*/

#include <iostream>
#include <sstream>
#include <time.h>
#include <clocale>
#include <fstream>
#include <vector>
#include <iomanip>
#include <numeric>

#include "Creature.h"
#include "Dresseur.h"
#include "ObjetMagique.h"
#include "PolyLand.h"
#include "Pouvoir.h"
#include "AsciiArt.h"

using namespace std;

const int DRESSEUR = 0, CREATURE = 1;
const int NB_DRESSEUR = 4, NB_CREATURE = 6;
const string LIGNE = "-------------------------------------------------------------------------------------";

void initialisationPolyland(PolyLand& polyland, ifstream& fichier) {

	// Verification
	if (!fichier.is_open()) {
		cout << "Error opening file";
		exit(-1);
	}

	// Dresseur
	string nomDresseur;

	// Objet magique
	string nomObjet, bonus;

	// Creature
	string nomCreature, attaque, defense, pointDeVie, energie;

	// Pouvoir
	string nomPouvoir, nombreDeDegat, manaNecessaire;

	string type;
	while (!fichier.eof()) {

		getline(fichier, type, '\t');

		switch (stoi(type)) {
		case DRESSEUR:
			getline(fichier, nomDresseur, '\t');
			getline(fichier, nomObjet, '\t');
			getline(fichier, bonus);
			//   if est pour lire le fichier sous Mac
			//  et retire le \r à la fin de la ligne
			if (bonus[bonus.size() - 1] == '\r')
				bonus.resize(bonus.size() - 1);
			polyland += make_shared<Dresseur>(nomDresseur);
			polyland.choisirDresseur(nomDresseur)->modifierObjetMagique(ObjetMagique(nomObjet, stoi(bonus)));
			break;

		case CREATURE:
			getline(fichier, nomCreature, '\t');
			getline(fichier, attaque, '\t');
			getline(fichier, defense, '\t');
			getline(fichier, pointDeVie, '\t');
			getline(fichier, energie, '\t');
			getline(fichier, nomPouvoir, '\t');
			getline(fichier, nombreDeDegat, '\t');
			getline(fichier, manaNecessaire);
			//   if est pour lire le fichier sous Mac
		//  et retire le \r à la fin de la ligne
			if (manaNecessaire[manaNecessaire.size() - 1] == '\r')
				manaNecessaire.resize(manaNecessaire.size() - 1);
			polyland += make_shared<Creature>(nomCreature, stoi(attaque), stoi(defense), stoi(pointDeVie), stoi(energie),
				Pouvoir(nomPouvoir, stoi(nombreDeDegat), stoi(manaNecessaire)));
			break;

		default:
			break;
		}
	}
}


int main() {
	srand(unsigned(time(nullptr)));
	setlocale(LC_ALL, "");

	vector<bool> tests;

	ifstream fichier("fichier.txt");
	AsciiArt art;
	PolyLand polyland;
	string vous = "Vous";
	
	cout << BLEU << art.polyland() << FIN << endl;

	/*---------------------------------------------------------------------------------------
	* Debut des TESTS
	----------------------------------------------------------------------------------------*/
	
	cout << endl << MAUVE << LIGNE << "\n > Debut des tests\n" << LIGNE << FIN << endl;

	// Test 1 : constructeurs des classes et operator+= de Polyland
	if (true) {
		cout << MAUVE << "\n > Initialisation de Polyland\n" << LIGNE << FIN << endl;
		try {
			bool success = true;
			initialisationPolyland(polyland, fichier);
			polyland += make_shared<Dresseur>(vous);
			polyland.choisirDresseur(vous)->modifierObjetMagique(ObjetMagique("potion", 200));
			tests.push_back(success);
		}
		catch (...) {
			tests.push_back(false);
		}
	}
	else {
		tests.push_back(false);
	}

	// TEST 2 : operator== de Dresseur
	if (true) {
		try {
			bool success = true;
			
			// Assignation de votre creature
			cout << endl << MAUVE << "\n > Assignation de votre creature\n" << LIGNE << FIN << endl;
			cout << "Choix de la premiere creature" << endl;
            polyland.choisirDresseur(vous)->ajouterCreature(polyland.choisirCreature("Bulbasaur"));
            cout << "Vous êtes arrivé en retard et on ne vous donne plus Bulbasaur" << endl;
            polyland.choisirDresseur(vous)->supprimerCreature("Bulbasaur");
			polyland.choisirDresseur(vous)->ajouterCreature(polyland.choisirCreature("Pikachu"));
			cout << "Vous etes chanceux voici un Pikachu rien que pour vous" << endl;

			// Assignation des creatures aux autres dresseurs
			polyland.choisirDresseur("Team rocket")->ajouterCreature(polyland.choisirCreature("Meowth"));
			polyland.choisirDresseur("Leon")->ajouterCreature(polyland.choisirCreature("Charizard"));
			polyland.choisirDresseur("Brock")->ajouterCreature(polyland.choisirCreatureAleatoire());
			polyland.choisirDresseur("May")->ajouterCreature(polyland.choisirCreatureAleatoire());

			success &= polyland.choisirDresseur("Leon")->obtenirCreatures()[0]->obtenirNom() == "Charizard" &&
				polyland.choisirDresseur("Brock")->obtenirNombreCreatures() == 1;
			if (!success) {
				cout << "assignation de creatures fail" << endl;
				return -1;
			}
			success &= *polyland.choisirDresseur("May") == *polyland.obtenirDresseurs()[2];
			if (!success) {
				cout << "obj Dresseur == obj Dresseur fail" << endl;
				return -1;
			}
			success &= *polyland.choisirDresseur("Leon") == "Leon";
			if (!success) {
				cout << "obj Dresseur == string nom fail" << endl;
				return -1;
			}
			success &= "Brock" == *polyland.choisirDresseur("Brock"); 
			if (!success) {
				cout << "string nom == obj Dresseur fail" << endl;
				return -1;
			}
			success &= *polyland.choisirCreature("Snorlax") == *polyland.obtenirCreatures()[4];
			if (!success) {
				cout << "obj Creature == obj Creature fail" << endl;
				return -1;
			}
			success &= *polyland.choisirCreature("Pikachu") == "Pikachu";
			if (!success) {
				cout << "obj Creature == string nom fail" << endl;
				return -1;
			}
			success &= "Bulbasaur" == *polyland.choisirCreature("Bulbasaur");
			if (!success) {
				cout << "string nom == obj Creature fail" << endl;
				return -1;
			}
			tests.push_back(success);
		}
		catch (...) {
			tests.push_back(false);
		}
	}
	else {
		tests.push_back(false);
	}

	// TEST 3 : operator<< 
	if (true) {
		try {
			bool success = true;

			// Affichage des infos
			cout << endl << MAUVE << "\n > Affichage des infos de tous les joueurs\n" << LIGNE << FIN << endl;
			for (auto&& d : polyland.obtenirDresseurs()) {
				cout << *d << endl;
			}

			tests.push_back(success);
		}
		catch (...) {
			tests.push_back(false);
		}
	}
	else {
		tests.push_back(false);
	}
    
	// TEST 4: operateur -=
	if (true) {
		try {
			bool success = true;
			cout << MAUVE << "\n > La team rocket quitte PolyLand\n" << LIGNE << FIN << endl;
			cout << ROUGE << "face a cette defaite, La team rocket s'enfuit de PolyLand sur leur montgolfiere" << FIN << endl;
			success &= polyland.choisirDresseur("Team rocket") != nullptr;
			polyland -= polyland.choisirDresseur("Team rocket");
			polyland -= polyland.choisirCreature("Meowth");
			polyland.infoDresseur("Team rocket");
			success &= polyland.choisirDresseur("Team rocket") == nullptr && polyland.choisirCreature("Meowth") == nullptr;
			tests.push_back(success);
		}
		catch (...) {
			tests.push_back(false);
		}
	}
	else {
		tests.push_back(false);
	}

	// TEST 5: operateur <<
	if (true) {
		try {
			bool success = true;

			// Affichage de vos infos
            cout << endl << MAUVE << "\n > Affichage de vos infos\n" << LIGNE << FIN << endl;
			cout << *polyland.choisirDresseur(vous) << endl;
            
            // Affichage des informations de polyland
            cout << endl << MAUVE << "\n > Affichage des informations de polyland\n" << LIGNE << FIN << endl;
            cout << polyland << std::endl;

			tests.push_back(success);
		}
		catch (...) {
			tests.push_back(false);
		}
	}
	else {
		tests.push_back(false);
	}
    
    // TEST 6: Mutation et augmentation de pouvoir
    if (true) {
        try{
            bool success = true;
            
            cout << endl;
            cout << MAUVE << "\n >Le tournois est terminé! Certaines créatures évoluent\n" << LIGNE << FIN << endl;
            
            Pouvoir eclaire("Eclaire", 25, 10);
            Pouvoir foudre = Pouvoir();
            foudre = eclaire;
            foudre.modifierNom("Foudre");
            
            foudre++;
            Creature raichu("Raichu", 20, 15, 100, 75, eclaire);
            raichu.modifierPouvoir(foudre);
            
                      
            Creature pichu("Richu", 0, 0, 100, 75, eclaire);
            pichu = raichu;
            pichu.modifierPouvoir(pichu.obtenirPouvoir()++);
            pichu.modifierNom("Pichu");
            
            
            cout << raichu << endl << endl;
            
            cout << pichu << endl;
            
            
            tests.push_back(success);
        }
        catch(...){
            tests.push_back(false);
        }
    } else {
        tests.push_back(false);
    }
    
	cout << endl << MAUVE << LIGNE << "\n > Fin des tests\n" << LIGNE << FIN << endl;

	/*---------------------------------------------------------------------------------------
	* Fin des TESTS
	----------------------------------------------------------------------------------------*/
	std::vector<float> ponderationTests = { 2, 2, 1, 2, 1, 2};

	// Affichage
	float totalPoints = 0;
	for (size_t i = 0; i < tests.size(); i++) {
		string output = "Test " + to_string(i + 1) + ": ";
		if (tests[i] == true) {
			output += "OK!";
			stringstream stream;
			stream << ponderationTests[i] << '/' << ponderationTests[i];
			cout << left << setw(15) << std::left << output
				<< stream.str() << endl;
			totalPoints += ponderationTests[i];
		}
		else {
			output += "ECHEC!";
			stringstream stream;
			stream << '0' << '/' << ponderationTests[i];
			std::cerr << std::left << std::setw(15) << output << "0/"
				<< ponderationTests[i] << endl;
		}
	}
	std::stringstream stream;
	stream << totalPoints << "/"
		<< accumulate(ponderationTests.begin(), ponderationTests.end(),
			0.0f);
	cout << VERT << left << setw(15) << "TOTAL: " << stream.str() << FIN << endl;

	return 0;
}
