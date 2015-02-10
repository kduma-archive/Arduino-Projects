#include "Arduino.h"  //standard types and constants of the Arduino language

enum Numb { NOTHING = -1, ZERO = 0, ONE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5,
SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, DECIMAL_POINT = 10}; // 10 means decimal point, -1 means nothing is being displayed

class kdLEDDisplay {

	public:
	Numb displaying;   // indicate which number is being displayed

	private:
	int aPin;  // these are the output pins
	int bPin;
	int cPin;
	int dPin;
	int ePin;
	int fPin;
	int gPin;
	int dpPin;

	int y1Pin;  // these are used to control display which digit
	int y2Pin;
	int y3Pin;
	int y4Pin;

	public:
	kdLEDDisplay();  // constructor with default output pins
	kdLEDDisplay(int a, int b, int c, int d, int e, int f, int g, int dp, int y1, int y2, int y3, int y4);  // constructor with specified output pins
	void DisplayDigit (Numb digit);
	void DisplayNumber (int number);

};
