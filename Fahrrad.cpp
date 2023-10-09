/*
 * Fahrrad.cpp
 *
 *  Created on: Sep 27, 2023
 *      Author: marian
 */

#include "Fahrrad.h"

Fahrrad::Fahrrad()
:Fahrzeug::Fahrzeug()
{
	std::cout << "created | name: " << this->p_sName << " | ID: " << this->p_iID << std::endl;
}

Fahrrad::Fahrrad(std::string sName)
:Fahrzeug::Fahrzeug(sName)
{
	std::cout << "created | name: " << this->p_sName << " | ID: " << this->p_iID << std::endl;
}

Fahrrad::Fahrrad(std::string sName, double maxGeschwindigkeit)
:Fahrzeug::Fahrzeug(sName, maxGeschwindigkeit)
{
	std::cout << "created | name: " << this->p_sName << " | ID: " << this-> p_iID << " | MaxGeschw.: " << this->p_dMaxGeschwindigkeit << std::endl;
}

Fahrrad::~Fahrrad()
{
}

void Fahrrad::vKopf() const
{
	Fahrzeug::vKopf();
}

void Fahrrad::vAusgeben() const
{
	Fahrzeug::vAusgeben();
}

double Fahrrad::dGeschwindigkeit()
{
	int dDeltaS = p_dGesamtStrecke / 20;
	p_dGeschwindigkeit = p_dMaxGeschwindigkeit * std::pow(0.9, dDeltaS);
	if(p_dGeschwindigkeit < 12)
	{
		p_dGeschwindigkeit = 12;
	}
	return p_dGeschwindigkeit;
}






