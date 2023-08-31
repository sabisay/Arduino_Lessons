#include <IRremote.h>

IRrecv irrecv(13);

decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(12,OUTPUT);


}

void loop() {
  //put your main code here, to run repeatedly:

  if (irrecv.decode(&results)){
     Serial.println(results.value);
     irrecv.resume();
  }

  if (results.value == 4097){
    digitalWrite(12,HIGH);
  }
  else if (results.value == 4098)
  digitalWrite(12,LOW);

}
