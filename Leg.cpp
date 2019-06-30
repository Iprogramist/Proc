#include "Leg.h"
#include <fstream>
#include <iostream>

using namespace std;
bool Check(ifstream &ifst, Leg &lg);

void ReadLeg(Leg &lg, ifstream &ifst)
{
	char str[10];
	ifst.getline(str, 10, '\n');
	lg.speed = atoi(str);
	Check(ifst, lg);
}

void OutLeg(Leg &lg, ofstream &ofst)
{
	ofst << " Максимальная скорость легкового а/м: " << lg.speed << endl;
}

bool Check(ifstream &ifst, Leg &lg)
{
	if (ifst.fail())
	{
		cout << "Неверный формат!" << endl;
		system("pause");
	}
	else if (lg.speed <= 0)
	{
		cout << "Скорость должна быть больше нуля!" << endl;
		system("pause");
	}
	else if (lg.speed - (int)lg.speed > 0)
	{
		cout << "Скорость должена быть целым числом!" << endl;
		system("pause");
	}
	return 0;
}