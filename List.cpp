#include "Car.h"
#include "List.h"
#include <fstream>

using namespace std;

void OutCar(Cars* a, ofstream &ofst);
Cars* InCar(ifstream &ifst);

void Init(List **begin)        //////// инициализация 
{
	*begin = NULL;
	*begin = new List;
	(*begin)->next = NULL;
}

void Free(List **begin, ofstream &ofst)       /////  освобождаем память (для этого начало передаем)
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
	ofst << "Контейнер освобожден!" << endl;
}

void InList(List **begin, ifstream &ifst)    /////// или же    
{
	int kol = 0;
	List *end = *begin;

	while (!ifst.eof())
	{
		if (kol == 0)
		{
			(*begin)->a = (*InCar(ifst));   // который считывает первую цифру
			(*begin)->next = NULL;
			kol++;
		}
		else
		{
			end->next = new List; // указатель выделяет память под новый эл
			end = end->next;  // и авняется след эл 
			end->a = (*InCar(ifst));
			end->next = NULL;
			kol++;
		}
	}
}


void OutList(List **b, ofstream &ofst)        // в док
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
	ofst << "Контейнер заполнен! " << endl;
	ofst << "Колличество Автомобилей: " << kol << endl;
	while (p)
	{
		ofst << i << ": ";
		OutCar(&(p)->a, ofst);     /////// p->a я разъименовываю и отправляю значение переменной 
		p = p->next;
		i++;
	}
}
