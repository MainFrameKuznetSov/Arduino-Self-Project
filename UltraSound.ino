#include <NewPing.h>
#include <New_Ping.h>
#define TPin 12// initialising the TRIGGER PIN with 12 of Arduino Digital Pin
#define EPin 13// initialising the ECHO PIN with 12 of Arduino Digital Pin
#define MaxDist 500
NewPing np(TPin,EPin,MaxDist);// Creating NewPing object 'np'
float dur,dist;
const int iter=5;// Fixing no. of pulses as 5
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{ 
  // put your main code here, to run repeatedly:
  dur=np.ping_median(iter);// Calculates the median of the 5(here) duration pulses 
  dist=(dur/2)*0.0343;// Assuming velocity of sound to be 343 m/s
  if(dist>500 || dist<1)// Setting limit of the HC-SR04 b/w 1 cm and 500 cm
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
