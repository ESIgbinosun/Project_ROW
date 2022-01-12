#include <wiringPi.h>
#include <stdio.h>
#include "ADC.cpp"


#define sensor 11

int val=0;
int main(void) {

    wiringPiSetup();
    pinMode(sensor, OUTPUT);
    //float ADC::read_input(0);

    float val = ADC::read_input(0);

    if(val<=100){
        cout<<"Water Level: Empty\n";
    }
    else if(val>100 && val<=300){
        cout<<"Water Level: Low\n";
    }
    else if(val>300 && val<=330){
        cout<<"Water Level: Medium\n";
    }
    else if(val>330){
        cout<<"Water Level: High\n";
    }
    delay(1000);



}//
// Created by stefa on 11/01/2022.
//

