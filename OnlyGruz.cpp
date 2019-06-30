#include <fstream>
#include "List.h"
#include "Car.h"

using namespace std;
void OutCar(Cars* car, ofstream &ofst);

void OnlyGruz(List **begin, ofstream &ofst)
{
	List *list = (*begin);
	int i = 1;
	ofst << "Только Грузовики!" << endl;
	while (list)
	{
		ofst << i << ": ";
		if (list->car.key == Cars::GRUZOV)
		{
			OutCar(&(list)->car, ofst);
		}
		else
		{ 
			ofst << "- " << endl;
		}
		list = list->next;
		i++;
	}
}