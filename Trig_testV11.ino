const int CH1IN1 = 2;                                         //Setting the digital pin numbers on the Arduino to drive motor controllers (leds for testing)
const int CH1IN2 = 3;                                         //Green = forward, Red = reverse
const int CH2IN1 = 4;
const int CH2IN2 = 5;
const int CH3IN1 = 6;
const int CH3IN2 = 7;
const unsigned int MAX_CMD_LEN = 9;                           //Set some max value for the cmd string?
static char cmd[MAX_CMD_LEN];                             //Create an array to hold the incoming command
static unsigned int cmd_pos = 0;

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
  while (Serial.available() > 0)                                //Check to see if anything is available in the serial receive buffer
    {
      char inByte = Serial.read();                              //Read the next available byte in the serial receive buffer
      if ( inByte != '\n' && ( cmd_pos < MAX_CMD_LEN - 1) )     //Message coming in (check not terminating character) and guard for over message size
    {
      cmd[cmd_pos] = inByte;                                    //Add incoming byte to array
      cmd_pos ++;                                               //Increment cmd_pos counter
      }
      else
     {
      cmd[cmd_pos] = '\0';                                      //add the null
     Serial.println(cmd);                                       //echo the command
//      cmd_pos = 0;
 
     }
    }

   if (strcmp(cmd, "*SSCTRG1") == 0)
   {
     digitalWrite(CH1IN1, HIGH);
     delay(2000);
     digitalWrite(CH1IN1, LOW);
     digitalWrite(CH1IN2, HIGH);
     delay(2000);
     digitalWrite(CH1IN2, LOW);
   }
   else if (strcmp(cmd, "*SSCTRG2") == 0)
   {
     digitalWrite(CH2IN1, HIGH);
     delay(2000);
     digitalWrite(CH2IN1, LOW);
     digitalWrite(CH2IN2, HIGH);
     delay(2000);
     digitalWrite(CH2IN2, LOW);
    }
    else if (strcmp(cmd, "*SSCTRG3") == 0)
    {
     digitalWrite(CH3IN1, HIGH);
     delay(2000);
     digitalWrite(CH3IN1, LOW);
     digitalWrite(CH3IN2, HIGH);
     delay(2000);
     digitalWrite(CH3IN2, LOW);
    }
    {
      cmd_pos = 0;
      Serial.flush();
      delay(1000);
   }
 }
