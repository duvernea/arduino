
int pSensPin = 0;
int pSensReading;
int buzzerPin = 12;
long buzzerFreq;
// max freq output of buzzer
long BUZZ_FREQ_MAX = 2500;
// max digitized value
long PR_MAX = 1023;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  pSensReading = analogRead(pSensPin);
  buzzerFreq = (pSensReading * BUZZ_FREQ_MAX) / PR_MAX;
  buzz(buzzerPin, buzzerFreq, 10);
  String reading = getStatusString(pSensReading);
  Serial.println(reading);
  
}
void buzz(int targetPin, long frequency, long length) {
  // pulsewidth in milliseconds (multiplied by 1E6)
  // Period = 1/frequency. pulsewidth is only 1/2 the period, 50% duty cycle
  long pulseWidth = 1000000/frequency/2;
  Serial.println(pulseWidth);
  long numCycles = frequency * length / 1000;

  for (long i=0; i < numCycles; i++) {
    digitalWrite(targetPin, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(targetPin, LOW);
    delayMicroseconds(pulseWidth);
  }
}
String getStatusString(int sensorValue) {
   String printout = "digital: ";
   printout += sensorValue;
   printout += "/1023 buzzer freq: ";
   printout += buzzerFreq;
   printout += "Hz";
   return printout;
}


