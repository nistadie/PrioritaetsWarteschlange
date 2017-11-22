/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nicos
 *
 * Created on 8. November 2017, 12:14
 */

#include <cstdlib>
#include <iostream>
#include "PrioSchlange.h"
#include "Sequence.h"

using namespace std;

string noDubsDatei(int);
string randomDatei(int);
string wcDatei(int);

int main() {
    
    try{
        Sequence ss;
		//Sequence für die NoDubsDateien
		cout << "NoDubs-Testdateien werden geladen\n";
		for (int i = 0;i < 10;i++) {
			ss.restore(noDubsDatei(i));
			PrioSchlange schlange(ss.getSize());
			schlange.getSelection(ss);
			cout << schlange.size() << endl;
			cout << "Zeit fuer insert: " << schlange.get_insert_time()<<endl;
			cout << "Groesste Prioritaet: " << schlange.prioVonElement(schlange.maximum());
			cout << "\t Nummer des Elementes: " << schlange.nummerVonElement(schlange.maximum()) << endl;
			//schlange.update(65075, 1);
			//cout << "Groesste Prioritaet nach Update: " << schlange.prioVonElement(schlange.maximum())<<endl;
			//cout << "Element an erster Stelle wird removed !!\n";
			//schlange.remove(65075);
			//cout << "Neues Element an erster Stelle: " << schlange.prioVonElement(schlange.maximum()) << endl;
			PQElement temp = schlange.extractMax();
			cout << "Zeit fuer extract: " << schlange.get_extract_time() << endl;
			cout << "Anzahl der Vertauschungen: " << schlange.get_swaps() << endl;
			string name = "ausgabe_" + noDubsDatei(i);
			schlange.schreibeInDatei(name);

		}


		cin.get();
		//Sequence für die wcDateien
		cout << "WC-Testdateien werden geladen:\n";
		for (int i = 0;i < 10;i++) {
			ss.restore(wcDatei(i));
			PrioSchlange schlange(ss.getSize());
			schlange.getSelection(ss);
			cout << schlange.size() << endl;
			cout << "Zeit fuer insert: " << schlange.get_insert_time() << endl;
			cout << "Groesste Prioritaet: " << schlange.prioVonElement(schlange.maximum());
			cout << "\t Nummer des Elementes: " << schlange.nummerVonElement(schlange.maximum()) << endl;
			PQElement temp = schlange.extractMax();
			cout << "Zeit fuer extract: " << schlange.get_extract_time() << endl;
			cout << "Anzahl der Vertauschungen: " << schlange.get_swaps() << endl;
			string name = "ausgabe_" + wcDatei(i);
			schlange.schreibeInDatei(name);
		}

		cin.get();
		//Sequence für Random-Dateien
		cout << "Random-Testdateien werden geladen:\n";
		for (int i = 0;i < 8;i++){
			ss.restore(randomDatei(i));
			PrioSchlange schlange(ss.getSize());
			schlange.getSelection(ss);
			cout << schlange.size() << endl;
			cout << "Zeit fuer insert: " << schlange.get_insert_time() << endl;
			cout << "Groesste Prioritaet: " << schlange.prioVonElement(schlange.maximum());
			cout << "\t Nummer des Elementes: " << schlange.nummerVonElement(schlange.maximum()) << endl;
			PQElement temp = schlange.extractMax();
			cout << "Zeit fuer extract: " << schlange.get_extract_time() << endl;
			cout << "Anzahl der Vertauschungen: " << schlange.get_swaps() << endl;
			string name = "ausgabe_" + randomDatei(i);
			schlange.schreibeInDatei(name);
		}
        
    }
    catch (const char* error){
        cout<<"FAILURE!!!\n";
        cout<<error;
    }
	cin.get();
    return 0;
}

string noDubsDatei(int element) {
	string files[] = { "sample1_no_dups.txt", "sample2_no_dups.txt", "sample3_no_dups.txt",
					   "sample4_no_dups.txt", "sample5_no_dups.txt", "sample6_no_dups.txt", "sample7_no_dups.txt",
					   "sample8_no_dups.txt", "sample9_no_dups.txt", "sample10_no_dups.txt" };
	return files[element];
}

string wcDatei(int element) {
	string files[] = { "sample1_wc.txt", "sample2_wc.txt", "sample3_wc.txt",
					   "sample4_wc.txt", "sample5_wc.txt", "sample6_wc.txt", "sample7_wc.txt",
					   "sample8_wc.txt", "sample9_wc.txt", "sample10_wc.txt"};
	return files[element];
}

string randomDatei(int element) {
	string files[] = { "sample1_random.txt", "sample2_random.txt", "sample3_random.txt",
					   "sample4_random.txt", "sample5_random.txt", "sample6_random.txt",
					   "sample8_random.txt", "sample9_random.txt" };
	return files[element];
}

