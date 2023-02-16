#include <RH_ASK.h>

#include <SPI.h>

RH_ASK rf_driver;

int delay1 = 100;
int buzzerPin = 8;

void setup() {
  // put your setup code here, to run once:
  rf_driver.init();
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
uint8_t buf[33];
uint8_t buflen = sizeof(buf);

if(rf_driver.recv(buf, &buflen)) {
  Serial.print("Message Received: ");
  String message = buf;
  Serial.println(message);
  if(message.indexOf("a") > -1) {
   Serial.println("Throw fast");   
   beep(1);
  }
  else if(message.indexOf("b") > -1) {
   Serial.println("Throw the John");   
   beep(2);
  }
  else if(message.indexOf("c") > -1) {
   Serial.println("make him slide");  
   beep(3);
  }
  else if(message.indexOf("e") > -1) {
   Serial.println("throw slow");   
   beep(5);
  }
  else if(message.indexOf("d") > -1) {
   Serial.println("spit slit thing");   
   beep(4);
  }
}
else {
  digitalWrite(2, LOW);
}

}

void beep(int num) {
  for(int i = 0; i < num; i++) {
    tone(buzzerPin, 784);
    delay(delay1);
    noTone(buzzerPin);
    delay(delay1);
  }
}
