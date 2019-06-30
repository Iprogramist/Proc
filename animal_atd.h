#ifndef __animal_atd__
#define __animal_atd__

#include "bird_atd.h"
#include "fish_atd.h"

namespace simple_animals 
{
	struct animal 
	{
		enum key {BIRD, FISH};
		key key; 
		char name[20];
    
		union
		{ 
			bird bir;
			fish fis;
		};
  };
} 
#endif
