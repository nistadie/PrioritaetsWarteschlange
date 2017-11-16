/**************************************************************
* Generierung von Zufallszahlen.
* Autor: H.-J. Eikerling, HS OS
* 21.9.2012: Initiale Version.
* To Do:
* - %
**************************************************************/

#pragma once
#include <string>
using namespace std;

class Random  {
protected:
	int max_range;
private:
	short fill_bits;
	int fill_mask;
public:
	Random(int max_range);
	~Random();
	int give();
};
