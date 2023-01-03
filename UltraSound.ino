#include <NewPing.h>
#include <New_Ping.h>
#define TPin 12
#define EPin 13
#define MaxDist 500
NewPing np(TPin,EPin,MaxDist);
float dur,dist;
const int iter=5;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{ 
  // put your main code here, to run repeatedly:
  dur=np.ping_median(iter);
  dist=(dur/2)*0.0343;
  if(dist>500 || dist<1)
  {
    Serial.println("Not in Range");
  }
  else
  {
    Serial.print("Distance:-> ");
    Serial.print(dist);
    Serial.println("cm");
  }
  delay(500);
}
