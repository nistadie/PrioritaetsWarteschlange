/**************************************************************
* Sortieren durch Auswahl (SelectionSort).
* Autor: Heinz-Josef Eikerling, HS OS
* 16.08.2016: Fertigstellung
* To Do:
* - %
**************************************************************/

#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "Environment.h"
#include "Debug.h"
#include "SelectionSort.h"

using namespace std;

SelectionSort::SelectionSort(int s) : Sequence(s)
{}

SelectionSort::~SelectionSort(void)
{}

void SelectionSort::sort() {
	/* Zeitmessung starten */
	clock_t start = clock();

	/* Algorithmus: iteriert Minimumn findden und an den Anfang platzieren */
	for (int i = 0; i < this->size - 1; i++) {
		int min_i = i;
		for (int j = i + 1; j < this->size; j++) {
#ifdef CNT_SWAPS_COMPS
			incComps();
#endif
			if (a[j] < a[min_i]) min_i = j;
		}
		swap(min_i, i);
	}

	clock_t end = clock();
	/* Zeitmessung beenden: durch Multiplikation mit 1000 und Division ergibt */ 
	/* sich ein Zeitwert in ms. */
	time = ((end - start) * 1000) / CLOCKS_PER_SEC;
}