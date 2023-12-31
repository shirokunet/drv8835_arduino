#include "drv8835.hpp"

Drv8835::Drv8835(int ledc_channel, int pin_pwm_a, int pin_pwm_b, bool reverse,
                 double deadband_canceler_a, double deadband_canceler_b) {
  ledc_channel_a_ = ledc_channel * 2 + 0;
  ledc_channel_b_ = ledc_channel * 2 + 1;
  deadband_canceler_a_ = deadband_canceler_a;
  deadband_canceler_b_ = deadband_canceler_b;
  pin_pwm_a_ = pin_pwm_a;
  pin_pwm_b_ = pin_pwm_b;
  reverse_ = reverse;

  pinMode(pin_pwm_a_, OUTPUT);
  pinMode(pin_pwm_b_, OUTPUT);

  digitalWrite(pin_pwm_a_, LOW);
  digitalWrite(pin_pwm_b_, LOW);

  ledcSetup(ledc_channel_a_, 25000, 10);
  ledcSetup(ledc_channel_b_, 25000, 10);

  ledcAttachPin(pin_pwm_a_, ledc_channel_a_);
  ledcAttachPin(pin_pwm_b_, ledc_channel_b_);

  ledcWrite(ledc_channel_a_, 0);
  ledcWrite(ledc_channel_b_, 0);
}

void Drv8835::drive(double desired_speed) {
  if (reverse_) {
    desired_speed *= -1.0;
  }

  if (desired_speed > 0) {
    desired_speed += deadband_canceler_a_;
  } else if (desired_speed < 0) {
    desired_speed -= deadband_canceler_b_;
  } else {
  }

  int speed = int(desired_speed * 1023);
  speed = min(max(speed, -1023), 1023);

  if (speed == 0) {
    ledcWrite(ledc_channel_a_, 1023);
    ledcWrite(ledc_channel_b_, 1023);
  } else if (speed > 0) {
    ledcWrite(ledc_channel_a_, abs(speed));
    ledcWrite(ledc_channel_b_, 0);
  } else if (speed < 0) {
    ledcWrite(ledc_channel_a_, 0);
    ledcWrite(ledc_channel_b_, abs(speed));
  } else {
    ledcWrite(ledc_channel_a_, 0);
    ledcWrite(ledc_channel_b_, 0);
  }
}
