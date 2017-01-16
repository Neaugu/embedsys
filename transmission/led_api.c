#define _BSD_SOURCE

#include "projet.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void dot(){
write_file(1);
usleep(500000);
write_file(0);
usleep(250000);

}

void dash(){
write_file(1);
usleep(1000000);
write_file(0);
usleep(250000);

}

void write_file(int value){

FILE *f = fopen("/sys/class/gpio/gpio117/value", "w");

if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}


fprintf(f, "%d", value);

fclose(f);

//(value ==0)?printf("."):printf("_");

}

void play_morse(char* sentence){



int len = strlen(sentence);
int i;

for(i=0; i<len; i++){

	
	switch(sentence[i]) {

	   case '0':
		  dot();
		  break; /* optional */
	
	   case '1':
		  dash();
		  break; /* optional */
	  
	  case '2':
		  usleep(500000);
		  break; /* optional */
	  
	  case '3':
		  usleep(1000000);
		  break; /* optional */
		  
	}
	
}
// remise a zero de la LED
FILE *f = fopen("/sys/class/gpio/gpio117/value", "w");

if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}


fprintf(f, "%d", 0);

fclose(f);
}
