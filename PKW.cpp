/*
 * PKW.cpp
 *
 *  Created on: Sep 27, 2023
 *      Author: marian
 */

#include "PKW.h"

PKW::PKW()
:Fahrzeug::Fahrzeug()
{
	std::cout << "created | name: " << this->p_sName << " | ID: " << this->p_iID << std::endl;
}

PKW::PKW(std::string sName)
:Fahrzeug::Fahrzeug(sName)
{
	std::cout << "created | name: " << this->p_sName << " | ID: " << this->p_iID << std::endl;
}

PKW::PKW(std::string sName, double maxGeschwindigkeit)
:Fahrzeug::Fahrzeug(sName, maxGeschwindigkeit)
{
	std::cout << "created | name: " << this->p_sName << " | ID: " << this-> p_iID << " | MaxGeschw.: " << this->p_dMaxGeschwindigkeit << std::endl;
}

PKW::~PKW()
{
}

void PKW::vKopf() const
{
	Fahrzeug::vKopf();
}

void PKW::vAusgeben() const
{
	Fahrzeug::vAusgeben();
}

void PKW::vSimulieren()
{
	if(dGlobaleZeit != p_dZeit)
	{
		double deltaT = dGlobaleZeit - p_dZeit;
		p_dGesamtStrecke += deltaT * p_dMaxGeschwindigkeit;
		p_dZeit = dGlobaleZeit;
		p_dGesamtZeit = dGlobaleZeit;
	}
}
