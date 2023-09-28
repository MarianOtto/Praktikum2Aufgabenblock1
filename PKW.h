/*
 * PKW.h
 *
 *  Created on: Sep 27, 2023
 *      Author: marian
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"
#include <limits>

class PKW: public Fahrzeug
{
private:
	double p_dVerbrauch;
	const double p_dTankvolumen;
	double p_dTankinhalt;

public:
	PKW();
	PKW(std::string sName);
	PKW(std::string sName, double maxGeschwindigkeit);
	PKW(std::string sName, double maxGeschwindigkeit, double Tankvolumen, double Verbrauch);
	virtual ~PKW();

	void vKopf() const;
	void vAusgeben() const;
	void vSimulieren();
	double dTanken(double dMenge);
};

#endif /* PKW_H_ */
