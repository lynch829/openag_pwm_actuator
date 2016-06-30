#include "openag_pwm_actuator.h"

PwmActuator::PwmActuator(int pin, bool is_active_low, float threshold) {
  _pin = pin;
  _is_active_low = is_active_low;
  _threshold = threshold;
}

void PwmActuator::begin() {
  pinMode(_pin, OUTPUT);
}

void PwmActuator::update() { }

void PwmActuator::set_cmd(std_msgs::Float32 cmd) {
  float val = cmd.data;
  if (val < 0 || val > 1) {
    has_error = true;
    error_msg = "Invalid command received";
    return;
  }
  if (_is_active_low) {
    val = 1-val;
  }
  val = _threshold + (1-_threshold)*val;
  int pwm_value = val*255;
  analogWrite(_pin, pwm_value);
}
