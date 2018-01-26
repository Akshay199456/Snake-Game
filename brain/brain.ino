#include <ZumoMotors.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,5);//Remember to cross RX and TX on other device
int serialInput = 0;
ZumoMotors motors;

void setup() {
  motors.flipLeftMotor(true);
  mySerial.begin(9600);

}

void loop() {

  if(mySerial.available()){
    serialInput = mySerial.read();
  }
  switch (serialInput) {
    case 0:
      //Continue as is
      Serial.println("Continue");
      break;
    case 1:
      //Move up if not moving up or down
      Serial.println("Move up");
      break;
    case 2:
      //Move left if not moving left or right
      Serial.println("Move left");
      break;
    case 3:
      //Move down if not moving up or down
      Serial.println("Move down");
      break;
    case 4:
      //Move right if not moving left or right
      Serial.println("Move right");
      break;
  }
  serialInput = 0;

}
