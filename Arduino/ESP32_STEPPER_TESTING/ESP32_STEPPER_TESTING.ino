#include <Stepper.h>

// Define the number of steps per revolution (for a 9° stepper motor)
const int stepsPerRevolution = 40;

// Define the pins connected to the TMC2208 step and direction pins
// int stepPin = 22;    // Pin for step signal (D12)
// int dirPin = 21;     // Pin for direction signal (D14)
// int enablePin = 23;  // Pin for enable signal (D13)

int stepPin = 35;    // Pin for step signal (D12)
int dirPin = 34;     // Pin for direction signal (D14)
int enablePin = 32;  // Pin for enable signal (D13)

// Create a Stepper object
Stepper stepper(stepsPerRevolution, stepPin, dirPin);

void setup() {
  // Set the enable pin to OUTPUT mode
  pinMode(enablePin, OUTPUT);
  
  // Initially disable the motor by setting the enable pin low (assuming active low enable)
  digitalWrite(enablePin, LOW);
  
  // Set motor speed to a higher RPM (e.g., 1000 RPM)
  stepper.setSpeed(10000);  // Increase speed to 1000 RPM or higher
}

void loop() {
  // Move motor 100 steps in one direction
  stepper.step(100);
  // delay(50);  // Reduced delay between steps, increase or decrease to your preference

}
