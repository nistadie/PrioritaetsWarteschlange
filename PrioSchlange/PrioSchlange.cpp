/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PrioSchlange.h"

PrioSchlange::PrioSchlange(int wert){
    max_length = wert;
    akt_length = 0;
    a = new PQElement[akt_length];
}

PrioSchlange::~PrioSchlange(){
    
}

PQElement& PrioSchlange::maximum() const throw (const char*){
    if(akt_length == 0){
        throw (const char*)("Die Prioritaetswarteschlange ist leer!!");
    }   
    return a[0];
}

PQElement PrioSchlange::extractMax() throw (const char*){
    if(akt_length == 0){
        throw (const char*)("Die Prioritaetswarteschlange ist leer!!");
    }
    PQElement temp = a[0];
    exchange(); // Tausche das Erste und das Letzte Element
    downheap(); // Stelle die Heap-Sort Eigenschaft wieder her
    return temp; // gebe das Extrahierte Element zurück
}

void PrioSchlange::insert(const PQElement& element) throw (const char*){
    if(akt_length < max_length){
        a[akt_length] = element;
        akt_length++;
        upheap();
    }
    else{
        throw (const char*)("Die Prioritätswarteschlange ist voll!!");
    }
    
}

int PrioSchlange::size()const{
    return akt_length;
}

void PrioSchlange::exchange(){
    a[0] = a[akt_length-1];
    akt_length--;
}

void PrioSchlange::downheap(){
    
    int zaehlerEbene =0;
    int akt_position=0;
    
    while(zaehlerEbene <= (akt_length/2)-2){
                                               
        if(  (a[akt_position].priority() < a[(akt_position*2)+1].priority())){ //Wenn die Wurzel kleiner ist als das linke Blatt
            if(akt_length%2 == 1){ //Prüft, ob ein rechtes Blatt existiert
                if(a[(akt_position*2)+1].priority() > a[(akt_position*2)+2].priority()) { //Wenn das linke Blatt größer ist als das Rechte
                    change(akt_position,((akt_position*2)+1)); //Tausche Wurzel und linkes Blatt
                    akt_position = (akt_position*2)+1;//Setze aktuelle Position auf das Linke Blatt
                }
                else{ //Wenn das linke Blatt kleiner ist als das Rechte
                    change(akt_position,((akt_position*2)+2)); //Tausche Wurzel und rechtes Blatt
                    akt_position = (akt_position*2)+2; // Setze aktuelle Position auf das rechte Blatt
                }
            }
            else{change(akt_position,((akt_position*2)+1)); // Falls kein Rechtes Blatt existiert
            akt_position = (akt_position*2)+1; // Setze aktuelle Position auf das linke Blatt
            }
        }       
        //Falls der Downheap erfüllt ist, wird die Methode abgebrochen
        else if ( (a[akt_position].priority() > a[(akt_position*2)+1].priority()) && (akt_length%2 ==0)){
            break;    
        }       
        else if( (a[akt_position].priority() > a[(akt_position*2)+1].priority()) && (a[akt_position].priority() > a[(akt_position*2)+2].priority()) && (akt_length%2==1)){
            break;
        }
        zaehlerEbene++;
    }  
}

void PrioSchlange::change(int pos_1, int pos_2){
    int temp = a[pos_1].priority();
    a[pos_1].set_priority(a[pos_2].priority());
    a[pos_2].set_priority(temp);
}

void PrioSchlange::upheap(){
   
    int akt_position = akt_length;
    
    while(akt_position >= 0){
    if(a[akt_position-1].priority() > a[(akt_position-1)/2].priority()){
        change(akt_position-1,(akt_position-1)/2);   
    }
    else if(a[akt_position-1].priority() < a[(akt_position-1)/2].priority()){
        break;
    }
    akt_position = (akt_position-1)/2;  
    }  
    downheap();
}

void PrioSchlange::getSelection(Sequence& sequence){
    for(int i=0;i<sequence.getSize();i++){
        PQElement objekt;
        objekt.set_number(i+1);
        objekt.set_priority(sequence.getElementAt(i));
        insert(objekt);
    }
}
        
