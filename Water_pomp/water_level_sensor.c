#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPiSPI.h>

#define CS_MCP3208 8 //BCM_GPIO_8

#define SPI_CHANNEL 0
#define SPI_SPEED   1000000 //1MHz

int read_mcp3208_adc(unsigned char adcChannel) {
    unsigned char buff[3];
    int adcValue = 0;

    buff[0] = 0x06 | ((adcChannel & 0x07) >> 2);
    buff[1] = ((adcChannel & 0x07) << 6);
    buff[2] = 0x00;

    digitalWrite(CS_MCP3208, 0); //Low : CS Active

    wiringPiSPIDataRW(SPI_CHANNEL, buff, 3);

    buff[1] = 0x0F & buff[1];
    adcValue = (buff[1] << 8) | buff[2];

    digitalWrite(CS_MCP3208, 1); //High : CS Inactive

    return adcValue;
}

int main (void) {
    int adcChannel = 0;
    int adcValue[8] = {0};

    if(wiringPiSetup() == -1) {
        fprintf (stdout, "Unable to start wiringPi: %s\n", strerror(errno));
        return 1;
    }

    if(wiringPiSPISetup(SPI_CHANNEL, SPI_SPEED) == -1) {
        fprintf (stdout, "wiringPiSPISetup Failed: %s\n", strerror(errno));
        return 1;
    }

    pinMode(CS_MCP3208, OUTPUT);

    int val;
    while(1) {
        delay(1000);
        adcValue[2] = read_mcp3208_adc(0); //Moisture Sensor
//        printf("Moisture = %5d\n", adcValue[2]);
        val = adcValue[2];
        if(val<=3000){
        printf("Water Level: low\n");
        }
        else{
            printf("Water Level: high\n");
        }



    }

    return 0;

}
//
// Created by stefa on 29/12/2021.
//

