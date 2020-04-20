/*
 * Annuaire.cpp
 *
 *  Created on: 2020-03-21
 *      Author: etudiant
 */

#include "Annuaire.h"
#include "validationFormat.h"
#include <sstream>
#include <iostream>
#include "Date.h"
#include "PersonneException.h"
#include<iterator>
#include <algorithm>
#include <vector>


using namespace std;
using namespace util;

namespace hockey
{

    Annuaire::Annuaire(string p_nomClub): m_nomClub(p_nomClub)
	{
    	for( unsigned i = 0; i < m_vMembres.size();i++)
    	  {
    	    m_vMembres[i]= NULL;
    	  }
    	INVARIANTS();
	}


    Annuaire::Annuaire(const Annuaire& p_Annuaire):m_nomClub(p_Annuaire.reqNomClub())
    {
    	for( unsigned i = 0; i < m_vMembres.size();i++)
    	{
    	   m_vMembres[i]= p_Annuaire.m_vMembres[i];
    	}
    	INVARIANTS();
    }

    Annuaire::~Annuaire()
    {
    	vector<Personne*>::iterator iter;

    	for( iter = m_vMembres.begin(); iter != m_vMembres.end();iter++)
    	{
    		delete (*iter);
    		(*iter) = 0;
    	}

    }

    const string& Annuaire::reqNomClub() const
     {
    	return m_nomClub;
     }

    void Annuaire::ajouterPersonne(const Personne& p_personne)
    {

     if (!PersonneEstDejaPresente(p_personne))
      {
    	 m_vMembres.push_back(p_personne.clone());
      }
     else
      {
    	 throw PersonneDejaPresentException (p_personne.reqPesonneFormatee());
      }
    }


    void Annuaire :: verifieInvariant() const
     {
      	 INVARIANT(!reqNomClub().empty());
     }


    Annuaire& Annuaire::operator= (const Annuaire& v)
    {
      if(this != &v)
      {
    	 for (unsigned int i=0; i< m_vMembres.size();++i)
    	  {
    		 delete this->m_vMembres[i];
    	     m_vMembres[i] = 0;
    	     this->m_vMembres[i]=(*m_vMembres[i]).clone();
    	     this->m_vMembres[i] = v.m_vMembres[i];
    	  }
      }
       return (*this);
    }

    bool Annuaire::PersonneEstDejaPresente(const Personne& p_personne) const
    {
        bool trouve = false;

    	for (unsigned int  i=0; i< m_vMembres.size(); i++)
        {
			if (*(m_vMembres[i]) == p_personne)
			{
				trouve = true;
				break;
			}
    	}

    	return trouve;
	}


    string Annuaire::reqAnnuaireFormate() const
    {
       ostringstream os;
       os << "Club              : ";
       os<< reqNomClub()<< endl;
       os << "------------------: "<<endl;

      for( unsigned i = 0; i < m_vMembres.size();i++)
      {
    	 os<< (m_vMembres[i]->reqPesonneFormatee());
    	 os << "------------------: "<<endl;
      }
         return os.str();
    }

}


