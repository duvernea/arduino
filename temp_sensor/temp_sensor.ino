/*
  TMP36 sensor - voltage output proportional to ambient temp
  More information on the sensor is available in the datasheet:
  http://dlnmh9ip6v2uc.cloudfront.net/datasheets/Sensors/Temp/TMP35_36_37.pdf

*/

const int temperaturePin = 0;
const double voltageMax = 1.1;
const int numBits = 10; // 10 bit adc

void setup()
{
  Serial.begin(9600);
  // analogReference(EXTERNAL);
  // INTERNAL ref = 1.1V
  // EXTERNAL = apply to AREF
  // DEFAULT = 5V
  analogReference(INTERNAL);
  
}

void loop()
{
 
  float voltage, degreesC, degreesF;

  // ADC value converted to 0 to 5V scale
  voltage = getVoltage(temperaturePin);
  
  // Formula from temperature sensor datasheet:
  degreesC = (voltage - 0.5) * 100.00;
  degreesF = degreesC * (9.0/5.0) + 32.0;
  
  printToSerial(voltage, degreesC, degreesF);
  
  delay(1000); // repeat once per second (change as you wish!)
}

float getVoltage(int pin)
{
  return (analogRead(pin) * 1/(pow(2,numBits))*voltageMax);
}
void printToSerial(float voltage, float degreesC, float degreesF) {
  Serial.print("voltage: ");
  Serial.print(voltage, 3);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);
}

