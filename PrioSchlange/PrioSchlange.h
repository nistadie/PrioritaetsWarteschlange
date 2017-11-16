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
    PQElement* a; //-------------------------------------------- Array mit PQElementen
public:
    PrioSchlange(int); //--------------------------------------- Standardkonstrruktor
    ~PrioSchlange();//------------------------------------------ Standarddestruktor
    PQElement& maximum ()const throw (const char*); //---------- Gebe das größte Element zurück a[0]
    PQElement extractMax () throw (const char*); //------------- Extrahiere das Größte Element und bring den Baum wieder in Ordnung (downheap())
    void insert(const PQElement&) throw (const char*); //------- Füge ein neuees Element hinzu und bring den Baum wieder in Ordnung (upheap())
    void exchange(); //----------------------------------------- Bringe das kleinste Element an die Erste stelle
    void change(int,int); //------------------------------------ Tausche den Platz zweier Elemente
    void downheap(); //----------------------------------------- Sortieren von der Wurzel zu den Blättern
    void upheap(); //------------------------------------------- Sortieren von den Blättern bis zur Wurzel
    int size()const; //----------------------------------------- Gebe die Anzahl der Elemente in der PrioSchlange zurück
    void getSelection(Sequence&); //---------------------------- Übergibt eine Sequence,damit die Werte im Sequence-Array an das PQElement Array übergeben werden können
};

#endif /* PRIOSCHLANGE_H */

