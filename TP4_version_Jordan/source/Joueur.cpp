/**
 * @file : Joueur.cpp
 * @date : 2020-04-02
 * @author : etudiant
 */

#include "Joueur.h"
#include"validationFormat.h"
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
namespace hockey
{
/**
 * @brief Constructeur de la classe Joueur avec des paramètres en entrée.
 * @param [in] p_nom un string représentant le nom du joueur
 * @param [in] p_prenom un string représentant le prénom du joueur
 * @param [in] p_dateNaissance un objet Date représentant la date de naissance du joueur
 * @param [in] p_telephone un string représentant le numéro de téléphone du joueur
 * @param [in] p_position
 * @pre Tous les paramètres en entrée doivent être valide pour une personne standard.
 * @pre La position du joueur doit être "centre","ailier","gardien" ou "défenseur"
 * @invariant Les invariants d'un joueur sont les mêmes que ceux d'une personne standard.
 * @invariant Le joueur doit avoir une position valide.
 */
Joueur::Joueur(std::string p_nom, std::string p_prenom, const util::Date& p_dateNaissance,
		std::string p_telephone, std::string p_position):
		Personne(p_nom, p_prenom,p_dateNaissance, p_telephone),m_position(p_position)
{
	PRECONDITION(util::validerAgeJoueur(p_dateNaissance));
	PRECONDITION(util::validerPosition(p_position));
	POSTCONDITION(m_position == p_position);
	INVARIANTS();
}

/**
 * @brief Constructeur par défaut sans paramètres. Permet de retourner une erreur de précondition s'il est utilisé.
 */
Joueur::Joueur():Personne()
{
	//PRECONDITION(false);
}

/**
 * @brief Méthode permettant de retourner la position du joueur.
 * @return un string représentant la position du joueur
 */
const string& Joueur::reqPosition() const
{
	return m_position;
}

/**
 * @brief Méthode permettant de retourner les informations du joueur.
 * @return un string représentant les informations du joueur
 */
string Joueur::reqPersonneFormate() const
{
	ostringstream os;
	os<<Personne::reqPersonneFormate();
	os<< left<< setw(24) << "Position" << setfill(' ');
	os <<": " <<m_position << endl;
	os<<"---------------------"<<endl;
	return os.str();
}

/**
 * @brief Méthode permettant de créer une nouvelle instance du joueur.
 * @return un pointeur vers la nouvelle instance du joueur.
 */
Personne* Joueur::clone() const
{
	return new Joueur(*this);
}

/**
 * @brief Destructeur de la classe Joueur.
 */
Joueur::~Joueur()
{
}

/**
 * @brief Méthode permettant de vérifier les invariants du joueur.
 */
void Joueur::verifieInvariant() const
{
	INVARIANT(util::validerPosition(m_position));
	INVARIANT(util::validerAgeJoueur(m_dateNaissance));
}
} /* namespace hockey */


