/**
 * @file : EntraineurTesteur.cpp
 * @date : 2020-04-11
 * @author : Jordan
 */
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Date.h"
#include "Personne.h"
#include "Entraineur.h"

using namespace std;
using namespace hockey;
using namespace util;

/**
 * @brief Test du constructeur de Entraineur
 * Cas valide de la création d'un objet Entraineur et vérification de l'assignation de tous les attributs
 * Cas invalide:
 *  Constructeur vide
 *  Constructeur avec:
 * 	Nom vide
 * 	Nom invalide
 * 	Prénom vide
 * 	Prénom invalide
 * 	Âge pas supérieur ou égal à 18 ans.
 * 	Numéro de téléphone invalide
 * 	Numéro de RAMQ invalide
 * 	Sexe invalide
 */
TEST(ConstructeurEntraineur, ConstructeurValide)
{
	Date ddnvalide = Date(18,03,1993);
	Entraineur entraineurTest = Entraineur("Longval", "Jordan", ddnvalide,
			                   "819 943-7804", "LONJ 9303 1815", 'M');
	ASSERT_EQ(entraineurTest.reqNom(), "Longval");
	ASSERT_EQ(entraineurTest.reqPrenom(), "Jordan");
	ASSERT_EQ(entraineurTest.reqDateNaissance(), ddnvalide);
	ASSERT_EQ(entraineurTest.reqTelephone(), "819 943-7804");
	ASSERT_EQ(entraineurTest.reqNumRAMQ(), "LONJ 9303 1815");
	ASSERT_EQ(entraineurTest.reqSexe(), 'M');
}

//***********************CAS INVALIDES DU CONSTRUCTEUR*********************
// Constructeur invalide car vide
TEST(ConstructeurEntraineur, ConstructeurVide)
{
		ASSERT_THROW(Entraineur EntraineurTest = Entraineur(), PreconditionException);
}

//Constructeur invalide car nom vide
TEST(ConstructeurEntraineur, NomInvalideVide)
{
	Date ddnvalide = Date(18,03,1993);
		ASSERT_THROW(Entraineur EntraineurTest("", "Jordan", ddnvalide,
                "819 943-7804", "LONJ 9303 1815", 'M'), PreconditionException);
}

//Nom invalide car caractère non valide
TEST(ConstructeurEntraineur, NomInvalideCaractere)
{
	Date ddnvalide = Date(18,03,1993);
		ASSERT_THROW(Entraineur EntraineurTest("Longval123", "Jordan", ddnvalide,
                "819 943-7804", "LONJ 9303 1815", 'M'), PreconditionException);
}

//Constructeur invalide car prénom vide
TEST(ConstructeurEntraineur, PrenomInvalideVide)
{
	Date ddnvalide = Date(18,03,1993);
		ASSERT_THROW(Entraineur EntraineurTest("Longval", "", ddnvalide,
                "819 943-7804", "LONJ 9303 1815", 'M'), PreconditionException);
}

//Prenom invalide car caractère non valide
TEST(ConstructeurEntraineur, PrenomInvalideCaractere)
{
	Date ddnvalide = Date(18,03,1993);
		ASSERT_THROW(Entraineur EntraineurTest("Longval", "Jordan123", ddnvalide,
                "819 943-7804", "LONJ 9303 1815", 'M'), PreconditionException);
}

//Âge inférieur à 18 ans
TEST(ConstructeurEntraineur, DdnInvalideSup17)
{
	Date ddnvalide = Date(18,03,2005);
		ASSERT_THROW(Entraineur EntraineurTest("Longval", "Jordan", ddnvalide,
                "819 943-7804", "LONJ 9303 1815", 'M'), PreconditionException);
}

//Numéro de téléphone indicatif invalide
TEST(ConstructeurEntraineur, NumeroTelIndicatifInvalide)
{
	Date ddnvalide = Date(18,03,1993);
		ASSERT_THROW(Entraineur EntraineurTest("Longval", "Jordan", ddnvalide,
                "811 943-7804", "LONJ 9303 1815", 'M'), PreconditionException);
}

//Numéro de téléphone format invalide
TEST(ConstructeurEntraineur, NumeroTelFormatInvalide)
{
	Date ddnvalide = Date(18,03,1993);
		ASSERT_THROW(Entraineur EntraineurTest("Longval", "Jordan", ddnvalide,
                "8199437804", "LONJ 9303 1815", 'M'), PreconditionException);
}

// Numéro de RAMQ vide
TEST(ConstructeurEntraineur, NumRAMQvide)
{
	Date ddnvalide = Date(18,03,1993);
		ASSERT_THROW(Entraineur EntraineurTest("Longval", "Jordan", ddnvalide,
                "819 943-7804", "", 'M'), PreconditionException);
}

// Numéro de RAMQ invalide
TEST(ConstructeurEntraineur, NumRAMQinvalide)
{
	Date ddnvalide = Date(18,03,1993);
		ASSERT_THROW(Entraineur EntraineurTest("Longval", "Jordan", ddnvalide,
                "819 943-7804", "LONJ 9306 1815", 'M'), PreconditionException);
}

// Numéro de RAMQ mauvais format
TEST(ConstructeurEntraineur, NumRAMQinvalideformat)
{
	Date ddnvalide = Date(18,03,1993);
		ASSERT_THROW(Entraineur EntraineurTest("Longval", "Jordan", ddnvalide,
                "819 943-7804", "LONJ93031815", 'M'), PreconditionException);
}

// Sexe invalide
TEST(ConstructeurEntraineur, Sexeinvalide)
{
	Date ddnvalide = Date(18,03,1993);
		ASSERT_THROW(Entraineur EntraineurTest("Longval", "Jordan", ddnvalide,
                "819 943-7804", "LONJ 9303 1815", 'A'), PreconditionException);
}

/**
 * @brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnEntraineurTest: public::testing::Test
{
public:
	UnEntraineurTest():
		unEntraineur("Longval", "Jordan", Date(18,03,1993),
                "819 943-7804", "LONJ 9303 1815", 'M')
		{};
		Entraineur unEntraineur;
};

/**
 * @brief: Test de la méthode reqNumRAMQ()
 * 	Cas valide: vérifier le retour du numéro de RAMQ
 * 	Cas invalide: aucun
 */
TEST_F(UnEntraineurTest, reqNumRAMQ)
{
	ASSERT_EQ("LONJ 9303 1815", unEntraineur.reqNumRAMQ());
}

/**
 * @brief: Test de la méthode reqSexe()
 * 	Cas valide: vérifier le retour du sexe
 * 	Cas invalide: aucun
 */
TEST_F(UnEntraineurTest, reqSexe)
{
	ASSERT_EQ('M', unEntraineur.reqSexe());
}

/**
 * @brief: Test de la méthode reqPersonneFormate()
 * 	Cas valide: vérifier le retour du la fonction
 * 	Cas invalide: aucun
 */
TEST_F(UnEntraineurTest, reqPersonneFormate)
{
	ostringstream os;
	os<< left<< setw(24) << "Nom" << setfill(' ');
	os <<": " << "Longval" << endl;
	os << left<< setw(24) << "Prenom" << setfill(' ') ;
	os <<": " << "Jordan" << endl;
	os << left<< setw(24) << "Date de naissance" << setfill(' ');
	os <<": " << Date(18, 03, 1993).reqDateFormatee() << endl;
	os << left<< setw(24) << "Telephone" << setfill(' ');
	os <<": " << "819 943-7804" << endl;
	os<< left<< setw(24) << "Numero de RAMQ" << setfill(' ');
	os <<": " << "LONJ 9303 1815" << endl;
	os<<"---------------------"<<endl;
	ASSERT_EQ(os.str(), unEntraineur.reqPersonneFormate());
}

/**
 * @brief: Test de la méthode clone() de entraineur
 * 	Cas valide: Vérifier que le clone a le même reqPersonneFormate mais pas la même adresse
 * 	Cas invalide: aucun
 */
TEST_F(UnEntraineurTest, testclone)
{
	Personne* p1 = unEntraineur.clone();
		ASSERT_TRUE(((p1->reqPersonneFormate())==
				     unEntraineur.reqPersonneFormate()) && !(p1 == &unEntraineur));

}
