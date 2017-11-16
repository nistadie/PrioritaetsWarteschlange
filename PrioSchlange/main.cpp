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

/*
 * 
 */
int main() {
    
    try{
        Sequence ss;       
        ss.restore("sample1_no_dups.txt");       
        PrioSchlange schlange(ss.getSize());       
        //schlange.getSelection(ss);
        
    }
    catch (const char* error){
        cout<<"FAILURE!!!\n";
        cout<<error;
    }
    return 0;
}

