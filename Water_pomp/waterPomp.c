#include <stdio.h>
#include <wiringPi.h>

#define POMP    7

int main(void)
{
    printf("Water POMP \n");
    wiringPiSetup ();
    pinMode (POMP, OUTPUT);

    for (;;){
        printf("Pomp on\n");
        digitalWrite (POMP,1);
        delay (3000);
        prinf("Pomp off\n")
        digitalWrite (POMP,0);
        delay (3000);


    }
    return 0;
}//
// Created by stefano on 18/11/2021.
//

