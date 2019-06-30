#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "Car.h"
#include "Bus.h"
#include "Gruz.h"
#include "Leg.h"
#include <fstream>
#include <iostream>

using namespace std;
void OutBus(Bus &bs, ofstream &ofst);
void ReadBus(Bus &bs, ifstream &ifst);
void ReadGruz(Gruz &gr, ifstream &ifst);
void OutGruz(Gruz &gr, ofstream &ofst);
void OutLeg(Leg &lg, ofstream &ofst);
void ReadLeg(Leg &lg, ifstream &ifst);
float RatioCar(Cars *car, int key);

float RatioCar(Cars *car, int key)
{
	float ratio;
	if (key == 2)
	{
		ratio = (float(car->avtobus.capacity) * float(75)) / float(car->power);
	}
	else if (key == 1)
	{
		ratio = (float(car->gruzovik.mas) / float(car->power));
	}
	else if (key == 3)
	{
		ratio = (float(75) / float(car->power));
	}
	return ratio;
}

Cars* InCar(ifstream &ifst)
{
	Cars *ca = new Cars;
	char gr[] = "gruzovik";
	char av[] = "avtobus";
	char lg[] = "legkovaya";
	char check[10];
	ifst.getline(check, 10, '\n');
	if (_stricmp(gr, check) != 0 and _stricmp(av, check) != 0 and _stricmp(lg, check) != 0)
	{
		cout << "Введен Неверный формат автомобиля!" << endl;
		system("pause");
	}
	int key = 3;
	if (_stricmp(gr, check) == 0)
	{
		key = 1;
	}
	if (_stricmp(av, check) == 0 )
	{
		key = 2;
	}
	if (_stricmp(lg, check) == 0)
	{
		key = 3;
	}
	
	char str[10];
	ifst.getline(str, 10, '\n');
	ca->power = atoi(str);
	if (ifst.fail()) {
		cout << "Неверный формат!" << endl;
		system("pause");
	}
	else if (ca->power <= 0) {
		cout << "Мощность должна быть больше нуля!" << endl;
		system("pause");
	}

	ifst.getline(str, 10, '\n');
	ca->exp = atof(str);
	if (ifst.fail()) {
		cout << "Неверный формат!" << endl;
		system("pause");
	}
	else if (ca->exp <= 0) {
		cout << "Расход должен быть больше нуля!" << endl;
		system("pause");
	}

	switch (key)  
	{
	case 1:
		ca->key = Cars::key::GRUZOV;
		ReadGruz(ca->gruzovik, ifst);  
		return ca; 
	case 2:
		ca->key = Cars::key::BUS;
		ReadBus(ca->avtobus, ifst);
		return ca;
	case 3:
		ca->key = Cars::key::LEGKOV;
		ReadLeg(ca->legkovaya, ifst);
		return ca;
	default:    
		exit;
	}
}

void OutCar(Cars* car, ofstream &ofst)       
{
	ofst << "Кол-во лошадинных сил: " << car->power << ' ' << "Отношение веса к мощности: " << RatioCar(car, car->key) << ' ';
	ofst << "Расход: " << car->exp << ' ';
	switch (car->key)
	{
	case Cars::key::GRUZOV:OutGruz(car->gruzovik, ofst);
		break;
	case Cars::key::BUS:OutBus(car->avtobus, ofst);
		break;
	case Cars::key::LEGKOV:OutLeg(car->legkovaya, ofst);
		break;
	default:
		ofst << "Ошибка!" << endl;
	}
}
