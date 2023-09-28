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
	Fahrzeug* Fahrrad = new Fahrzeug("Fahrrad");
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

int main(void)
{
	//vAufgabe_1();
	//vAufgabe_1a();
	PKW Auto("Auto", 80, 50, 4.5);

	std::cout << "\n\n";
	Auto.vKopf();
	std::cout << "\n";
	Auto.vAusgeben();

	dGlobaleZeit = 2.5;
	Auto.vSimulieren();

	std::cout << "\n\n";
	Auto.vKopf();
	std::cout << "\n";
	Auto.vAusgeben();

	Auto.dTanken(3);

	std::cout << "\n\n";
	Auto.vKopf();
	std::cout << "\n";
	Auto.vAusgeben();

	Auto.dTanken();

	std::cout << "\n\n";
	Auto.vKopf();
	std::cout << "\n";
	Auto.vAusgeben();
}

