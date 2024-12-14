/// Use GPIO 21 and 22 for SDA and SCL respectively for I2C interface with ESP32

#include <LiquidCrystal_I2C.h> // yo gotta install this lib 1st

#define c 0.0343

const int lcd_r = 2;
const int lcd_c = 16;
const int trigger = 5;
const int echo = 18;
long duration;
double dist;

LiquidCrystal_I2C lcd(0x27, lcd_c, lcd_r);

void setup()
{
	Serial.begin(115200);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	lcd.init();
	lcd.backlight(); // remove if you dont wanna burn your eyes in the bright yellow or blue light
}

void loop()
{
	digitalWrite(trigger, LOW);
	delayMicroseconds(2);

	digitalWrite(trigger, HIGH);
	delayMicroseconds(10);

	digitalWrite(trigger, LOW);

	duration = pulseIn(echo, HIGH);
	distanceCm = duration * c / 2;

	lcd.clear();

	Serial.print(" dist in cm: ");
	Serial.println(dist);

	lcd.setCursor(0, 0);
	lcd.print("Distance:");

	lcd.setCursor(1, 0);
	lcd.print(dist);

	delay(1000);
}