#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "Car.h"
#include "Bus.h"
#include "Gruz.h"
#include <fstream>

using namespace std;

void OutBus(Bus &bs, ofstream &ofst);
void readBus(Bus &bs, ifstream &ifst);
void readGruz(Gruz &gr, ifstream &ifst);
void OutGruz(Gruz &gr, ofstream &ofst);

Cars* InCar(ifstream &ifst)
{
	Cars *avto = new Cars;
	char od[] = "gruzovik";
	char dv[] = "avtobus";
	char tmp[10];
	ifst.getline(tmp, 10, '\n');
	int key = 3;
	if (_stricmp(od, tmp) == 0)
	{
		key = 1;
	}
	if (_stricmp(dv, tmp) == 0 )
	{
		key = 2;
	}
	
	char str[10];
	ifst.getline(str, 10, '\n');
	avto->power = atoi(str);

	ifst.getline(str, 10, '\n');
	avto->exp = atof(str);

	switch (key)   
	{
	case 1:
		avto->key = Cars::key::GRUZOV;
		readGruz(avto->gruzovik, ifst);  
		return avto; 
	case 2:
		avto->key = Cars::key::BUS;
		readBus(avto->avtobus, ifst);
		return avto;
	default:   
		exit;
	}

}

void OutCar(Cars* a, ofstream &ofst)        
{

	ofst << "Кол-во лошадинных сил: " << a->power << ' ';
	ofst << "Расход: " << a->exp << ' ';
	switch (a->key)
	{
	case Cars::key::GRUZOV:OutGruz(a->gruzovik, ofst);
		break;
	case Cars::key::BUS:OutBus(a->avtobus, ofst);
		break;
	default:
		ofst << "Ошибка!" << endl;
	}
}