#include <fstream>
#include "fish_atd.h"

using namespace std;

namespace simple_animals 
{
	void In(fish &t, ifstream &ifst) 
	{
		ifst >> t.place;
	}

	void Out(fish &t, char name[20] ,ofstream &ofst)
	{
		if (t.place == 0) 
		{
			ofst << "Рыба " <<name<< " живет в озере" << endl;
		}
		else if (t.place == 1) 
		{
			ofst << "Рыба " << name << " живет в море" << endl;
		}
		else if (t.place == 2) 
		{
			ofst << "Рыба " << name << " живет в реке" << endl;
		}
	}
} 

