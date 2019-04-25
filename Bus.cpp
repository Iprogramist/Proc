#include "Bus.h"
#include <fstream>
using namespace std;

void readBus(Bus &bs, ifstream &ifst)
{
	char str[10];
	ifst.getline(str,10, '\n');
	bs.capacity = atoi(str);
}

void OutBus(Bus &bs, ofstream &ofst)
{
	ofst << " Вместимость пассажиров: " << bs.capacity << endl;
}
