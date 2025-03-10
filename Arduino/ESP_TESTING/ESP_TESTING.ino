//front left motor

//drive blue and yellow
int motor1pin1 = 12;
int motor1pin2 = 14;
int pwm1 = 13;

//front right motor
//drive red and green
int pwm2 = 27;
int motor2pin1 = 26;
int motor2pin2 = 25;

//front left motor

//drive blue yellow
int motor3pin1 = 17;
int motor3pin2 = 5;
int pwm3 = 16;

//front right motor
int pwm4 = 15;
//drive red green
int motor4pin1 = 4;
int motor4pin2 = 2;

int motorSpeed = 125; //default

void rightTurn();
void leftTurn(); 
void setSpeed(int pwm_freq );
void stop(); 

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1,  OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(motor4pin1,  OUTPUT);
  pinMode(motor4pin2, OUTPUT);


  //(Optional)
  pinMode(pwm1,  OUTPUT); 
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3,  OUTPUT); 
  pinMode(pwm4, OUTPUT);
  
  Serial.begin(9600); 
  
  
  //(Optional)
}

void loop() {
  // put your main code here, to run repeatedly:

  //Controlling speed (0  = off and 255 = max speed):     
  //(Optional)
  

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
        setSpeed(motorSpeed);
        break;
      case 'd':
        motorSpeed -= 10;
        setSpeed(motorSpeed);
        break;
      case 's':
        stop();
        break;
      // default:
      //   // Test to see if the command is a number
      //   stop();
      case 'f':
        forward();
        break; 
    }
  
   }
  
}

void setSpeed(int pwm_freq) {
  // Clamp the frequency to the range [0, 255]
  pwm_freq = constrain(pwm_freq, 0, 255); 
  
  // Write to PWM pins
  analogWrite(pwm1, pwm_freq); // ENA pin
  analogWrite(pwm2, pwm_freq); // ENB pin
  analogWrite(pwm3, pwm_freq); // ENA pin
  analogWrite(pwm4, pwm_freq); // ENB pin
}

void backward(){
  digitalWrite(motor1pin1,  LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);

  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  delay(5);
}


void stop(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, LOW);
  delay(5);
}

void leftTurn(){
  // motor goes up
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  // motor goes down
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  // motor goes down
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  //motor goes up
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  delay(5);
}

void rightTurn(){
  // motor goes down
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  // motor goes up
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  // motor goes uo
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);

  //motor goes down
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
  delay(5);
}

void forward(){
  // motor goes down
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  // motor goes up
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  // motor goes uo
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  //motor goes down
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
  delay(5);
}

