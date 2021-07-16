int ledPin = 7;
int tempPin = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(tempPin, INPUT);
  Serial.begin(9600);
}
 
void loop()
{
  float read = analogRead(tempPin);
  float voltage = read / 1024 * 5;
  float temp = (voltage - 0.5) * 100;
  
  String hotOrCold = "cold";
  
  if (temp > 20) {
  	hotOrCold = "hot";
	digitalWrite(ledPin, HIGH);
  } else {
  	digitalWrite(ledPin, LOW);
  }
  
  Serial.print("\ntemp: ");
  Serial.print(temp);
  Serial.print(" (" + hotOrCold + ")");
  
  delay(1000);
}
