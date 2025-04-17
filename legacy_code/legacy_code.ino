#include "DHT.h"   
#include <LiquidCrystal_I2C.h>  

#define DHTPIN A0               
#define DHTTYPE DHT11           

#define fan 10                  
#define led 23                  
#define pump 9          // 액체펌프 디지털핀 9번으로 정의하기 (릴레이 모듈)
 
DHT dht(DHTPIN, DHTTYPE);       

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Serial.begin(9600);
  dht.begin();                   
  lcd.init();                    
  lcd.backlight();               
  pinMode(fan,OUTPUT);           
  pinMode(led, OUTPUT);          
  pinMode(pump, OUTPUT);               //디지털 핀 9번 출력모드 설정(액체펌프 릴레이)    
}
 
void loop() {
  float humidity = dht.readHumidity();      
  float temperature = dht.readTemperature();
 
  if (isnan(humidity) || isnan(temperature) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  //Serial.print((int)temperature); Serial.print(" *C, ");
  //Serial.print((int)humidity); Serial.println(" %");   
  // 온습도 센서값 주석처리.
  
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
  
  int cds = analogRead(A3);
  // Serial.print("cds = ");    
  // Serial.println(cds);           
  // CDS 조도센서값 주석처리 
  
  if (cds > 880){              
    digitalWrite(led,LOW);
  }
  else{
    digitalWrite(led,HIGH);
  }
  
  digitalWrite(fan,HIGH);    
  
  // 수위센서 확인
  int water = analogRead(A1);
  Serial.print("water = ");      
  Serial.println(water);   
  
  if (water>850){                        // 조건문 물수위가 낮으면 액체펌프를 가동하고
    digitalWrite(pump,1);
  }
  if (water<300){                        // 조건문 물수위가 오르면 액체펌프를 정지한다. 
    digitalWrite(pump,0);
  }
    
}