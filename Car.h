#pragma once
#ifndef _Cars_
#define _Cars_

#include "Gruz.h"
#include "Bus.h"
#include "Leg.h"

struct Cars
{
	enum key { GRUZOV=1 , BUS, LEGKOV };
	key key;
	int power;
	float exp;
	union
	{		
		Gruz gruzovik;
		Bus avtobus;
		Leg legkovaya;
	};
};

#endif