#include <fstream>
#include "Car.h"
#include "List.h"

using namespace std;

float RatioCar(Cars *a, int k);


bool Compare(Cars *first, Cars *second)
{
	return RatioCar(first, first->key) < RatioCar(second, second->key);
}