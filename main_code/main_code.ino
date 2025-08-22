#include <Wire.h>

const int MPU_addr = 0x68;
int16_t AcX, AcY, AcZ;

int minVal = 265;
int maxVal = 402;

double x, y;
double Xdiff, Ydiff;

bool runningX = true;
bool runningY = true;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);

  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();

  int xAng = map(AcX, minVal, maxVal, -90, 90);
  int yAng = map(AcY, minVal, maxVal, -90, 90);
  int zAng = map(AcZ, minVal, maxVal, -90, 90);

  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);

  Xdiff = (x < 180) ? x : (360 - x);
  Ydiff = (y < 160) ? (y + 20) : abs(340 - y);

  if (x < 20 || x > 340) {
    runningX = true;
  }
  if (y < 360 && y > 320) {
    runningY = true;
  }

  if (Xdiff > Ydiff) {
    if (x > 30 && x < 170 && runningX == true) {
      Serial.println("LEFT");
      runningX = false;
    } else if (x < 320 && x > 180 && runningX == true) {

      Serial.println("RIGHT");
      runningX = false;
    }
  } else if (Xdiff < Ydiff) {
    if (y > 10 && y < 160 && runningY == true) {
      Serial.println("DOWN");
      runningY = false;
    } else if (y < 310 && y > 160 && runningY == true) {
      Serial.println("UP");
      runningY = false;
    }
  }

  Xdiff = 0;
  Ydiff = 0;
}




