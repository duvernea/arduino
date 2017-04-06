
const int button1Pin = 2;  
const int button2Pin = 3;  

const int ledSwitch1 = 9;
const int ledSwitch2 =  13;    
const int ledBothSwitches = 12;

void setup()
{
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);

  pinMode(ledSwitch1, OUTPUT); 
  pinMode(ledSwitch2, OUTPUT);
  pinMode(ledBothSwitches, OUTPUT);
}

void loop()
{
  int button1State, button2State;  // variables to hold the pushbutton states

  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  
  if (((button1State == LOW) && button2State == LOW)) {
    
    for (int i=0; i<5; i++) {
      digitalWrite(ledBothSwitches,HIGH);
      delay(50);
      digitalWrite(ledBothSwitches, LOW);
      delay(50);
    }
  } else if (button1State == LOW) {
    digitalWrite(ledSwitch1, HIGH);  // turn the LED on
  } else if (button2State == LOW) {
    digitalWrite(ledSwitch2, HIGH);  // turn the LED on
  } else {
    digitalWrite(ledSwitch1, LOW);  // turn the LED off
    digitalWrite(ledSwitch2, LOW);  // turn the LED off
  }
}
