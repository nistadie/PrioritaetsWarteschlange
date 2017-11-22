/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "PQElement.h"

//Konstruktor
PQElement::PQElement(){
    
}

//Destruktor
PQElement::~PQElement(){
    
}

//Gibt die Priorität des Elementes zurück
int PQElement::priority() const{
    return prio;
}

//Weisst dem Element einer IdentNummer zu
void PQElement::set_number(int _number){
    nummer = _number;
}

//Weisst dem Element einer Priorität zu
void PQElement::set_priority(int _prio){
    prio = _prio;
}

//Kann man nehmen , muss man aber nicht :D
bool PQElement::operator <(const PQElement& element) const{
    return (prio < element.prio);
}

//Gebe die IdentNummer des Elementes zurück
int PQElement::get_number() const {
	return nummer;
}