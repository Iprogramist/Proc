#include "Car.h"
#include "List.h"
#include <fstream>
#include <iostream>

using namespace std;
void OutCar(Cars* car, ofstream &ofst);
Cars* InCar(ifstream &ifst);
bool Compare(Cars *firstCar, Cars *secondCar);

void Init(List **begin)        
{
	*begin = NULL;
	*begin = new List;
	(*begin)->next = NULL;
}

void Free(List **begin, ofstream &ofst)    
{
	if (*begin == 0)
	{
		return;
	}
	List *list = *begin;
	List *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		delete tmp;
	}
	*begin = NULL;
	ofst << "��������� ����������!" << endl;
}

void InList(List **begin, ifstream &ifst)    /////// ��� ��    
{
	int count = 0;
	List *end = *begin;

	while (!ifst.eof())
	{
		if (count == 0)
		{
			(*begin)->car = (*InCar(ifst));   // ������� ��������� ������ �����
			(*begin)->next = NULL;
			count++;
		}
		else
		{
			end->next = new List; // ��������� �������� ������ ��� ����� ��
			end = end->next;  // � �������� ���� �� 
			end->car = (*InCar(ifst));
			end->next = NULL;
			count++;
		}
	}
}

void OutList(List **ls, ofstream &ofst)        // � ���
{
	List *list = *ls;
	int i = 1;
	int  count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	list = *ls;
	ofst << "��������� ��������! " << endl;
	ofst << "����������� �����������: " << count << endl;
	while (list)
	{
		ofst << i << ": ";
		OutCar(&(list)->car, ofst);     /////// p->a � �������������� � ��������� �������� ���������� 
		list = list->next;
		i++;
	}
}

void Sort(List **begin)
{
	char signOfCompare;
	bool check;
	cout << "\n��� �������������? �� ����������� (>) ��� �������� (<): ";
	cin >> signOfCompare;
	while (signOfCompare != '<' and signOfCompare != '>')
	{
		cout << "\n������ �����, ������� < ��� >: ";
		cin >> signOfCompare;
	}
	switch (signOfCompare)
	{
		case '>':
		{
			check = 0;
			break;
		}
		case '<':
		{
			check = 1;
			break;
		}
		default:
		{
			cout << "������!" << endl;
		}
	}
	Cars tmpCar;
	List* tmp1;
	List * tmp2;

	for (tmp1 = (*begin); tmp1; tmp1 = tmp1->next)
	{
		for (tmp2 = (*begin); tmp2; tmp2 = tmp2->next)
		{
			if (Compare(&tmp1->car, &tmp2->car) - check)
			{
				tmpCar = tmp1->car;
				tmp1->car = tmp2->car;
				tmp2->car = tmpCar;
			}
		}
	}
}