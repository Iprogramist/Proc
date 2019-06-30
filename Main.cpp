// laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdio>
#include "List.h"

using namespace std;

void Init(List **begin);
void Free(List **begin, ofstream &ofst);
void InList(List **begin, ifstream &ifst);
void OutList(List **ls, ofstream &ofst);
void Sort(List **begin);
void OnlyGruz(List **begin, ofstream &ofst);


int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream in;
	in.open("InFile.txt");
	if (!in.is_open())
	{
		cout << "Ошибка с файлом";
		return -1;
	}

	ofstream out;
	out.open("OutFile.txt");
	if (!out.is_open())
	{
		cout << "Ошибка с файлом";
		return -1;
	}

	cout << "Начало обработки данных" << endl;

	List* begin;

	Init(&begin);
	InList(&begin, in);
	OutList(&begin, out);
	Sort(&begin);
	OutList(&begin, out);
	OnlyGruz(&begin, out);
	Free(&begin, out);
	cout << "Обработка завершена" << endl;

	in.close();
	out.close();

	_getch();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
