#include <fstream>
#include "List.h"
#include "Car.h"

using namespace std;

void OutCar(Cars* a, ofstream &ofst);

void OnlyGruz(List **begin, ofstream &ofst)
{
	List *a = (*begin);
	int i = 1;
	ofst << "Только Грузовики!" << endl;
	while (a)
	{
		ofst << i << ": ";
		if (a->a.key == Cars::GRUZOV)
			OutCar(&(a)->a, ofst);
		else
			ofst << "- " << endl;
		a = a->next;
		i++;
	}
}