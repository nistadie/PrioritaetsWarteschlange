/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PQElement.h
 * Author: nicos
 *
 * Created on 8. November 2017, 12:20
 */

#ifndef PQELEMENT_H
#define PQELEMENT_H

class PQElement{
    int prio; //---------------------------------------------- Prioritätswert
    int nummer; //-------------------------------------------- Fortlaufende, eindeutige Nummer
    
public:
    PQElement(); //------------------------------------------- Standardkonstruktor
    ~PQElement(); //------------------------------------------ Standarddestruktor
    int priority() const; //---------------------------------- Gebe die Priorität des PQElementes zurück
	int get_number() const; //-------------------------------- Gibt die Nummer es Elementes zurück
    void set_number(int); //---------------------------------- Weißt dem Element eine Nummer zu
    void set_priority(int); //-------------------------------- Weise dem Element eine neue Priorität zu
    bool operator < (const PQElement&) const; //-------------- Vergleicht, ob das Linke Element größer ist als das rechte und gibt einen Wahrheitswert zurück
    
};

#endif /* PQELEMENT_H */

