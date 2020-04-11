/*
 * Entraineur.h
 *
 *  Created on: 2020-03-14
 *      Author: etudiant
 */

#ifndef ENTRAINEUR_H_
#define ENTRAINEUR_H_

#include "Personne.h"

namespace hockey
{
	class Entraineur: public Personne
	{
	   public :

		Entraineur(string nom, string prenom, util::Date dateNaissance,string telephone,string p_numRAMQ,char p_sexe);

		Entraineur(const Entraineur& p_Entraineur);

		~Entraineur();

		const string& reqNumRAMQ() const;
		const char& reqSexe() const;

		string reqPesonneFormatee() const;

		virtual Personne* clone() const;

		private:
		string m_numRAMQ;
		char m_sexe;
		void verifieInvariant() const;
	};
}


#endif /* ENTRAINEUR_H_ */
