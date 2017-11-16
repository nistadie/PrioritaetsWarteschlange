/**************************************************************
* Random.cpp
* Bestimmung von Zufallszahlen (Integer-Werte). 
* Mit dieser Klasse können auch Zufallszahlen erzeugt werden, die größer
* als RAND_MAX (der Wert ist je nach Plattform unterschiedlich; z.B. 
* 32767 = 2^15 - 1) sind. Dies wird erreicht, in dem zwei Zufallszahlen 
* konkateniert werden.
*
* Autor: H.-J. Eikerling, HS OS
* 21.9.2012: Initiale Version.
* To Do:
* - %
**************************************************************/

#ifdef _WIN32
#endif

#include <time.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>

#include "Random.h"
#include "Debug.h"

using namespace std;

/*
 * Ctor.
 */
Random::Random(int req_range = -1)
{
	max_range = req_range;
	fill_mask = 0;
	fill_bits = 0;
	cout << "RAND_MAX = " << RAND_MAX << endl;
	
	/* Anzahl der Bits bestimmen, die für die Bereichserweiterung notwendig sind. */
	if (req_range > RAND_MAX) {
		int req_padding = (max_range / RAND_MAX);
#ifdef DEBUG
		cout << "Required padding is: " << req_padding << endl;
#endif
		int cur_padding = 1;
		while (cur_padding < req_padding) {
			cur_padding = cur_padding << 1;
			fill_mask = fill_mask << 1;
			fill_mask += 1;
			fill_bits++;
		}
	}
#ifdef DEBUG
	cout << "No. of fill bits is: " << fill_bits << endl;
	cout << "Fill mask is: " << fill_mask << endl;
	srand(clock());
#endif
	srand (12);
}

Random::~Random()
{
}

/*
 * Liefert eine Zufallszahl (int-Wert).
 */
int Random::give()
{
	int value = rand();
	int sec_value = rand();

	for (int i = 1; i <= fill_bits; i++) {
		value = value << 1;
	}	
	value += (sec_value &&  fill_mask);
	return (value % max_range);
}
