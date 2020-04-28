/**
 * @file : AnnuaireTesteur.cpp
 * @date : 2020-04-13
 * @author : Jordan
 */
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Date.h"
#include "Annuaire.h"
#include "Joueur.h"
#include "Entraineur.h"

using namespace std;
using namespace hockey;
using namespace util;

/**
 * @brief Test du constructeur par paramètre de Annuaire
 * Cas valide de la création d'un objet Annuaire et vérification de l'attribut de nom.
 * Cas invalide:
 * Constructeur vide
 * On ne spécifie pas de condition sur la validité d'un nom d'équipe
 */
TEST(ConstructeurParamAnnuaire, ConstructeurValide)
{
	string nomClub = "Champions de Sherbrooke";
	Annuaire annuaireTest = Annuaire(nomClub);
	ASSERT_EQ(nomClub, annuaireTest.reqNomClub());
}

// CAS INVALIDES
TEST(ConstructeurParamAnnuaire, ConstructeurVide)
{
	ASSERT_THROW(Annuaire annuaireTest = Annuaire(),PreconditionException);
}

/**
 * @brief Test du constructeur par copie
 */
TEST(ConstructeurCopieAnnuaire, ConstructeurValide)
{
	Annuaire annuaireTest1("Club1");
	Joueur joueur1 = Joueur("un","joueur",Date(1,1,2005),
			"819 943-7804", "centre");
	Entraineur entraineur1 = Entraineur("Longval","Jordan",
			Date(18,03,1993),"819 564-0140", "LONJ 9303 1815",'M');
	annuaireTest1.ajouterPersonne(joueur1);
	annuaireTest1.ajouterPersonne(entraineur1);
	Annuaire annuaireTest2(annuaireTest1);
	bool memeValeurs = (annuaireTest1.reqAnnuaireFormate()
			            ==
			            annuaireTest2.reqAnnuaireFormate());
	ASSERT_TRUE(memeValeurs);
}


/**
 * @brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnAnnuaireTest: public::testing::Test
{
public:
	UnAnnuaireTest():
		annuaireTest("Champions de Sherbrooke"),
		joueurTest("un","joueur",Date(1,1,2005),
				"819 943-7804", "centre"),
		entraineurTest("Longval","Jordan",
	                   Date(18,03,1993),"819 564-0140",
		               "LONJ 9303 1815",'M'),
	    annuaireTest2("test")
		{};
		Annuaire annuaireTest;
		Joueur joueurTest;
		Entraineur entraineurTest;
		Annuaire annuaireTest2;
};

/**
 * @brief: Test de la méthode reqNomClub()
 * 	Cas valide: vérifier le retour du nom de Club
 * 	Cas invalide: aucun
 */
TEST_F(UnAnnuaireTest, reqNomClub)
{
	ASSERT_EQ("Champions de Sherbrooke", annuaireTest.reqNomClub());
}

/**
 * @brief: Test de la méthode reqAnnuaireFormate()
 * 	Cas valide: vérifier le retour de reqNomClub
 * 	Cas invalide: aucun
 */
TEST_F(UnAnnuaireTest, reqAnnuaireFormate)
{
	annuaireTest.ajouterPersonne(joueurTest);
	annuaireTest.ajouterPersonne(entraineurTest);
	ostringstream os;
	os<<"Club  : "<< "Champions de Sherbrooke"<<endl;
	os<<"---------------------"<<endl;
	os<< left<< setw(24) << "Nom" << setfill(' ');
	os <<": " << "un" << endl;
	os << left<< setw(24) << "Prenom" << setfill(' ') ;
	os <<": " << "joueur" << endl;
	os << left<< setw(24) << "Date de naissance" << setfill(' ');
	os <<": " << Date(1, 1, 2005).reqDateFormatee() << endl;
	os << left<< setw(24) << "Telephone" << setfill(' ');
	os <<": " << "819 943-7804" << endl;
	os<< left<< setw(24) << "Position" << setfill(' ');
	os <<": " <<"centre" << endl;
	os<<"---------------------"<<endl;
	os<< left<< setw(24) << "Nom" << setfill(' ');
	os <<": " << "Longval" << endl;
	os << left<< setw(24) << "Prenom" << setfill(' ') ;
	os <<": " << "Jordan" << endl;
	os << left<< setw(24) << "Date de naissance" << setfill(' ');
	os <<": " << Date(18, 03, 1993).reqDateFormatee() << endl;
	os << left<< setw(24) << "Telephone" << setfill(' ');
	os <<": " << "819 564-0140" << endl;
	os<< left<< setw(24) << "Numero de RAMQ" << setfill(' ');
	os <<": " << "LONJ 9303 1815" << endl;
	os<<"---------------------"<<endl;
	ASSERT_EQ(os.str(),annuaireTest.reqAnnuaireFormate());
}

/**
 * @brief: Test de l'opérateur d'assignation
 * 	Cas valide: vérifier que l'assignation fonctionne bien
 * 	Cas invalide:aucun
 */
TEST_F(UnAnnuaireTest, TestOperateurdassignation)
{
	annuaireTest.ajouterPersonne(joueurTest);
	annuaireTest.ajouterPersonne(entraineurTest);
	annuaireTest2 = annuaireTest;
	ASSERT_TRUE(annuaireTest.reqAnnuaireFormate()
			    ==
			    annuaireTest2.reqAnnuaireFormate());
}

/**
 * @brief: Test de la fonction ajouterPersonne
 * 	Cas valide: Si reqAnnuaireFormate retourne les bonnes valeurs
 * 	Cas invalide:aucun
 */
TEST_F(UnAnnuaireTest, TestAjoutPersonne)
{
	annuaireTest.ajouterPersonne(joueurTest);
	ostringstream os;
	os<<"Club  : "<< "Champions de Sherbrooke"<<endl;
	os<<"---------------------"<<endl;
	os<< left<< setw(24) << "Nom" << setfill(' ');
	os <<": " << "un" << endl;
	os << left<< setw(24) << "Prenom" << setfill(' ') ;
	os <<": " << "joueur" << endl;
	os << left<< setw(24) << "Date de naissance" << setfill(' ');
	os <<": " << Date(1, 1, 2005).reqDateFormatee() << endl;
	os << left<< setw(24) << "Telephone" << setfill(' ');
	os <<": " << "819 943-7804" << endl;
	os<< left<< setw(24) << "Position" << setfill(' ');
	os <<": " <<"centre" << endl;
	os<<"---------------------"<<endl;
	ASSERT_EQ(os.str(), annuaireTest.reqAnnuaireFormate());
}





