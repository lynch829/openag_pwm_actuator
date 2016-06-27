#include <openag_percent_actuator.h>

#define PIN 6

PercentActuator actuator(PIN, false, 0.5);

void setup() {
  Serial.begin(9600);
  actuator.begin();
}

std_msgs::Float32 state;

void loop() {
  if (Serial.available()) {
    state.data = Serial.parseFloat();
    Serial.println(state.data);
    actuator.set_state(state);
  }
  if (actuator.has_error) {
    Serial.print("Error: ");
    Serial.println(actuator.error_msg);
    actuator.has_error = false;
  }
}
