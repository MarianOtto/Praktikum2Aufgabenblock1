/*
 * PKW.h
 *
 *  Created on: Sep 27, 2023
 *      Author: marian
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"

class PKW: public Fahrzeug
{
public:
	PKW();
	PKW(std::string sName);
	PKW(std::string sName, double maxGeschwindigkeit);
	virtual ~PKW();

	void vKopf() const;
	void vAusgeben() const;
	void vSimulieren();
};

#endif /* PKW_H_ */
