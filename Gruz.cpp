#include "Gruz.h"
#include <fstream>

using namespace std;

void readGruz(Gruz &gr, ifstream &ifst)
{
	char str[10];
	ifst.getline(str, 10, '\n');
	gr.mas = atoi(str);
}


void OutGruz(Gruz &gr, ofstream &ofst)
{
	ofst << " Грузоподъемность грузовика: " << gr.mas << endl;
}