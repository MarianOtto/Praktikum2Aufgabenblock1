/*
 * main.cpp
 *
 *  Created on: Sep 23, 2023
 *      Author: marian
 */

#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "PKW.h"

double dGlobaleZeit = 0.0;

void vAufgabe_1()
{
	Fahrzeug Auto("Auto");
	Fahrzeug Bus;
	Fahrzeug* Zug = new Fahrzeug("Zug");
	Zug->vAusgeben();
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
	std::cout << shared2.use_count() << " Count after vector" << std::endl;
	vector_shared.clear();
}

void vAufgabe_1a()
{
	std::unique_ptr<Fahrzeug> Auto = std::make_unique<Fahrzeug>("Auto", 130);
	std::unique_ptr<Fahrzeug> Bus = std::make_unique<Fahrzeug>("Bus", 90);
	std::unique_ptr<Fahrzeug> Fahrrad = std::make_unique<Fahrzeug>("Fahrrad",25);
	std::vector<std::unique_ptr<Fahrzeug>> vector_Fahrzeuge;
	vector_Fahrzeuge.push_back(std::move(Auto));
	vector_Fahrzeuge.push_back(std::move(Bus));
	vector_Fahrzeuge.push_back(std::move(Fahrrad));
	for(int i = 0; i < 3; i++)
	{
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
	int iCountPKW;
	int iCountFahrrad;
	std::cout << "Bitte Anzahl an Autos eingeben: ";
	std::cin >> iCountPKW;
	std::cout << std::endl << "Bitte Anzahl an Fahrräder eingeben: ";
	std::cin >> iCountFahrrad;
	std::cout << std::endl;
	std::vector<std::unique_ptr<Fahrzeug>> vector_Fahrzeug;

	for(int i = 1; i <= iCountPKW; i++)
	{
		std::string sName = "PKW" + std::to_string(i);
		std::cout << sName;
		std::unique_ptr<PKW> PKWs = std::make_unique<PKW>(sName, (double) (rand() % 5 * 20 + 20), (double) (rand() % 5 * 10 + 25), (double) (rand() % 5) + 1);
		vector_Fahrzeug.push_back(std::move(PKWs));
	}

	for(int i = 1; i <= iCountFahrrad; i++)
	{
		std::string sName = "Fahrrad" + std::to_string(i);
		std::unique_ptr<Fahrrad> Bikes = std::make_unique<Fahrrad>(sName, rand() % 5 * 5 + 5);
		vector_Fahrzeug.push_back(std::move(Bikes));
	}

	double dSchritte;
	std::cout << "Bitte Anzahl Zeitschritte eingeben: ";
	std::cin >> dSchritte;
	std::cout << std::endl;

	for(int i = 0; i <= dSchritte; i++)
	{
		double dDeltaT = rand() % 180;
		dDeltaT /= 60;
		dGlobaleZeit += dDeltaT;
		std::cout << dDeltaT;
		std::cout << std::endl;
		vector_Fahrzeug.at(1)->vKopf();
		std::cout << std::endl;
		for(auto &Fahrzeug : vector_Fahrzeug)
		{
			if((int)Fahrzeug->getdZeit() / 3 < (int) dGlobaleZeit / 3) {Fahrzeug->dTanken(1000); std::cout << std::endl;}
			Fahrzeug->vSimulieren();
			Fahrzeug->vAusgeben();
			std::cout << std::endl;
		}
	}


}

int main(void)
{
	//vAufgabe_1();
	//vAufgabe_1a();
	vAufgabe_2();
//	PKW Auto("Auto", 80, 50, 4.5);
//
//	std::cout << "\n\n";
//	Auto.vKopf();
//	std::cout << "\n";
//	Auto.vAusgeben();
//
//	dGlobaleZeit = 2.5;
//	Auto.vSimulieren();
//
//	std::cout << "\n\n";
//	Auto.vKopf();
//	std::cout << "\n";
//	Auto.vAusgeben();
//
//	Auto.dTanken(3);
//
//	std::cout << "\n\n";
//	Auto.vKopf();
//	std::cout << "\n";
//	Auto.vAusgeben();
//	Fahrrad Rad("Rad", 15);
//	std::cout << "\n\n";
//	Rad.vKopf();
//	std::cout << "\n";
//	Rad.vAusgeben();
//
//	for(int i = 1; i < 10; i++)
//	{
//		dGlobaleZeit += 1;
//		Rad.vSimulieren();
//
//		std::cout << "\n\n";
//		Rad.vKopf();
//		std::cout << "\n";
//		Rad.vAusgeben();
//	}
}

