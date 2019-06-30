#include "stdafx.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../laba1/Bus.h"
#include "../laba1/Car.h"
#include "../laba1/Gruz.h"
#include "../laba1/leg.h"
#include "../laba1/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

void Init(List **begin);;
	
void InList(List **begin, ifstream &ifst);
void OutList(List **b, ofstream &ofst);
void Sort(List **begin);
void OnlyGruz(List **begin, ofstream &ofst);

void OutCar(Cars* a, ofstream &ofst);
Cars* InCar(ifstream &ifst);
float RatioCar(Cars *a, int k);
bool Compare(Cars *first, Cars *second);

void readBus(Bus &bs, ifstream &ifst);
void readGruz(Gruz &gr, ifstream &ifst);
void readLeg(Leg &lg, ifstream &ifst);
void OutBus(Bus &bs, ofstream &ofst);
void OutGruz(Gruz &gr, ofstream &ofst);
void OutLeg(Leg &lg, ofstream &ofst);


TEST_CLASS(In_lower)
{
public:

	TEST_METHOD(Gruzz)
	{
		ifstream ifst("../UnitTest1/TestFiles/In_lower_Gruz.txt");
		Gruz myGruz;
		readGruz(myGruz, ifst);

		int expected = 2;
		int actual = myGruz.mas;

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Legg)
	{
		ifstream ifst("../UnitTest1/TestFiles/In_lower_Leg.txt");
		Leg myLeg;
		readLeg(myLeg, ifst);

		int expected = 1;
		int actual = myLeg.speed;

		Assert::AreEqual(expected, actual);
	}


	TEST_METHOD(Buss)
	{
		ifstream ifst("../UnitTest1/TestFiles/In_lower_Bus.txt");
		Bus myBus;
		readBus(myBus, ifst);

		int expected = 1;
		int actual = myBus.capacity;

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(In_middle)
{
public:
	TEST_METHOD(test_exp)
	{
		Cars* testCar;
		ifstream ifst("../UnitTest1/TestFiles/In_middle_Bus.txt");
		testCar = InCar(ifst);

		int expected = 23.5;
		int actual = testCar->exp;
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(test_key)
	{
		Cars* testCar;
		ifstream ifst("../UnitTest1/TestFiles/In_middle_Bus.txt");
		testCar = InCar(ifst);

		int expected = Cars::key::BUS;
		int actual = testCar->key;

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(test_power_Bus)
	{
		Cars* testCar;
		ifstream ifst("../UnitTest1/TestFiles/In_middle_Bus.txt");
		testCar = InCar(ifst);

		int expected = 3;
		int actual = testCar->power;

		Assert::AreEqual(expected, actual);
	}


	TEST_METHOD(test_bus_capacity)
	{
		Cars* testCar;
		ifstream ifst("../UnitTest1/TestFiles/In_middle_Bus.txt");
		testCar = InCar(ifst);

		int expected = 4;
		int actual = testCar->avtobus.capacity;

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(test_leg_power)
	{
		Cars* testCar;
		ifstream ifst("../UnitTest1/TestFiles/In_middle_Leg.txt");
		testCar = InCar(ifst);

		int expected = 3;
		int actual = testCar->power;

		Assert::AreEqual(expected, actual);
	}
	TEST_METHOD(test_gruz_power)
	{
		Cars* testCar;
		ifstream ifst("../UnitTest1/TestFiles/In_middle_Gruz.txt");
		testCar = InCar(ifst);

		int expected = 4;
		int actual = testCar->power;

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(IТ_OUT_higher)
{
public:

	TEST_METHOD(IN_OUT_Test_cont)
	{
		List *testing_cont;
		Init(&testing_cont);
		ifstream test_file_in("../UnitTest1/TestFiles/In_higher_1.txt");//входной
		InList(&testing_cont, test_file_in);
		ofstream test_file_out("../UnitTest1/TestFiles/In_higher_2.txt");//выходной
		OutList(&testing_cont, test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../UnitTest1/TestFiles/In_higher_2.txt", "r");;
		FILE *file_2 = fopen("../UnitTest1/TestFiles/In_higher_3.txt", "r");//эталон
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(Out_lower)
{
public:

	TEST_METHOD(Test1_gruz)
	{
		Gruz testing_type;
		testing_type.mas = 1;
		ofstream test_file_out("../UnitTest1/TestFiles/Out_lower_Gruz.txt");
		OutGruz(testing_type, test_file_out);
		test_file_out.close();

		ifstream test_file_in("../UnitTest1/TestFiles/Out_lower_Gruz.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "Грузоподъемность грузовика: 1";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test2_Bus)
	{
		Bus testing_type;
		testing_type.capacity = 1;
		ofstream test_file_out("../UnitTest1/TestFiles/Out_lower_Bus.txt");
		OutBus(testing_type, test_file_out);
		test_file_out.close();

		ifstream test_file_in("../UnitTest1/TestFiles/Out_lower_Bus.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "Вместимость пассажиров: 1";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test3_Leg)
	{
		Leg testing_type;
		testing_type.speed = 1;
		ofstream test_file_out("../UnitTest1/TestFiles/Out_lower_Leg.txt");
		OutLeg(testing_type, test_file_out);
		test_file_out.close();

		ifstream test_file_in("../UnitTest1/TestFiles/Out_lower_Leg.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "Максимальная скорость легкового а/м: 1";

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(Out_middle)
{
public:

	TEST_METHOD(Buss)
	{
		Cars* testing_type = new Cars;
		testing_type->key = testing_type->BUS;
		testing_type->avtobus.capacity = 3;
		testing_type->exp = 6;
		testing_type->power = 5;
		ofstream test_file_out("../UnitTest1/TestFiles/Out_middle_Bus.txt");
		OutCar(testing_type, test_file_out);
		test_file_out.close();

		ifstream test_file_in("../UnitTest1/TestFiles/Out_middle_Bus.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "Кол-во лошадинных сил: 5 Отношение веса к мощности: 45 Расход: 6 Вместимость пассажиров: 3";

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_Sort)
{
public:

	TEST_METHOD(Test_sort_IN_OUT)
	{
		List* testing_cont;
		Init(&testing_cont);
		ifstream test_file_in("../UnitTest1/TestFiles/In_higher_1.txt");//вход
		InList(&testing_cont, test_file_in);
		Sort(&testing_cont);
		ofstream test_file_out("../UnitTest1/TestFiles/Sort_2.txt");//выход
		OutList(&testing_cont, test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../UnitTest1/TestFiles/Sort_2.txt", "r");;
		FILE *file_2 = fopen("../UnitTest1/TestFiles/Sort_3.txt", "r");//эталон
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_Filter)
{
public:

	TEST_METHOD(Test_filter_IN_OUT)
	{
		List* testing_cont;
		Init(&testing_cont);
		ifstream test_file_in("../UnitTest1/TestFiles/In_higher_1.txt");
		InList(&testing_cont, test_file_in);
		ofstream test_file_out("../UnitTest1/TestFiles/Filter_2.txt");
		OnlyGruz(&testing_cont, test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../UnitTest1/TestFiles/Filter_2.txt", "r");;
		FILE *file_2 = fopen("../UnitTest1/TestFiles/Filter_3.txt", "r");
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(RatioCar_func)
{
public:

	TEST_METHOD(Test1_bus)
	{
		Cars *testCar=new Cars;
		testCar->avtobus.capacity = 10;
		testCar->power = 5;
		
		int actual = RatioCar(testCar,2);

		Assert::AreEqual(150, actual);
	}

	TEST_METHOD(Test2_gruz)
	{
		Cars *testCar=new Cars;
		testCar->gruzovik.mas = 10;
		testCar->power = 5;

		int actual = RatioCar(testCar, 1);

		Assert::AreEqual(2, actual);
	}

	TEST_METHOD(Test3_leg)
	{
		Cars *testCar=new Cars;
		testCar->power = 5;

		int actual = RatioCar(testCar, 3);

		Assert::AreEqual(15, actual);
	}
};

TEST_CLASS(testing_Compare)
{
public:

	TEST_METHOD(Test_Compare)
	{
		Cars *testCar1 = new Cars;
		testCar1->gruzovik.mas = 10;
		testCar1->power = 5;
		testCar1->key = Cars::key::GRUZOV;

		Cars *testCar2 = new Cars;
		testCar2->power = 5;
		testCar2->key = Cars::key::LEGKOV;

		int expected = true;
		int actual = true;

		if (Compare(testCar1, testCar2)==false)
		{
			actual = false;
		}
		
		Assert::AreEqual(expected, actual);
	}
};