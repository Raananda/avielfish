
const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int o1 =  4;      // actuator 1
const int c1 =  5;
const int o2 =  6;      // actuator 2
const int c2 =  7;

char buttonState1 = HIGH;
char buttonState2 = HIGH;
char relay1 = LOW;
char relay2 = LOW;
char relay3 = LOW;
char relay4 = LOW;



unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

unsigned long currentMillis1 = 0;
unsigned long currentMillis2 = 0;
int counter1, counter2;



const long interval = 4000;           // interval at which to open and close (milliseconds)



void setup() {

  Serial.begin(9600);

  pinMode(o1, OUTPUT);
  pinMode(c1, OUTPUT);
  pinMode(o2, OUTPUT);
  pinMode(c2, OUTPUT);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  counter1 = 0;
  counter2 = 0;
  digitalWrite(c1, HIGH);
   delay(10000);
   digitalWrite(c1, LOW);
  digitalWrite(c2, HIGH);
  delay(10000);
  digitalWrite(c1, LOW);
  digitalWrite(c2, LOW);



}

void loop() {
  currentMillis1 = millis();
  currentMillis2 = millis();

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == LOW) {
    counter1 = 5;
  }// if b1

  if (buttonState2 == LOW) {
    counter2 = 5;
  }// if b2

  if (counter1 > 0)
  {
    if (currentMillis1 - previousMillis1 >= interval)
    {
      Serial.write("b1");

      previousMillis1 = currentMillis1;

      if (relay1 == LOW) // open
      {
        relay1 = HIGH;
        relay2 = LOW;
      }// relay1
      else // close
      {
        relay1 = LOW;
        relay2 = HIGH;
        counter1--;
        Serial.println(counter1);
      } // else
      /*    if (counter1 == 0)
           {
             relay1 = LOW;
             relay2 = LOW;

           }*/
      digitalWrite(o1, LOW);
      digitalWrite(c1, LOW);
      delay(100);
      digitalWrite(o1, relay1);
      digitalWrite(c1, relay2);

      if (counter1 == 0)
      {
        relay1 = LOW;
        relay2 = LOW;
        delay(interval);
        digitalWrite(o1, relay3);
        digitalWrite(c1, relay4);

      }

    }// interval
  }// counter1



  if (counter2 > 0)
  {
    if (currentMillis2 - previousMillis2 >= interval)
    {
      Serial.write("b2");

      previousMillis2 = currentMillis2;

      if (relay3 == LOW) // open
      {
        relay3 = HIGH;
        relay4 = LOW;
      }// relay3
      else // close
      {
        relay3 = LOW;
        relay4 = HIGH;
        counter2--;
        Serial.println(counter2);
      } // else

      /*  if (counter2 == 0)
        {
          relay3 = LOW;
          relay4 = LOW;
        }*/
      digitalWrite(o2, LOW);
      digitalWrite(c2, LOW);
      delay(100);
      digitalWrite(o2, relay3);
      digitalWrite(c2, relay4);
      if (counter2 == 0)
      {
        delay(interval);
        relay3 = LOW;
        relay4 = LOW;
      }
      digitalWrite(o2, relay3);
      digitalWrite(c2, relay4);

    }// interval
  }// counter2




}// end main
