/*
 * AnnuaireTesteur.cpp
 *
 *  Created on: 2020-03-29
 *      Author: etudiant
 */

#include<gtest/gtest.h>
using namespace hockey;
using namespace util;

TEST(AnnuaireConstructeur,ConstructeurParametres)
{
	Date entaineurDate(01, 01, 1970);
    Entraineur  unEntraineur("Bonneau","Jean",entaineurDate,"514 369-9874","BONJ 7001 0112",'M');
	Date joueurDate(12, 12, 2002);

	Joueur unJoueur("BLO","JOE",joueurDate,"514 369-9874","centre");

	Annuaire unAnnuaire("Winners");

	unAnnuaire.ajouterPersonne(unEntraineur);
	unAnnuaire.ajouterPersonne(unJoueur);
	ASSERT_EQ("Winners",unAnnuaire.reqNomClub());

}
