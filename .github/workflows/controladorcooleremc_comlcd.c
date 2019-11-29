#include <LiquidCrystal.h> LiquidCrystallcd(7,6,5,4,3,2);
int tempPin = A1;
int fan = 11;
int led=8;
int temp;
int tempMin =
int tempMax = 100
int fanSpeed;
int fanLCD;
30; 70;
void setup() { pinMode(fan, OUTPUT); pinMode(led, OUTPUT); pinMode(tempPin, INPUT); lcd.begin(16,2);
}
void loop() {
temp = readTemp(); if(temp <tempMin) { fanSpeed = 0; digitalWrite(fan, LOW);
22
CONTROLADOR DE COOLER 

}
if((temp >= tempMin) && (temp <= tempMax)) {
fanSpeed = map(temp, tempMin, tempMax, 32, 255); // veloc atual
fanLCD = map(temp, tempMin, tempMax, 0, 100); // mostra velocidade
analogWrite(fan, fanSpeed);  //gira cooler
speed
}
if(temp >tempMax) 
{
digitalWrite(led, HIGH);  //liga led
   } else {                    
digitalWrite(led, LOW);
}
lcd.print("TEMP: "); lcd.print(temp); lcd.print("C "); lcd.setCursor(0,1); lcd.print("COOLERS: "); lcd.print(fanLCD); lcd.print("%"); delay(200); lcd.clear();
}
23
Controlador de cooler

intreadTemp() { 
temp = analogRead(tempPin); return temp * 0.48828125;
}
