#include "DHT.h"   
#include <LiquidCrystal_I2C.h>  

#define DHTPIN A0               
#define DHTTYPE DHT22           

#define fan 10                  
#define led 23                  
#define pump 9

DHT dht(DHTPIN, DHTTYPE);       

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Serial.begin(9600);
  
  dht.begin();                   
  lcd.init();                    
  lcd.backlight();

  pinMode(fan,OUTPUT);           
  pinMode(led, OUTPUT);          
  pinMode(pump, OUTPUT);
}
 
void loop() {
  int cds = analogRead(A3);
  if (cds < 600)
  {
    digitalWrite(led, LOW);
    digitalWrite(fan, LOW);
    digitalWrite(pump,LOW);
    return;
  }

  digitalWrite(led,HIGH);
  digitalWrite(fan,HIGH);
  delay(2000);

  digitalWrite(fan,LOW);

  float humidity    = dht.readHumidity();      
  float temperature = dht.readTemperature();
 
  if ( isnan(humidity) || isnan(temperature) ) {
    humidity = 0;
    temperature = 0;
  }
  
  String humi = "Humi : ";      
  humi += (String)humidity;
  humi += "%";
 
  String temp = "temp : ";      
  temp += (String)temperature;
  temp += "C";
 
  lcd.setCursor(0, 0);          
  lcd.print(humi);
  lcd.setCursor(0, 1);
  lcd.print(temp);
  
  int water = analogRead(A1);
  Serial.print("water = ");      
  Serial.println(water);   
  
  if (water>850){                       
    digitalWrite(pump,1);
  }
  if (water<300){                    
    digitalWrite(pump,0);
  }
    
}