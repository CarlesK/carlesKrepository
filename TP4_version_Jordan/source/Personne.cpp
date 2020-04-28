/**
 * @file Personne.cpp
 * @brief Cette classe sert au maintien et à la manipulation des personnes.
 * Cette classe est abstraite.
 * <p>
 * Les valeurs qui entrent dans la classe doivent être validée à priori.
 * <p>
 * Attributs: string p_nom, string p_prenom, Date p_dateNaissance, string p_telephone
 * @author Jordan Longval
 */

#include "Date.h"
#include "Personne.h"
#include "validationFormat.h"
#include "ContratException.h"
#include <sstream>
#include <iomanip>

using namespace std;
namespace hockey
{

/**
 * @brief constructeur d'un objet Personne à partir de valeurs passées en paramètres.
 * @param[in] p_nom est une chaîne de caractères (string) qui représente le nom de la personne créée.
 * @param[in] p_prenom est une chaîne de caractères (string) qui représente le prénom de la personne créée.
 * @param[in] p_dateNaissance est un objet Date qui représente la date de naissance de la personne créée.
 * @param[in] p_telephone est une chaîne de caractères (string) qui représente le prénom de la personne créée.
 * @pre Les valeurs entrées doivent être valides et avoir un format valide.
 */
Personne::Personne(std::string p_nom, std::string p_prenom,
		const util::Date& p_dateNaissance, std::string p_telephone):m_nom(p_nom), m_prenom(p_prenom),
				m_dateNaissance(p_dateNaissance), m_telephone(p_telephone)
{
	PRECONDITION(util::validerFormatNom(p_nom));
	PRECONDITION(util::validerFormatNom(p_prenom));
	PRECONDITION(util::validerTelephone(p_telephone));

	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_prenom == p_prenom);
	POSTCONDITION(m_dateNaissance == p_dateNaissance);
	POSTCONDITION(m_telephone == p_telephone);
	INVARIANTS();
}


/**
 * @brief constructeur d'un objet Personne vide.
 * Ce constructeur existe pour renvoyer une erreur si un objet Personne est créé sans paramètres
 */
Personne::Personne()
{
	//PRECONDITION(false);
}

/**
 * @brief retourne le nom de le personne.
 * @return une chaîne de caractères (string) qui représente le nom de la personne.
 */
const string& Personne::reqNom() const
{
	return m_nom;
}

/**
 * @brief retourne le prénom de le personne.
 * @return une chaîne de caractères (string) qui représente le prénom de la personne.
 */
const string& Personne::reqPrenom() const
{
	return m_prenom;
}

/**
 * @brief retourne le téléphone de le personne.
 * @return une chaîne de caractères (string) qui représente le numéro de téléphone de la personne.
 */
const string& Personne::reqTelephone() const
{
	return m_telephone;
}

/**
 * @brief retourne la date de naissance de la personne .
 * @return un objet date qui représente la date de naissance de la personne.
 */
 const util::Date Personne::reqDateNaissance() const
{
	return m_dateNaissance;
}

/**
 * @brief asigne un nouveau numéro de téléphone à la personne.
 * @param[in] p_telephone une chaîne de caractère (string) qui représente le numéro de téléphone de la personne.
 * @pre le numéro de téléphone doit être valide et dans un format valide XXX XXX-XXXX.
 */
void Personne::asgTelephone(const string& p_telephone)
{
	PRECONDITION(util::validerTelephone(p_telephone));
	m_telephone = p_telephone;
	POSTCONDITION(m_telephone == p_telephone);
	INVARIANTS();
}

/**
 * @brief créer une chaîne de caractères (string) représentant les informations de la personne.
 * @return une chaîne de caractères (string) représentant les informations de la personne.
 */
string Personne::reqPersonneFormate() const
{
	ostringstream os;
	os << left<< setw(24) << "Nom" << setfill(' ');
	os <<": " << m_nom << endl;
	os << left<< setw(24) << "Prenom" << setfill(' ') ;
    os <<": " << m_prenom << endl;
    os << left<< setw(24) << "Date de naissance" << setfill(' ');
   	os <<": " << m_dateNaissance.reqDateFormatee() << endl;
   	os << left<< setw(24) << "Telephone" << setfill(' ');
   	os <<": " << m_telephone << endl;

	return os.str();
}

/**
 * \brief surcharge de l'opérateur == pour les objets Personne.
 * \param[in] p_personne qui est une personne valide.
 * \return un booléen indiquant si les deux personnes sont égales ou pas sur la base de leur nom, prénom et date de naissance.
 */
bool Personne::operator ==(const Personne& p_personne) const
{
	return (m_nom == p_personne.m_nom) &&
			(m_prenom == p_personne.m_prenom) &&
			(m_dateNaissance == p_personne.m_dateNaissance);


}
/**
 * @brief fonction permettant de vérifier les invariants de la classe personne.
 */
void Personne::verifieInvariant() const
{
	INVARIANT(util::validerFormatNom(m_nom));
	INVARIANT(util::validerFormatNom(m_prenom));
	INVARIANT(util::validerTelephone(m_telephone));

}
} /* namespace hockey */


