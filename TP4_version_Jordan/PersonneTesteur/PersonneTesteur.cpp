/**
 * @file : PersonneTesteur.cpp
 * @date : 2020-04-13
 * @author : Jordan
 */
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Date.h"
#include "Personne.h"
#include "Entraineur.h"

using namespace std;
using namespace hockey;
using namespace util;

/**
 * @brief Création d'une classe dérivée PersonneTest
 * pour pouvoir tester les propriétés de Personne qui est une classe abstraite.
 *
 */
class PersonneTest: public Personne
{
public:
	PersonneTest():Personne(){};
	PersonneTest(string p_nom, string p_prenom,
			     const Date& p_dateNaissance, string p_telephone):
    Personne(p_nom, p_prenom,
			     p_dateNaissance, p_telephone){};
	virtual Personne* clone() const
	{
		return new PersonneTest(*this);
	}
};

/**
 * @brief Test du constructeur de PersonneTest
 * Cas valide de la création d'un objet Personne et vérification de l'assignation de tous les attributs
 * Cas invalide:
 *  Constructeur vide
 *  Constructeur avec:
 * 	Nom vide
 * 	Nom invalide
 * 	Prénom vide
 * 	Prénom invalide
 * 	Numéro de téléphone invalide
 */
TEST(ConstructeurPersonne, ConstructeurValide)
{
	PersonneTest unePersonne("Longval", "Jordan", Date(18,03,1993), "819 943-7804");
	ASSERT_EQ("Longval", unePersonne.reqNom());
	ASSERT_EQ("Jordan", unePersonne.reqPrenom());
	ASSERT_EQ(Date(18,03,1993),unePersonne.reqDateNaissance());
	ASSERT_EQ("819 943-7804", unePersonne.reqTelephone());
}

//***********************CAS INVALIDES DU CONSTRUCTEUR*********************
// Constructeur invalide car vide
TEST(ConstructeurPersonne, ConstructeurVide)
{
		ASSERT_THROW(PersonneTest unePersonneTest = PersonneTest(), PreconditionException);
}

// Constructeur invalide car nom vide
TEST(ConstructeurPersonne, ConstructeurNomVide)
{
		ASSERT_THROW(PersonneTest unePersonneTest = PersonneTest("",
				"Jordan", Date(18,03,1993), "819 943-7804"), PreconditionException);
}

// Constructeur invalide car nom invalide
TEST(ConstructeurPersonne, ConstructeurNominvalide)
{
		ASSERT_THROW(PersonneTest unePersonneTest = PersonneTest("Longval123",
				"Jordan", Date(18,03,1993), "819 943-7804"), PreconditionException);
}

// Constructeur invalide car prénom vide
TEST(ConstructeurPersonne, ConstructeurPrenomvide)
{
		ASSERT_THROW(PersonneTest unePersonneTest = PersonneTest("Longval",
				"", Date(18,03,1993), "819 943-7804"), PreconditionException);
}

// Constructeur invalide car prénom invalide
TEST(ConstructeurPersonne, ConstructeurPrenominvalide)
{
		ASSERT_THROW(PersonneTest unePersonneTest = PersonneTest("Longval",
				"Jordan123", Date(18,03,1993), "819 943-7804"), PreconditionException);
}

// Constructeur invalide car indicatif invalide
TEST(ConstructeurPersonne, ConstructeurIndicatifInvalide)
{
		ASSERT_THROW(PersonneTest unePersonneTest = PersonneTest("Longval",
				"Jordan", Date(18,03,1993), "811 943-7804"), PreconditionException);
}

// Constructeur invalide car format téléphone invalide
TEST(ConstructeurPersonne, ConstructeurTelephoneInvalide)
{
		ASSERT_THROW(PersonneTest unePersonneTest = PersonneTest("Longval",
				"Jordan", Date(18,03,1993), "8199437804"), PreconditionException);
}


/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe Personne
 */
class UnePersonneTest: public::testing::Test
{
public:
	UnePersonneTest():
		unePersonne("Longval", "Jordan", Date(18,03,1993),
                "819 943-7804")
        ,uneAutrePersonne("Longval", "Jordan", Date(18,03,1993),
                "819 943-7804")
        ,uneAutreAutrePersonne("Longval", "Jordan", Date(19,03,1993),
                "819 943-7804")
		{};
		PersonneTest unePersonne;
		PersonneTest uneAutrePersonne;
		PersonneTest uneAutreAutrePersonne;
};

/**
 * @brief: Test de la méthode reqDateNaissance()
 * 	Cas valide: vérifier le retour de la ddn de la personne
 * 	Cas invalide: aucun
 */
TEST_F(UnePersonneTest, reqDateNaissance)
{
	ASSERT_EQ(Date(18,03,1993), unePersonne.reqDateNaissance());
}

/**
 * @brief: Test de la méthode reqNom()
 * 	Cas valide: vérifier le retour du nom de la personne
 * 	Cas invalide: aucun
 */
TEST_F(UnePersonneTest, reqNom)
{
	ASSERT_EQ("Longval", unePersonne.reqNom());
}

/**
 * @brief: Test de la méthode reqPrenom()
 * 	Cas valide: vérifier le retour du prenom de la personne
 * 	Cas invalide: aucun
 */
TEST_F(UnePersonneTest, reqPrenom)
{
	ASSERT_EQ("Jordan", unePersonne.reqPrenom());
}

/**
 * @brief: Test de la méthode reqTelephone()
 * 	Cas valide: vérifier le retour du num Telephone de la personne
 * 	Cas invalide: aucun
 */
TEST_F(UnePersonneTest, reqTelephone)
{
	ASSERT_EQ("819 943-7804", unePersonne.reqTelephone());
}

/**
 * @brief: Test de la méthode asgTelephone()
 * 	Cas valide: Lorsque l'on assigne un numéro valide en format et indicatif
 * 	Cas invalides: Indicatif invalide, Format invalide
 */
TEST_F(UnePersonneTest, asgTelephonevalide)
{
	unePersonne.asgTelephone("819 820-4860");
}
// cas invalide: mauvais indicatif
TEST_F(UnePersonneTest, asgTelephoneIndicatifInvalide)
{
	ASSERT_THROW(unePersonne.asgTelephone("811 820-4860"),
			PreconditionException);
}

// cas invalide: mauvais format telephone
TEST_F(UnePersonneTest, asgTelephoneFormatInvalide)
{
	ASSERT_THROW(unePersonne.asgTelephone("8198204860"),
			PreconditionException);
}

/**
 * @brief: Test de la méthode reqPersonneFormate()
 * 	Cas valide: Vérifier que la string de retour est la bonne
 * 	Cas invalide: Aucun
 */
TEST_F(UnePersonneTest, reqPersonneFormate)
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
		ASSERT_EQ(os.str(), unePersonne.reqPersonneFormate());
}

/**
 * @brief: Test de la méthode d'égalité()
 * 	Cas valide: Vérifier que la fonction retourne vrai lorsque vrai et faux lorsque faux
 * 	Cas invalide: Aucun
 */
TEST_F(UnePersonneTest, operateurEgalite)
{
	bool bool1 = (unePersonne == uneAutrePersonne);
	bool bool2 = (unePersonne == uneAutreAutrePersonne);
	ASSERT_TRUE(bool1 && !bool2);
}

/**
 * @brief: Test de la méthode de clonage()
 * 	Cas valide: Vérifier que la personne cloné est égale mais n'a pas la même adresse
 * 	Cas invalide: Aucun
 */
TEST_F(UnePersonneTest, testClonage)
{
	Personne* p1 = unePersonne.clone();
    ASSERT_TRUE(((p1->reqPersonneFormate())==
	unePersonne.reqPersonneFormate()) && !(p1 == &unePersonne));
}

