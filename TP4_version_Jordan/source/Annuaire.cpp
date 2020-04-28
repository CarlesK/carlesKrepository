/**
 * \file Annuaire.cpp
 * \brief Fichier qui contient l'implémentation de la classe Annuaire.
 * Cette classe permet de gérer les différentes personnes membre d'une équipe de hockey.
 *
 * Attributs:
 * 	- string m_nomClub: Le nom de l'équipe de hockey.
 * 	- vector<*Personne> m_vMembres: un vecteur contenant des pointeurs vers les personnes membres de l'équipe
 * 	  ajouter à l'Annuaire.
 * \author Jordan Longval
 * \version TP3
 * \date: 2020-04-02
 */

#include <sstream>
#include <iomanip>
#include "ContratException.h"
#include "Annuaire.h"

using namespace std;
namespace hockey
{

/**
 * @brief constructeur d'un objet annuaire sans paramètre. Ce constructeur permet d'initialiser une erreur de précondition
 * si le constructeur sans paramètre est utilisé.
 */
Annuaire::Annuaire()
{
	//PRECONDITION(false);
};

/**
 * @brief constructeur d'un objet annuaire avec le paramètre du nom de club.
 * @param[in] p_nomClub  Un string qui représente le nom de l'équipe de hockey que l'annuaire gère.
 * @pre p_nomClub ne doit pas être un string vide.
 * @invariant string m_nomclub doit être non vide.
 */
Annuaire::Annuaire(std::string p_nomClub):m_nomClub(p_nomClub)
{
	PRECONDITION(!(p_nomClub==""));
	POSTCONDITION(m_nomClub == p_nomClub);
	INVARIANTS();
}

/**
 * @brief retourne le nom de l'équipe hockey.
 * @return une chaîne de caractères (string) qui représente le nom de l'équipe.
 */
const string& Annuaire::reqNomClub() const
{
	return m_nomClub;
}

/**
 * @brief retourne le nom de l'équipe et les informations des membres.
 * @return une chaîne de caractères (string) qui représente les infos de l'équipe.
 */
std::string Annuaire::reqAnnuaireFormate() const
{
	ostringstream os;
	os<<"Club  : "<< m_nomClub<<endl;
	os<<"---------------------"<<endl;
	for(unsigned int i =0;i<m_vMembres.size();i++)
	{
		os<<m_vMembres[i]->reqPersonneFormate();
	}
	return os.str();
}

/**
 * @brief Constructeur de la classe annuaire qui accepte en paramètre un annuaire.
 * Ce type de constructeur permet de créer un nouvel annuaire avec les informations de l'annuaire passé en paramètre
 * @param [in] p_annuaire un annuaire valide dont le nom n'est pas un string vide
 * @pre p_annuaire doit être non vide.
 */
Annuaire::Annuaire(const Annuaire& p_annuaire)
{
	PRECONDITION(!(p_annuaire.m_nomClub==""));
	this->m_nomClub = p_annuaire.reqNomClub();
	for(unsigned int i =0; i<p_annuaire.m_vMembres.size();i++)
	{
		m_vMembres.push_back(p_annuaire.m_vMembres[i]->clone());
	}
	POSTCONDITION(this->reqAnnuaireFormate() == p_annuaire.reqAnnuaireFormate());
	INVARIANTS();
}

/**
 * @brief Surcharge de l'opérateur = permettant d'attribuer les attributs d'un annuaire à un autre.
 * @param [in] p_annuaire un annuaire valide dont le nom n'est pas un string vide
 * @pre p_annuaire doit être non vide.
 * @return l'annuaire initiale avec ses attributs changés pour ceux de p_annuaire.
 */
Annuaire& Annuaire::operator =(const Annuaire& p_annuaire)
{
	PRECONDITION(!(p_annuaire.m_nomClub==""));
	if (this != & p_annuaire)
	{
		m_nomClub = p_annuaire.reqNomClub();
		for(unsigned int i =0; i<m_vMembres.size();i++)
						{
							delete m_vMembres[i];
						}
		m_vMembres.clear();
		for(unsigned int i =0; i<p_annuaire.m_vMembres.size();i++)
			{
				m_vMembres.push_back(p_annuaire.m_vMembres[i]->clone());
			}
	}
	return *this;
}

/**
 * @brief fonction permettant d'ajouter le pointeur d'une personne à l'annuaire.
 * @param [in] p_personne une personne que l'on veut ajouter à l'annuaire.
 */
void Annuaire::ajouterPersonne(const Personne& p_personne)
{
	m_vMembres.push_back(p_personne.clone());
}

/**
 * @brief fonction permettant de vérifier l'invariant de la classe annuaire.
 */
void Annuaire::verifieInvariant() const
{
	INVARIANT(!(m_nomClub==""));
}

/**
 * @brief Destructeur de la classe annuaire.
 * Lors de la destruction de l'objet, les personnes membres sont également détruits.
 */
Annuaire::~Annuaire()
{
	for(unsigned int i =0; i<m_vMembres.size();i++)
				{
					delete m_vMembres[i];
				}
	m_vMembres.clear();
}

} /* namespace hockey */
