#include <RH_ASK.h>

#include <SPI.h>

RH_ASK rf_driver;

bool pressed2 = false;
bool pressed3 = false;
bool pressed4 = false;
bool pressed5 = false;

int btnstate2 = 0;
int btnstate3 = 0;
int btnstate4 = 0;
int btnstate5 = 0;

void setup() {
  rf_driver.init();
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  btnstate2 = digitalRead(2);
  btnstate3 = digitalRead(3);
  btnstate4 = digitalRead(4);
  btnstate5 = digitalRead(5);

  if(btnstate2 == LOW) {
      if(pressed2) {
        pressed2 = false;
        const char *msg = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        rf_driver.send((uint8_t *)msg, strlen(msg));
        rf_driver.waitPacketSent(); 
      }
  }
  else {
    pressed2 = true;
  }
//--------------
  if(btnstate3 == LOW) {
      if(pressed3) {
        pressed3 = false;
        const char *msg = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
        rf_driver.send((uint8_t *)msg, strlen(msg));
        rf_driver.waitPacketSent(); 
      }
  }
  else {
    pressed3 = true;
  }
 //--------------
  if(btnstate4 == LOW) {
      if(pressed4) {
        pressed4 = false;
        const char *msg = "ccccccccccccccccccccccccccccccccc";
        rf_driver.send((uint8_t *)msg, strlen(msg));
        rf_driver.waitPacketSent(); 
      }
  }
  else {
    pressed4 = true;
  }
  if(btnstate5 == LOW) {
      if(pressed5) {
        pressed5 = false;
        const char *msg = "ddddddddddddddddddddddddddddddddd";
        rf_driver.send((uint8_t *)msg, strlen(msg));
        rf_driver.waitPacketSent(); 
      }
  }
  else {
    pressed5 = true;
  }


}
