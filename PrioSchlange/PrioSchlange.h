/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrioSchlange.h
 * Author: nicos
 *
 * Created on 8. November 2017, 12:20
 */

#ifndef PRIOSCHLANGE_H
#define PRIOSCHLANGE_H
#include "PQElement.h"
#include "Sequence.h"


class PrioSchlange{
    int akt_length; //------------------------------------------ Akuelle Anzahl der Elemente in der PrioSchlange
    int max_length; //------------------------------------------ Max Anzahl der möglichen Elemente in der PrioSchlange
	int insert_time; //----------------------------------------- Zeit für die Berechnung
	int extract_time; //---------------------------------------- Zeit für das extrahieren des größten Elements
	int extract_length; //-------------------------------------- Enthält die länge des sortierten Arrays nach der Schleife extract MAX
	int swaps; //----------------------------------------------- Anzahl der Vertauschungen
	PQElement* a; //-------------------------------------------- Array mit PQElementen
	PQElement* sorted_a; //------------------------------------- Enthält alle Elemente in Sortierter reihenfolge
	int* referenzfeld; //--------------------------------------- Array mit Referenzen ( INDEX ) auf die Elemente in dem Array a
public:
    PrioSchlange(int); //--------------------------------------- Standardkonstrruktor
    ~PrioSchlange();//------------------------------------------ Standarddestruktor
    PQElement& maximum ()const throw (const char*); //---------- Gebe das größte Element zurück a[0]
    PQElement extractMax () throw (const char*); //------------- Extrahiere das Größte Element und bring den Baum wieder in Ordnung (downheap())
    void insert(const PQElement&) throw (const char*); //------- Füge ein neuees Element hinzu und bring den Baum wieder in Ordnung (upheap())
    void exchange(); //----------------------------------------- Bringe das kleinste Element an die Erste stelle
    void change(int,int); //------------------------------------ Tausche den Platz zweier Elemente
    void downheap(int); //-------------------------------------- Sortieren von der Wurzel zu den Blättern
    void upheap(int); //---------------------------------------- Sortieren von den Blättern bis zur Wurzel
    int size()const; //----------------------------------------- Gebe die Anzahl der Elemente in der PrioSchlange zurück
    void getSelection(Sequence&); //---------------------------- Übergibt eine Sequence,damit die Werte im Sequence-Array an das PQElement Array übergeben werden können
	int prioVonElement(const PQElement&); //-------------------- Gibt die Priorität eines Elementes zurück
	int nummerVonElement(const PQElement&); //------------------ Gibt die Nummer eines Elementes zurück
	int get_swaps() const; //----------------------------------- Gebe die Anzahl der Vertauschungen zurück
	double get_extract_time() const; //------------------------- Gebe die Zeit für das extrahieren Zurück
	double get_insert_time() const; //-------------------------- Gebe die Zeit für die Berechnung zurück
	int get_extract_length() const; //-------------------------- Gibt die Anzahl der Elemente im sortierten Array zurück
	void update(int, int); //----------------------------------- Weist einem Element eine neue Priorität zu
	void remove(int); //---------------------------------------- Entfernt ein Element an der Stelle INDEX
	void schreibeInDatei(string); //---------------------------- Schreibt das Fertig sortierte Array in eine Ausgabedatei
};

#endif /* PRIOSCHLANGE_H */

