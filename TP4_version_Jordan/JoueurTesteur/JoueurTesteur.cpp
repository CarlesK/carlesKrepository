/**
 * @file : JoueurTesteur.cpp
 * @date : 2020-04-09
 * @author : Jordan Longval
 */
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Date.h"
#include "Personne.h"
#include "Joueur.h"

using namespace std;
using namespace hockey;
using namespace util;


/**
 * @brief Test du constructeur de Joueur
 * Cas valide de la création d'un objet Joueur et vérification de l'assignation de tous les attributs
 * Cas invalide:
 *  Constructeur vide
 *  Constructeur avec:
 * 	Nom vide
 * 	Nom invalide
 * 	Prénom vide
 * 	Prénom invalide
 * 	Âge pas dans l'intervale 15 à 17 ans.
 * 	Numéro de téléphone invalide
 * 	Position de joueur invalide
 */
TEST(ConstructeurJoueur, ConstructeurValide)
{
	Date ddnvalide = Date(1,1,2005);
	Joueur joueurTest = Joueur("Blo", "Joe", ddnvalide,
			                   "819 943-7804", "centre");
	ASSERT_EQ(joueurTest.reqNom(), "Blo");
	ASSERT_EQ(joueurTest.reqPrenom(), "Joe");
	ASSERT_EQ(joueurTest.reqDateNaissance(), ddnvalide);
	ASSERT_EQ(joueurTest.reqTelephone(), "819 943-7804");
	ASSERT_EQ(joueurTest.reqPosition(), "centre");
}

//***********************CAS INVALIDES DU CONSTRUCTEUR*********************
// Constructeur invalide car vide
TEST(ConstructeurJoueur, ConstructeurVide)
{
		ASSERT_THROW(Joueur joueurTest = Joueur(), PreconditionException);
}

//Constructeur invalide car nom vide
TEST(ConstructeurJoueur, NomInvalideVide)
{
	Date ddnvalide = Date(1,1,2005);
		ASSERT_THROW(Joueur joueurTest("", "Joe", ddnvalide,
                "819 943-7804", "centre"), PreconditionException);
}

//Nom invalide car caractère non valide
TEST(ConstructeurJoueur, NomInvalideCaractere)
{
	Date ddnvalide = Date(1,1,2005);
	ASSERT_THROW(Joueur joueurTest("Bloe123", "Joe", ddnvalide,
                "819 943-7804", "centre"), PreconditionException);
}

//Constructeur invalide car prénom vide
TEST(ConstructeurJoueur, PrenomInvalideVide)
{
	Date ddnvalide = Date(1,1,2005);
	ASSERT_THROW(Joueur joueurTest("Blo", "", ddnvalide,
                "819 943-7804", "centre"), PreconditionException);
}

//Prenom invalide car caractère non valide
TEST(ConstructeurJoueur, PrenomInvalideCaractere)
{
	Date ddnvalide = Date(1,1,2005);
	ASSERT_THROW(Joueur joueurTest("Blo", "Joe123", ddnvalide,
                "819 943-7804", "centre"), PreconditionException);
}

//Âge inférieur à 15 ans
TEST(ConstructeurJoueur, DdnInvalideInf15)
{
	Date ddninvalide = Date(1,1,2010);
	ASSERT_THROW(Joueur joueurTest("Blo", "Joe", ddninvalide,
		                "819 943-7804", "centre"), PreconditionException);
}

//Âge supérieur à 17 ans
TEST(ConstructeurJoueur, DdnInvalideSup17)
{
	Date ddninvalide = Date(1,1,2000);
	ASSERT_THROW(Joueur joueurTest("Blo", "Joe", ddninvalide,
		                "819 943-7804", "centre"), PreconditionException);
}

//Numéro de téléphone indicatif invalide
TEST(ConstructeurJoueur, NumeroTelIndicatifInvalide)
{
	Date ddnvalide = Date(1,1,2005);
		ASSERT_THROW(Joueur joueurTest("Blo", "Joe", ddnvalide,
	                "811 943-7804", "centre"), PreconditionException);
}

//Numéro de téléphone format invalide
TEST(ConstructeurJoueur, NumeroTelFormatInvalide)
{
	Date ddnvalide = Date(1,1,2005);
		ASSERT_THROW(Joueur joueurTest("Blo", "Joe", ddnvalide,
	                "8199437804", "centre"), PreconditionException);
}

// Position de joueur invalide
TEST(ConstructeurJoueur, PositionInvalide)
{
	Date ddnvalide = Date(1,1,2005);
			ASSERT_THROW(Joueur joueurTest("Blo", "Joe", ddnvalide,
		                "819 943-7804", "centr"), PreconditionException);
}


/**
 * @brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnJoueurTest: public::testing::Test
{
public:
	UnJoueurTest():
		unJoueur("Blo", "Joe", Date(1, 1, 2005), "819 943-7804", "centre")
		{};
		Joueur unJoueur;
};

/**
 * @brief: Test de la méthode reqPosition()
 * 	Cas valide: vérifier le retour de la position
 * 	Cas invalide: aucun
 */
TEST_F(UnJoueurTest, reqPosition)
{
	ASSERT_EQ("centre", unJoueur.reqPosition());
}

/**
 * @brief: Test de la méthode reqPosition()
 * 	Cas valide: vérifier le retour de la position
 * 	Cas invalide: aucun
 */
TEST_F(UnJoueurTest, reqPersonneFormate)
{
	ostringstream os;
	os<< left<< setw(24) << "Nom" << setfill(' ');
	os <<": " << "Blo" << endl;
	os << left<< setw(24) << "Prenom" << setfill(' ') ;
	os <<": " << "Joe" << endl;
	os << left<< setw(24) << "Date de naissance" << setfill(' ');
	os <<": " << Date(1, 1, 2005).reqDateFormatee() << endl;
	os << left<< setw(24) << "Telephone" << setfill(' ');
	os <<": " << "819 943-7804" << endl;
	os<< left<< setw(24) << "Position" << setfill(' ');
	os <<": " <<"centre" << endl;
	os<<"---------------------"<<endl;
	ASSERT_EQ(os.str(), unJoueur.reqPersonneFormate());
}
/**
 * @brief: Test de la méthode clone() de joueur
 * 	Cas valide: Vérifier que le clone a le même reqPersonneFormate mais pas la même adresse
 * 	Cas invalide: aucun
 */
TEST_F(UnJoueurTest, clone)
{
	Personne* p1 = unJoueur.clone();
	ASSERT_TRUE(((p1->reqPersonneFormate())==
			     unJoueur.reqPersonneFormate()) && !(p1 == &unJoueur));
}



