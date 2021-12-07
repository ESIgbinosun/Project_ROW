#include <stdio.h>
#include <wiringPi.h>

#define POMP    7
#define HIGH    1
#define LOW     0

int main(void) {
    printf("Water POMP is online\n");
    wiringPiSetup();
    pinMode(POMP, OUTPUT);

    while (1) {

        char chr = getchar();

        switch (chr) {
            case 's':
                printf("Pomp activated\n");
                digitalWrite(POMP, HIGH);
                break;

            case 'd':
                printf("Pomp deactivated\n");
                digitalWrite(POMP, LOW);
                break;

            default:
                printf("Pomp status\n");
        }


    }
}

// Created by stefano on 18/11/2021.
//

