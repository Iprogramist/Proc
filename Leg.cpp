#include "Leg.h"
#include <fstream>

using namespace std;

void readLeg(Leg &lg, ifstream &ifst)
{
	char str[10];
	ifst.getline(str, 10, '\n');
	lg.speed = atoi(str);
}


void OutLeg(Leg &lg, ofstream &ofst)
{
	ofst << " ������������ �������� ��������� �/�: " << lg.speed << endl;
}