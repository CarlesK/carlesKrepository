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
using namespace hockey;
using namespace util;

TEST(EntraineurConstructeur,ConstructeurParametres)
{   Date uneDate(01, 01, 1970);
    hockey::Entraineur  unEntraineur("Bonneau","Jean",uneDate,"514 369-9874","BONJ 7001 0112",'M');
	ASSERT_TRUE(unEntraineur.reqDateNaissance().estBissextile(1980));
}












