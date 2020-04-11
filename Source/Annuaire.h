/*
 * Annuaire.h
 *
 *  Created on: 2020-03-21
 *      Author: etudiant
 */

#ifndef ANNUAIRE_H_
#define ANNUAIRE_H_
using namespace std;
#include <vector>
#include "Personne.h"

namespace hockey
{

  class Annuaire
 {
   public:
    Annuaire(string p_nomClub);
    Annuaire(const Annuaire& p_Annuaire);
    ~Annuaire();
    const string& reqNomClub() const;
    string reqAnnuaireFormate() const;
    void ajouterPersonne(const Personne& p_personne);

  private:
    string  m_nomClub;
    vector<Personne*> m_vMembres;
    void verifieInvariant() const;
 };

}

#endif /* ANNUAIRE_H_ */
