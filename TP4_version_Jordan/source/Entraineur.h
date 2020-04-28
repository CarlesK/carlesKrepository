/**
 * \file : Entraineur.h
 * \brief Fichier contenant l'interface de la classe Entraineur.
 * Cette classe est dérivée de la classe Personne.
 * Attributs:
 * -string m_numRAMQ: le numéro de RAMQ de la personne dans le format standard suivant
 * 	NNNP AAMM JJXX où NN sont les trois premières lettres du nom de famille de la personne en Maj,
 * 	P est la première lettre du prénom de la personne en Maj,
 * 	AA sont les deux derniers chiffres de l'année de naissance de la personne
 * 	MM sont les chiffres du mois de naissance de la personne
 * 	JJ sont les chiffres du jour de naissance de la personne
 * 	XX est un code administratif dont on ne connait pas la valeur.
 * -char m_sexe: le sexe de l'entraîneur ('M' ou 'F')
 *
 * Note: L'entraîneur doit être majeur pour être valide.
 *
 * \author : Jordan Longval
 * \date : 2020-04-02
 */

#ifndef ENTRAINEUR_H_
#define ENTRAINEUR_H_

#include "Personne.h"
#include "ContratException.h"

namespace hockey
{
/**
 * \class Entraineur
 * \brief Cette classe sert au maintien et à la manipulation des entraineurs. Elle hérite de la classe Personne.
 *              <p>
 *              Les valeurs qui entrent dans la classe doivent être validée à priori.
 *              <p>
 *              Attributs: string p_nom, string p_prenom, Date p_dateNaissance, string p_telephone, p_numRAMQ, p_sexe
 */
class Entraineur: public Personne
{
public:
	Entraineur(std::string p_nom, std::string p_prenom,
			   const util::Date& p_dateNaissance, std::string p_telephone,
			   std::string p_numRAMQ, char p_sexe);
	Entraineur();
	const std::string& reqNumRAMQ() const;
	const char& reqSexe() const;
	virtual std::string reqPersonneFormate() const;
	virtual Personne* clone() const;
	virtual ~Entraineur();

private:
	std::string m_numRAMQ;
	char m_sexe;
	void verifieInvariant() const;
};

} /* namespace hockey */

#endif /* ENTRAINEUR_H_ */
