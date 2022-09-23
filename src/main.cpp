/** I, Andrew Maye, 000344062 certify that this material is my original work.
No other person's work has been used without due acknowledgement. **/

#include <Arduino.h>

/**
 * This function is used to find the equivalent tempature input as digitized output. Returns tempature input 
 * **/
float findEquivalent(int dValue, float maxTemp, int PDV){
  float equivalent;
  float resolution = maxTemp/PDV;
  equivalent = resolution * dValue;
  return equivalent;
}

/**
 *  this function takes the tempature as a parameter and returns a judgement of tempature. 
 * */
String makeJudgement(int tempature){
  String judgement;
  if(tempature < 10){
    judgement = "Cold!";
  } else if (tempature >= 10 && tempature < 15 ){
    judgement = "Cool";
  } else if (tempature >= 15 && tempature < 25 ){
    judgement = "Perfect";
  } else if (tempature >= 25 && tempature < 30 ){
    judgement = "Warm";
  } else if (tempature >= 30 && tempature < 35 ){
    judgement = "Hot";
  } else if (tempature > 35){
    judgement = "Too Hot!";
  }
  return judgement;
  }

void setup() {
  // put your setup code here, to run once:

  
  // configure the USB serial monitor 
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  int dVal;
  float result; 
  float maxTemp = 50.00;
  int PDV = 1024;  
  String judgement;

  // read digitized value from the D1 Mini's A/D convertor 
  dVal = analogRead(A0);

  result = findEquivalent(dVal, maxTemp, PDV);
  judgement = makeJudgement(result);

  // print value to the USB port 
  Serial.println("Digitized output of " + String(dVal) + " is equivalent to a tempature input of = " + result + " deg. C, which is " + String(judgement)); 
  
  // wait 2 seconds (2000 ms) 
  delay(2000);
}

