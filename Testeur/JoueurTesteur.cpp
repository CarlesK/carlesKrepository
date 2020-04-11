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


TEST(JoueurConstructeur,AgeInferieur)
{   Date uneDate(12, 12, 2019);
    ASSERT_THROW(Joueur unJoueur("BLO","JOE",uneDate,"514 369-9874","Centre"),PreconditionException) << "Age du Jour pas moins de 15 ans";
}


TEST(JoueurConstructeur,AgeSuperieur)
{   Date uneDate(12, 12, 2000);
    ASSERT_THROW(Joueur unJoueur("BLO","JOE",uneDate,"514 369-9874","Centre"),PreconditionException) << "Age du Jour pas plus de 17 ans";
}


TEST(JoueurConstructeur,PositionInvalide)
{   Date uneDate(12, 12, 2014);
    ASSERT_THROW(Joueur unJoueur("BLO","JOE",uneDate,"514 369-9874","attaquant"),PreconditionException) << "Position Invalide";
}







