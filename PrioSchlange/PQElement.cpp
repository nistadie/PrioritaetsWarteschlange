/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "PQElement.h"

PQElement::PQElement(){
    
}

PQElement::~PQElement(){
    
}

int PQElement::priority() const{
    return prio;
}

void PQElement::set_number(int _number){
    nummer = _number;
}

void PQElement::set_priority(int _prio){
    prio = _prio;
}

bool PQElement::operator <(const PQElement& element) const{
    return (prio < element.prio);
}