/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


int COOL[6] = {3, 5, 6, 9, 10, 11};

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  for (int i = 0; i < 6; i++) pinMode(COOL[i], OUTPUT); //настройка ног
  Serial.begin(9600);
}


void OnOff(int pin)
{
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
}
// the loop function runs over and over again foreve

int cmd = 77;

void loop() {
  //Serial.write("Hello");
  if (Serial.available())
  {
    cmd = Serial.read();
    //Serial.write(cmd);
    if ((cmd/10) < 6) 
    {    
      //Serial.write(cmd/10);
      if((cmd%10) > 0) 
      {
        Serial.println("OK");
        digitalWrite(COOL[cmd/10], HIGH);
      }
      else digitalWrite(COOL[cmd/10], LOW);
    } 
    else
    {
      Serial.println("YOU BAD BOY");
    }
  }
 
}
