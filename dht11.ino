#include "DHT.h"
#define dht_pin 18

DHT dht(dht_pin, DHT11);
void setup()
{

	Serial.begin(115200);
	dht.begin();
}

void loop()
{
	double humi = dht.readHumidity();
	double temp = dht.readTemperature();
	Serial.print("Temperature: ");
	Serial.print(temp);
	Serial.print("C");
	Serial.print("/nHumidity: ");
	Serial.println(humi);
	delay(1000);
}