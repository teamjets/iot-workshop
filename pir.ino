const int pir = 18;
void setup()
{
	pinMode(pir, INPUT);
	Serial.begin(115200);
}

void loop()
{
	int sensor_output;
	sensor_output = digitalRead(pir);
	if (sensor_output == LOW)
	{
		Serial.print("Watashi wa blind! \n");
		delay(500);
	}
	else
	{
		Serial.print("Miteruu yoo! \n");
		delay(500);
	}
}