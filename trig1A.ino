/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

 
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;      // the number of the pushbutton pin
const int adEnPin =  6;      // the number of the adEn pin
const int trigPin = 4;       // the number of the trigger pin
const int ledPin = 13;      // the number of the ledPin
unsigned long seconds = 1000UL; // capital L!!
unsigned long minutes = seconds * 60;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(adEnPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    
    digitalWrite(ledPin, HIGH);
    delay(10 * minutes);
    digitalWrite(ledPin, LOW);
    digitalWrite(adEnPin, HIGH);
    delay(2000);
    digitalWrite(trigPin, HIGH);
    delay(100);
    digitalWrite(trigPin, LOW);
    delay(5000);
    digitalWrite(adEnPin, LOW);
  } else  {
    digitalWrite(ledPin, LOW);
    digitalWrite(adEnPin, LOW);
    digitalWrite(trigPin, LOW);
    
  }
}
