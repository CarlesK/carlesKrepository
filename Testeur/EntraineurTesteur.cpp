/*
 * EntraineurTesteur.cpp
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
#include <string>
using namespace hockey;
using namespace util;


/**
 * \brief Test du Constructeur Entraineur::Entraineur(string p_nom, string p_prenom, util::Date p_dateNaissance,string p_telephone,string p_numRAMQ,char p_sexe )
 * cas valide : <br>
 * 	Entraineur avec tous les parametres au format valide
 * <br>
 * cas invalide : <br>
 * 	Entraineur avec un numero de RAMQ au format invalide
 * 	Entraineur avec un numero de RAMQ incompatible avec les donnees saisies
 * 	Entraineur avec un numero de telephone au format invalide
 * 	Entraineur mineur
 */


TEST(EntraineurConstructeurValide,m_numRAMQ)
{   Date uneDate(01, 01, 1970);
    Entraineur  unEntraineur("Bonneau","Jean",uneDate,"514 369-9874","BONJ 7001 0112",'M');
	ASSERT_EQ("BONJ 7001 0112",unEntraineur.reqNumRAMQ());
}

TEST(EntraineurConstructeurValide,reqSexe)
{   Date uneDate(01, 01, 1970);
    Entraineur  unEntraineur("Bonneau","Jean",uneDate,"514 369-9874","BONJ 7001 0112",'M');
    ASSERT_EQ('M',unEntraineur.reqSexe());
}


TEST(EntraineurConstructeurInValide,InvalidPhoneFormat)
{   Date uneDate(01, 01, 1970);
    ASSERT_THROW( Entraineur  unEntraineur("Bonneau","Jean",uneDate,"411 369-9874","BONJ 7001 0112",'M'),PreconditionException) << "Le numero de telephone doit etre au format Canadien valide";
}


TEST(EntraineurConstructeurInValide,InvalidRAMQFormat)
{   Date uneDate(01, 01, 1970);
    ASSERT_THROW( Entraineur  unEntraineur("Bonneau","Clotaire",uneDate,"411 369-9874","BONJ 7001 0112",'M'),PreconditionException) << "Le numero de RAMQ doit etre au format valide";
}


TEST(EntraineurConstructeurInValide,mineur)
{   Date dateNaissance(01, 01,2019);
    ASSERT_THROW( Entraineur  unEntraineur("Bonneau","Jean",dateNaissance,"514 369-9874","BONJ 7001 0112",'M'),PreconditionException) << "L'entraineur ne doit pas etre mineur";
}


/**
 * \class EntraineurValide
 * \brief Fixture pour les tests avec un entraineur Valide
 */


Date uneDate(01, 01, 1970);

class EntraineurValide : public ::testing::Test
{
    public:

	EntraineurValide(): unEntraineur("Bonneau","Jean",uneDate,"514 369-9874","BONJ 7001 0112",'M')
    {

    }

	Entraineur unEntraineur;
};


/**
 * \brief Test de la méthode void Entraineur:: reqPesonneFormatee() const
 *
 */
TEST_F(EntraineurValide,reqPesonneFormatee)
{
   string msgInfos = "Nom               : Bonneau \nPrenom            : Jean \nDate de naissance : Jeudi le 01 janvier 1970 \nTelephone         : 514 369-9874\nNumero de RAMQ    : BONJ 7001 0112 \n";

   ASSERT_EQ(msgInfos, unEntraineur.reqPesonneFormatee());

}


/**
 * \brief Test de la méthode void Entraineur::clone() const
 *
 */

TEST_F(EntraineurValide,clone)
{
  ASSERT_EQ("Bonneau", unEntraineur.clone()->reqNom());

}




