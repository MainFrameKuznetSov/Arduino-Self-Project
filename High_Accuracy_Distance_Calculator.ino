#include <DHT.h>
//#include <DHT_U.h>
#include <NewPing.h>
//#include <New_Ping.h>
#define TPin1 12
#define EPin1 12
#define TPin2 5
#define EPin2 5
#define MaxDist 500
#define DPIN 7
#define DHTTYPE DHT22
NewPing np1(TPin1,EPin1,MaxDist);
NewPing np2(TPin2,EPin2,MaxDist);
float dur1,dur2,dist1,dist2;
const int iter=5;
DHT dht(DPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  // put your main code here, to run repeatedly:
  float speed;
  //dur = pulseIn(EPin, HIGH);
  float hum, temp;
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.print("Humidity:- ");
  Serial.println(hum);
  Serial.print("Temperature:- ");
  Serial.println(temp);
  speed = 331.4 + (0.606 * temp) + (0.0124 * hum);
  dur1=np1.ping_median(iter);
  dur2=np2.ping_median(iter);  
  dist1= (dur1 / 2) * (speed/ 10000);
  dist2= (dur2 / 2) * (speed/ 10000);
  Serial.print("Speed:- ");
  Serial.print(speed);
  Serial.println(" m/s");
  if (dist1 > 500 || dist1 < 1) {
    Serial.println("Not in Range");
  } else {
    Serial.print("Distance 1:-> ");
    Serial.print(dist1);
    Serial.println(" cm");
  }
  if (dist2 > 500 || dist2 < 1) {
    Serial.println("Not in Range");
  } else {
    Serial.print("Distance 2:-> ");
    Serial.print(dist2);
    Serial.println(" cm");
  }
  delay(500);
  Serial.println("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
}
