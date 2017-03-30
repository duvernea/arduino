/*
  TMP36 sensor - voltage output proportional to ambient temp
  More information on the sensor is available in the datasheet:
  http://dlnmh9ip6v2uc.cloudfront.net/datasheets/Sensors/Temp/TMP35_36_37.pdf

*/

const int temperaturePin = 0;


void setup()
{
  Serial.begin(9600);
}

void loop()
{
 
  float voltage, degreesC, degreesF;

  // ADC value converted to 0 to 5V scale
  voltage = getVoltage(temperaturePin);
  
  // Formula from temperature sensor datasheet:
  degreesC = (voltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0/5.0) + 32.0;
  
  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);
  
  delay(1000); // repeat once per second (change as you wish!)
}

float getVoltage(int pin)
{
  double voltageMax = 5;
  int numBits = 10;
  return (analogRead(pin) * 1/(pow(2,numBits))*voltageMax);
}
void printToSerial(float voltage, float degreesC, float degreesF) {
  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);
}

