#include "Bus.h"
#include <fstream>
#include <iostream>

using namespace std;
bool Check(ifstream &ifst, Bus &bs);

void ReadBus(Bus &bs, ifstream &ifst)
{
	char str[10];
	ifst.getline(str,10, '\n');
	bs.capacity = atoi(str);
	Check(ifst, bs);
}

bool Check(ifstream &ifst, Bus &bs)
{
	if (ifst.fail())
	{
		cout << "�������� ������!" << endl;
		system("pause");
	}
	else if (bs.capacity <= 0)
	{
		cout << "����������� ������ ���� ������ ����!" << endl;
		system("pause");
	}
	else if (bs.capacity - (int)bs.capacity > 0)
	{
		cout << "����������� ������� ���� ����� ������!" << endl;
		system("pause");
	}
	return 0;
}

void OutBus(Bus &bs, ofstream &ofst)
{
	ofst << " ����������� ����������: " << bs.capacity << endl;
}
