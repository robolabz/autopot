/*
 * AutoPot - Automatic Water Dispensing Pot
 *
 * http://robolabz.com/blog/?p=4
 *
 * by Robolabz (www.robolabz.com)
 */

const int motorPin = 3;  // Water Motor PIN
const int trigPin = 7; // Ultrasonic Trigger PIN 
const int echoPin = 6; // Ultrasonic Echo PIN

float duration, distance;

void setup() {
  
  pinMode(motorPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {
  
  ReadDistance();
  
  if(distance<10){ // Check object is closer
    
    digitalWrite(motorPin,HIGH);
    
    for(int i=0;i<100;i++)
    {
      ReadDistance();
      if (distance>10) { // If object is away,stop the motor
        digitalWrite(motorPin,LOW);
        break;
      }
      delay(40);
    }
    
  }
  
  digitalWrite(motorPin,LOW);

  
  delay(100);
}

/* Read distance to the object */ 
void ReadDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
}
