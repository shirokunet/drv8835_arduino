#include <Arduino.h>

#include "drv8835.hpp"

Drv8835 throttle = Drv8835(0, 18, 19);
Drv8835 steering = Drv8835(1, 17, 5);

void setup() {
  Serial.begin(115200);
}

void motor_test(double throttle_value, double steering_value, int delay_msec) {
  throttle.drive(throttle_value);
  steering.drive(steering_value);
  Serial.printf("%f, %f\n", throttle_value, steering_value);
  delay(delay_msec);
}

void loop() {
  motor_test(0.3, 0.0, 2000);
  motor_test(-0.3, 0.0, 2000);
  motor_test(0.0, 0.3, 2000);
  motor_test(0.0, -0.3, 2000);
}
