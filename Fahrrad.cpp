/*
 * Fahrrad.cpp
 *
 *  Created on: Sep 27, 2023
 *      Author: marian
 */

#include "Fahrrad.h"

//BEGIN Constructors etc.

Fahrrad::Fahrrad()
:Fahrzeug::Fahrzeug()
{
}

Fahrrad::Fahrrad(std::string sName)
:Fahrzeug::Fahrzeug(sName)
{
}

Fahrrad::Fahrrad(std::string sName, double maxGeschwindigkeit)
:Fahrzeug::Fahrzeug(sName, maxGeschwindigkeit)
{
}

Fahrrad::~Fahrrad()
{
}

//END Constructors etc.

//BEGIN Other

double Fahrrad::dGeschwindigkeit()
{
	uint8_t dDeltaS = p_dGesamtStrecke / 20;
	p_dGeschwindigkeit = p_dMaxGeschwindigkeit * std::pow(0.9, dDeltaS);
	if(p_dGeschwindigkeit < 12)
	{
		p_dGeschwindigkeit = 12;
	}
	return p_dGeschwindigkeit;
}

//END Other




