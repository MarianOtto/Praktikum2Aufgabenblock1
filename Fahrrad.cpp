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

void Fahrrad::vSimulieren()
{
	if(dGlobaleZeit != p_dZeit)
	{
		double deltaT = dGlobaleZeit - p_dZeit;
		p_dGesamtStrecke += deltaT * p_dMaxGeschwindigkeit;
		p_dZeit = dGlobaleZeit;
		p_dGesamtZeit = dGlobaleZeit;
	}
}
