/*
 * JoueurTesteur.cpp
 *
 *  Created on: 2020-03-25
 *      Author: etudiant
 */

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
 * \brief Test du Constructeur Joueur::Joueur(string p_nom, string p_prenom, util::Date p_dateNaissance,string p_telephone,string p_position)
 * cas valide : <br>
 * 	Joueur consruit avec les parametres tous valides
 *
 * <br>
 * cas invalide : <br>
 * 	Joueur dont la position est ail et n'est donc pas parmi les positions possibles (ailier,centre,defenseur,gardien)
 * 	Joueur dont l 'age de moins de 15 ans
 * 	Joueur dont l 'age est plus  de 17 ans
 */


TEST(JoueurConstructeurValide,argumentsValides)
{
	Date uneDate(01, 01, 2005);
	Joueur unJoueur("BLO","JOE",uneDate,"514 369-9874","centre");
	ASSERT_EQ("BLO",unJoueur.reqNom());
	ASSERT_EQ("JOE",unJoueur.reqPrenom());
	ASSERT_EQ(uneDate,unJoueur.reqDateNaissance());
	ASSERT_EQ("centre",unJoueur.reqPosition());
}

TEST(JoueurConstructeurInValide,PositionInvalide)
{
	ASSERT_THROW( Joueur unJoueur("BLO","JOE",Date(01, 01, 2005),"514 369-9874","ail"),PreconditionException) << "La position du joueur etre valide";
}


TEST(JoueurConstructeurInValide,AgeInsufisant)
{
    ASSERT_THROW(Joueur unJoueur("BLO","JOE",Date(12, 12, 2019),"514 369-9874","centre"),PreconditionException) << "le Joueur doit avoir au moins 15 ans";
}


TEST(JoueurConstructeurInValide,AgeTropEleve)
{   Date uneDate(12, 12, 2000);
    ASSERT_THROW(Joueur unJoueur("BLO","JOE",Date(12, 12, 2000),"514 369-9874","centre"),PreconditionException) << "le Joueur doit avoir plus de 17 ans";
}


/**
 * \class JoueurValide
 * \brief Fixture pour les tests  un objet Joueur Valide
 */


class JoueurValide : public ::testing::Test
{
    public:

	JoueurValide(): unJoueur("BLO","JOE",Date(01, 01, 2005),"514 369-9874","centre")
    {

    }

	Joueur unJoueur;
};

/**
 * \brief Test de la méthode const string& Joueur::reqPosition() const
 *
 */

TEST_F(JoueurValide,reqPosition)
{
   ASSERT_EQ("centre", unJoueur.reqPosition());
}


/**
 * \brief Test de la méthode string Joueur:: reqPesonneFormatee() const
 *
 */

TEST_F(JoueurValide,reqPesonneFormatee)
{
   Personne * unePersonne;

   unePersonne = unJoueur.clone();

   string msgInfos = "Nom               : BLO \nPrenom            : JOE \nDate de naissance : Samedi le 01 janvier 2005 \nTelephone         : 514 369-9874\nPosition          : centre \n";

   ASSERT_EQ(msgInfos, unePersonne->reqPesonneFormatee());
}

/**
 * \brief Test de la méthode 	Personne*  Joueur:: clone() const
 *
 */

TEST_F(JoueurValide,clone)
{
  ASSERT_EQ("BLO", unJoueur.clone()->reqNom());

}














