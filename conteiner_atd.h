#ifndef __conteiner__
#define __conteiner__
namespace simple_animals 
{
	struct animal;
	struct container
	{
		enum {max_len = 100};
		int len; 
		animal *cont[max_len];
	};
}
#endif