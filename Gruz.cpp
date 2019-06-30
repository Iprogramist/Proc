#include "Gruz.h"
#include <fstream>
#include <iostream>

using namespace std;
bool Check(ifstream &ifst, Gruz &gr);

void ReadGruz(Gruz &gr, ifstream &ifst)
{
	char str[10];
	ifst.getline(str, 10, '\n');
	gr.mas = atoi(str);
	Check(ifst, gr);
}

void OutGruz(Gruz &gr, ofstream &ofst)
{
	ofst << " Грузоподъемность грузовика: " << gr.mas << endl;
}

bool Check(ifstream &ifst, Gruz &gr)
{
	if (ifst.fail())
	{
		cout << "Неверный формат!" << endl;
		system("pause");
	}
	else if (gr.mas <= 0)
	{
		cout << "Масса должна быть больше нуля!" << endl;
		system("pause");
	}
	else if (gr.mas - (int)gr.mas > 0)
	{
		cout << "Масса должена быть целым числом!" << endl;
		system("pause");
	}
	return 0;
}