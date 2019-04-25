#include "Car.h"
#include "List.h"
#include <fstream>
#include <iostream>

using namespace std;

void OutCar(Cars* a, ofstream &ofst);
Cars* InCar(ifstream &ifst);
bool Compare(Cars *first, Cars *second);

void Init(List **begin)        //////// ������������� 
{
	*begin = NULL;
	*begin = new List;
	(*begin)->next = NULL;
}

void Free(List **begin, ofstream &ofst)       /////  ����������� ������ (��� ����� ������ ��������)
{
	if (*begin == 0)
		return;
	List *p = *begin;
	List *t;

	while (p)
	{
		t = p;
		p = p->next;
		delete t;
	}
	*begin = NULL;
	ofst << "��������� ����������!" << endl;
}

void InList(List **begin, ifstream &ifst)    /////// ��� ��    
{
	int kol = 0;
	List *end = *begin;

	while (!ifst.eof())
	{
		if (kol == 0)
		{
			(*begin)->a = (*InCar(ifst));   // ������� ��������� ������ �����
			(*begin)->next = NULL;
			kol++;
		}
		else
		{
			end->next = new List; // ��������� �������� ������ ��� ����� ��
			end = end->next;  // � �������� ���� �� 
			end->a = (*InCar(ifst));
			end->next = NULL;
			kol++;
		}
	}
}


void OutList(List **b, ofstream &ofst)        // � ���
{
	List *p = *b;
	int i = 1;
	int  kol = 0;
	while (p)
	{
		kol++;
		p = p->next;
	}
	p = *b;
	ofst << "��������� ��������! " << endl;
	ofst << "����������� �����������: " << kol << endl;
	while (p)
	{
		ofst << i << ": ";
		OutCar(&(p)->a, ofst);     /////// p->a � �������������� � ��������� �������� ���������� 
		p = p->next;
		i++;
	}
}

void Sort(List **begin)
{
	char p;
	bool proverka;
	cout << "\n��� �������������? �� ����������� (>) ��� �������� (<): ";
	cin >> p;
	switch (p)
	{
	case '>':
	{
		proverka = 0;
		break;
	}

	case '<':
	{
		proverka = 1;
		break;
	}
	default:
	{
		cout << "������!" << endl;
	}
	}
	Cars t3;
	List* t1;
	List * t2;

	for (t1 = (*begin); t1; t1 = t1->next)
	{
		for (t2 = (*begin); t2; t2 = t2->next)
		{
			if (Compare(&t1->a, &t2->a) - proverka)
			{
				t3 = t1->a;
				t1->a = t2->a;
				t2->a = t3;
			}
		}
	}
}