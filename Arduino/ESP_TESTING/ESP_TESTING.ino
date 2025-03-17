int motorA1_pin1 = 14;
int motorA1_pin2 = 12;

int motorA2_pin1 = 27;
int motorA2_pin2 = 26;

int motorA3_pin1 = 35;
int motorA3_pin2 = 32;

int motorA4_pin1 = 5;
int motorA4_pin2 = 18;

int motorB1_pin1 = 2;
int motorB1_pin2 = 4;

int motorB2_pin1 = 16;
int motorB2_pin2 = 17;

int motorB3_pin1 = 21;
int motorB3_pin2 = 19;

int motorB4_pin1 = 23;
int motorB4_pin2 = 22;

int ena12 = 13;
int ena34 = 25; 

int motors[] = {
motorA1_pin1,
motorA1_pin2,
motorA2_pin1,
motorA2_pin2,
motorA3_pin1,
motorA3_pin2,
motorA4_pin1,
motorA4_pin2,
motorB1_pin1,
motorB1_pin2,
motorB2_pin1,
motorB2_pin2,
motorB3_pin1,
motorB3_pin2,
motorB4_pin1,
motorB4_pin2,
};

int motors_size = sizeof(motors)/sizeof(motors[0]);

int motors_A [] = {
  motorA1_pin1,
  motorA1_pin2,
  motorA2_pin1,
  motorA2_pin2,
  motorA3_pin1,
  motorA3_pin2,
  motorA4_pin1,
  motorA4_pin2
};

int motors_B [] = {
  motorB1_pin1,
  motorB1_pin2,
  motorB2_pin1,
  motorB2_pin2,
  motorB3_pin1,
  motorB3_pin2,
  motorB4_pin1,
  motorB4_pin2,
};

int side_size = sizeof(motors_A)/sizeof(motors_A[0]);

int enable_pins[] = {
  ena12,
  ena34
};

int motorSpeed = 125; //default

void setup() {

  for(int i = 0; i < motors_size; i++){
    pinMode(motors[i], OUTPUT);
  }
  pinMode(ena12, OUTPUT);
  pinMode(ena34, OUTPUT);
  
  Serial.begin(9600); 
}

void loop() {
  //Controlling speed (0  = off and 255 = max speed):     

   if (Serial.available() > 0) {
    char command = Serial.read();
    Serial.print("You command: ");
    Serial.print(command); 
    Serial.print(" Your pwm: ");
    Serial.println(motorSpeed);

    switch (command) {
      case 'r': 
        rightTurn();
        break;
      case 'l':
        leftTurn();
        break;
      case 'i':
        motorSpeed  += 10;
        setSpeed();
        break;
      case 'd':
        motorSpeed -= 10;
        setSpeed();
        break;
      case 's':
        stop();
        break;
      case 'f':
        forward();
        break; 
    }
  
   }
  
}

void setSpeed() {
  // Clamp the frequency to the range [0, 255]
  if (motorSpeed > 255) {
      motorSpeed = 255;
  } else if (motorSpeed < 0) {
      motorSpeed = 0;
  }
  
  // Write to PWM pins
  analogWrite(ena12, motorSpeed);
  analogWrite(ena34, motorSpeed);
}

void backward(){
  // Needs to be tested
  for(int i = 0; i < side_size; i+=2){
    if(i%4==0){
      digitalWrite(motors_A[i], LOW);
      digitalWrite(motors_A[i+1], HIGH);
      digitalWrite(motors_B[i], HIGH);
      digitalWrite(motors_B[i+1], LOW);
    }else{
      digitalWrite(motors_A[i], HIGH);
      digitalWrite(motors_A[i+1], LOW);
      digitalWrite(motors_B[i], LOW);
      digitalWrite(motors_B[i+1], HIGH);
    }
    
  }
  delay(5);
}


void stop(){
  for(int i=0; i<16; i++){
    digitalWrite(motors[i], LOW);
  }
  delay(5);
}

void rightTurn(){
  for(int i=0; i<side_size; i++){
    if(i%2==0){
      digitalWrite(motors_A[i], HIGH);
      digitalWrite(motors_B[i], LOW);
    }else{
      digitalWrite(motors_A[i], LOW);
      digitalWrite(motors_B[i], HIGH);
    }
  }
  // Manually writing to each motor
  // digitalWrite(motorB1_pin1,LOW);
  // digitalWrite(motorB1_pin2,HIGH);
  // digitalWrite(motorB2_pin1,LOW);
  // digitalWrite(motorB2_pin2,HIGH);
  // digitalWrite(motorB3_pin1,LOW);
  // digitalWrite(motorB3_pin2,HIGH);
  // digitalWrite(motorB4_pin1,LOW);
  // digitalWrite(motorB4_pin2,HIGH);
  // digitalWrite(motorA1_pin1,HIGH);
  // digitalWrite(motorA1_pin2,LOW);
  // digitalWrite(motorA2_pin1,HIGH);
  // digitalWrite(motorA2_pin2,LOW);
  // digitalWrite(motorA3_pin1,HIGH);
  // digitalWrite(motorA3_pin2,LOW);
  // digitalWrite(motorA4_pin1,HIGH);
  // digitalWrite(motorA4_pin2,LOW);
  delay(5);
}

void leftTurn(){
    for(int i=0; i<side_size; i++){
      if(i%2==0){
        digitalWrite(motors_A[i], LOW);
        digitalWrite(motors_B[i], HIGH);
      }else{
        digitalWrite(motors_A[i], HIGH);
        digitalWrite(motors_B[i], LOW);
      }
    }
  // Manually Writing to Motors
  // digitalWrite(motorA1_pin1,LOW);
  // digitalWrite(motorA1_pin2,HIGH);
  // digitalWrite(motorA2_pin1,LOW);
  // digitalWrite(motorA2_pin2,HIGH);
  // digitalWrite(motorA3_pin1,LOW);
  // digitalWrite(motorA3_pin2,HIGH);
  // digitalWrite(motorA4_pin1,LOW);
  // digitalWrite(motorA4_pin2,HIGH);
  // digitalWrite(motorB1_pin1,HIGH);
  // digitalWrite(motorB1_pin2,LOW);
  // digitalWrite(motorB2_pin1,HIGH);
  // digitalWrite(motorB2_pin2,LOW);
  // digitalWrite(motorB3_pin1,HIGH);
  // digitalWrite(motorB3_pin2,LOW);
  // digitalWrite(motorB4_pin1,HIGH);
  // digitalWrite(motorB4_pin2,LOW);
  delay(5);
}

void forward(){
  // Needs to be tested
  for(int i = 0; i < side_size; i+=2){
    if(i%4==0){
      digitalWrite(motors_A[i], HIGH);
      digitalWrite(motors_A[i+1], LOW);
      digitalWrite(motors_B[i], LOW);
      digitalWrite(motors_B[i+1], HIGH);
    }else{
      digitalWrite(motors_A[i], LOW);
      digitalWrite(motors_A[i+1], HIGH);
      digitalWrite(motors_B[i], HIGH);
      digitalWrite(motors_B[i+1], LOW);
    }
    
  }
  delay(5);
}

