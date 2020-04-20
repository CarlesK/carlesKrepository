/*
 * PersonneException.cpp
 *
 *  Created on: 2020-04-18
 *      Author: etudiant
 */

#include "PersonneException.h"
#include <sstream>

using namespace std;
/**
 * \brief Constructeur de la classe de base PersonneException
 * \param[in] raison Message décrivant l'erreur
 */
PersonneException::PersonneException(const std::string& raison) : std::runtime_error(raison){}

/**
 * \brief Constructeur de la classe PersonneDejaPresentException \n
 *    	Le constructeur public PersonneDejaPresentException(...)initialise
 *     	sa classe de base PersonneException.
 * \param[in] raison : raison  echec du test
 *
 */


PersonneDejaPresentException::PersonneDejaPresentException(const std::string& raison)
: PersonneException(raison){}

