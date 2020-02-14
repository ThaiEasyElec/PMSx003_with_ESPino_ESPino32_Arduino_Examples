#include "PMS.h"
#include <SoftwareSerial.h>

static const int RXPin = 0, TXPin = 2;
SoftwareSerial PMS_Serial(RXPin, TXPin);

PMS pms(PMS_Serial);
PMS::DATA data;

void setup()
{
  Serial.begin(115200);
  PMS_Serial.begin(9600);
}

void loop()
{
  if (pms.read(data))
  {
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_1_0);

    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(data.PM_AE_UG_2_5);

    Serial.print("PM 10.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_10_0);

    Serial.println();
  }

  // Do other stuff...
}
