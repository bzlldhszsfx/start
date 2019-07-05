int led_red = 0; // the red LED is connected to Pin 0 of the Arduino
int led_yellow = 1; // the yellow LED is connected to Pin 1 of the Arduino
int led_green = 2; // the green LED is connected to Pin 2 of the Arduino

void setup() {
  // set up all the LEDs as OUTPUT
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
int income=0;
void loop() {
  if(Serial.available()>0)
  {
    income=Serial.read();
    switch(income)
    {
      case 'f':
        forward();
        break;
      case 'b':
        backward();
        break;
      case 'l':
        left();
        break;
      case 'r':
        right();
        break; 
      case 's':
        stop();
      break;
    }
  }
}
void forward()
    {
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(11,HIGH);    
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
    }
void backward()
    {
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(11,LOW);    
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);
    }
void left()
    {
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(11,LOW);    
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
    }
void right()
    {
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(8,LOW);
      digitalWrite(11,HIGH);    
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
    }
void stop()
    {
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(8,LOW);
      digitalWrite(11,LOW);    
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
    }
