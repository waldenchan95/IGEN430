//  DC MOTOR FSM

//States
typedef enum States {IDLE, LEFT, RIGHT, STOP, FORW, BACK, INCREASE_PWM, DECREASE_PWM} state; 

//Commands
typedef enum Commands {LeftTurn, RightTurn, Stop, Forward, Backward, IncreaseSpeed, DecreaseSpeed} command; 


//        LOGIC: 
//            If the command recieved from wifi is one of commands above, perform the action to the motors
//            Else, do nothing 


void setup() {
  // put your setup code here, to run once:

}

void loop() {

  while (1){            //      polling state until command
    switch(state) {
      case IDLE:
      break;

      case LEFT:
      break;

      case RIGHT:
      break;

      case STOP: 
      break; 

      case FORW:
      break; 

      case BACK:
      break; 

      default: 
      break; 
    }
  }
}
