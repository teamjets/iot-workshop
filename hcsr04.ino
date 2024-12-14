#define c 0.0343

const int trigger = 5;
const int echo = 18;
long duration;
double dist;

void setup()
{
	Serial.begin(115200);
	pinMode(trigger, OUTPUT);
	pinMode(echo, INPUT);
}

void loop()
{
	digitalWrite(trigger, LOW);
	delayMicroseconds(2);

	digitalWrite(trigger, HIGH);
	delayMicroseconds(10);

	digitalWrite(trigger, LOW);

	duration = pulseIn(echo, HIGH);
	dist = duration * c / 2;

	Serial.print(" dist in cm: ");
	Serial.println(dist);

	delay(1000);
}