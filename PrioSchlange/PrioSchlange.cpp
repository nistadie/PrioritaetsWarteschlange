/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PrioSchlange.h"
#include <time.h>
#include <iostream>
#include <fstream>

//Konstruktor
PrioSchlange::PrioSchlange(int wert){
    max_length = wert;
    akt_length = 0;
	insert_time = 0;
	extract_time = 0;
	swaps = 0;
    a = new PQElement[max_length];
	sorted_a = new PQElement[max_length];
	referenzfeld = new int[max_length];
}

//Destruktor
PrioSchlange::~PrioSchlange(){
}

//Gebe das Element mit der größten Priorität zurück
PQElement& PrioSchlange::maximum() const throw (const char*){
    if(akt_length == 0){
        throw (const char*)("Die Prioritaetswarteschlange ist leer!!");
    }   
    return a[0];
}

//Ziehe das größte Element raus und stell den Heap wieder her
PQElement PrioSchlange::extractMax() throw (const char*){
	clock_t start = clock();
    if(akt_length == 0){
        throw (const char*)("Die Prioritaetswarteschlange ist leer!!");
    }
	PQElement temp = a[0];
	for (int i = akt_length - 1;i >= 0;i--) {

		exchange(); // Tausche das Erste und das Letzte Element
		downheap(0); // Stelle die Heap-Sort Eigenschaft wieder her
	}
	clock_t end = clock();
	extract_time = ((end - start) * 1000) / CLOCKS_PER_SEC;
	return temp; // gebe das Extrahierte Element zurück
}

//Füge dem Array ein neues Element hinzu
void PrioSchlange::insert(const PQElement& element) throw (const char*){
    if(akt_length < max_length){
        a[akt_length] = element;
		referenzfeld[element.get_number()] = akt_length;
        akt_length++;
        upheap(akt_length);
    }
    else{
        throw (const char*)("Die Prioritätswarteschlange ist voll!!");
    }
    
}

//Gebe die aktuelle länge des Arrays zurück
int PrioSchlange::size()const{
    return akt_length;
}

//Setze das letzte Element an die Stelle des ersten
void PrioSchlange::exchange(){
	sorted_a[akt_length-1] = a[0];
	referenzfeld[a[akt_length - 1].get_number()] = 0;
    a[0] = a[akt_length-1];
    akt_length--;
}

//downheap() , erklärt sich von selbst :D
void PrioSchlange::downheap(int index){
    
    int wurzel=index;
    
	while (1) {
		int linkesBlatt = (wurzel * 2) + 1;
		int rechtesBlatt = (wurzel * 2) + 2;

		if (linkesBlatt <= (akt_length-1)) {
			if ((a[wurzel].priority() < a[linkesBlatt].priority()) || a[wurzel].priority() < a[rechtesBlatt].priority()) { //Wenn die Wurzel kleiner ist als das linke Blatt
				//if (akt_length % 2 == 1) { //Prüft, ob ein rechtes Blatt existiert
				if (rechtesBlatt < akt_length) {
					if (a[linkesBlatt].priority() > a[rechtesBlatt].priority()) { //Wenn das linke Blatt größer ist als das Rechte
						change(wurzel, linkesBlatt); //Tausche Wurzel und linkes Blatt
						wurzel = linkesBlatt;//Setze aktuelle Position auf das Linke Blatt
					}
					else  { //Wenn das linke Blatt kleiner ist als das Rechte
						change(wurzel, rechtesBlatt); //Tausche Wurzel und rechtes Blatt
						wurzel = rechtesBlatt; // Setze aktuelle Position auf das rechte Blatt
					}
				}
				//}
				else {
					change(wurzel, linkesBlatt); // Falls kein Rechtes Blatt existiert
					wurzel = linkesBlatt; // Setze aktuelle Position auf das linke Blatt
				}
			}
			else if ((linkesBlatt > (akt_length - 1)) || (rechtesBlatt > (akt_length - 1))) {
				break;
			}

			//Falls der Downheap erfüllt ist, wird die Methode abgebrochen
			else if ((a[wurzel].priority() > a[linkesBlatt].priority()) && (akt_length % 2 == 0)) {
				break;
			}
			//Falls der Heap erfüllt ist
			else if ((a[wurzel].priority() > a[linkesBlatt].priority()) && (a[wurzel].priority() > a[rechtesBlatt].priority()) && (akt_length % 2 == 1)) {
				break;
			}
			else if (a[wurzel].priority() > a[linkesBlatt].priority() && a[wurzel].priority() == a[rechtesBlatt].priority()) {
				break;
			}
			else if (a[wurzel].priority() > a[rechtesBlatt].priority() && a[wurzel].priority() == a[linkesBlatt].priority()) {
				break;
			}
			else if (a[wurzel].priority() == a[rechtesBlatt].priority() && a[wurzel].priority() == a[linkesBlatt].priority()) {
				break;
			}


			//Falls das Rechte Blatt in der untersten Wurzel größer ist
			else if ((a[wurzel].priority() > a[linkesBlatt].priority()) && (a[wurzel].priority() < a[rechtesBlatt].priority()) && (akt_length % 2 == 1)) {
				change(wurzel, rechtesBlatt);
				break;
			}
		}
		else {
			break;
		}
	}
}

void PrioSchlange::change(int pos_1, int pos_2) {
	PQElement temp = a[pos_1];
	referenzfeld[a[pos_1].get_number()] = pos_2;
	referenzfeld[a[pos_2].get_number()] = pos_1;
    a[pos_1] = a[pos_2];
    a[pos_2] = temp;
	swaps++;
}

void PrioSchlange::upheap(int index){
   
    int akt_position = index;

	if (akt_length > 1) { //Wenn das Array mehr als 1 Element enthält
		while (akt_position > 1) { //upheap durchführen bis zur Wurzel

			int wurzel = (akt_position / 2) - 1;
			int blatt = akt_position-1;

			if (a[blatt].priority() > a[wurzel].priority()) {
				change(blatt, wurzel);
			}
			else if (a[blatt].priority() < a[wurzel].priority()) {
				break;
			}
			akt_position = wurzel + 1;
		}
		//downheap(0);
	}
}

void PrioSchlange::getSelection(Sequence& sequence){
	clock_t start = clock();
    for(int i=0;i<sequence.getSize();i++){

        PQElement objekt;
        objekt.set_number(i+1); // Weist dem Element eine Nummer hinzu
        objekt.set_priority(sequence.getElementAt(i)); //Schiebt die Priorität vom Sequence-Array in ein Element des PrioSchlange-Array

        insert(objekt);
    }
	clock_t end = clock();
	insert_time = ((end - start) * 1000) / CLOCKS_PER_SEC;
}

int PrioSchlange::prioVonElement(const PQElement& element) {
	return element.priority();
}

int PrioSchlange::nummerVonElement(const PQElement& element) {
	return element.get_number();
}

int PrioSchlange::get_swaps()const {
	return swaps;
}

double PrioSchlange::get_insert_time() const {
	return insert_time;
}

double PrioSchlange::get_extract_time() const {
	return extract_time;
}
        
int PrioSchlange::get_extract_length() const {
	return extract_length;
}

void PrioSchlange::update(int index, int zahl) {
	//a[An der Stelle mit dem Index "index"] wird um die Priorität zahl erhöht
	a[referenzfeld[index]].set_priority((a[referenzfeld[index]].priority()) + zahl);
	if (zahl < 0) {
		downheap(referenzfeld[index]);
	}
	else {
		upheap(referenzfeld[index]+1);//+1 , da man nicht den tatsächlichen INDEX an die upheap funktion übergibt, 
		//									sondern eigentlich die Anzahl der Elemente in der Insert Funktion
	}
}

void PrioSchlange::remove(int index) {
	int i = referenzfeld[index];
	change(i, akt_length - 1);
	akt_length--;
	downheap(i);
}

void PrioSchlange::schreibeInDatei(string name) {
	ofstream ausgabe(name);
	ausgabe << max_length<<endl;
	for (int i = max_length-1;i >= 0;i--) {
		ausgabe<<sorted_a[i].priority()<<endl;
	}
	ausgabe.close();
}
