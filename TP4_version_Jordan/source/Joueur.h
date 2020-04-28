/**
 * @file : Joueur.h
 * @date : 2020-04-02
 * @author : etudiant
 */

#ifndef JOUEUR_H_
#define JOUEUR_H_

#include "Personne.h"
#include "ContratException.h"

namespace hockey
{
/**
 * \class Joueur
 * \brief Cette classe sert au maintien et à la manipulation des joueurs. Elle hérite de la classe Personne.
 *
 *              <p>
 *              Les valeurs qui entrent dans la classe doivent être validée à priori.
 *              <p>
 *              Attributs: string p_nom, string p_prenom, Date p_dateNaissance, string p_telephone, string p_position
 */
class Joueur: public Personne
{
public:
	Joueur(std::string p_nom, std::string p_prenom,
		   const util::Date& p_dateNaissance,
		   std::string p_telephone, std::string p_position);
	Joueur();
	const std::string& reqPosition() const;
	virtual std::string reqPersonneFormate() const;
	virtual Personne* clone() const;
	virtual ~Joueur();
private:
	std::string m_position;
	void verifieInvariant() const;
};

} /* namespace hockey */

#endif /* JOUEUR_H_ */
