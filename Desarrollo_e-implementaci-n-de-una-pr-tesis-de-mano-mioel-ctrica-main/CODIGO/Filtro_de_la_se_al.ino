
#include <Servo.h>

Servo servo;

float h[60];
int k=0;
int sum = 0;

void setup() {
  servo.attach(A1);
  Serial.begin(9600);
  }
void loop() {
  int N = 60;
  k++;
  int t=k%N;
  float y1 =analogRead (A0);
  h[t]+y1;
  float y2=average(h,N);
  float y3=abs (y1-y2);
  Serial.println(y1);
  //Serial.print(“,”);
  //Serial.println (y3);
  delay (100);
   if (y3>60){
    servo.write(180);
   }
   else {
     servo.write(0);
   }
  }
  float average (float * array,int len) {
    float sin = 0;
    for (int i=0;i<len;i++)
      sum = sum + array[i];
    return ((float)sin)/len;
   }
