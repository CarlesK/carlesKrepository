/**
 * @file validationFormat.cpp
 * @brief Ce fichier comporte les fonctions permettant de valider le numéro de téléphone standard canadien au niveau national ainsi que le numéro de la RAMQ.
 * @author Jordan Longval
 * @version 1.0
 * @date 10/02/20
 */

#include "validationFormat.h"
#include <iostream>

namespace util{
// Fonctions pour valider le numéro de téléphone


/**
 * \brief Valide le format d'un numéro de téléphone pour qu'il respecte le format national canadien standard.
 * \param[in] p_telephone Un string contenant le numéro de téléphone à valider.
 * \pre p_telephone doit être une variable std::string.
 * \return un bool qui est vrai lorsque le numéro respecte le format  et faux si ce n'est pas le cas.
 */
bool validerTelephone(const std::string& p_telephone)
{
	bool conditionsAtteintes = false;
	if(verificationLongueurTel(p_telephone) != 0)
	{
		if(verificationEspaceTrait(p_telephone) != 0)
		{
			if(verificationChiffres(p_telephone) != 0)
			{
				if(verificationIndicatif(p_telephone) != 0)
				{
					conditionsAtteintes = true;
				}
			}

		}
	}
	return conditionsAtteintes;

}

/**
 * \brief Vérifie que le string du numéro de téléphone est de la bonne longueur
 * \param[in] p_telephone Un string contenant le numéro de téléphone à valider.
 * \pre p_telephone doit être une variable std::string.
 * \return un bool qui est vrai lorsque le numéro est de la bonne longueur et faux si ce n'est pas le cas.
 */
bool verificationLongueurTel(const std::string& p_telephone)
{
	bool conditionLongueurAtteinte = false;
	if(p_telephone.length() == LONGUEUR_NUMERO_TEL)
	{
		conditionLongueurAtteinte = true;
	}
	return conditionLongueurAtteinte;
}

/**
 * @brief Vérifie que le numéro contient un espace et un trait et qu'ils sont aux bons endroits
 * @param[in] p_telephone Un string contenant le numéro de téléphone à valider.
 * @pre p_telephone doit être une variable std::string qui a passé toutes les validations des fonctions précédentes.
 * @return un bool qui est vrai lorsque l'espace et le trait sont présents et aux bons endroits
 * et faux si ce n'est pas le cas.
 */
bool verificationEspaceTrait(const std::string& p_telephone)
{
	bool conditionEspaceTraitAtteinte = false;
	if(p_telephone[POSITION_ESPACE_TEL]== ' ' && p_telephone[POSITION_TRAIT_TEL] == '-')
	{
		conditionEspaceTraitAtteinte = true;
	}
	return conditionEspaceTraitAtteinte;
}

/**
 * \brief Vérifie que le numéro ne contient que des chiffres (à l'exception de l'espace et du trait)
 * \param[in] p_telephone Un string contenant le numéro de téléphone à valider.
 * \pre p_telephone doit être une variable std::string qui a passé toutes les validations des fonctions précédentes.
 * \return un bool qui est vrai lorsque le numéro ne contient que des chiffres
 * et faux si ce n'est pas le cas.
 */
bool verificationChiffres(const std::string& p_telephone)
{
	bool conditionChiffres = true;
	std::string p_telephone_court = p_telephone;
				p_telephone_court.erase(POSITION_ESPACE_TEL,1);
				p_telephone_court.erase(POSITION_TRAIT_TEL-1,1);// -1 pour le erase précédent
	for(unsigned int i=0;i < p_telephone_court.length();i++)
				{
					conditionChiffres = conditionChiffres &&
							std::isdigit(p_telephone_court[i]);
				}
	return conditionChiffres;
}

/**
 * \brief Vérifie que l'indicatif du numéro est un indicatif valide.
 * Pour ce faire le programme vérifie dans un tableau d'indicatifs acceptés INDICATIFS_ACCEPTES[]
 * ou encore accepte l'indicatif s'il commence par un 9.
 * \param[in] p_telephone Un string contenant le numéro de téléphone à valider.
 * \pre p_telephone doit être une variable std::string qui a passé toutes les validations des fonctions précédentes.
 * \return un bool qui est vrai lorsque le numéro a un indicatif valide.
 * et faux si ce n'est pas le cas.
 */
bool verificationIndicatif(const std::string& p_telephone)
{
	bool conditionIndicatif = false;
	std::string indicatif = p_telephone.substr(0, LONGUEUR_INDICATIF);
	if(indicatif[0] == INDICATIF_PAYANT)
	{
		conditionIndicatif = true;
	}
	else
	{
		for(unsigned int i = 0; i < (sizeof(INDICATIFS_ACCEPTES)/sizeof(INDICATIFS_ACCEPTES[0])); i++)
		{
			conditionIndicatif = (conditionIndicatif || indicatif == INDICATIFS_ACCEPTES[i]);
		}
	}
	return conditionIndicatif;
}


// Fonction pour valider le numéro de RAMQ

/**
 * \brief Vérifie qu'un numéro de RAMQ fourni sous forme de string respecte le format standard
 * et qu'il concorde avec les autres informations fournies. Le format standard est les suivant
 * NNNP AAMM JJXX où NN sont les trois premières lettres du nom de famille de la personne en Maj,
 * P est la première lettre du prénom de la personne en Maj,
 * AA sont les deux derniers chiffres de l'année de naissance de la personne
 * MM sont les chiffres du mois de naissance de la personne
 * JJ sont les chiffres du jour de naissance de la personne
 * XX est un code administratif dont on ne connait pas la valeur.
 * \param[in] p_numero Un string contenant le numéro de RAMQ à valider
 * \param[in] p_nom Un string contenant le nom de la personne
 * \param[in] p_prenom Un string contenant le prenom de la personne
 * \param[in] p_jourNaissance un entier représentant le jour de naissance de la personne
 * \param[in] p_moisNaissance un entier représentant le mois de naissance de la personne
 * \param[in] p_anneeNaissance un entier représentant les deux derniers chiffres de l'année de naissance de la personne
 * \param[in] p_sexe un charactère représentant le sexe de la personne
 * \pre les valeurs p_nom à p_sex doivent être valides. les valeurs valides de p_sex sont 'm','M',pour homme
 * et 'f','F', pour femme.
 * \return un bool qui est vrai lorsque le numéro de RAMQ est valide.
 * et faux si ce n'est pas le cas.
 */
bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom, const
std::string& p_prenom, int p_jourNaissance, int p_moisNaissance, int
p_anneeNaissance, char p_sexe)
{
	bool conditionsAtteintes = false;
	if(verificationLongueurRAMQ(p_numero) != 0)
	{
		if(verificationPositionEspacesRAMQ(p_numero) != 0)
		{
			if(verificationNomRAMQ(p_numero, p_nom) != 0)
			{
				if(verificationPrenomRAMQ(p_numero, p_prenom) != 0)
				{
					if(verificationAnneeRAMQ(p_numero, p_anneeNaissance) != 0)
					{
						if(verificationMoisRAMQ(p_numero, p_moisNaissance, p_sexe) != 0)
						{
							if(verificationJourRAMQ(p_numero, p_jourNaissance) != 0)
							{
								conditionsAtteintes = true;
							}
						}
					}
				}
			}
		}
	}

	return conditionsAtteintes;
}

/**
 * \brief Vérifie que le numéro de la RAMQ fournie est de la bonne longueur.
 * \param[in] p_numero Le string du numéro de la RAMQ fourni.
 * \pre p_numero doit être un string
 * \return un bool qui est vrai lorsque le numéro est de la bonne longueur
 * et faux si ce n'est pas le cas.
 */
bool verificationLongueurRAMQ(const std::string& p_numero)
{
	bool conditionLongueurAtteinte = false;
		if(p_numero.length() == LONGUEUR_NUMERO_RAMQ)
		{
			conditionLongueurAtteinte = true;
		}
		return conditionLongueurAtteinte;
}

/**
 * \brief Vérifie que le numéro de la RAMQ fournie possède deux espaces qui sont aux bons endroits
 * \param[in] p_numero Le string du numéro de la RAMQ fourni
 * \pre p_numero doit être un string
 * \return un bool qui est vrai lorsque les espaces sont présents et aux bons endroits
 * et faux si ce n'est pas le cas.
 */
bool verificationPositionEspacesRAMQ(const std::string& p_numero)
{
	bool conditionPositionEspaces = false;
		if(p_numero[POSITION_ESPACES_RAMQ[0]]== ' ' &&
				p_numero[POSITION_ESPACES_RAMQ[1]] == ' ')
		{
			conditionPositionEspaces = true;
		}
	return conditionPositionEspaces;
}

/**
 * \brief Vérifie que le numéro de la RAMQ fournie concorde avec le nom de la personne
 * \param[in] p_numero Le string du numéro de la RAMQ fourni
 * \param[in] p_nom un string contenant le nom de la personne
 * \pre p_numero doit être un string
 * \pre p_nom doit être un string et le nom doit être valide.
 * \return un bool qui est vrai lorsque le numéro de la RAMQ concorde avec le nom de la personne
 * et faux si ce n'est pas le cas.
 */
bool verificationNomRAMQ(const std::string& p_numero, const std::string& p_nom)
{
	bool conditionNom = false;
	std::string LettresNom = transfoMajuscule(p_nom.substr(0,NB_LETTRES_NOM));
	if(LettresNom == p_numero.substr(POS_LETTRES_NOM,NB_LETTRES_NOM))
	{
		conditionNom = true;
	}
	return conditionNom;
}

/**
 * \brief Vérifie que le numéro de la RAMQ fournie concorde avec le prénom de la personne
 * \param[in] p_numero Le string du numéro de la RAMQ fourni
 * \param[in] p_prenom un string contenant le nom de la personne
 * \pre p_numero doit être un string
 * \pre p_prenom doit être un string et le prenom doit être valide.
 * \return un bool qui est vrai lorsque le numéro de la RAMQ concorde avec le prenom de la personne
 * et faux si ce n'est pas le cas.
 */
bool verificationPrenomRAMQ(const std::string& p_numero, const std::string& p_prenom)
{
	bool conditionPrenom = false;
	std::string LettresPrenom = transfoMajuscule(p_prenom.substr(0,NB_LETTRES_PRENOM));
	if(LettresPrenom == p_numero.substr(POS_LETTRE_PRENOM, NB_LETTRES_PRENOM))
	{
		conditionPrenom = true;
	}
	return conditionPrenom;
}

/**
 * \brief Vérifie que le numéro de la RAMQ fournie concorde avec l'année de naissance de la personne
 * \param[in] p_numero Le string du numéro de la RAMQ fourni
 * \param[in] p_anneeNaissance un int contenant l'annee de naissance de la personne
 * \pre p_numero doit être un string
 * \pre p_anneeNaissance doit être un int et l'année de naissance doit être valide.
 * \return un bool qui est vrai lorsque le numéro de la RAMQ concorde avec l'année de naissance de la personne
 * et faux si ce n'est pas le cas.
 */
bool verificationAnneeRAMQ(const std::string& p_numero, const int p_anneeNaissance)
{
	bool conditionAnneeRAMQ = false;
	int anneeNumRAMQ = std::stoi(p_numero.substr(POS_ANNEE, LONGUEUR_ANNEE));
	if((p_anneeNaissance%VALEUR_DE_COUPE) == anneeNumRAMQ)//VALEUR_DE_COUPE = 100 donc permet de garder
		                                                  // les deux derniers chiffres de l'année de naissance
	{
		conditionAnneeRAMQ = true;
	}
	return conditionAnneeRAMQ;
}

/**
 * \brief Vérifie que le numéro de la RAMQ fournie concorde avec le mois de naissance de la personne
 * \param[in] p_numero Le string du numéro de la RAMQ fourni
 * \param[in] p_moisNaissance un int contenant le mois de naissance de la personne
 * \param[in] p_sexe un char représentant le sexe de la personne.
 * \pre p_numero doit être un string
 * \pre p_moisNaissance doit être un int et le mois de naissance doit être valide.
 * \pre p_sexe doit être un char valant 'm','M','f' ou 'F' et le sexe de la personne doit être valide.
 * \return un bool qui est vrai lorsque le numéro de la RAMQ concorde avec le mois de naissance de la personne
 * et faux si ce n'est pas le cas.
 */
bool verificationMoisRAMQ(const std::string& p_numero, const int p_moisNaissance,  char& p_sexe)
{
	bool conditionMoisRAMQ = false;
	int moisNumRAMQ = std::stoi(p_numero.substr(POS_MOIS, LONGUEUR_MOIS));
	if(p_sexe >= DEBUT_MINUSCULE)//si minuscule
	{
		p_sexe += CHANGEMENT_MAJUSCULE;
	}
	if(p_sexe == 'F')
	{
		if(p_moisNaissance+AJOUT_FEMME == moisNumRAMQ)
		{
			conditionMoisRAMQ = true;
		}
	}
	if(p_sexe == 'M')
	{
		if(p_moisNaissance == moisNumRAMQ)
		{
			conditionMoisRAMQ = true;
		}
	}
	return conditionMoisRAMQ;
}

/**
 * \brief Vérifie que le numéro de la RAMQ fournie concorde avec le jour de naissance de la personne
 * \param[in] p_numero Le string du numéro de la RAMQ fourni
 * \param[in] p_jourNaissance un int contenant le jour de naissance de la personne
 * \pre p_numero doit être un string
 * \pre p_jourNaissance doit être un int et le jour de naissance doit être valide.
 * \return un bool qui est vrai lorsque le numéro de la RAMQ concorde avec le jour de naissance de la personne
 * et faux si ce n'est pas le cas.
 */
bool verificationJourRAMQ(const std::string& p_numero, int p_jourNaissance)
{
	bool conditionJourRAMQ = false;
		int jourNumRAMQ = std::stoi(p_numero.substr(POS_JOUR, LONGUEUR_JOUR));
		if(p_jourNaissance == jourNumRAMQ)
		{
			conditionJourRAMQ = true;
		}
		return conditionJourRAMQ;
}

/**
 * \brief Fonction qui prend un string en entrée et donne en sortie un string majuscule du string d'entrée.
 * \param[in] p_chaineAChanger un string que l'on veut mettre complètement en majuscule
 * \pre p_chaineAChanger ne doit contenir que des lettres de a à z ou A à Z.
 * \return un string contenant la version majuscule de la chaine à changer.
 */
std::string transfoMajuscule(const std::string& p_chaineAChanger)
{
	std::string chaineDeSortie = "";
	for(unsigned int i = 0; i < p_chaineAChanger.length(); i++)
	{
		if(p_chaineAChanger[i]<DEBUT_MINUSCULE)//si la lettre est déjà en maj.
		{
			chaineDeSortie += p_chaineAChanger[i];
		}
		else
		{
			chaineDeSortie += p_chaineAChanger[i]+CHANGEMENT_MAJUSCULE;
		}

	}
	return chaineDeSortie;
}

/**
 * \brief Vérifie que le nom donné ne contient que des lettres (maj ou min) et n'est pas vide
 * \param[in] p_nom le nom à valider
 * \return un bool qui est vrai lorsque le nom de contient que des lettres (Maj ou min) et n'est pas vide
 * et faux si ce n'est pas le cas.
 */
bool validerFormatNom(const std::string& p_nom)
{
	bool conditionNom = true;
	if (p_nom == "")
	{
		conditionNom = false;
	}
	else
	{
		for(unsigned int i = 0; i < p_nom.length(); i++)
		{
			if(!((p_nom[i] >= 'A' && p_nom[i] <= 'Z') || (p_nom[i] >= 'a' && p_nom[i] <= 'z')))
			{
				  conditionNom = false;
			}
		}
	}
	return conditionNom;
}

/**
 * \brief Vérifie que le sexe donné en entrée est soit 'M','m','F' ou 'f'.
 * \param[in] p_sexe le sexe à valider
 * \return un bool qui est vrai lorsque les conditions sont satisfaites.
 */
bool validerSexe(const char& p_sexe)
{
	bool conditionValSexe = false;
	if(p_sexe=='M'||p_sexe == 'm'||p_sexe == 'F'||p_sexe == 'f')
	{
		conditionValSexe = true;
	}
	return conditionValSexe;
}

/**
 * \brief Vérifie que la position en entrée est soit "centre","ailier","défenseur" ou "gardien"
 * \param[in] p_position la position à valider
 * \return un bool qui est vrai lorsque les conditions sont satisfaites.
 */
bool validerPosition(const std::string& p_position)
{
	bool conditionValPosition = false;
	if(p_position == "ailier"||p_position == "centre"||
	   p_position == "défenseur"||p_position == "gardien")
	{
		conditionValPosition = true;
	}
	return conditionValPosition;
}

/**
 * \brief Vérifie que l'âge en entrée est supérieur à 18 ans
 * \param[in] p_dateNaissanceEntraineur la date de naissance à valider
 * \return un bool qui est vrai lorsque les conditions sont satisfaites.
 */
bool validerAgeEntraineur(const Date& p_dateNaissanceEntraineur)
{
	bool conditionValAgeEntraineur = false;
	Date tempsActuel = Date();
	int agePersonne = tempsActuel - p_dateNaissanceEntraineur;
	if(NB_JOURS_MAJEUR<=agePersonne)
	{
		conditionValAgeEntraineur = true;
	}
	return conditionValAgeEntraineur;
}

/**
 * \brief Vérifie que l'âge en entrée est entre 15 et 17 ans
 * \param[in] p_dateNaissanceJoueur la date de naissance à valider
 * \return un bool qui est vrai lorsque les conditions sont satisfaites.
 */
bool validerAgeJoueur(const Date& p_dateNaissanceJoueur)
{
	bool conditionValAgeJoueur = false;
	Date tempsActuel = Date();
	int agePersonne = tempsActuel - p_dateNaissanceJoueur;
	if(NB_JOURS_MIN_MIDGET<=agePersonne &&
	   agePersonne<=NB_JOURS_MAX_MIDGET)
	{
		conditionValAgeJoueur = true;
	}
	return conditionValAgeJoueur;
}

}// namespace util


