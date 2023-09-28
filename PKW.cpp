/*
 * PKW.cpp
 *
 *  Created on: Sep 27, 2023
 *      Author: marian
 */

#include "PKW.h"

PKW::PKW()
:Fahrzeug::Fahrzeug(),
 p_dVerbrauch(4.5),
 p_dTankvolumen(55),
 p_dTankinhalt(p_dTankvolumen / 2)
 {
	std::cout <<
			"created | name: " 	<< this->	p_sName <<
			" | ID: " 			<< this-> 	p_iID <<
			" | MaxGeschw.: " 	<< this->	p_dMaxGeschwindigkeit <<
			" | Volumen: " 		<< this->	p_dTankvolumen <<
			" | Verbrauch: " 	<< this->	p_dVerbrauch <<
			" | Inhalt: " 		<< this->	p_dTankinhalt <<
			std::endl;
}

PKW::PKW(std::string sName)
:Fahrzeug::Fahrzeug(sName),
 p_dVerbrauch(4.5),
 p_dTankvolumen(55),
 p_dTankinhalt(p_dTankvolumen / 2)
 {
	std::cout <<
			"created | name: " 	<< this->	p_sName <<
			" | ID: " 			<< this-> 	p_iID <<
			" | MaxGeschw.: " 	<< this->	p_dMaxGeschwindigkeit <<
			" | Volumen: " 		<< this->	p_dTankvolumen <<
			" | Verbrauch: " 	<< this->	p_dVerbrauch <<
			" | Inhalt: " 		<< this->	p_dTankinhalt <<
			std::endl;
}

PKW::PKW(std::string sName, double dmaxGeschwindigkeit)
:Fahrzeug::Fahrzeug(sName, dmaxGeschwindigkeit),
 p_dVerbrauch(4.5 ),
 p_dTankvolumen(55),
 p_dTankinhalt(p_dTankvolumen / 2)
{
	std::cout <<
			"created | name: " 	<< this->	p_sName <<
			" | ID: " 			<< this-> 	p_iID <<
			" | MaxGeschw.: " 	<< this->	p_dMaxGeschwindigkeit <<
			" | Volumen: " 		<< this->	p_dTankvolumen <<
			" | Verbrauch: " 	<< this->	p_dVerbrauch <<
			" | Inhalt: " 		<< this->	p_dTankinhalt <<
			std::endl;
}

PKW::PKW(std::string sName, double dmaxGeschwindigkeit, double dTankvolumen, double dVerbrauch)
:Fahrzeug::Fahrzeug(sName, dmaxGeschwindigkeit),
 p_dVerbrauch(dVerbrauch),
 p_dTankvolumen(dTankvolumen),
 p_dTankinhalt(dTankvolumen / 2)
{
	std::cout <<
			"created | name: " 	<< this->	p_sName <<
			" | ID: " 			<< this-> 	p_iID <<
			" | MaxGeschw.: " 	<< this->	p_dMaxGeschwindigkeit <<
			" | Volumen: " 		<< this->	p_dTankvolumen <<
			" | Verbrauch: " 	<< this->	p_dVerbrauch <<
			" | Inhalt: " 		<< this->	p_dTankinhalt <<
			std::endl;
}

PKW::~PKW()
{
}

void PKW::vKopf() const
{
	Fahrzeug::vKopf();
	std::cout <<
		std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) <<
		std::setw(11) << "Inhalt " <<
		std::setw(18) << "Gesamtverbrauch ";
}

void PKW::vAusgeben() const
{
	Fahrzeug::vAusgeben();
	std::cout <<
		std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) <<
		std::setw(11) << p_dTankinhalt <<
		std::setw(18) << p_dGesamtVerbrauch;
}

void PKW::vSimulieren()
{
	if(dGlobaleZeit != p_dZeit)
	{
		if(!EpsilonEquals(p_dTankinhalt, 0))
		{
		double dDeltaT = dGlobaleZeit - p_dZeit;
		double dDeltaS = dDeltaT * p_dMaxGeschwindigkeit;
		p_dGesamtStrecke += dDeltaS;
		p_dTankinhalt -= p_dVerbrauch * dDeltaS / 100;
		p_dGesamtVerbrauch += p_dVerbrauch * dDeltaS / 100;
		p_dZeit = dGlobaleZeit;
		p_dGesamtZeit = dGlobaleZeit;
		}
	}
}

double PKW::dTanken(double dMenge = std::numeric_limits<double>::infinity())
//Defaultvalue Fixen
{
	if(dMenge > p_dTankvolumen - p_dTankinhalt)
	{
		dMenge = p_dTankvolumen - p_dTankinhalt;
	}
	p_dTankinhalt += dMenge;
	std::cout << "\n\nEs wurden " << dMenge << " Liter getankt!";
	return dMenge;
}










