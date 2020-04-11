/*
 * Entraineur.cpp
 *
 *  Created on: 2020-03-14
 *      Author: etudiant
 */

#include "Personne.h"
#include "Entraineur.h"
#include "validationFormat.h"
#include <sstream>
#include <iostream>
#include "Date.h"

using namespace std;

using namespace util;

namespace hockey
{

    Entraineur::Entraineur(string p_nom, string p_prenom, util::Date p_dateNaissance,string p_telephone,string p_numRAMQ,char p_sexe ):
    		    Personne( p_nom, p_prenom, p_dateNaissance,p_telephone),m_numRAMQ(p_numRAMQ),m_sexe(p_sexe)
	{  PRECONDITION(util::validerNumRAMQ(p_numRAMQ,p_nom,p_prenom,p_dateNaissance.reqJourAnnee(),p_dateNaissance.reqMois(),p_dateNaissance.reqAnnee(),p_sexe));
	    INVARIANTS();
	}

    /**
     * \brief constructeur par copie*/
    Entraineur:: Entraineur(const Entraineur& p_Entraineur):Personne(p_Entraineur),m_numRAMQ(p_Entraineur.m_numRAMQ),m_sexe(p_Entraineur.m_sexe)
    {
    	Date cDate;
    	PRECONDITION(((cDate -(p_Entraineur.reqDateNaissance()))/ (Date::estBissextile(cDate.reqAnnee())? 366 : 365)) >=19 )//conditio de majorite
       INVARIANTS();
    }

	 Entraineur:: ~Entraineur()
	{

	}

	string Entraineur:: reqPesonneFormatee() const
	{   string strNumRAMQ = conversionMajuscule(SupprimerEspaces(reqNumRAMQ()));
		ostringstream os;
		os << "Numero de RAMQ    : ";
		os << strNumRAMQ.substr(0, 4)<< " ";
		os << strNumRAMQ.substr(4, 4)<< " ";
		os<<  strNumRAMQ.substr(8, 4)<< " " <<endl;

		return Personne::reqPesonneFormatee() + "\n" + os.str();

	}

	const string& Entraineur::reqNumRAMQ() const
	{
		return m_numRAMQ;
	}


	const char& Entraineur::reqSexe() const
	{
		return m_sexe;
	}

	/* brief Teste l'invariant de la classe Entraineur. L'invariant de cette classe s'assure que la classe Entraineur est valide*/

	void Entraineur :: verifieInvariant() const
	{
		INVARIANT(!reqNom().empty());
		INVARIANT(!reqPrenom().empty());

	}

	  Personne*  Entraineur::clone() const
	{
	    return new Entraineur(*this);
	 }

}

