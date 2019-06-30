#include "Car.h"
#include "List.h"
#include <fstream>

using namespace std;
void OutCar(Cars* car, ofstream &ofst);

void MultiMethod(List **list, ofstream &ofst)
{
	ofst << "�����������." << endl;
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
				ofst << "�������� � ��������." << endl;
				break;
			}
			case Cars::LEGKOV:
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
				ofst << "�������� � ����������." << endl;
			}
			break;
		}
		case Cars::LEGKOV:
		{
			switch ((*list)->next->car.key)
			{
			case Cars::GRUZOV:
			{
				ofst << "�������� � ��������." << endl;
				break;
			}
			case Cars::LEGKOV:
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
				ofst << "�������� � ����������." << endl;
			}
			break;
		}
		case Cars::BUS:
		{
			switch ((*list)->next->car.key)
			{
			case Cars::GRUZOV:
			{
				ofst << "������� � ��������." << endl;
				break;
			}
			case Cars::LEGKOV:
			{
				ofst << "������� � ��������." << endl;
				break;
			}
			case Cars::BUS:
			{
				ofst << "������� � �������." << endl;
				break;
			}
			default:
				ofst << "������� � ����������." << endl;
			}
			break;
		}
		default:
			ofst << "���������." << endl;
		}
		OutCar(&(*list)->car, ofst);
		OutCar(&(*list)->next->car, ofst);
		(*list) = (*list)->next;
	}
}