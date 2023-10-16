/*
 * Fahrzeug.h
 *
 *  Created on: Sep 23, 2023
 *      Author: marian
 */
#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
#define DEBUG

#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <memory>

extern double dGlobaleZeit;
class Fahrzeug
{
private:
	static int p_iMaxID;

protected:
	std::string p_sName;
	const int p_iID;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	double p_dGesamtVerbrauch;
	double p_dGeschwindigkeit;


public:
	//Constructor etc.
	Fahrzeug();
	Fahrzeug(std::string sName);
	Fahrzeug(std::string sName, double maxGeschwindigkeit);
	virtual ~Fahrzeug();
	Fahrzeug(const Fahrzeug&) = delete;

	//Getter
	double getdZeit() const;
	double getdGesamtStrecke() const;
	std::string getsName() const;
	double getdMaxGeschwindigkeit() const;

	//Setters
	void setsName(std::string Name);
	void setdMaxGeschwindigkeit(double MaxGeschwindigkeit);

	//Operator Overload
	virtual bool operator<(const Fahrzeug& Fahrzeug);
	void operator=(const Fahrzeug& Fahrzeug);

	//Other
	virtual void vKopf() const;
	virtual void vAusgeben() const;
	virtual void vSimulieren();
	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());
	bool EpsilonEquals(double dNum1, double dNum2);
	virtual double dGeschwindigkeit();
};



#endif /* FAHRZEUG_H_ */
