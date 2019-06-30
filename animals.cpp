#include <fstream>
#include "animal_atd.h"

using namespace std;

namespace simple_animals
{
	void In(bird &r, ifstream &ist);
	void In(fish  &t, ifstream &ist);

	animal* In(ifstream &ifst)
	{
		animal *sp;
		int choice;
		ifst >> choice;
		switch(choice)
		{
			case 1:
				sp = new animal;
				sp->key = animal::key::BIRD;
				In(sp->bir, ifst);
				ifst >> sp->name;
				return sp;
			case 2:
				sp = new animal;
				sp->key = animal::key::FISH;
				In(sp->fis, ifst);
				ifst >> sp->name;
				return sp;
			default:
				return 0;
		}
	}

void Out(bird &r, char name[20],ofstream &ofst);
void Out(fish  &t, char name[20],ofstream &ofst);

  
 void Out(animal &s, ofstream &ofst) 
 {
		switch(s.key) 
		{
			case animal::key::BIRD:
				Out(s.bir, s.name,ofst);
				break;
			case animal::key::FISH:
				Out(s.fis, s.name, ofst);
				break;
			default:
			ofst << "Некорректно!" << endl;
		}
  }
} // end simple_animals namespace


