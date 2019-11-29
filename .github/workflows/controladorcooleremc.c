int tempPin = A1;
int fan = 11;
int temp;
int tempMin =
int tempMax = 100%
int fanSpeed;
30; 70;
void setup() { pinMode(fan, OUTPUT); pinMode(tempPin, INPUT);
}
void loop() {
temp = readTemp(); if(temp <tempMin) { fanSpeed = 0; digitalWrite(fan, LOW);

}
if((temp >= tempMin) && (temp <= tempMax)) {
fanSpeed = map(temp, tempMin, tempMax, 32, 255); // veloc atual
analogWrite(fan, fanSpeed);  //gira cooler
speed
}
if(temp >tempMax) 
readTemp() { 
temp = analogRead(tempPin); return temp * 0.48828125;
}
