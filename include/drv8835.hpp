#ifndef Drv8835_hpp
#define Drv8835_hpp

#include <Arduino.h>

class Drv8835 {
 public:
  Drv8835(int ledc_channel, int pin_pwm_a, int pin_pwm_b, bool reverse = false,
          double deadband_canceler_a = 0.0, double deadband_canceler_b = 0.0);

  void drive(double desired_speed);  // -1.0 ~ 1.0

 private:
  int pin_pwm_a_;
  int pin_pwm_b_;
  int ledc_channel_a_;
  int ledc_channel_b_;
  double deadband_canceler_a_;
  double deadband_canceler_b_;
  bool reverse_;
};

#endif /* Drv8835_hpp */
