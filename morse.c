#include <Wire.h>
#include <Keypath.h>

#define LED 13
#define DOT 1000
#define DASH 3000

static const int keys[15][5] = {
	{DOT, DASH, DASH, DASH , DASH},
	{DOT, DOT, DASH, DASH, DASH},
	{DOT, DOT, DOT, DASH, DASH},
	{DOT, DOT, DOT, DOT, DASH},
	{DOT, DOT, DOT, DOT, DOT},
	{DASH, DOT, DOT, DOT, DOT},
	{DASH, DASH, DOT, DOT, DOT},
	{DASH, DASH, DASH, DOT, DOT},
	{DASH, DASH, DASH, DASH, DOT},
	{DASH, DASH, DASH, DASH, DASH},
	{DOT, DASH, 0, 0, 0},
	{DASH, DOT, DOT, DOT, 0},
	{DASH, DOT, DASH, DOT, 0},
	{DASH, DOT, DOT, 0, 0},
	{0, 0, 0, 0, 0}
};// 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, A, B, C, E, *

char hexaKeys[4][4] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
}

byte rowPins[4] = {9, 8, 7, 6}
byte colPins[4] = {5, 4, 3, 2}

Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, 4, 4);


int[] getMorseCode(char key){
	switch(key) {
		case '1' : return keys[0];
		case '2' : return keys[1];
		case '3' : return keys[2];
		case '4' : return keys[3];
		case '5' : return keys[4];
		case '6' : return keys[5];
		case '7' : return keys[6];
		case '8' : return keys[7];
		case '9' : return keys[8];
		case '0' : return keys[9];
		case 'A' : return keys[10];
		case 'E' : return keys[11];
		case 'C' : return keys[12];
		case 'D' : return keys[13];
		case '#' : return keys[14];
		case '*' : return 0; //FINISH
		default : 0; //ERROR
	}
}

int charCounter = 0;
char message[100];


void setup(void) {
	pinMode(LED, OUTPUT);
	Serial.begin(9600);
	Serial.println("Moorse Translator Initialized");
}


void loop(void){
	char key = keypad.getKey();
	message[charCounter];
	charCounter = charCounter++;
	delay(30)

//When the coode is finished, reset the counter
}

