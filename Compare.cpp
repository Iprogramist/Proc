#include <fstream>
#include "Car.h"
#include "List.h"

using namespace std;
float RatioCar(Cars *car, int key);

bool Compare(Cars *firstCar, Cars *secondCar)
{
	return RatioCar(firstCar, firstCar->key) < RatioCar(secondCar, secondCar->key);
}