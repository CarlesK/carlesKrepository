/*
 * AnnuaireTesteur.cpp
 *
 *  Created on: 2020-03-29
 *      Author: etudiant
 */

#include<gtest/gtest.h>
#include<Annuaire.h>
#include<Personne.h>
#include<PersonneException.h>

using namespace hockey;
using namespace util;


/**
 * \brief Test du Constructeur  Annuaire::Annuaire(string p_nomClub): m_nomClub(p_nomClub)
 * cas valide : <br>
 * 	Annuaire avec tous les parametres au format valide
 * <br>
 * cas invalide : <br>
  N/A
 */

TEST(AnnuaireConstructeurValide,ArgumentValide)
{
	Annuaire unAnnuaire("Winners de hockeyville");
	ASSERT_EQ("Winners de hockeyville",unAnnuaire.reqNomClub());
}


/**
 * \class AnnuaireValide
 * \brief Fixture pour les tests avec un objet Annuaire valide
 */


class AnnuaireValide : public ::testing::Test
{
    public:

	AnnuaireValide(): unAnnuaire("Winners de hockeyville")
    {

    }

	Annuaire unAnnuaire;
};


/**
 * \brief Test de la méthode void Annuaire::ajouterPersonne(const Personne& p_personne)
 *
 */



TEST_F(AnnuaireValide,reqNomClub)
{
	ASSERT_EQ("Winners de hockeyville",unAnnuaire.reqNomClub());
}


/**
 * \brief Test de la méthode void Annuaire::ajouterPersonne(const Personne& p_personne)
 *
 */

TEST_F(AnnuaireValide,ajouterPersonne)
{

	Joueur unJoueur("BLO","JOE",Date(01, 01, 2005),"418 789-9874","centre");

	unAnnuaire.ajouterPersonne(unJoueur);
	string msgInfos = "Club              : Winners de hockeyville\n------------------: \nNom               : BLO \nPrenom            : JOE \nDate de naissance : Samedi le 01 janvier 2005 \nTelephone         : 418 789-9874\nPosition          : centre \n------------------: \n";

   ASSERT_EQ(msgInfos, unAnnuaire.reqAnnuaireFormate());
}


/**
 * \brief Test de la méthode string Annuaire::reqAnnuaireFormate() const
 *
 */

TEST_F(AnnuaireValide,reqAnnuaireFormate)
{
	Entraineur  unEntraineur("Bocquet","Bill",Date(01, 01, 1970),"514 369-9874","BOCB 7001 0112",'M');
	Joueur unJoueur("BLO","JOE",Date(01, 01, 2005),"418 789-9874","centre");

	unAnnuaire.ajouterPersonne(unEntraineur);
	unAnnuaire.ajouterPersonne(unJoueur);

	string msgInfos = "Club              : Winners de hockeyville\n------------------: \nNom               : Bocquet \nPrenom            : Bill \nDate de naissance : Jeudi le 01 janvier 1970 \nTelephone         : 514 369-9874\nNumero de RAMQ    : BOCB 7001 0112 \n------------------: \nNom               : BLO \nPrenom            : JOE \nDate de naissance : Samedi le 01 janvier 2005 \nTelephone         : 418 789-9874\nPosition          : centre \n------------------: \n";

   ASSERT_EQ(msgInfos, unAnnuaire.reqAnnuaireFormate());
}


/**
 * \brief Test de la méthode bool PersonneEstDejaPresente(const Personne& p_personne) const;
 *
 */


TEST_F(AnnuaireValide,PersonneDejaPresente)
{
	Entraineur  unEntraineur("Bocquets","Bill",Date(01, 01, 1970),"514 369-9874","BOCB 7001 0112",'M');
	unAnnuaire.ajouterPersonne(unEntraineur);

	try
	   {
		unAnnuaire.ajouterPersonne(unEntraineur);
	   }
	   catch(PersonneException const& e)
	   {
	       cout << "ERREUR : " << e.what() << endl;
	   }

}


















