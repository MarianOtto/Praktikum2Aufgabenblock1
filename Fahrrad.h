/*
 * Fahrrad.h
 *
 *  Created on: Sep 27, 2023
 *      Author: marian
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include "Fahrzeug.h"

class Fahrrad: public Fahrzeug
{
public:
	Fahrrad();
	Fahrrad(std::string sName);
	Fahrrad(std::string sName, double maxGeschwindigkeit);
	virtual ~Fahrrad();

	void vKopf() const;
	void vAusgeben() const;
	double dGeschwindigkeit();
};

#endif /* FAHRRAD_H_ */
