#include "List.h"
#include "Car.h"
#include <fstream>

using namespace std;
void OutCar(Cars* car, ofstream &ofst);
	
void MultiMethod(List **list, ofstream &ofst)
{
	ofst << "�����������." << endl;
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
				ofst << "������� � �������." << endl;
				break;
			}
			case Cars::GRUZOV:
			{
				ofst << "������� � ��������." << endl;
				break;
			}
			default:
				ofst << "���������." << endl;
			}
			break;
		}
		case Cars::GRUZOV:
		{
			switch ((*list)->next->a.key)
			{
			case Cars::GRUZOV:
			{
				ofst << "�������� � ��������." << endl;
				break;
			}
			case Cars::BUS:
			{
				ofst << "�������� � �������." << endl;
				break;
			}
			default:
				ofst << "���������." << endl;
			}
			break;
		}
		default:
			ofst << "���������." << endl;
		}
		OutCar(&(*list)->a, ofst);
		OutCar(&(*list)->next->a, ofst);
		(*list) = (*list)->next;
	}
}