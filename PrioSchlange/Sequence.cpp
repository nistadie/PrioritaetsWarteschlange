/**************************************************************
* Sortieren durch Auswahl (SelectionSort).
* Autor: Heinz-Josef Eikerling, HS OS
* 16.08.2016: Fertigstellung
* To Do:
* - %
**************************************************************/

#ifdef _WIN32
#endif

#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "Sequence.h"
#include "Random.h"
#include "Debug.h"

using namespace std;

unsigned long long Sequence::swaps = 0;
unsigned long long Sequence::comps = 0;

Sequence::Sequence(int s)
{
	this->resetStats();
	size = s;
	a = new int[size];
}

Sequence::~Sequence(void)
{
	delete a;
}

void Sequence::generateRandom()
{
	Random rand(this->size);
	for (int i = 0; i < size; i++) {
		a[i] = rand.give();
	}
#ifdef DEBUG
	cout << "Array generated!" << endl;
#endif
}

void Sequence::store(string fname) {
	//	cout << "Storing on '" << fname << "'." << endl;
	ofstream fs(fname.c_str());
	fs << size << endl;
	for (int i = 0; i < size; i++)
		fs << a[i] << endl;
}

void Sequence::restore(string fname) {
#ifdef DEBUG
	cout << "Restoring from '" << fname << "'." << endl;
#endif
	ifstream fs(fname.c_str());
	if (!fs) {
		cerr << "Cannot open file '" << fname << "'" << endl;
		return;
	}
	fs >> size;
#ifdef DEBUG
	cout << size << " elements in file." << endl;
#endif
	delete a;
	/* reset field / statistics */
	a = new int[size];
	this->resetStats();
	for (int i = 0; i < size; i++) {
		int val;
                cout<<val<<endl;
		fs >> val; a[i] = val;
	}
}

bool Sequence::check() {
#ifdef DEBUG
	cout << "Checking array..." << endl;
#endif
	for (int i = 0; i < size - 1; i++) {
		if (a[i] > a[i + 1]) {
			cerr << "Error: wrong sorting at line " << i << endl;
			return false;
		}
	}
	return true;
}

double Sequence::averageDuplicates() {
#ifdef DEBUG
	cout << "Checking duplicates in sorted sequence ..." << endl;
#endif
	// current length of duplicates sequence
	double dups = 1;
	int dup_seq = 1;
	int last_val = a[0];
	for (int i = 1; i < size - 1; i++) {
		if (last_val == a[i]) {
			dup_seq++;
		}
		else {
			// end of sequence found -> compute new av. dups
			int n = i + 1;
			dups = (((n - dup_seq)*dups) + dup_seq*dup_seq) / n;
			// set new last_val
			last_val = a[i];
			dup_seq = 1;
		}
	}
	return dups;
}
