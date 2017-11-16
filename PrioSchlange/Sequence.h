/**************************************************************
* Schnittstelle der Klasse Sequence.
* Kann als Basisklasse fuer Klassen verwendet werden, die
* Sortier-Verfahren implementieren.
* Autor: Heinz-Josef Eikerling, HS OS
* 16.08.2016: Fertigstellung
* To Do:
* - %
**************************************************************/

#pragma once
#include <string>
#include "Random.h"

/* Durch Setzen der Variable koennen die Vertauschen gezaehlt werden. */
/* Per 'define' und 'undef' ein- und ausschalten. */
/* Achtung: die Aufrufe ben�tigen Zeit! */
#define CNT_SWAPS_COMPS
//#undef CNT_SWAPS_COMPS

using namespace std;

class Sequence
{
protected:
	int size;
	int time;
	int* a;
public:
	static unsigned long long swaps;
	static unsigned long long comps;
public:
        Sequence(){}
	Sequence(int s);
	~Sequence();

	/* Erzeugung / Restaurierung */
	void generateRandom();
	void store(string fname);
	void restore(string fname);

	/* Eigenschaften auslesen */
	bool check();
	double averageDuplicates();
	void resetStats() { swaps = 0;	comps = 0;	time = 0; }

	/* Methoden zum Zugriff auf das Feld */
	int getElementAt(int idx) { return a[idx]; }
	int getSize() { return size; }
	int getTime() { return time; }
	inline void swap(int i, int j) {
		int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
#ifdef CNT_SWAPS_COMPS
		incSwaps();
#endif
	}
	
	/* Statistik-Funktionen */
	inline void incSwaps() { swaps++; }
	inline void incComps() { comps++; }
};
