/*
 * main.cpp
 *
 *  Created on: Sep 23, 2023
 *      Author: marian
 */

#define TEST 0

#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "PKW.h"

double dGlobaleZeit = 0.0;

bool bEpsilonEquals(double dNum1, double dNum2)
{
	if(abs(dNum1 - dNum2) < std::pow(10,-25.0))
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& ostr, const Fahrzeug& Fahrzeug)
{
	Fahrzeug.vAusgeben();
	return ostr;
}

void vAufgabe_1()
{
	std::cout << "\n\n Aufgabe 1 \n\n";

	Fahrzeug Auto("Auto");
	Fahrzeug Bus;
	Fahrzeug* Zug = new Fahrzeug("Zug");
	std::cout << "Test vAusgeben() und vKopf(): " << std::endl;
	Zug->vKopf();
	std::cout << std::endl;
	Zug->vAusgeben();
	std::cout << std::endl;
	std::unique_ptr<Fahrzeug> unique1 = std::make_unique<Fahrzeug>("Unique1");
	std::unique_ptr<Fahrzeug> unique2 = std::make_unique<Fahrzeug>("Unique2");
	std::shared_ptr<Fahrzeug> shared1 = std::make_shared<Fahrzeug>("Shared1");
	std::shared_ptr<Fahrzeug> shared2 = std::make_shared<Fahrzeug>("Shared2");
	std::cout << "Before: Count of shared2: " << shared2.use_count() << std::endl;
	std::shared_ptr<Fahrzeug> shared2_1 = shared2;
	std::cout << "After: Count of shared2: " << shared2.use_count() << std::endl;
	std::vector<std::unique_ptr<Fahrzeug>> vector_unique;
	vector_unique.push_back(std::move(unique1));
	vector_unique.push_back(std::move(unique2));
	vector_unique.clear();
	std::vector<std::shared_ptr<Fahrzeug>> vector_shared;
	vector_shared.push_back(shared1);
	vector_shared.push_back(shared2);
	vector_shared.push_back(std::move(shared2_1));
	std::cout << "Count after vector " << shared2.use_count() << std::endl;
	vector_shared.clear();
}

void vAufgabe_1a()
{
	std::cout << "\n\n Aufgabe 1a \n\n";

	std::unique_ptr<Fahrzeug> Auto = std::make_unique<Fahrzeug>("Auto", 130);
	std::unique_ptr<Fahrzeug> Bus = std::make_unique<Fahrzeug>("Bus", 90);
	std::unique_ptr<Fahrzeug> Fahrrad = std::make_unique<Fahrzeug>("Fahrrad",25);
	std::vector<std::unique_ptr<Fahrzeug>> vector_Fahrzeuge;
	vector_Fahrzeuge.push_back(std::move(Auto));
	vector_Fahrzeuge.push_back(std::move(Bus));
	vector_Fahrzeuge.push_back(std::move(Fahrrad));
	for(int i = 0; i < 3; i++)
	{
		std::cout << std::endl << "Simulationsschritt: " << i << std::endl;
		std::cout << std::endl;
		vector_Fahrzeuge.at(1)->vKopf();
		std::cout << std::endl;
		double deltaT = rand()%60;
		deltaT /= 60;
		dGlobaleZeit += deltaT;
		for(auto &vector:vector_Fahrzeuge)
		{
			vector->vSimulieren();
			vector->vAusgeben();
			std::cout << std::endl;
		}
	}
}

void vAufgabe_2()
{
	std::cout << "\n\n Aufgabe 2 \n\n";

	int iCountPKW;
	int iCountFahrrad;
	std::cout << "Bitte Anzahl an Autos eingeben: ";
	std::cin >> iCountPKW;
	std::cout << std::endl << "Bitte Anzahl an Fahrräder eingeben: ";
	std::cin >> iCountFahrrad;
	std::cout << std::endl;
	std::vector<std::unique_ptr<Fahrzeug>> vector_Fahrzeug;

	if(iCountPKW > 0)
	{
		for(int i = 1; i <= iCountPKW; i++)
		{
			std::string sName = "PKW" + std::to_string(i);
			std::unique_ptr<PKW> PKWs = std::make_unique<PKW>(sName, (double) (rand() % 5 * 20 + 20), (double) (rand() % 5 * 10 + 25), (double) (rand() % 5) + 1);
			vector_Fahrzeug.push_back(std::move(PKWs));
		}
	}

	if(iCountFahrrad > 0)
	{
		for(int i = 1; i <= iCountFahrrad; i++)
		{
			std::string sName = "Fahrrad" + std::to_string(i);
			std::unique_ptr<Fahrrad> Bikes = std::make_unique<Fahrrad>(sName, rand() % 5 * 5 + 5);
			vector_Fahrzeug.push_back(std::move(Bikes));
		}
	}
	double dSchritte;
	std::cout << "Bitte Anzahl Zeitschritte eingeben: ";
	std::cin >> dSchritte;
	std::cout << std::endl;

	for(int i = 0; i <= dSchritte; i++)
	{
		double dDeltaT = rand() % 210;
		dDeltaT /= 60;
		dGlobaleZeit += dDeltaT;
		std::cout << std::endl <<  std::endl << "Simulationsschritt: " << i << std::endl << std::endl;
		vector_Fahrzeug.at(0)->vKopf();
		for(auto &Fahrzeug : vector_Fahrzeug)
		{
			if((int)Fahrzeug->getdZeit() / 3 < (int) dGlobaleZeit / 3) {Fahrzeug->dTanken(); std::cout << std::endl;}
			Fahrzeug->vSimulieren();
			Fahrzeug->vAusgeben();
		}
	}
}

void vAufgabe_3()
{
	std::cout << "\n\n Aufgabe 3 \n\n";

	PKW PKW1("PKW1", 100, 50, 4.5);
	PKW PKW2("PKW2");
	Fahrzeug Fahrzeug("Fahrzeug", 100);
	Fahrrad Fahrrad("Fahrrad", 20);

	std::cout << "Ausgabe mit Operator Overload :" << std::endl << std::endl;
	PKW1.vKopf();
	std::cout << std::endl << PKW1 << std::endl << Fahrrad << std::endl << std::endl;

	std::cout << "Test Vergleichsopator:" << std::endl << std::endl;
	std::cout << "Vor Simulation: " << std::endl;
	PKW1.vKopf();
	std::cout << std::endl << PKW1 << std::endl << PKW2 << std::endl;
	if(PKW2<PKW1)
	{
		std::cout << PKW1.getsName() << " ist weiter gefahren";
	}
	else
	{
		std::cout << PKW2.getsName() << " ist weiter gefahren";
	}
	std::cout << std::endl << std::endl;

	dGlobaleZeit += 2;
	PKW1.vSimulieren();
	PKW2.vSimulieren();

	std::cout << "Nach Simulation: " << std::endl;
	PKW1.vKopf();
	std::cout << std::endl << PKW1 << std::endl << PKW2 << std::endl;
	if(PKW2<PKW1)
	{
		std::cout << PKW1.getsName() << " ist weiter gefahren";
	}
	else
	{
		std::cout << PKW2.getsName() << " ist weiter gefahren";
	}
	std::cout << std::endl;

	std::cout << "Teste Zuweisung:" << std::endl << std::endl;

	std::cout << "Fahrzeug = Fahrrad" << std::endl;
	std::cout << "Zuvor: \n\n";
	PKW1.vKopf();
	std::cout << std::endl << Fahrzeug << std::endl << Fahrrad << std::endl << std::endl;
	Fahrzeug = Fahrrad;
	std::cout << "Danach: \n\n" << Fahrzeug << std::endl << Fahrrad << std::endl << std::endl;

	std::cout << "Fahrzeug/PKW" << std::endl;
	std::cout << "Fahrzeug = PKW1" << std::endl;
	std::cout << "Zuvor: \n\n";
	PKW1.vKopf();
	std::cout << std::endl << Fahrzeug << std::endl << PKW1 << std::endl << std::endl;
	Fahrzeug = PKW1;
	std::cout << "Danach: \n\n" << Fahrzeug << std::endl << PKW1 << std::endl << std::endl;

	std::cout << "PKW/Fahrzeug" << std::endl;
	std::cout << "PKW2 = Fahrzeug" << std::endl;
	std::cout << "Zuvor: \n\n";
	PKW1.vKopf();
	std::cout << std::endl << PKW2 << std::endl << Fahrzeug << std::endl << std::endl;
	Fahrzeug = Fahrrad;
	std::cout << "Danach: \n\n" << PKW2 << std::endl << Fahrzeug << std::endl << std::endl;

	std::cout << "PKW/PKW" << std::endl;
	std::cout << "PKW1 = PKW2" << std::endl;
	std::cout << "Zuvor: \n\n";
	PKW1.vKopf();
	std::cout << std::endl << PKW1 << std::endl << PKW2 << std::endl << std::endl;
	Fahrzeug = Fahrrad;
	std::cout << "Danach: \n\n" << PKW1 << std::endl << PKW2 << std::endl << std::endl;

}

int main(void)
{
#if TEST == 1

#endif
	std::srand(std::time(NULL));//
	vAufgabe_1();
	vAufgabe_1a();
	vAufgabe_2();
	vAufgabe_3();
}

