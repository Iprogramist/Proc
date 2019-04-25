#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "Car.h"
#include "Bus.h"
#include "Gruz.h"
#include "Leg.h"
#include <fstream>


using namespace std;


void OutBus(Bus &bs, ofstream &ofst);
void readBus(Bus &bs, ifstream &ifst);
void readGruz(Gruz &gr, ifstream &ifst);
void OutGruz(Gruz &gr, ofstream &ofst);
void OutLeg(Leg &lg, ofstream &ofst);
void readLeg(Leg &lg, ifstream &ifst);

float RatioCar(Cars *a, int k);



float RatioCar(Cars *a,int k)
{
	float m;
	if (k == 2)
	{
		m = (float(a->avtobus.capacity) * float(75)) / float(a->power);
	}
	else if (k==1)
	{
		m =(float(a->gruzovik.mas) / float(a->power));
	}
  else if (k==3)
	{
		m =(float(75) / float(a->power));
	}
	return m;
}




Cars* InCar(ifstream &ifst)
{
	Cars *avto = new Cars;
	char od[] = "gruzovik";
	char dv[] = "avtobus";
	char lg[] = "legkovaya";

	char prov[10];
	ifst.getline(prov, 10, '\n');
	int key = 3;
	if (_stricmp(od, prov) == 0)
	{
		key = 1;
	}
	if (_stricmp(dv, prov) == 0 )
	{
		key = 2;
	}
	if (_stricmp(lg, prov) == 0)
	{
		key = 3;
	}
	
	char str[10];
	ifst.getline(str, 10, '\n');
	avto->power = atoi(str);

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
	case 3:
		avto->key = Cars::key::LEGKOV;
		readLeg(avto->legkovaya, ifst);
		return avto;
	default:    
		exit;
	}

}

void OutCar(Cars* a, ofstream &ofst)        // â äîê
{
	ofst << "Êîë-âî ëîøàäèííûõ ñèë: " << a->power << ' ' << "Îòíîøåíèå âåñà ê ìîùíîñòè: " << RatioCar(a, a->key) << ' ';
	ofst << "Êîë-âî ëîøàäèíûõ ñèë: " << a->power << ' ';
	switch (a->key)
	{
	case Cars::key::GRUZOV:OutGruz(a->gruzovik, ofst);
		break;
	case Cars::key::BUS:OutBus(a->avtobus, ofst);
		break;
	case Cars::key::LEGKOV:OutLeg(a->legkovaya, ofst);
		break;
	default:
		ofst << "Îøèáêà!" << endl;
	}

}