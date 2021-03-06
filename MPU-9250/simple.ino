//File for work with gyro
#include "MPU9250.h"

MPU9250 mpu;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    delay(2000);

    if (!mpu.setup(0x68)) {  // change to your own address
        while (1) {
            Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
            delay(5000);
        }
    }
}

void loop() {
    if (mpu.update()) {
        static uint32_t prev_ms = millis();
        while (millis() > prev_ms + 25) {
            print_pitch_roll();
            prev_ms = millis();
        }
    }
}
void print_pitch_roll(){
  Serial.print("Pitch, Roll: ");
  Serial.print(mpu.getPitch());
  Serial.print(" , ");
  Serial.println(mpu.getRoll());
}
bool bool_pitch_roll(){
  if(mpu.getPitch() < 5 || mpu.getRoll() < 5)
    return true;
}

void print_roll_pitch_yaw() {
    Serial.print("Yaw, Pitch, Roll: ");
    Serial.print(mpu.getYaw(), 2);
    Serial.print(", ");
    Serial.print(mpu.getPitch(), 2);
    Serial.print(", ");
    Serial.println(mpu.getRoll(), 2);
}
