#ifndef OPENAG_PERCENT_ACTUATOR_H
#define OPENAG_PERCENT_ACTUATOR_H

#include "Arduino.h"
#include <std_msgs/Float32.h>

class PercentActuator {
  public:
    // Constructor
    PercentActuator(int pin, bool is_active_low, float threshold);

    // Public variables
    bool has_error;
    char* error_msg;

    // Public functions
    void begin();
    void set_state(std_msgs::Float32 state);

  private:
    // Private variables
    int _pin;
    bool _is_active_low;
    float _threshold;
};

#endif
