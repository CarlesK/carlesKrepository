/*
 * PersonneTesteur.cpp
 *
 *  Created on: 2020-03-21
 *      Author: etudiant
 */

/*
 * PersonneTesteur.cpp
 *
 *  Created on: 2020-03-21
 *      Author: etudiant
 */
#include<gtest/gtest.h>

using namespace hockey;
using namespace util;



/**
 * \brief Test du Constructeur PersonneTest(string p_nom, string p_prenom, util::Date p_dateNaissance,string p_telephone):m_nom (p_nom),m_prenom (p_prenom),m_dateNaissance (p_dateNaissance)
 * cas valide : <br>
 * 	PersonneTest comme object Personne construit avec tous les arguments valides
 *
 * <br>
 * cas invalide : <br>
 * 	Entraineur comme object implementant la classe abstraite Personne avec un nom au format invalide
 * 	Entraineur comme object implementant la classe abstraite Personne avec un prenom au format invalide
 * 	Entraineur comme object implementant la classe abstraite Personne avec un date de Naissance au format invalide
 * 	Entraineur comme object implementant la classe abstraite Personne avec un nom identique au prenom
 */

/* Classe construit pour le besoin unique de tester la classe abstraite Personne*/

class PersonneTest: public Personne{

  public:

	PersonneTest(string p_nom, string p_prenom, util::Date p_dateNaissance,string p_telephone):Personne(p_nom, p_prenom,p_dateNaissance,p_telephone){

  }

 Personne*  clone() const {
		return 0;
	 }

};


TEST(PersonneTestConstructeurValide,argumentsValides)
{
	Date uneDate(01, 01, 1970);
    PersonneTest unePersonne("Bonneau","Jean",uneDate,"514 369-9874");
	ASSERT_EQ("Bonneau",unePersonne.reqNom());
	ASSERT_EQ("Jean",unePersonne.reqPrenom());
	ASSERT_EQ(uneDate,unePersonne.reqDateNaissance());
	ASSERT_EQ("514 369-9874",unePersonne.reqTelephone());
}


TEST(PersonneTestConstructeurInValide,nomInvalide)
{
   ASSERT_THROW( PersonneTest unePersonne("Bonneau","Jea2",Date(01, 01, 1970),"514 369-9874"),PreconditionException) << "Le formant du prenom doit être valide";
}


TEST(PersonneTestConstructeurInValide,prenomInvalide)
{
    ASSERT_THROW( PersonneTest  unePersonne("1onneau","Jean",Date(01, 01, 1970),"514 369-9874"),PreconditionException) << "Le formant du nom doit être valide";
}


TEST(PersonneTestConstructeurInValide,prenomEgalNom)
{
    ASSERT_THROW( PersonneTest  unePersonne("Bonneau","Bonneau",Date(01, 01, 1970),"514 369-9874"),PostconditionException) << "Le nom doit être different du prenom";
}


/**
 * \class EntraineurValide
 * \brief Fixture pour les tests avec un un objet valide implementant la clase abstraite Personne
 */


class PersonneValide : public ::testing::Test
{
    public:

	PersonneValide(): unePersonne("Bonneau","Jean",Date(01, 01, 1970),"514 369-9874")
    {

    }

	PersonneTest unePersonne;
};


/**
 * \brief Test de la méthode const string& Personne::reqTelephone() const
 *
 */

TEST_F(PersonneValide,reqTelephone)
{
   ASSERT_EQ("514 369-9874", unePersonne.reqTelephone());
}


/**
 * \brief Test de la méthode void Personne::asgTelephone(const std::string& p_telephone)
 *
 */
TEST_F(PersonneValide,asgTelephone)
{
	unePersonne.asgTelephone("418-789-9874");
    ASSERT_EQ("418-789-9874", unePersonne.reqTelephone());
}


/**
 * \brief Test de la méthode Personne::reqDateNaissance() const
 *
 */
TEST_F(PersonneValide,reqDateNaissance)
{  Date naissance(01, 01, 1970);
   ASSERT_EQ(naissance, unePersonne.reqDateNaissance());
}


/**
 * \brief Test de la méthode const string& Personne::reqNom() const
 *
 */
TEST_F(PersonneValide,reqNom)
{
   ASSERT_EQ("Bonneau", unePersonne.reqNom());
}


/**
 * \brief Test de la méthode const string& Personne::reqPrenom() const
 *
 */
TEST_F(PersonneValide,reqPrenom)
{
   ASSERT_EQ("Jean", unePersonne.reqPrenom());
}


/**
 * \brief Test de la méthode string Personne ::reqPesonneFormatee() const
 *
 */

TEST_F(PersonneValide,reqPesonneFormatee)
{

   string msgInfos = "Nom               : Bonneau \nPrenom            : Jean \nDate de naissance : Jeudi le 01 janvier 1970 \nTelephone         : 514 369-9874";

   ASSERT_EQ(msgInfos, unePersonne.reqPesonneFormatee());
}


/**
 * \brief Test de la méthode bool Personne:: operator ==(const Personne& p_personne) const
 *
 */

TEST_F(PersonneValide,operateurEgal)
{
	PersonneTest  unePersonneA("Bonneau","Jean",Date(01, 01, 1970),"514 513-0230");
    ASSERT_TRUE(unePersonneA == unePersonne);
}





