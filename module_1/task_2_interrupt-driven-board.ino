int ledPin = 7;
int buttonPin = 2;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(buttonPin), the_ISR, CHANGE);
}
 
void loop()
{
  //nothing in loop
}


void the_ISR()
{
  bool read = digitalRead(buttonPin);
  if (read) {
	digitalWrite(ledPin, HIGH);
  } else {
  	digitalWrite(ledPin, LOW);
  }
  Serial.print("\nPressed down: ");
  Serial.print(read);
}
