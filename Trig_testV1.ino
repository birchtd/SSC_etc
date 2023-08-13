const int CH1IN1 = 2;
const int CH1IN2 = 3;
const int CH2IN1 = 4;
const int CH2IN2 = 5;
const int CH3IN1 = 6;
const int CH3IN2 = 7;

void setup() 
{
  Serial.begin(9600);
  pinMode(CH1IN1, OUTPUT);
  pinMode(CH1IN2, OUTPUT);
  pinMode(CH2IN1, OUTPUT);
  pinMode(CH2IN2, OUTPUT);
  pinMode(CH3IN1, OUTPUT);
  pinMode(CH3IN2, OUTPUT);
}

void loop() 
{
  char ch;
  if (Serial.available() > 0)
  {
   ch = Serial.read();
   if (ch == '1')
   {
     digitalWrite(CH1IN1, HIGH);
     delay(2000);
     digitalWrite(CH1IN1, LOW);
     digitalWrite(CH1IN2, HIGH);
     delay(2000);
     digitalWrite(CH1IN2, LOW);
   }
   else if (ch == '2')
   {
     digitalWrite(CH2IN1, HIGH);
     delay(2000);
     digitalWrite(CH2IN1, LOW);
     digitalWrite(CH2IN2, HIGH);
     delay(2000);
     digitalWrite(CH2IN2, LOW);
    }
    else if (ch == '3')
    {
     digitalWrite(CH3IN1, HIGH);
     delay(2000);
     digitalWrite(CH3IN1, LOW);
     digitalWrite(CH3IN2, HIGH);
     delay(2000);
     digitalWrite(CH3IN2, LOW);
    }
    else
    delay(1000);
    Serial.flush();
  }
}
