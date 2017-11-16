/**************************************************************
* Schnittstelle der Klasse SelectionSort.
* Autor: Heinz-Josef Eikerling, HS OS
* 16.08.2016: Fertigstellung
* To Do:
* - %
**************************************************************/

using namespace std;

#include "Sequence.h"

class SelectionSort : public Sequence
{
private:

protected:

public:
	SelectionSort(int s = 100);
	~SelectionSort(void);
	void sort();
};
