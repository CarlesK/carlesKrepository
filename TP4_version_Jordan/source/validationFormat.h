/**
 * @file validationFormat.h
 * @brief Fichier de déclaration des constantes et des fonctions pour la validation
 * @author Jordan Longval
 * @version 1.0
 * @date 10/02/20
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <iostream>
#include <string>
#include "Date.h"

namespace util{
// Constantes pour validerTelephone
static const std::string INDICATIFS_ACCEPTES[] =
			  {"403", "604", "236", "250", "778", "902",
	 	 	   "204", "506", "902", "905", "519", "289",
	 	 	   "705", "613", "807", "416", "647", "438",
	 	 	   "514", "450", "579", "418", "581", "819",
	 	 	   "973", "306", "709", "867", "800", "866",
	 	 	   "877", "888", "855"};
static const unsigned int LONGUEUR_NUMERO_TEL = 12;
static const unsigned int POSITION_ESPACE_TEL = 3;
static const unsigned int POSITION_TRAIT_TEL = 7;
static const unsigned int LONGUEUR_INDICATIF = 3;
static const char INDICATIF_PAYANT = '9';

// Fonctions pour validerTelephone
bool validerTelephone(const std::string& p_telephone);
bool verificationLongueurTel(const std::string& p_telephone);
bool verificationEspaceTrait(const std::string& p_telephone);
bool verificationChiffres(const std::string& p_telephone_court);
bool verificationIndicatif(const std::string& p_telephone);

// Constantes pour validerNumRAMQ
static const unsigned int LONGUEUR_NUMERO_RAMQ = 14;
static const unsigned int POSITION_ESPACES_RAMQ[] = {4, 9};
static const int CHANGEMENT_MAJUSCULE = (char)'A'-(char)'a'; // pour passer de min a maj
static const char DEBUT_MINUSCULE = 'a';
static const int NB_LETTRES_NOM = 3;
static const int POS_LETTRES_NOM = 0;
static const int NB_LETTRES_PRENOM = 1;
static const int POS_LETTRE_PRENOM = 3;
static const int POS_ANNEE = 5;
static const int LONGUEUR_ANNEE = 2;
static const int VALEUR_DE_COUPE  = 100;
static const int POS_MOIS = 7;
static const int LONGUEUR_MOIS = 2;
static const int POS_JOUR = 10;
static const int LONGUEUR_JOUR = 2;
static const int AJOUT_FEMME = 50;

//Constante pour valider les dates
static const int NB_JOURS_MAJEUR = 18*365;
static const int NB_JOURS_MIN_MIDGET = 15*365;
static const int NB_JOURS_MAX_MIDGET = 17*365;
// Fonctions pour validerNumRAMQ
bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom, const
std::string& p_prenom, int p_jourNaissance, int p_moisNaissance, int
p_anneeNaissance, char p_sexe);
bool verificationLongueurRAMQ(const std::string& p_numero);
bool verificationPositionEspacesRAMQ(const std::string& p_numero);
bool verificationNomRAMQ(const std::string& p_numero, const std::string& p_nom);
bool verificationPrenomRAMQ(const std::string& p_numero, const std::string& p_prenom);
bool verificationAnneeRAMQ(const std::string& p_numero, int p_anneeNaissance);
bool verificationMoisRAMQ(const std::string& p_numero, int p_moisNaissance, char& p_sex);
bool verificationJourRAMQ(const std::string& p_numero, int p_jourNaissance);
std::string transfoMajuscule(const std::string& chaineAChanger);

// Fonction pour valider nom
bool validerFormatNom(const std::string& p_nom);

// Fonction pour valider le sexe
bool validerSexe(const char& p_sexe);

// Fonction pour valider la position
bool validerPosition(const std::string& p_position);

// Fonction pour valider l'âge des entraîneurs
bool validerAgeEntraineur(const Date& p_dateNaissanceEntraineur);

// Fonction pour valider l'âge des joueurs
bool validerAgeJoueur(const Date& p_dateNaissanceJoueur);


}// namespace util
#endif /* VALIDATIONFORMAT_H_ */
