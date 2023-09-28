/*
 * Fahrzeug.h
 *
 *  Created on: Sep 23, 2023
 *      Author: marian
 */
#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

extern double dGlobaleZeit;
class Fahrzeug
{
private:
	static int p_iMaxID;

protected:
	std::string p_sName;
	const int p_iID;
	const double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	double p_dGesamtVerbrauch;


public:
	Fahrzeug();
	Fahrzeug(std::string sName);
	Fahrzeug(std::string sName, double maxGeschwindigkeit);
	virtual ~Fahrzeug();

	virtual void vKopf() const;
	virtual void vAusgeben() const;
	virtual void vSimulieren();
	virtual double dTanken(double dMenge);
	bool EpsilonEquals(double dNum1, double dNum2);
};



#endif /* FAHRZEUG_H_ */
