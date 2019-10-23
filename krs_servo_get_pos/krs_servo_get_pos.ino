#include "IcsHardSerialClass.h"

const byte EN_PIN = 2;
const long BAUDRATE = 1250000;
const int TIMEOUT = 100;

IcsHardSerialClass krs(&Serial2,EN_PIN,BAUDRATE,TIMEOUT);

void setup() {
  Serial.begin(115200);
  krs.begin();
}

void loop() {
  const int servo_amount_half = 5;
  int servo_id_arr[2][servo_amount_half] = {{2, 5, 7, 9, 11}, {1, 4, 6, 8, 10}};  // L, R

  for (int lr = 0; lr < 2; ++lr)
  {
    for (int servo_number = 0; servo_number < servo_amount_half; ++servo_number)
    {
      int id = servo_id_arr[lr][servo_number];
      Serial.print(krs.setFree(id));
      Serial.print(',');
    }
  }

  Serial.print("\n");
}
