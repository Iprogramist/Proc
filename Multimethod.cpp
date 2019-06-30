#include "Car.h"
#include "List.h"
#include <fstream>

using namespace std;
void OutCar(Cars* car, ofstream &ofst);

void MultiMethod(List **list, ofstream &ofst)
{
	ofst << "Мультиметод." << endl;
	while ((*list)->next != NULL)
	{
		switch ((*list)->car.key)
		{
		case Cars::GRUZOV:
		{
			switch ((*list)->next->car.key)
			{
			case Cars::GRUZOV:
			{
				ofst << "Грузовик и грузовик." << endl;
				break;
			}
			case Cars::LEGKOV:
			{
				ofst << "Грузовик и легковая." << endl;
				break;
			}
			case Cars::BUS:
			{
				ofst << "Грузовик и автобус." << endl;
				break;
			}
			default:
				ofst << "Грузовик и непонятное." << endl;
			}
			break;
		}
		case Cars::LEGKOV:
		{
			switch ((*list)->next->car.key)
			{
			case Cars::GRUZOV:
			{
				ofst << "Легковая и грузовик." << endl;
				break;
			}
			case Cars::LEGKOV:
			{
				ofst << "Легковая и легковая." << endl;
				break;
			}
			case Cars::BUS:
			{
				ofst << "Легковая и автобус." << endl;
				break;
			}
			default:
				ofst << "Легковая и непонятное." << endl;
			}
			break;
		}
		case Cars::BUS:
		{
			switch ((*list)->next->car.key)
			{
			case Cars::GRUZOV:
			{
				ofst << "Автобус и грузовик." << endl;
				break;
			}
			case Cars::LEGKOV:
			{
				ofst << "Автобус и легковая." << endl;
				break;
			}
			case Cars::BUS:
			{
				ofst << "Автобус и автобус." << endl;
				break;
			}
			default:
				ofst << "Автобус и непонятное." << endl;
			}
			break;
		}
		default:
			ofst << "Непонятно." << endl;
		}
		OutCar(&(*list)->car, ofst);
		OutCar(&(*list)->next->car, ofst);
		(*list) = (*list)->next;
	}
}