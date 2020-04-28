/**
 * \file : Annuaire.h
 * \brief : Fichier qui contient l'interface de la classe annuaire qui permet
 * de faire la gestion des personnes membres d'une équipe de hockey dans un annuaire.
 *
 * Attributs:
 * - string m_nomClub: Le nom de l'équipe de hockey.
 * - vector<*Personne> m_vMembres: un vecteur contenant des pointeurs vers les personnes membres de l'équipe
 * \author : Jordan Longval
 * \version : TP3
 * \date : 2020-04-02
 *
 */

#ifndef ANNUAIRE_H_
#define ANNUAIRE_H_

#include <vector>
#include "Personne.h"

namespace hockey
{
/**
 * \class Annuaire
 * \brief Cette classe sert à la gestion des personnes membres d'une équipe de hockey.
 *              <p>
 *              Les instances de la classe doivent être construites avec un nom d'équipe en param[in].
 *              <p>
 *              Attributs: string m_nomClub ( le nom de l'équipe de hockey), vector<Personne*> m_vMembres (vecteur contenant des pointeurs vers les personnes membres de l'équipe).
 */
class Annuaire
{
public:
	Annuaire();
	Annuaire(std::string p_nomClub);
	const std::string& reqNomClub() const;
	std::string reqAnnuaireFormate() const;
	Annuaire (const Annuaire& p_annuaire); //constructeur copie
	Annuaire &operator=(const Annuaire& p_annuaire); // constructeur  d'assignation
	void ajouterPersonne( const Personne& p_personne);
	~Annuaire();
private:
	std::string m_nomClub;
	std::vector<Personne*> m_vMembres;
	void verifieInvariant() const;
};

} /* namespace hockey */

#endif /* ANNUAIRE_H_ */
