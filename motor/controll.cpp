#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <unistd.h>
#include <stdio.h>
#include <conio.h>

void goForwards(int fd); //prototype
void goBackwards(int fd); //prototype
void stop(int fd); //prototype
void goLeft(int fd); //prototype
void goRight(int fd); //prototype

int main(){

    int fd;
    fd = wiringPiI2CSetup(0x32);


	while(1){

		char ch = 0;
		ch = getch();

			switch(ch) {

			case 'w':
				printf("de robot gaat naar vooren\n");
				goForwards(fd);
				break;

			case 's':
				printf("de robot gaat naar achteren\n");
				goBackwards(fd);
				break;

			case 'a':
				printf("de robot gaat naar links\n");
				goLeft(fd);
				break;

			case 'd':
				printf("de robot gaat naar rechts\n");
				goRight(fd);
				break;

			default:
				printf("HIJ IS GESTOPT\n");
				stop(fd);
				break;
			}
	}
	return 0;
}

void goForwards(int fd) {
    unsigned char arr[7] = {7, 3, 0x22, 1, 3, 0x22, 1};
    write(fd, &arr[0], 7);
}

void stop(int fd) {
    unsigned char arr[7] = {7, 3, 0x22, 0, 3, 0x22, 0};
    write(fd, &arr[0], 7);
}

void goBackwards(int fd) {
    unsigned char arr[7] = {7, 3, 0x22, 2, 3, 0x22, 2};
    write(fd, &arr[0], 7);
}

void goLeft(int fd) {
    unsigned char arr[7] = {7, 3, 0x50, 2, 3, 0x50, 1};
    write(fd, &arr[0], 7);
}

void goRight(int fd) {
    unsigned char arr[7] = {7, 3, 0x50, 1, 3, 0x50, 0};
    write(fd, &arr[0], 7);
}

