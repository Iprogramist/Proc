#include "List.h"
#include "Car.h"
#include <fstream>

using namespace std;
void OutCar(Cars* car, ofstream &ofst);
	
void MultiMethod(List **list, ofstream &ofst)
{
	ofst << "Мультиметод." << endl;
	while ((*list)->next != NULL)
	{
		switch ((*list)->a.key)
		{
		case Cars::BUS:
		{
			switch ((*list)->next->a.key)
			{
			case Cars::BUS:
			{
				ofst << "Автобус и автобус." << endl;
				break;
			}
			case Cars::GRUZOV:
			{
				ofst << "Автобус и грузовик." << endl;
				break;
			}
			default:
				ofst << "Непонятно." << endl;
			}
			break;
		}
		case Cars::GRUZOV:
		{
			switch ((*list)->next->a.key)
			{
			case Cars::GRUZOV:
			{
				ofst << "Грузовик и грузовик." << endl;
				break;
			}
			case Cars::BUS:
			{
				ofst << "Грузовик и автобус." << endl;
				break;
			}
			default:
				ofst << "непонятно." << endl;
			}
			break;
		}
		default:
			ofst << "непонятно." << endl;
		}
		OutCar(&(*list)->a, ofst);
		OutCar(&(*list)->next->a, ofst);
		(*list) = (*list)->next;
	}
}