/*
 * Fahrzeug.cpp
 *
 *  Created on: Sep 23, 2023
 *      Author: marian
 */



#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 0;

//BEGIN Constructors

Fahrzeug::Fahrzeug()
:p_sName("0"),
 p_iID(++Fahrzeug::p_iMaxID),
 p_dMaxGeschwindigkeit(10),
 p_dGesamtStrecke(0),
 p_dGesamtZeit(0),
 p_dZeit(0),
 p_dGesamtVerbrauch(0),
 p_dGeschwindigkeit(p_dMaxGeschwindigkeit)
{
#ifdef DEBUG
	std::cout <<
			"created | name: " 	<< this->	p_sName <<
			" | ID: " 			<< this-> 	p_iID <<
			" | MaxGeschw.: " 	<< this->	p_dMaxGeschwindigkeit <<
			std::endl;
#endif
}

Fahrzeug::Fahrzeug(std::string sName)
:p_sName(sName),
 p_iID(++Fahrzeug::p_iMaxID),
 p_dMaxGeschwindigkeit(10),
 p_dGesamtStrecke(0),
 p_dGesamtZeit(0),
 p_dZeit(0),
 p_dGesamtVerbrauch(0),
 p_dGeschwindigkeit(p_dMaxGeschwindigkeit)
{
#ifdef DEBUG
	std::cout <<
			"created | name: " 	<< this->	p_sName <<
			" | ID: " 			<< this-> 	p_iID <<
			" | MaxGeschw.: " 	<< this->	p_dMaxGeschwindigkeit <<
			std::endl;
#endif
}

Fahrzeug::Fahrzeug(std::string sName, double dmaxGeschwindigkeit)
:p_sName(sName),
 p_iID(++Fahrzeug::p_iMaxID),
 p_dMaxGeschwindigkeit(dmaxGeschwindigkeit < 0 ? abs(dmaxGeschwindigkeit) : dmaxGeschwindigkeit),
 p_dGesamtStrecke(0),
 p_dGesamtZeit(0),
 p_dZeit(0),
 p_dGesamtVerbrauch(0),
 p_dGeschwindigkeit(p_dMaxGeschwindigkeit)
{
#ifdef DEBUG
	std::cout <<
			"created | name: " 	<< this->	p_sName <<
			" | ID: " 			<< this-> 	p_iID <<
			" | MaxGeschw.: " 	<< this->	p_dMaxGeschwindigkeit <<
			std::endl;
#endif
}

Fahrzeug::~Fahrzeug()
{
#ifdef DEBUG
	std::cout <<
			"Destroyed | name: " 	<< this-> p_sName <<
			" | ID: "				<< this-> p_iID <<
			std::endl;
#endif
}

//END Constructors etc.

//BEGIN Getters

double Fahrzeug::dGetZeit() const
{
	return p_dZeit;
}

double Fahrzeug::dGetGesamtStrecke() const
{
	return p_dGesamtStrecke;
}

std::string Fahrzeug::sGetName() const
{
	return p_sName;
}

double Fahrzeug::dGetMaxGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}
//END Getters

//BEGIN Setters

void Fahrzeug::setName(std::string Name)
{
	p_sName = Name;
}

void Fahrzeug::setMaxGeschwindigkeit(double MaxGeschwindigkeit)
{
	p_dMaxGeschwindigkeit = MaxGeschwindigkeit;
}

//END Setters
//BEGIN Operator Overload

bool Fahrzeug::operator<(const Fahrzeug& Fahrzeug2)
{
	if(p_dGesamtStrecke < Fahrzeug2.dGetGesamtStrecke())
	{
		return true;
	}
	return false;
}

void Fahrzeug::operator=(const Fahrzeug& Fahrzeug)
{
	p_dMaxGeschwindigkeit = Fahrzeug.dGetMaxGeschwindigkeit();
	p_sName = Fahrzeug.sGetName();
}

//END Operator Overload

//BEGIN Other

void Fahrzeug::vKopf() const
{
	std::cout <<
		std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) <<
		std::setw( 4) << "ID" << " " <<
		std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left) <<
		std::setw(10) << "Name" <<
		std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::fixed <<
		std::setw(20) << "MaxGeschwindigkeit" <<
		std::setw(20) << "Mom.Geschwindigkeit" <<
		std::setw(15) << "GesamtStrecke";

}

void Fahrzeug::vAusgeben() const
{
	std::cout.precision(2);
	std::cout <<
		std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) <<
		std::setw( 4) << p_iID << " " <<
		std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left) <<
		std::setw(10) << p_sName <<
		std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::fixed <<
		std::setw(20) << p_dMaxGeschwindigkeit <<
		std::setw(20) << p_dGeschwindigkeit <<
		std::setw(15) << p_dGesamtStrecke;
}

void Fahrzeug::vSimulieren()
{
	if(dGlobaleZeit != p_dZeit)
	{
		p_dGeschwindigkeit = dGeschwindigkeit();
		double deltaT = dGlobaleZeit - p_dZeit;
		p_dGesamtStrecke += deltaT * p_dGeschwindigkeit;
		p_dZeit = dGlobaleZeit;
		p_dGesamtZeit = dGlobaleZeit;
	}
}

double Fahrzeug::dTanken(double dMenge)
{
	return 0;
}

bool Fahrzeug::bEquals(double dNum1, double dNum2)
{
	if(abs(dNum1 - dNum2) < std::pow(10,-25.0))
	{
		return true;
	}
	return false;
}

double Fahrzeug::dGeschwindigkeit()
{

	return p_dMaxGeschwindigkeit;
}

//END Other

std::ostream& operator<<(std::ostream& ostr, const Fahrzeug& Fahrzeug)
{
	Fahrzeug.vAusgeben();
	return ostr;
}

