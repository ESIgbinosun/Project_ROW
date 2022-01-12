


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <stdbool.h>





#define encoderOutput 0
static volatile int globalCounter ;
int rpm;

int interval = 1000;
long previousMillis = 0;
long currentMillis = 0;
//bool measureRpm = false;


//Interrupt service routine:

void wheelInterrupt(void) { ++globalCounter;fflush(stdout); }


int main(void)
{
    wiringPiSetup();
    pullUpDnControl(encoderOutput,PUD_DOWN);

    //initialisation
    wiringPiISR (encoderOutput, INT_EDGE_FALLING, &wheelInterrupt) ;
    previousMillis = millis();

    while(1)
    {
        currentMillis = millis();
        if (currentMillis - previousMillis > interval) {
            previousMillis = currentMillis;

            rpm = (float) (globalCounter * 60 / 20);

            if(rpm > 0){
                printf("RPM: %d \n", rpm );

            }
            globalCounter = 0;

            //printf("RPM: %d \n", rpm , globalCounter);
        }
        //printf("RPM: %d \n",globalCounter);

        usleep(500);

    };

    return 0;
}
