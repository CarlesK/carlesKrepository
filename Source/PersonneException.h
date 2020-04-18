/*
 * PersonneException.h
 *
 *  Created on: 2020-04-18
 *      Author: etudiant
 */

#ifndef PERSONNEEXCEPTION_H_
#define PERSONNEEXCEPTION_H_


#include <string>
#include <stdexcept>
/**
 * \class PersonneException
 * \brief Classe de base des exceptions de contrat.
 */
class PersonneException: public std::runtime_error
{
public:
	PersonneException(const std::string& raison);
	~PersonneException() throw (){};
};



/**
 * \class AssertionException
 * \brief Classe pour la gestion des erreurs d'assertion.
 */

class PersonneDejaPresentException: public PersonneException
{
  public:
	PersonneDejaPresentException(const std::string& raison);
};

#endif /* PERSONNEEXCEPTION_H_ */
