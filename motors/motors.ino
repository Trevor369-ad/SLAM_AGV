// Define a struct to hold configuration parameters
struct MotorConfig {
  // Encoder pins
  const uint8_t ENCODER_A = PA8;
  const uint8_t ENCODER_B = PA11;

  // Motor control pins
  const uint8_t IN1 = PB4;
  const uint8_t IN2 = PB3;
  const uint8_t PWM1 = PB8;

  // Encoder parameters
  const int PULSES_PER_REV = 600; // Encoder PPR
  const unsigned long RPM_TIMEOUT = 10000; // 10ms in microseconds

  // PID parameters (modifiable via Serial Monitor)
  float kp = 10.0;
  float ki = 70.0;
  float kd = 300.0;
};

// Create a global instance of the struct
MotorConfig motorConfig;

// Variables to track encoder state and motor control
volatile int encoder_count = 0;
volatile bool direction = true;
volatile unsigned long last_pulse_time = 0;
volatile float current_rpm = 0;

float previous_error = 0;
float integral = 0;
int pwm_value = 0;  // Current PWM output

void encoderISR() {
  int A_state = digitalRead(motorConfig.ENCODER_A);
  int B_state = digitalRead(motorConfig.ENCODER_B);
  unsigned long current_time = micros();

  if (A_state == B_state) {
    direction = false; // Reverse
    encoder_count--;
  } else {
    direction = true; // Forward
    encoder_count++;
  }

  // Calculate RPM in real-time
  if (last_pulse_time > 0) {
    unsigned long time_diff = current_time - last_pulse_time;
    if (time_diff > 0) {
      current_rpm = (60.0 * 1e6) / (motorConfig.PULSES_PER_REV * time_diff);
    }
  }
  last_pulse_time = current_time;
}

void setup() {
  Serial.begin(115200);

  pinMode(motorConfig.ENCODER_A, INPUT_PULLUP);
  pinMode(motorConfig.ENCODER_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(motorConfig.ENCODER_A), encoderISR, CHANGE);

  pinMode(motorConfig.IN1, OUTPUT);
  pinMode(motorConfig.IN2, OUTPUT);
  pinMode(motorConfig.PWM1, OUTPUT);

  Serial.println("Enter new values in the format: kp=XX ki=XX kd=XX");
}

void setMotorRPM(float target_rpm) {
  bool target_direction = (target_rpm >= 0);
  target_rpm = abs(target_rpm); // Work with absolute RPM for calculations

  // Check if the motor has stopped (no encoder pulse detected for 10ms)
  if (micros() - last_pulse_time > motorConfig.RPM_TIMEOUT) {
    current_rpm = 0;
  }

  // PID speed control
  float i_factor = 0.01;
  float error = (target_rpm - current_rpm) * i_factor;
  integral += error * i_factor;
  float derivative = (error - previous_error) * i_factor;
  previous_error = error;

  // Compute new PWM value
  pwm_value = motorConfig.kp * error + motorConfig.ki * integral + motorConfig.kd * derivative;
  pwm_value = constrain(pwm_value, 0, 4096); // Limit to 12-bit PWM max value

  // Set motor direction
  digitalWrite(motorConfig.IN1, target_direction);
  digitalWrite(motorConfig.IN2, !target_direction);
  analogWrite(motorConfig.PWM1, pwm_value);

  // Print target and actual RPM for monitoring
  Serial.print(millis() / 1000.0);
  Serial.print("\t");
  Serial.print(target_rpm);
  Serial.print("\t");
  Serial.print(current_rpm);
  Serial.print("\t");
  Serial.println(pwm_value);
}

void readSerialInput() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n'); // Read input
    input.trim();

    Serial.print("Received input: ");
    Serial.println(input);

    if (input.startsWith("kp=")) {
      int ki_index = input.indexOf(" ki=");
      int kd_index = input.indexOf(" kd=");

      if (ki_index != -1 && kd_index != -1) {
        float new_kp = input.substring(3, ki_index).toFloat();
        float new_ki = input.substring(ki_index + 4, kd_index).toFloat();
        float new_kd = input.substring(kd_index + 4).toFloat();

        Serial.print("Parsed values: ");
        Serial.print("kp="); Serial.print(new_kp);
        Serial.print(", ki="); Serial.print(new_ki);
        Serial.print(", kd="); Serial.println(new_kd);

        motorConfig.kp = new_kp;
        motorConfig.ki = new_ki;
        motorConfig.kd = new_kd;

        previous_error = 0;
        integral = 0;
        pwm_value = 0;

        Serial.println("PID values updated successfully!");
      } else {
        Serial.println("Invalid format! Use: kp=XX ki=XX kd=XX");
      }
    }
  }
}

void loop() {
  readSerialInput();  // Check for new PID values from Serial Monitor
  setMotorRPM(150);   // Maintain motor speed at 150 RPM
}
