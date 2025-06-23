// String data;
// long rprevcountTime, rcurrentcountTime, frontMotorsTimeDiff;
// // Define a struct to hold configuration parameters
//  typedef struct {
//    // Encoder pins
//    uint8_t ENCODER_A;
//    uint8_t ENCODER_B;
 
//    // Motor control pins
//    uint8_t DIR1;
//    uint8_t DIR2;
//    uint8_t SpeedPin;
 
//    // Encoder parameters
//    int PULSES_PER_REV; // Encoder PPR
//    unsigned long RPM_TIMEOUT = 10000; // 10ms in microseconds
 
//    // PID parameters (modifiable via Serial Monitor)
//    float kp = 0.0;
//    float ki = 0.0;
//    float kd = 0.0;
//    float PID_scaling_factor = 0;

//    float PrevInput,ITerm, timeDiff;

//   // Variables to track encoder state and motor control
//   volatile int encoder_count = 0;
//   volatile bool optical_encoded;
//   volatile unsigned long last_pulse_time = 0;
//   volatile float current_rpm = 0, prev_rpm = 0, prev_encoder_count = 0;
  
//   float previous_error = 0;
//   float integral = 0;
//   int pwm_value = 0;  // Current PWM output
//   float target_rpm;
//   volatile bool direction = (target_rpm >= 0);
//  }encoded_motor_info;

// // Create a global instance of the struct
// encoded_motor_info frontRight_encoded_motor, frontLeft_encoded_motor, backRight_encoded_motor, backLeft_encoded_motor;
 
 
// void backRight_encoded_motor_ISR() {
//   int A_state = digitalRead(backRight_encoded_motor.ENCODER_A);
//   int B_state = digitalRead(backRight_encoded_motor.ENCODER_B);
//   unsigned long current_time = micros();

//   if (A_state == B_state) {
//     backRight_encoded_motor.direction = true; // Reverse
//     backRight_encoded_motor.encoder_count++;
//   } else {
//     backRight_encoded_motor.direction = false; // Forward
//     backRight_encoded_motor.encoder_count--;
//   }

//   // Calculate RPM in real-time
//   if (backRight_encoded_motor.last_pulse_time > 0) {
//     unsigned long time_diff = current_time - backRight_encoded_motor.last_pulse_time;
//     if (time_diff > 0) {
//       backRight_encoded_motor.current_rpm = (60.0 * 1e6) / (backRight_encoded_motor.PULSES_PER_REV * time_diff)*2;
//       //backRight_encoded_motor.current_rpm = ((1/backRight_encoded_motor.PULSES_PER_REV)/time_diff)*1000*60;
//     }
//   }
//   backRight_encoded_motor.last_pulse_time = current_time;
// }

// void backLeft_encoded_motor_ISR() {
//   int A_state = digitalRead(backLeft_encoded_motor.ENCODER_A);
//   int B_state = digitalRead(backLeft_encoded_motor.ENCODER_B);
//   unsigned long current_time = micros();

//   if (A_state != B_state) {
//     backLeft_encoded_motor.direction = false; // Reverse
//     backLeft_encoded_motor.encoder_count--;
//   } else {
//     backLeft_encoded_motor.direction = true; // Forward
//     backLeft_encoded_motor.encoder_count++;
//   }

//   // Calculate RPM in real-time
//   if (backLeft_encoded_motor.last_pulse_time > 0) {
//     unsigned long time_diff = current_time - backLeft_encoded_motor.last_pulse_time;
//     if (time_diff > 0) {
//       backLeft_encoded_motor.current_rpm = (60.0 * 1e6) / (backLeft_encoded_motor.PULSES_PER_REV * time_diff)*2;
//     }
//   }
//   backLeft_encoded_motor.last_pulse_time = current_time;
// }

// void frontRight_encoded_motor_ISR() {
//   unsigned long currentTime = millis();

//   if (frontRight_encoded_motor.direction == false) {
//     frontRight_encoded_motor.encoder_count--;
//   } else {
//     frontRight_encoded_motor.encoder_count++;
//   }

//   // Calculate RPM 
//   if (1) {
//     frontRight_encoded_motor.timeDiff = currentTime - frontRight_encoded_motor.last_pulse_time;
//     if (1/*frontRight_encoded_motor.timeDiff >= 10*/) {
//       frontRight_encoded_motor.current_rpm = ((abs(frontRight_encoded_motor.encoder_count-frontRight_encoded_motor.prev_encoder_count) / (float)frontRight_encoded_motor.PULSES_PER_REV)/frontRight_encoded_motor.timeDiff)*1000 * 60.0;// * 4.036;//(60.0 * 1e6) / (frontRight_encoded_motor.PULSES_PER_REV * time_diff);
//       frontRight_encoded_motor.prev_encoder_count = frontRight_encoded_motor.encoder_count;
//       frontRight_encoded_motor.last_pulse_time = currentTime;
//     }
//   }
  
// }

// void frontLeft_encoded_motor_ISR() {
//   unsigned long currentTime = millis();

//   if (frontLeft_encoded_motor.direction == false) {
//     frontLeft_encoded_motor.encoder_count--;
//   } else {
//     frontLeft_encoded_motor.encoder_count++;
//   }

//   // Calculate RPM  
//   if (1) {
//     frontLeft_encoded_motor.timeDiff = currentTime - frontLeft_encoded_motor.last_pulse_time;
//     if (frontLeft_encoded_motor.timeDiff > 0) {
//       frontLeft_encoded_motor.current_rpm = ((abs(frontLeft_encoded_motor.encoder_count-frontLeft_encoded_motor.prev_encoder_count) / (float)frontLeft_encoded_motor.PULSES_PER_REV)/frontLeft_encoded_motor.timeDiff)*1000 * 60.0/4.0;//4.0 -> LEFT ENCODER ISSUE// * 4.036;//(60.0 * 1e6) / (frontLeft_encoded_motor.PULSES_PER_REV * time_diff);
//       frontLeft_encoded_motor.prev_encoder_count = frontLeft_encoded_motor.encoder_count;
//       frontLeft_encoded_motor.last_pulse_time = currentTime;
//     }
//   }

// }


// void initMotors(){
//   backLeft_encoded_motor.DIR1 = PA5;
//   backLeft_encoded_motor.DIR2 = PA4;
//   backLeft_encoded_motor.SpeedPin = PA0; 
//   backLeft_encoded_motor.ENCODER_A = PB0;//
//   backLeft_encoded_motor.ENCODER_B = PB1;//

//   backRight_encoded_motor.DIR1 = PB3;
//   backRight_encoded_motor.DIR2 = PB4;
//   backRight_encoded_motor.SpeedPin = PB8; 
//   backRight_encoded_motor.ENCODER_A = PA11;
//   backRight_encoded_motor.ENCODER_B = PA8;

//   frontLeft_encoded_motor.DIR1 = PA3;
//   frontLeft_encoded_motor.DIR2 = PA2;
//   frontLeft_encoded_motor.SpeedPin = PA1; 
//   frontLeft_encoded_motor.ENCODER_A = PA6;
//   //frontRight_encoded_motor.ENCODER_B = PA7;

//   frontRight_encoded_motor.DIR1 = PB6;
//   frontRight_encoded_motor.DIR2 = PB5;
//   frontRight_encoded_motor.SpeedPin = PB7; 
//   frontRight_encoded_motor.ENCODER_A = PA12;
//   //frontLeft_encoded_motor.ENCODER_B = PA15;

//   pinMode(backRight_encoded_motor.DIR1, OUTPUT);
//   pinMode(backRight_encoded_motor.DIR2, OUTPUT);
//   pinMode(backRight_encoded_motor.SpeedPin, OUTPUT);
//   pinMode(backRight_encoded_motor.ENCODER_A, INPUT);
//   pinMode(backRight_encoded_motor.ENCODER_B, INPUT);
//   attachInterrupt(digitalPinToInterrupt(backRight_encoded_motor.ENCODER_A), backRight_encoded_motor_ISR, RISING);


//   pinMode(backLeft_encoded_motor.DIR1, OUTPUT);
//   pinMode(backLeft_encoded_motor.DIR2, OUTPUT);
//   pinMode(backLeft_encoded_motor.SpeedPin, OUTPUT);
//   pinMode(backLeft_encoded_motor.ENCODER_A, INPUT);
//   pinMode(backLeft_encoded_motor.ENCODER_B, INPUT_PULLUP);
//   attachInterrupt(digitalPinToInterrupt(backLeft_encoded_motor.ENCODER_B), backLeft_encoded_motor_ISR, RISING);

//   pinMode(frontRight_encoded_motor.DIR1, OUTPUT);
//   pinMode(frontRight_encoded_motor.DIR2, OUTPUT);
//   pinMode(frontRight_encoded_motor.SpeedPin, OUTPUT);
//   pinMode(frontRight_encoded_motor.ENCODER_A, INPUT);
//   //pinMode(frontRight_encoded_motor.ENCODER_B, INPUT);
//   attachInterrupt(digitalPinToInterrupt(frontRight_encoded_motor.ENCODER_A), frontRight_encoded_motor_ISR, RISING);


//   pinMode(frontLeft_encoded_motor.DIR1, OUTPUT);
//   pinMode(frontLeft_encoded_motor.DIR2, OUTPUT);
//   pinMode(frontLeft_encoded_motor.SpeedPin, OUTPUT);
//   pinMode(frontLeft_encoded_motor.ENCODER_A, INPUT_PULLUP);
//   //pinMode(frontLeft_encoded_motor.ENCODER_B, INPUT);
//   attachInterrupt(digitalPinToInterrupt(frontLeft_encoded_motor.ENCODER_A), frontLeft_encoded_motor_ISR, FALLING);

//   backRight_encoded_motor.optical_encoded = 0;
//   backLeft_encoded_motor.optical_encoded = 0;

//   backRight_encoded_motor.PULSES_PER_REV = 718;
//   backLeft_encoded_motor.PULSES_PER_REV = 718;

//   frontRight_encoded_motor.optical_encoded = 1;
//   frontLeft_encoded_motor.optical_encoded = 1;

//   frontRight_encoded_motor.PULSES_PER_REV = 30;
//   frontLeft_encoded_motor.PULSES_PER_REV = 30;

//   backRight_encoded_motor.kp = backLeft_encoded_motor.kp = 10.0;
//   backRight_encoded_motor.ki = backLeft_encoded_motor.ki = 75;//70.0;
//   backRight_encoded_motor.kd = backLeft_encoded_motor.kd = 300.0;

//   frontLeft_encoded_motor.kp = 9;
//   frontLeft_encoded_motor.ki = 5;//4;
//   frontLeft_encoded_motor.kd = 10;

//   frontRight_encoded_motor.kp = 10;//97.0;
//   frontRight_encoded_motor.ki = 4;//77.0;
//   frontRight_encoded_motor.kd = 10;//50.0;

//   frontLeft_encoded_motor.PID_scaling_factor = frontRight_encoded_motor.PID_scaling_factor = (1000/1.5);
//   frontLeft_encoded_motor.RPM_TIMEOUT = 20;

//   frontRight_encoded_motor.RPM_TIMEOUT = 20;
//   frontLeft_encoded_motor.optical_encoded = frontRight_encoded_motor.optical_encoded = 1;

// } 

// void setup() {
//   Serial.begin(115200);
//   initMotors();
//   // Serial.println("Enter new values in the format: kp=XX ki=XX kd=XX");
// }

// void loop() {

//   //readSerialInput();  // Check for new PID values from Serial Monitor
//   // backRight_encoded_motor.target_rpm = 100;// Maintain motor speed at 150 RPM
//   // backLeft_encoded_motor.target_rpm = 100;// Maintain motor speed at 150 RPM
    

//   // // //serialPID();
//   // frontLeft_encoded_motor.target_rpm = 100; 
//   // frontRight_encoded_motor.target_rpm = 100;//100; 

//   // if(frontRight_encoded_motor.target_rpm<20) {
//   //   frontRight_encoded_motor.target_rpm = 0;
//   // }
//   // if(frontLeft_encoded_motor.target_rpm<20) {
//   //   frontLeft_encoded_motor.target_rpm = 0;
//   // }

//   // if(backRight_encoded_motor.target_rpm<20) {
//   //   backRight_encoded_motor.target_rpm = 0;
//   // }
//   // if(backLeft_encoded_motor.target_rpm<20) {
//   //   backLeft_encoded_motor.target_rpm = 0;
//   // }

//   setMotorRPM(&frontRight_encoded_motor); 
//   setMotorRPM(&frontLeft_encoded_motor); 
//   setMotorRPM(&backRight_encoded_motor); 
//   setMotorRPM(&backLeft_encoded_motor);
  
//   //printMotorData();
//   //sendEncoderCounts();

//   serialCommands();
  
// }

// void serialCommands(){
//   if(Serial.available()){
//     int BUFFER_SIZE = 500;
//     char cmd[BUFFER_SIZE];
//     data = Serial.readString();
//     data.toCharArray(cmd, BUFFER_SIZE);
//     data.trim();
//     char f_char = cmd[0];
//     if(f_char == 'm'){
//       getSerialCmds();
//     }
//     if(f_char == 'e'){
//       sendEncoderCounts();
//     }

//   }
// }

// void getSerialCmds(){
//   // data.remove(data.indexOf("m"),2);
//   // String D1_ = data;
//   // D1_.remove(data.indexOf(" "));
//   // int D1 = D1_.toInt();

//   // data.remove(0, data.indexOf(" ")+1); 
//   // String D2_ = data;
//   // D2_.remove(data.indexOf(" "));
//   // int D2 = D2_.toInt();

//   // data.remove(0, data.indexOf(" ")+1);
//   // String D3_ = data;
//   // D3_.remove(data.indexOf(" "));
//   // int D3 = D3_.toInt();

//   // data.remove(0, data.indexOf(" ")+1);
//   // String D4_ = data;
//   // D4_.remove(data.indexOf(" "));
//   // int D4 = D4_.toInt();

//   data.remove(data.indexOf("m"), 2);

//   int values[4];
//   for (int i = 0; i < 4; i++) {
//     values[i] = data.substring(0, data.indexOf(" ")).toInt();
//     data = data.substring(data.indexOf(" ") + 1);
//   }

//   // Access them as values[0] = D1, values[1] = D2, etc.


//   frontRight_encoded_motor.target_rpm = values[1];//D2;
//   frontLeft_encoded_motor.target_rpm = values[0];//D1;
//   backRight_encoded_motor.target_rpm = values[3];//D4;
//   backLeft_encoded_motor.target_rpm = values[2];//D3;
//   Serial.println("OK");
//   // setMotorRPM(&frontRight_encoded_motor); 
//   // setMotorRPM(&frontLeft_encoded_motor); 
//   // setMotorRPM(&backRight_encoded_motor); 
//   // setMotorRPM(&backLeft_encoded_motor); 
// }
 
// void setMotorRPM(encoded_motor_info *p) {
//   bool target_direction = (p->target_rpm >= 0);
//   // Check if the motor has stopped (no encoder pulse detected for 10ms)
//   if(!(p->optical_encoded)){
//     if ((micros() - p->last_pulse_time) > p->RPM_TIMEOUT) {
//       p->current_rpm = 0;
//     }

//     float setpoint = abs(p->target_rpm); // Work with absolute RPM for calculations

//     // PID speed control
//     float i_factor = 0.01;
//     float error = (setpoint - p->current_rpm) * i_factor;
//     // p->integral += error * i_factor;
//     float derivative = (error - p->previous_error) * i_factor;
//     p->previous_error = error;

//     // Compute new PWM value
//     p->pwm_value = p->kp * error + p->ki * p->integral + p->kd * derivative;
//     if((p->pwm_value <= 4096) && (p->pwm_value >= 0)){
//       p->integral += error * i_factor;
//     }

//   }else{
//     if (((millis() - p->last_pulse_time > p->RPM_TIMEOUT))) {
//       p->current_rpm = 0;
//     }
//     //p->target_rpm = abs(p->target_rpm);
//     //p->timeDiff = c_time - p->last_pulse_time;
//     if(1/*abs(p->timeDiff >= 250)*/){
//       float input = p->current_rpm;
//       //Serial.println(input);
//       long error = abs(p->target_rpm) - input;
//       //Serial.print("error ");Serial.println(error);
//       float derivative = error - p->previous_error;
//       p->previous_error = error;

//       p->pwm_value = ((p->kp * error) + (p->ki * p->integral) - (p->kd * derivative))/p->PID_scaling_factor;
//       //Serial.println(p->kp);

//       if((p->pwm_value <= 4096) && (p->pwm_value >= 0)){
//         p->integral += error;
//       }
//     }
//   }
//   p->pwm_value = constrain(p->pwm_value, 0, 4096);// Limit to 12-bit PWM max value
//   // Set motor direction

//   if(abs(p->target_rpm) > 20){
//     digitalWrite(p->DIR1, target_direction);
//     digitalWrite(p->DIR2, !target_direction);
//     analogWrite(p->SpeedPin, p->pwm_value);
//   }else{
//    analogWrite(p->SpeedPin, 0); 
//   }

// }

// void sendEncoderCounts(){
//   Serial.print(frontLeft_encoded_motor.encoder_count); Serial.print("  ");
//   Serial.print(frontRight_encoded_motor.encoder_count); Serial.print("  ");
//   Serial.print(backLeft_encoded_motor.encoder_count); Serial.print("  ");
//   Serial.println(backRight_encoded_motor.encoder_count);
// }

// void printMotorData(){
//   Serial.print("Front R rpm:");Serial.print(frontRight_encoded_motor.current_rpm);
//   Serial.print("  Front R pwm:");Serial.print(frontRight_encoded_motor.pwm_value);
//   Serial.print("  Front R encoder count:");Serial.print(frontRight_encoded_motor.encoder_count);

//   Serial.print("  Front L rpm:");Serial.print(frontLeft_encoded_motor.current_rpm);
//   Serial.print("  Front L pwm:");Serial.print(frontLeft_encoded_motor.pwm_value);
//   Serial.print("  Front L encoder count:");Serial.println(frontLeft_encoded_motor.encoder_count);
//   //Serial.println("OK");

//   // Serial.print("  Back R rpm:");Serial.print(backRight_encoded_motor.current_rpm);
//   // Serial.print("  Back R pwm:");Serial.print(backRight_encoded_motor.pwm_value);
//   // Serial.print("  Back R encoder count:");Serial.print(backRight_encoded_motor.encoder_count);

//   // Serial.print("  Back L rpm:");Serial.print(backLeft_encoded_motor.current_rpm);
//   // Serial.print("  Back L pwm:");Serial.print(backLeft_encoded_motor.pwm_value);
//   // Serial.print("  Back L encoder count:");Serial.println(backLeft_encoded_motor.encoder_count);
// }

// float get_d(String data){
//   data.remove(data.indexOf("p"),data.indexOf("d")+1);
//   return data.toFloat(); 
// }

// float get_i(String data){
//   data.remove(data.indexOf("p"),data.indexOf("i")+1);
//   data.remove(data.indexOf("d"));
//   return data.toFloat();
// }

// float get_p(String data){
//   data.remove(data.indexOf("p"),1);
//   data.remove(data.indexOf("i"));
//   return data.toFloat();
// }

// void serialPID(){
//   if(Serial.available()){
//     String data = Serial.readString();

//     frontLeft_encoded_motor.kp = get_p(data);
//     frontLeft_encoded_motor.ki = get_i(data);
//     frontLeft_encoded_motor.kd = get_d(data);
//     resetPID();
//     //moving = 1;
//   }
// }

// void resetPID(){
//   frontLeft_encoded_motor.previous_error = frontRight_encoded_motor.previous_error = 0;
//   frontLeft_encoded_motor.integral = frontRight_encoded_motor.integral = 0;
//   frontLeft_encoded_motor.pwm_value = frontRight_encoded_motor.pwm_value = 0;
// }





////Gemini
#include <Arduino.h> // Make sure core Arduino types are included

// --- Configuration Constants ---
const unsigned long SERIAL_BAUD_RATE = 115200;
const unsigned long PID_UPDATE_INTERVAL_MS = 4; // Update PID every 10ms
const unsigned long RPM_CALC_INTERVAL_MS = 4; // Calculate RPM every 10ms (can be same as PID)
const unsigned long SERIAL_TIMEOUT_MS = 1000; // Timeout for serial commands (adjust if needed)
const int SERIAL_BUFFER_SIZE = 100; // Max size for incoming serial commands

//Buzzer
int buzzer = PB13;
float prev_cmd_time, cmd_timout = 100;

// --- Global Variables ---
char serialBuffer[SERIAL_BUFFER_SIZE];
int serialBufferIndex = 0;
bool commandReady = false;

unsigned long lastPidUpdateTime = 0;
unsigned long lastRpmCalcTime = 0;

// Define a struct to hold configuration parameters
typedef struct {
  // Encoder pins
  uint8_t ENCODER_A;
  uint8_t ENCODER_B; // NEEDED for quadrature

  // Motor control pins
  uint8_t DIR1;
  uint8_t DIR2;
  uint8_t SpeedPin;
  uint8_t PWM_Channel; // Optional: For direct timer control if not using analogWrite

  // Encoder parameters
  float PULSES_PER_REV; // Encoder PPR (Counts Per Revolution depends on decoding X1, X2, X4)
  float COUNTS_PER_REV; // Actual counts per rev based on decoding (e.g., 4 * PPR for X4)

  // PID parameters
  float kp = 0.0;
  float ki = 0.0;
  float kd = 0.0;
  float integral = 0.0;
  float previous_error = 0.0;
  float PID_scaling_factor = 0.0;

  // State Variables
  volatile long encoder_count = 0; // Use long for larger counts
  volatile unsigned long last_pulse_time_us = 0;
  volatile int last_A_state; // Store last state for quadrature
  volatile int last_B_state; // Store last state for quadrature

  long prev_encoder_count = 0; // For RPM calculation
  unsigned long prev_rpm_calc_time_us = 0;

  int current_rpm = 0;
  int target_rpm = 0;
  int pwm_value = 0;
  bool direction_actual = true; // Actual direction based on encoder reading (true=forward?) - Define convention
  bool is_quadrature;

} encoded_motor_info;

// Create global instances of the struct
encoded_motor_info frontRight_motor, frontLeft_motor, backRight_motor, backLeft_motor;

// --- ISR Functions (Keep VERY Lean) ---

// Generic ISR handler template
void handleQuadratureEncoderInterrupt(encoded_motor_info* pMotor) {
    int a_state = digitalRead(pMotor->ENCODER_A);
    int b_state = digitalRead(pMotor->ENCODER_B);
    pMotor->last_pulse_time_us = micros(); // Record time of last activity

    // Basic Quadrature Decoding (X1 or X2 - adjust if needed)
    // This example decodes on A rising edge, checks B for direction
    // For full X4 decoding, attach interrupts to BOTH pins on CHANGE
    // and use a state machine based on prev_A, prev_B, curr_A, curr_B.

    if (1/*a_state != pMotor->last_A_state*/) { // Check if A changed
         if (a_state == HIGH) { // Rising edge on A
             if (b_state == LOW) {
                 pMotor->encoder_count++; // Forward
                 pMotor->direction_actual = true;
             } else {
                 pMotor->encoder_count--; // Reverse
                 pMotor->direction_actual = false;
             }
         }
         // Optional: Add handling for falling edge if doing X2/X4
    }
    // Add similar logic if interrupting on B pin changes for X2/X4

    pMotor->last_A_state = a_state; // Store current state for next time
    pMotor->last_B_state = b_state;
}

// Generic ISR handler for Single-Channel Encoders
void handleSingleChannelEncoderInterrupt(encoded_motor_info* pMotor) {
    // Only need to increment count and update time
    pMotor->encoder_count++; // Always increment for single channel
    pMotor->last_pulse_time_us = micros();
    // No direction check possible here
}


// Specific ISRs calling the appropriate generic handler
// void frontRight_ISR() { handleSingleChannelEncoderInterrupt(&frontRight_motor); }
// void frontLeft_ISR()  { handleSingleChannelEncoderInterrupt(&frontLeft_motor); }

void frontRight_ISR() { handleQuadratureEncoderInterrupt(&frontRight_motor); }
void frontLeft_ISR()  { handleQuadratureEncoderInterrupt(&frontLeft_motor); }
void backRight_ISR()  { handleQuadratureEncoderInterrupt(&backRight_motor); }
void backLeft_ISR()   { handleQuadratureEncoderInterrupt(&backLeft_motor); }

// --- Initialization ---
void initMotors() {
    // --- Pin Definitions ---
    // Back Left--
    backLeft_motor.DIR1 = PA5;
    backLeft_motor.DIR2 = PA4;
    backLeft_motor.SpeedPin = PA0;
    backLeft_motor.ENCODER_A = PB0;
    backLeft_motor.ENCODER_B = PB1; // Assign B pin

    // Back Right--
    backRight_motor.DIR1 = PB3;
    backRight_motor.DIR2 = PB4;
    backRight_motor.SpeedPin = PB8;
    backRight_motor.ENCODER_B = PA11;
    backRight_motor.ENCODER_A = PA8; // Assign B pin

    // Front Left--
    frontLeft_motor.DIR1 = PA3;
    frontLeft_motor.DIR2 = PA2;
    frontLeft_motor.SpeedPin = PA1;
    frontLeft_motor.ENCODER_A = PA6;
    frontLeft_motor.ENCODER_B = PA7; // *** MUST ASSIGN A REAL PIN FOR B ***

    // Front Right--
    frontRight_motor.DIR1 = PB5;
    frontRight_motor.DIR2 = PB6;
    frontRight_motor.SpeedPin = PB7;
    frontRight_motor.ENCODER_A = PA12;
    frontRight_motor.ENCODER_B = PA15;// *** MUST ASSIGN A REAL PIN FOR B ***

    // --- Motor Parameters ---
    // Pulses Per Revolution (from datasheet)
    backRight_motor.PULSES_PER_REV = 718.0; // 
    backLeft_motor.PULSES_PER_REV = 718.0;  // Example
    frontRight_motor.PULSES_PER_REV = 718.0;
    frontLeft_motor.PULSES_PER_REV = 718.0;

    // Back Motors (Quadrature)
    backLeft_motor.is_quadrature = true;
    backRight_motor.is_quadrature = true;
    // ... (Set PPR, CPR, PID for back motors) ...
    // Use X1 decoding for CPR calculation (or adjust if using X2/X4)
    backLeft_motor.COUNTS_PER_REV = backLeft_motor.PULSES_PER_REV * 1;
    backRight_motor.COUNTS_PER_REV = backRight_motor.PULSES_PER_REV * 1;


    // Front Motors (Single Channel)
    frontLeft_motor.is_quadrature = true;
    frontRight_motor.is_quadrature = true;
    // ... (Set PPR, PID for front motors) ...
    // For single channel, Counts Per Rev is just Pulses Per Rev
    frontLeft_motor.COUNTS_PER_REV = frontLeft_motor.PULSES_PER_REV;
    frontRight_motor.COUNTS_PER_REV = frontRight_motor.PULSES_PER_REV;
    // *** Remove or comment out lines setting front motor ENCODER_B pins ***
    // frontLeft_motor.ENCODER_B = PA7; // NOT USED
    // frontRight_motor.ENCODER_B = PA15; // NOT USED


    // // Counts Per Revolution (based on decoding - e.g., X4)
    // // If using X4 decoding (interrupt on A/B CHANGE), CPR = 4 * PPR
    // // If using X1/X2 (interrupt on one pin RISING/FALLING), CPR = 1*PPR or 2*PPR
    // // Adjust CPR based on your *actual* decoding in handleEncoderInterrupt!
    // // Assuming X1 decoding (Rising edge on A) for now:
    // backRight_motor.COUNTS_PER_REV = backRight_motor.PULSES_PER_REV * 1;
    // backLeft_motor.COUNTS_PER_REV = backLeft_motor.PULSES_PER_REV * 1;
    // frontRight_motor.COUNTS_PER_REV = frontRight_motor.PULSES_PER_REV * 1;
    // frontLeft_motor.COUNTS_PER_REV = frontLeft_motor.PULSES_PER_REV * 1;


    // --- PID Tuning --- (Initial values, tune carefully!)
    backRight_motor.kp = 10.0; backRight_motor.ki = 5.0; backRight_motor.kd = 2;//5.0; // KD was very high? 300//p300i10d30
    backLeft_motor.kp = 10.0; backLeft_motor.ki = 75.0; backLeft_motor.kd = 300;//5.0;
    backLeft_motor.PID_scaling_factor = backRight_motor.PID_scaling_factor = 100.0;

    frontLeft_motor.kp = 10.0; frontLeft_motor.ki = 75.0; frontLeft_motor.kd = 300;//1.0; // KD was 10
    frontRight_motor.kp = 10.0; frontRight_motor.ki = 75.0; frontRight_motor.kd = 300;//1.0; // KD was 10
    frontLeft_motor.PID_scaling_factor = frontRight_motor.PID_scaling_factor = 100.0;

    // --- Pin Modes & Interrupts ---
    encoded_motor_info* motors[] = {&frontRight_motor, &frontLeft_motor, &backRight_motor, &backLeft_motor};
    // Define ISRs separately now
    void (*front_isrs[])() = {frontRight_ISR, frontLeft_ISR};
    void (*back_isrs[])() = {backRight_ISR, backLeft_ISR}; 

    // Front Motors (Single Channel - RISING edge likely best)
    pinMode(frontRight_motor.DIR1, OUTPUT);
    pinMode(frontRight_motor.DIR2, OUTPUT);
    pinMode(frontRight_motor.SpeedPin, OUTPUT);
    pinMode(frontRight_motor.ENCODER_A, INPUT_PULLUP);
    // No need to read initial state of B or configure B pin
    attachInterrupt(digitalPinToInterrupt(frontRight_motor.ENCODER_A), frontRight_ISR, RISING);

    pinMode(frontLeft_motor.DIR1, OUTPUT);
    pinMode(frontLeft_motor.DIR2, OUTPUT);
    pinMode(frontLeft_motor.SpeedPin, OUTPUT);
    pinMode(frontLeft_motor.ENCODER_A, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(frontLeft_motor.ENCODER_A), frontLeft_ISR, RISING); // Or FALLING depending on encoder


    // Back Motors (Quadrature - RISING edge on A for X1/X2 example)
    pinMode(backRight_motor.DIR1, OUTPUT);
    pinMode(backRight_motor.DIR2, OUTPUT);
    pinMode(backRight_motor.SpeedPin, OUTPUT);
    pinMode(backRight_motor.ENCODER_A, INPUT_PULLUP);
    pinMode(backRight_motor.ENCODER_B, INPUT_PULLUP);
    backRight_motor.last_A_state = digitalRead(backRight_motor.ENCODER_A);
    backRight_motor.last_B_state = digitalRead(backRight_motor.ENCODER_B);
    attachInterrupt(digitalPinToInterrupt(backRight_motor.ENCODER_A), backRight_ISR, RISING); // Or CHANGE for X4

    pinMode(backLeft_motor.DIR1, OUTPUT);
    pinMode(backLeft_motor.DIR2, OUTPUT);
    pinMode(backLeft_motor.SpeedPin, OUTPUT);
    pinMode(backLeft_motor.ENCODER_A, INPUT_PULLUP);
    pinMode(backLeft_motor.ENCODER_B, INPUT_PULLUP);
    backLeft_motor.last_A_state = digitalRead(backLeft_motor.ENCODER_A);
    backLeft_motor.last_B_state = digitalRead(backLeft_motor.ENCODER_B);
    attachInterrupt(digitalPinToInterrupt(backLeft_motor.ENCODER_A), backLeft_ISR, RISING); // Or CHANGE for X4  
}

// --- RPM Calculation ---
void calculateRPM(encoded_motor_info* pMotor) {
    long current_count;
    float current_time_us;
    float delta_time_us;
    long delta_count;

    // Atomically read volatile variables
    //noInterrupts();
    current_count = pMotor->encoder_count;
    current_time_us = millis();
    //interrupts();

    delta_time_us = current_time_us - pMotor->prev_rpm_calc_time_us;
    delta_count = current_count - pMotor->prev_encoder_count;

    // Handle micros() rollover
    // if (current_time_us < pMotor->prev_rpm_calc_time_us) {
    //     delta_time_us = (0xFFFFFFFF - pMotor->prev_rpm_calc_time_us) + current_time_us;
    // }

    if (delta_time_us > 0 && pMotor->COUNTS_PER_REV > 0) {
        // RPM = (Counts / Time_us) * (us_per_Minute / Counts_per_Rev)
        // For single channel, delta_count will always be >= 0.
        // The result is speed magnitude.
        pMotor->current_rpm = (((delta_count/pMotor->COUNTS_PER_REV)/delta_time_us)*60000)*2;//    (float)delta_count * 60000 / ((float)delta_time_us * pMotor->COUNTS_PER_REV);

        // For quadrature, delta_count can be negative, giving signed RPM.
        // However, PID often works better with magnitude, let's adjust in PID update.
        // If you need signed RPM for quadrature here, keep it as is.
        // If you want magnitude for all, use:
        // pMotor->current_rpm = fabs((float)delta_count * 60000000.0f / ((float)delta_time_us * pMotor->COUNTS_PER_REV));

    } else {
        // Check for timeout to set RPM to 0 if stopped
        //noInterrupts();
        unsigned long last_pulse = pMotor->last_pulse_time_us;
        //interrupts();
        // Increased timeout slightly, adjust as needed (e.g., time for 1-2 counts at slowest desired speed)
        if ((current_time_us - last_pulse) > 10) { // 100ms timeout example
             pMotor->current_rpm = 0.0;
        }
        // else keep previous RPM if delta_time_us was 0?
    }

    // Store current values for the next calculation
    pMotor->prev_encoder_count = current_count;
    pMotor->prev_rpm_calc_time_us = current_time_us;
}

// --- PID Control ---
void updatePID(encoded_motor_info* pMotor, float dt_seconds) {
    int target = pMotor->target_rpm;
    int current = pMotor->current_rpm; // This is magnitude for front, potentially signed for back
    int error;

    if (pMotor->is_quadrature) {
        // Back Motors: Can use signed target and potentially signed current
        // Option 1: Error based on signed target and signed current (if calcRPM provides it)
        // error = target - current;
        // Option 2: Error based on magnitude (often simpler for PID tuning)
           error = abs(target) - abs(current); // Compare magnitudes
           // Direction will be handled below based on target sign
    } else {
        // Front Motors: Current RPM is only magnitude. Error must use abs(target).
        error = abs(target) - current; // Compare magnitudes
    }
    //Serial.println(error);
    // --- PID Calculation (same as before) ---
    // Proportional Term
    float pTerm = pMotor->kp * error;

    // Integral Term (with anti-windup)
    pMotor->integral += pMotor->ki * error;// * dt_seconds;
    float max_integral = 4095.0; // Example limit, needs tuning
    pMotor->integral = constrain(pMotor->integral, 0, max_integral); // Note: Integral is signed

    // Derivative Term
    float derivative = 0.0;
    if (dt_seconds > 0.00001f) {
         // Calculate derivative on the error we just computed
         derivative = (error - pMotor->previous_error);// / dt_seconds;
    }
    float dTerm = pMotor->kd * derivative;

    // Compute PID Output (signed)
    float output = (pTerm + pMotor->integral + dTerm);

    // Store error for next derivative calculation
    pMotor->previous_error = error;


    // --- Motor Direction and PWM Output ---
    bool target_direction_is_forward = (target >= 0); // Determine desired direction

    // PWM magnitude is the absolute value of the signed PID output
    int pwm_magnitude = output;
    pMotor->pwm_value = constrain(pwm_magnitude, 0, 4095); // STM32 analogWrite is often 12-bit


    // Apply output based on target speed magnitude and direction
    if (fabs(target) < 1.0) { // Small deadband around zero target speed
        analogWrite(pMotor->SpeedPin, 0); // Stop motor
        pMotor->pwm_value = 0;
        pMotor->integral = 0; // Reset integral when stopped
    } else {
        // Set direction based on TARGET RPM sign
        digitalWrite(pMotor->DIR1, target_direction_is_forward);
        digitalWrite(pMotor->DIR2, !target_direction_is_forward);
        // Apply PWM magnitude
        analogWrite(pMotor->SpeedPin, pMotor->pwm_value);
    }
}

// --- Serial Communication ---

void handleSerialInput() {
  while (Serial.available() > 0) {
      Serial.println("Serial data received");
      prev_cmd_time = millis();
      char incomingByte = Serial.read();

    if (incomingByte == '\n' || incomingByte == '\r') { // Command terminator
      if (serialBufferIndex > 0) { // We have a command
        serialBuffer[serialBufferIndex] = '\0'; // Null-terminate
        commandReady = true;
        // Don't reset index here, processCommand will do it
      }
      // Ignore empty lines
    } else if (serialBufferIndex < SERIAL_BUFFER_SIZE - 1) {
      serialBuffer[serialBufferIndex++] = incomingByte;
    } else {
      // Buffer overflow, discard buffer and start over
      serialBufferIndex = 0;
      Serial.println("ERR: Buffer Overflow"); // Send error back
    }
  }
}

void processCommand() {
  if (!commandReady) {
      return;
  }
  

  // Serial.print("Processing command: [");
  // Serial.print(serialBuffer);
  // Serial.println("]");

  // Example command format: "m T1 T2 T3 T4" or "e"
  // T1=FL, T2=FR, T3=BL, T4=BR
  // Example parsing:
  if (serialBuffer[0] == 'm') {
    int t1, t2, t3, t4;
    // Use sscanf for robust parsing
    int itemsParsed = sscanf(serialBuffer, "m %d %d %d %d", &t1, &t2, &t3, &t4);
    
    // Serial.print("sscanf items parsed: ");
    // Serial.println(itemsParsed);
    
    if (itemsParsed == 4) {
      frontLeft_motor.target_rpm = t1;
      frontRight_motor.target_rpm = t2;
      backLeft_motor.target_rpm = t3;
      backRight_motor.target_rpm = t4;

      //Serial.print(t1); Serial.print(" "); Serial.print(t2); Serial.print(" "); Serial.print(t3); Serial.print(" "); Serial.print(t4); Serial.print(" ");
      Serial.println("OK"); // Acknowledge
    } else {
      Serial.println("ERR: Invalid 'm' format");
    }
  } else if (serialBuffer[0] == 'e' && serialBuffer[1] == '\0') { // Check it's just "e"
    sendEncoderCounts();
    // No "OK" needed here as data is the response
  } else if(serialBuffer[0] == 'b'){
    int t1;
    // Use sscanf for robust parsing
    int itemsParsed = sscanf(serialBuffer, "b %d", &t1);
    Serial.println("OK");
    digitalWrite(buzzer, HIGH);
    delay(t1);
    digitalWrite(buzzer, LOW);
    delay(5);
    digitalWrite(buzzer, HIGH);
    delay(t1);
    digitalWrite(buzzer, LOW);
  }
  // Add handlers for other commands ('p', 'i', 'd' for tuning?)
  // else if (serialBuffer[0] == 'p') { ... }
  else {
    Serial.print("ERR: Unknown command: ");
    Serial.println(serialBuffer);
  }

  // Reset buffer for next command
  serialBufferIndex = 0;
  commandReady = false;
}

void sendEncoderCounts() {
    char txBuffer[100];
    long fl_count, fr_count, bl_count, br_count;

    noInterrupts();
    // Front counts are total pulses, Back counts are net position
    fl_count = frontLeft_motor.encoder_count;
    fr_count = frontRight_motor.encoder_count;
    bl_count = backLeft_motor.encoder_count;
    br_count = backRight_motor.encoder_count;
    interrupts();

    sprintf(txBuffer, "%ld %ld %ld %ld", fl_count, fr_count, bl_count, br_count);
    Serial.println(txBuffer);
}

void printMotorData() {
  // Reduced frequency debug printing
  static unsigned long lastPrintTime = 0;
  if (millis() - lastPrintTime > 100) { // Print every 500ms
    lastPrintTime = millis();

    char buffer[200]; // Larger buffer for combined output

    // Format data for one motor pair per line for readability
    sprintf(buffer, "F: Tgt:%d Rpm:%d Pwm:%d Cnt:%ld | Tgt:%d Rpm:%d Pwm:%d Cnt:%ld",
            frontLeft_motor.target_rpm, frontLeft_motor.current_rpm, frontLeft_motor.pwm_value, frontLeft_motor.encoder_count,
            frontRight_motor.target_rpm, frontRight_motor.current_rpm, frontRight_motor.pwm_value, frontRight_motor.encoder_count
    );
    Serial.println(buffer);

    sprintf(buffer, "B: Tgt:%d Rpm:%d Pwm:%d Cnt:%ld | Tgt:%d Rpm:%d Pwm:%d Cnt:%ld",
            backLeft_motor.target_rpm, backLeft_motor.current_rpm, backLeft_motor.pwm_value, backLeft_motor.encoder_count,
            backRight_motor.target_rpm, backRight_motor.current_rpm, backRight_motor.pwm_value, backRight_motor.encoder_count
    );
    Serial.println(buffer);
  }
}


// --- Arduino Setup ---
void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  while (!Serial); // Wait for serial connection (optional)
  //Serial.println("System Initializing...");

  pinMode(buzzer, OUTPUT);
  initMotors();

  // Initialize timing variables
  unsigned long now = millis();
  lastPidUpdateTime = now;
  lastRpmCalcTime = now;
  // Initialize previous RPM calculation times
  unsigned long now_us = micros();
  frontLeft_motor.prev_rpm_calc_time_us = now_us;
  frontRight_motor.prev_rpm_calc_time_us = now_us;
  backLeft_motor.prev_rpm_calc_time_us = now_us;
  backRight_motor.prev_rpm_calc_time_us = now_us;

  frontLeft_motor.kp /= frontLeft_motor.PID_scaling_factor; 
  frontLeft_motor.ki /= frontLeft_motor.PID_scaling_factor; 
  frontLeft_motor.kd /= frontLeft_motor.PID_scaling_factor; 

  frontRight_motor.kp /= frontRight_motor.PID_scaling_factor; 
  frontRight_motor.ki /= frontRight_motor.PID_scaling_factor; 
  frontRight_motor.kd /= frontRight_motor.PID_scaling_factor; 

  backLeft_motor.kp /= backLeft_motor.PID_scaling_factor; 
  backLeft_motor.ki /= backLeft_motor.PID_scaling_factor; 
  backLeft_motor.kd /= backLeft_motor.PID_scaling_factor; 

  backRight_motor.kp /= backRight_motor.PID_scaling_factor; 
  backRight_motor.ki /= backRight_motor.PID_scaling_factor; 
  backRight_motor.kd /= backRight_motor.PID_scaling_factor; 



  //Serial.println("Initialization Complete. Ready.");
}

// --- Arduino Loop ---
void loop() {
  frontLeft_motor.target_rpm = 0;
  frontRight_motor.target_rpm = 0;
  backLeft_motor.target_rpm = 0;
  backRight_motor.target_rpm = 100;
  prev_cmd_time = millis();
      
  while((millis() - prev_cmd_time) >= cmd_timout){
    handleSerialInput();
    backLeft_motor.target_rpm = 0;
    backRight_motor.target_rpm = 0;
    frontLeft_motor.target_rpm = 0;
    frontRight_motor.target_rpm = 0;
    float dt_sec = 1;
    updatePID(&frontLeft_motor, dt_sec);
    updatePID(&frontRight_motor, dt_sec);

    updatePID(&backLeft_motor, dt_sec);
    updatePID(&backRight_motor, dt_sec);
  }

  unsigned long currentMillis = millis();

  // 1. Handle Serial Input (Non-blocking)
  handleSerialInput();
  processCommand(); // Process if a command is ready

  // 2. Calculate RPM periodically
  if (currentMillis - lastRpmCalcTime >= RPM_CALC_INTERVAL_MS) {
      lastRpmCalcTime = currentMillis; // Schedule next calc

      calculateRPM(&frontLeft_motor);
      calculateRPM(&frontRight_motor);
      calculateRPM(&backLeft_motor);
      calculateRPM(&backRight_motor);
  }

  // 3. Update PID Controllers periodically
  if (currentMillis - lastPidUpdateTime >= PID_UPDATE_INTERVAL_MS) {
        float dt_sec = (currentMillis - lastPidUpdateTime) / 1000.0f; // Calculate time delta
        lastPidUpdateTime = currentMillis; // Schedule next update

      // Avoid updating PID immediately after RPM calc if intervals are the same
      // to ensure fresh RPM value is used. This structure handles it.

      updatePID(&frontLeft_motor, dt_sec);
      updatePID(&frontRight_motor, dt_sec);

      //backLeft_motor.target_rpm = 100;
      //backRight_motor.target_rpm = 100;
      updatePID(&backLeft_motor, dt_sec);
      updatePID(&backRight_motor, dt_sec);
  }

  // 4. Optional Debug Output (throttled)
  //printMotorData(); // Prints only every ~500ms now
  //serialPID();
  // 5. Other tasks? (Keep the loop fast)

}

void resetPID() { // If needed for tuning commands
  frontLeft_motor.previous_error = frontRight_motor.previous_error = 0;
  frontLeft_motor.integral = frontRight_motor.integral = 0;
  backLeft_motor.previous_error = backRight_motor.previous_error = 0;
  backLeft_motor.integral = backRight_motor.integral = 0;
  // PWM value is output, no need to reset here
}

void serialPID(){
if(Serial.available()){
  String data = Serial.readString();

  backRight_motor.kp = get_p(data);
  backRight_motor.ki = get_i(data);
  backRight_motor.kd = get_d(data);
  resetPID();
  //moving = 1;
}
}


float get_d(String data){
  data.remove(data.indexOf("p"),data.indexOf("d")+1);
  return data.toFloat(); 
}

float get_i(String data){
  data.remove(data.indexOf("p"),data.indexOf("i")+1);
  data.remove(data.indexOf("d"));
  return data.toFloat();
}

float get_p(String data){
  data.remove(data.indexOf("p"),1);
  data.remove(data.indexOf("i"));
  return data.toFloat();
}