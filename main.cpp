#include <iostream>
#include <fstream>
#include "conteiner_atd.h"

using namespace std;

namespace simple_animals
{
	void Init(container &c) ;
	void Clear(container &c);
	void In(container &c, ifstream &ifst) ;
	void Out(container &c, ofstream &ofst) ;
	void MultiMethod(container &c, ofstream &ofst);
}

using namespace simple_animals;

int main(int argc, char* argv[]) 
{
	if(argc !=3)	
	{
		cout << "incorrect command line! " "Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start"<< endl;
	container c;
	Init(c);
	In(c, ifst);
    ofst << "Заполненный контейнер. " << endl;
	Out(c, ofst);
	MultiMethod(c, ofst);
	Clear(c);
    ofst << "Пустой контейнер. " << endl;
	Out(c, ofst);
	cout << "Stop"<< endl;
	system ("pause");

	return 0;
}
