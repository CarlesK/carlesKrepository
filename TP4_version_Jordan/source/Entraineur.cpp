/**
   \file : Entraineur.h
 * \brief Fichier contenant l'implémentation de la classe Entraineur.
 *     Cette classe est dérivée de la classe Personne.
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

#include "Entraineur.h"
#include "validationFormat.h"
#include "Date.h"
#include "validationFormat.h"
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
namespace hockey
{
/**
 * @brief Constructeur de la classe entraîneur avec des paramètres en entrée.
 * @param [in] p_nom un string représentant le nom de l'entraîneur
 * @param [in] p_prenom un string représentant le prénom de l'entraîneur
 * @param [in] p_dateNaissance un objet Date représentant la date de naissance de l'entraîneur
 * @param [in] p_telephone un string représentant le numéro de téléphone de l'entraîneur
 * @param [in] p_numRAMQ un string représentant le numéro de RAMQ de l'entraîneur
 * @param [in] p_sexe un char représentant le sexe de l'entraîneur
 * @pre Tous les paramètres en entrée doivent être valide pour une personne standard.
 * @pre Le numéro de RAMQ de l'entraîneur doit être valide avec les infos de l'entraîneur et avoir un format valide
 * @pre Le sexe de l'entraîneur doit être 'm' ou 'M' pour homme et 'f' ou 'F' pour femme.
 * @invariant Les invariants de l'entraîneur sont les mêmes que ceux d'une personne standard.
 * @invariant L'entraîneur doit également avoir un sexe valide et un numéro de RAMQ valide.
 */
Entraineur::Entraineur(std::string p_nom,std::string p_prenom,
		const util::Date& p_dateNaissance, std::string p_telephone,
		std::string p_numRAMQ, char p_sexe): Personne(p_nom, p_prenom,
				                             p_dateNaissance, p_telephone),
											 m_numRAMQ(p_numRAMQ), m_sexe(p_sexe)
{
	PRECONDITION(util::validerNumRAMQ(p_numRAMQ, p_nom, p_prenom, p_dateNaissance.reqJour(),p_dateNaissance.reqMois(),
			p_dateNaissance.reqAnnee(), p_sexe));
	util::Date dateActuelle = util::Date();
	int tempsMajeur = 18*365;
	PRECONDITION((dateActuelle-p_dateNaissance)>tempsMajeur);
	POSTCONDITION(m_numRAMQ == p_numRAMQ);
	POSTCONDITION(m_sexe == p_sexe);
	INVARIANTS();
}

/**
 * @brief Constructeur de la classe entraîneur sans paramètre d'entrée.
 * Ce constructeur permet de retourner une erreur de précondition si le constructeur vide par défaut est utilisé.
 */
Entraineur::Entraineur():Personne(),m_numRAMQ("0"),m_sexe('0')
{
	//PRECONDITION(false);
}

/**
 * @brief Méthode permettant de retourner le numéro de RAMQ de l'entraîneur.
 * @return un string représentant le numéro de RAMQ de l'entraîneur.
 */
const string& Entraineur::reqNumRAMQ() const
{
	return m_numRAMQ;
}

/**
 * @brief Méthode permettant de retourner le sexe de l'entraîneur.
 * @return un char représentant le sexe de l'entraîneur.
 */
const char& Entraineur::reqSexe() const
{
	return m_sexe;
}

/**
 * @brief Méthode permettant de retourner les informations de l'entraîneur.
 * @return un string représentant les informations de l'entraîneur.
 */
string Entraineur::reqPersonneFormate() const
{
	ostringstream os;
	os<<Personne::reqPersonneFormate();
	os<< left<< setw(24) << "Numero de RAMQ" << setfill(' ');
   	os <<": " <<m_numRAMQ << endl;
   	os<<"---------------------"<<endl;
   	return os.str();
}

/**
 * @brief Méthode permettant de créer une nouvelle instance de l'entraîneur.
 * @return un pointeur vers la nouvelle instance de l'entraîneur.
 */
Personne* Entraineur::clone() const
{
	return new Entraineur(*this);
}

/**
 * @brief Destructeur de la classe Entraineur
 */
Entraineur::~Entraineur()
{
}

/**
 * @brief Méthode permettant de vérifier les invariants de l'entraîneur
 */
void Entraineur::verifieInvariant() const
{
	INVARIANT(util::validerSexe(m_sexe));
	INVARIANT(util::validerAgeEntraineur(m_dateNaissance));
}
} /* namespace hockey */

