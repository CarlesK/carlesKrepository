/*
 * Personne.h
 *
 *  Created on: 2020-02-15
 *      Author: etudiant
 */


/*
 * Personne.h
 *
 *  Created on: 2020-02-15
 *      Author: Carles Kouaya
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_
#include "Date.h"
#include <string>
using namespace std;

namespace hockey
{
	class Personne
	{
      public:
		Personne(string nom, string prenom, util::Date dateNaissance,string telephone);
		Personne(const Personne& p_Personne);
		virtual ~Personne();
		util::Date reqDateNaissance() const;
		const string& reqNom() const;
		const string& reqPrenom() const;
		const string& reqTelephone() const;
		void asgTelephone(const std::string& telephone);
		virtual string reqPesonneFormatee() const;
		bool operator ==(const Personne& p_personne) const;
		virtual Personne* clone() const = 0;

	 protected:
		string  m_nom;
		string  m_prenom;
		util::Date m_dateNaissance;
		string  m_telephone;
	 private:
		void verifieInvariant() const;
	};

}

#endif /* PERSONNE_H_ */


