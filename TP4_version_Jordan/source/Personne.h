/**
 * @file Personne.h
 * @brief Fichier qui contient l'interface de la classe abstraite
 * Personne qui permet de récolter les informations d'une personne.
 * @author Jordan Longval
 * @version TP3
 * @date
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include "Date.h"
#include "string"
#include "ContratException.h"
namespace hockey
{
/**
 * \class Personne
 * \brief Cette classe sert au maintien et à la manipulation des personnes.
 *
 *              Cette classe est abstraite.
 *              <p>
 *              Les valeurs qui entrent dans la classe doivent être validée à priori.
 *              <p>
 *              Attributs: string p_nom, string p_prenom, Date p_dateNaissance, string p_telephone
 */
class Personne
{
public:
	Personne();
	Personne(std::string p_nom, std::string p_prenom, const util::Date& p_dateNaissance, std::string p_telephone);
	const util::Date reqDateNaissance() const;
	const std::string& reqNom() const;
	const std::string& reqPrenom() const;
	const std::string& reqTelephone() const;
	void asgTelephone(const std::string& p_telephone);
	virtual std::string reqPersonneFormate() const;
	bool operator ==(const Personne& p_personne) const;
	virtual Personne* clone() const =0;
	virtual ~Personne(){};

private:
	std::string m_nom;
	std::string m_prenom;
protected:
	util::Date m_dateNaissance;
private:
	std::string m_telephone;
	void verifieInvariant() const;
;
};

} /* namespace hockey */

#endif /* PERSONNE_H_ */
