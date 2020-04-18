/*
 * Joueur.cpp
 *
 *  Created on: 2020-03-20
 *      Author: etudiant
 */
#include <map>
#include <string>
#include "Personne.h"
#include "Joueur.h"
#include "validationFormat.h"
#include <sstream>
#include <iostream>
#include "Date.h"


using namespace std;

using namespace util;

namespace hockey
{

  Joueur::Joueur(string p_nom, string p_prenom, Date p_dateNaissance,string p_telephone,string p_position):
    		   Personne( p_nom, p_prenom, p_dateNaissance,p_telephone),m_position(p_position)
	{

	  Date cDate;
	  PRECONDITION(((cDate -(p_dateNaissance))/ (Date::estBissextile(cDate.reqAnnee())? 366 : 365)) >=15 )
	  PRECONDITION(((cDate -(p_dateNaissance))/ (Date::estBissextile(cDate.reqAnnee())? 366 : 365)) <=17 )

	  map<string, int> positions;

	  positions["ailier"]    =1;
	  positions["centre"]    =2;
	  positions["defenseur"] =3;
	  positions["gardien"]   =4;

	  PRECONDITION(positions.find(conversionMinuscule(p_position)) != positions.end());
	  INVARIANTS();
	}

  Joueur:: Joueur(const Joueur& p_Joueur):Personne(p_Joueur),m_position(p_Joueur.m_position)
      {
      	Date cDate;
      	PRECONDITION(((cDate -(p_Joueur.reqDateNaissance()))/ (Date::estBissextile(cDate.reqAnnee())? 366 : 365)) >=15 )
      	PRECONDITION(((cDate -(p_Joueur.reqDateNaissance()))/ (Date::estBissextile(cDate.reqAnnee())? 366 : 365)) <=17 )

		map<string, int> positions;

      	positions["ailier"]    =1;
    	positions["centre"]    =2;
    	positions["defenseur"] =3;
    	positions["gardien"]   =4;

    	PRECONDITION(positions.find(conversionMinuscule(p_Joueur.m_position)) != positions.end());

        INVARIANTS();
      }

  	 Joueur:: ~Joueur()
  	 {

  	 }

  	const string& Joueur::reqPosition() const
  	{
  		return m_position;
  	}

  	void Joueur :: verifieInvariant() const
  	{
  		INVARIANT(!reqNom().empty());
  		INVARIANT(!reqPrenom().empty());
  	}

  	Personne*  Joueur:: clone() const
  	{
  		  return new Joueur(*this);
  	}

  	string Joueur:: reqPesonneFormatee() const
  		{
  			ostringstream os;
  			os << "Position          : ";
  			os<< reqPosition()<< " "<<endl;
  		 return Personne::reqPesonneFormatee() + "\n" + os.str();
  		}

}
