/*
 * Fahrzeug.cpp
 *
 *  Created on: Sep 23, 2023
 *      Author: marian
 */



#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 0;

Fahrzeug::Fahrzeug()
:p_sName("0"),
 p_iID(++Fahrzeug::p_iMaxID),
 p_dMaxGeschwindigkeit(10),
 p_dGesamtStrecke(0),
 p_dGesamtZeit(0),
 p_dZeit(0)
{
	std::cout << "created | name: " << this->p_sName << " | ID: " << this->p_iID << std::endl;
}

Fahrzeug::Fahrzeug(std::string sName)
:p_sName(sName),
 p_iID(++Fahrzeug::p_iMaxID),
 p_dMaxGeschwindigkeit(10),
 p_dGesamtStrecke(0),
 p_dGesamtZeit(0),
 p_dZeit(0)
{
	std::cout << "created | name: " << this->p_sName << " | ID: " << this->p_iID << std::endl;
}

Fahrzeug::Fahrzeug(std::string sName, double maxGeschwindigkeit)
:p_sName(sName),
 p_iID(++Fahrzeug::p_iMaxID),
 p_dMaxGeschwindigkeit(maxGeschwindigkeit < 0 ? abs(maxGeschwindigkeit) : maxGeschwindigkeit),
 p_dGesamtStrecke(0),
 p_dGesamtZeit(0),
 p_dZeit(0)
{
	std::cout << "created | name: " << this->p_sName << " | ID: " << this-> p_iID << " | MaxGeschw.: " << this->p_dMaxGeschwindigkeit << std::endl;
}

Fahrzeug::~Fahrzeug()
{
}

void Fahrzeug::vKopf() const
{
	std::cout <<
	std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) <<
	std::setw( 4) << "ID" << " " <<
	std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left) <<
	std::setw(10) << std::setprecision(2) << "Name" <<
	std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::fixed <<
	std::setw(20) << std::setprecision(2) << "MaxGeschwindigkeit" <<
	std::setw(15) << "GesamtStrecke" <<
	"\n";
	int a = 1 + 4 + 10 + 20 + 15;
	for(int i = 0; i < a; i++)
	{
		std::cout << "-";
	}
}

void Fahrzeug::vAusgeben() const
{
	std::cout.precision(2);
	std::cout <<
	std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) <<
	std::setw( 4) << p_iID << " " <<
	std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left) <<
	std::setw(10) << std::setprecision(2) << p_sName <<
	std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::fixed <<
	std::setw(20) << std::setprecision(2) << p_dMaxGeschwindigkeit <<
	std::setw(15) << p_dGesamtStrecke;
}

void Fahrzeug::vSimulieren()
{
	if(dGlobaleZeit != p_dZeit)
	{
		double deltaT = dGlobaleZeit - p_dZeit;
		p_dGesamtStrecke += deltaT * p_dMaxGeschwindigkeit;
		p_dZeit = dGlobaleZeit;
		p_dGesamtZeit = dGlobaleZeit;
	}
}




