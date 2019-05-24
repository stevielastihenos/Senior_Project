#include <Servo.h>


Servo myservo;
int pos;
const int buttonPin = 4;
unsigned long time = 0;
unsigned long duration1;
unsigned long duration2;
unsigned long duration3;


void setup()
{
 pinMode(buttonPin, INPUT);
 pinMode(2, OUTPUT);
 myservo.attach(9);               // Attach output pin 9 to force device(servo motor)
 myservo.write(100);              // Initialize position of force device
 pinMode(6,OUTPUT);               // Vibrational Device output pin
 pinMode(11,OUTPUT);              // Electrotactile Device output pin
 Serial.begin(9600);              // Being reading in serial communication

}

void loop()
{
  if (Serial.available() > 0)
  {
    switch(Serial.read())                     // This switch statement will read in the user device selection
    {

      case 'x':                               // When each Serial.read() reads in an 'x' character,
      {                                       // this tells the program communication is lost and
          digitalWrite(2, HIGH);              // to send a HIGH signal to the LED output pin
          delay(5000);
          digitalWrite(2, LOW);
          break;
      }

     case 'v':
      {
       Serial.println("Vibrational Device Selected");
       duration1 = Serial.parseInt();                   // Once a device is selected, the duration variable is
       Serial.println(duration1);                       // then stored for latter use with the Serial.perseInt() function
       delay(5000);

       switch(Serial.read())                            // This switch statement will read in data pertainting
       {                                                // to magnitude user inputs

        case 'x':
        {
          Serial.println("LED");
          digitalWrite(2, HIGH);
          delay(5000);
          digitalWrite(2, LOW);
          break;
        }

        case 'l':
        {
          Serial.println("Vibrational with magnitude low");
          analogWrite(6,50);
          for (int x=1; x <= duration1; x++)
          {
            if (digitalRead(buttonPin) == HIGH)
             {
               analogWrite(6,0);
               break;
             }
            delay(1000);
          }
          analogWrite(6,0);
          break;
        }
        case 'm':
         {
          Serial.println("Vibrational with magnitude medium");
          analogWrite(6,100);
          for (int x=1; x <= duration1; x++)
          {
            if (digitalRead(buttonPin) == HIGH)
             {
               analogWrite(6,0);
               break;
             }
            delay(1000);
          }
          analogWrite(6,0);
          break;
         }

        case 'h':
         {
          Serial.println("Vibrational with magnitude high");
          analogWrite(6,250);
          for (int x=1; x <= duration1; x++)
          {
            if (digitalRead(buttonPin) == HIGH)
             {
               analogWrite(6,0);
               break;
             }
            delay(1000);
          }
          analogWrite(6,0);
          break;
         }

        default:
          Serial.println("Oops.. something went wrong!");
          break;
       }
       break;
      }

     case 'e':
      {
       Serial.println("Electrotactile Devices Selected");
       duration2 = Serial.parseInt();
       Serial.println(duration2);
       delay (5000);

       switch(Serial.read())
       {
        case 'x':
        {
          digitalWrite(2, HIGH);
          delay(5000);
          digitalWrite(2, LOW);
          break;
        }
        case 'l':
         {
          Serial.println("Electrotactile with magnitude low");
          digitalWrite(11,HIGH);
          for (int x=1; x <= duration2; x++)
          {
            if (digitalRead(buttonPin) == HIGH)
             {
               digitalWrite(11,LOW);
               break;
             }
            delay(1000);
          }
          digitalWrite(11,LOW);
          break;
         }
        case 'm':
         {
          Serial.println("Electrotactile with magnitude medium");
          digitalWrite(11,HIGH);
          for (int x=1; x <= duration2; x++)
          {
            if (digitalRead(buttonPin) == HIGH)
             {
               digitalWrite(11,LOW);
               break;
             }
            delay(1000);
          }
          digitalWrite(11,LOW);
          break;
         }
        case 'h':
         {
          Serial.println("Electrotactile with magnitude high");
          digitalWrite(11,HIGH);
          for (int x=1; x <= duration2; x++)
          {
            if (digitalRead(buttonPin) == HIGH)
             {
               digitalWrite(11,LOW);
               break;
             }
            delay(1000);
          }
          digitalWrite(11,LOW);
          break;
         }

        default:
          Serial.println("Oops.. something went wrong!");
          break;
       }
       break;
      }

     case 'f':
      {
       Serial.println("Force Device Selected");
       duration3 = Serial.parseInt();
       Serial.println(duration3);
       delay (5000);

       switch(Serial.read())
       {
        case 'x':
        {
          digitalWrite(2, HIGH);
          delay(5000);
          digitalWrite(2, LOW);
          break;
        }
        case 'l':
          Serial.println("Force with magnitude low");

          for (int x=1; x <= duration3; x++)
          {
            if (digitalRead(buttonPin) == HIGH)
             {
               break;
             }
            for(pos = 100; pos < 250; pos += 2)  // goes from 0 degrees to 180 degrees
            {                                    // in steps of 1 degree
             myservo.write(pos);              // tell servo to go to position in variable 'pos'
             delay(5);                       // waits 5ms for the servo to reach the position
             if (digitalRead(buttonPin) == HIGH)
             {
               break;
             }
            }
            for(pos = 250; pos>=100; pos-=2)     // goes from 180 degrees to 0 degrees
            {
             myservo.write(pos);              // tell servo to go to position in variable 'pos'
             delay(5);                       // waits 5ms for the servo to reach the position
             if (digitalRead(buttonPin) == HIGH)
             {
               break;
             }
            }
            delay(250);
          }
          break;

        case 'm':
          Serial.println("Force with magnitude medium");

          for (int x=1; x <= duration3; x++)
          {
            if (digitalRead(buttonPin) == HIGH)
             {
               break;
             }
            for(pos = 100; pos < 250; pos += 2)  // goes from 0 degrees to 180 degrees
            {                                    // in steps of 1 degree
             myservo.write(pos);              // tell servo to go to position in variable 'pos'
             delay(5);                       // waits 5ms for the servo to reach the position
             if (digitalRead(buttonPin) == HIGH)
             {
               break;
             }
            }
            for(pos = 250; pos>=100; pos-=2)     // goes from 180 degrees to 0 degrees
            {
             myservo.write(pos);              // tell servo to go to position in variable 'pos'
             delay(5);                       // waits 5ms for the servo to reach the position
             if (digitalRead(buttonPin) == HIGH)
             {
               break;
             }
            }
            delay(250);
          }
          break;

        case 'h':

          Serial.println("Force with magnitude high");
          for (int x=1; x <= duration3; x++)
          {
            if (digitalRead(buttonPin) == HIGH)
             {
               break;
             }
            for(pos = 100; pos < 250; pos += 2)  // goes from 0 degrees to 180 degrees
            {                                    // in steps of 1 degree
             myservo.write(pos);              // tell servo to go to position in variable 'pos'
             delay(5);                       // waits 5ms for the servo to reach the position
             if (digitalRead(buttonPin) == HIGH)
             {
               break;
             }
            }
            for(pos = 250; pos>=100; pos-=2)     // goes from 180 degrees to 0 degrees
            {
             myservo.write(pos);              // tell servo to go to position in variable 'pos'
             delay(5);                       // waits 5ms for the servo to reach the position
             if (digitalRead(buttonPin) == HIGH)
             {
               break;
             }
            }
            delay(250);
          }
          break;

        default:
          Serial.println("Oops.. something went wrong!");
          break;
       }
       break;
      }

     default:
       Serial.println("Error!");
       break;
    }
  }
}
