#pragma once
#ifndef _Cars_
#define _Cars_

#include "Gruz.h"
#include "Bus.h"

struct Cars
{
	enum key { GRUZOV=1 , BUS };
	key key;
	int power;
	union
	{		
		Gruz gruzovik;
		Bus avtobus;
	};
};

#endif