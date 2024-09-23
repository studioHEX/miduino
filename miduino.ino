int sensorPin = 1;
int sensorPin2 = 2;
//rest of setup here

void setup() {
  Serial.begin(9600); //starting serial connection
  pinmode(sensorPin, INPUT);
  pinmode(sensorPin2, INPUT);

}

void loop() {
  int sensorVal = digitalRead(sensorPin);
  int sensorVal2 = digitalRead(sensorPin2);

  Serial.print(sensorVal);
  Serial.print(" ");
  Serial.print(sensorVal2);
  Serial.println();
  //keep repeating this until you covered all the sensors

}
