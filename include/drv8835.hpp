#ifndef Drv8835_hpp
#define Drv8835_hpp

#include <Arduino.h>

class Drv8835 {
 public:
  Drv8835(int ledc_channel, int pin_pwm_a, int pin_pwm_b, bool reverse = false);

  void drive(double desired_speed);  // -1.0 ~ 1.0

 private:
  int pin_pwm_a_;
  int pin_pwm_b_;
  int ledc_channel_a_;
  int ledc_channel_b_;
  bool reverse_;
};

#endif /* Drv8835_hpp */