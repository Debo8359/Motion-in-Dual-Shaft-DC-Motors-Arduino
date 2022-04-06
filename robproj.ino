int motorfl=13; // it is the pin which give signal to the motor driver for clockwise rotation of the left motors
int motorbl=12; // it is the pin which give signal to the motor driver for counter-clockwise rotation of the lrft motors
int motorfr=11; // it is the pin which give signal to the motor driver for clockwise rotation of the right motors
int motorbr=10; // it is the pin which give signal to the motor driver for counter-clockwise rotation of the right motors
int forward=A0; // this pin will take the input for the forward motion of the robot
int backward=A1; // this pin will take the input for the backward motion of the robot
int right=A2; // this pin will take the input for the robot to take right turn
int left=A3; // this pin will take the input for the robot to take left turn
int vforward; // this stores the value read by analog pin A0
int vbackward; // this stores the value read by analog pin A1
int vright; // this stores the value read by analog pin A2
int vleft; // this stores the value read by analog pin A3

void setup() { // here we defined every pin and it's role (input or output)
  pinMode(motorfl,OUTPUT); 
  digitalWrite(motorfl,HIGH);
  pinMode(motorbl,OUTPUT);
  digitalWrite(motorbl,HIGH);
  pinMode(motorfr,OUTPUT);
  digitalWrite(motorfr,HIGH);
  pinMode(motorbr,OUTPUT);
  digitalWrite(motorbr,HIGH);
  pinMode(forward,INPUT);
  pinMode(backward,INPUT);
}

void loop() {
  vforward = digitalRead(forward); // it reads the corrosponding pin
  vbackward = digitalRead(backward); // it reads the corrosponding pin
  vleft = digitalRead(left); // it reads the corrosponding pin
  vright = digitalRead(right); // it reads the corrosponding pin
  if (vforward == 1 && vbackward == 1){ // if no button is pressed then robot will not move
    digitalWrite(motorfl,LOW);
    digitalWrite(motorfr,LOW);
    digitalWrite(motorbl,LOW);
    digitalWrite(motorbr,LOW);
  }
  if (vforward == 0) { // if forward button is pressed then robot will move forward
    digitalWrite(motorfl,HIGH);
    digitalWrite(motorfr,HIGH); 
  }
  if (vbackward == 0) { // if backward button is pressed then robot will move backward
    digitalWrite(motorbl,HIGH);
    digitalWrite(motorbr,HIGH);
  }
  if (vleft == 0) { // if forward left is pressed then robot will move lrft
    digitalWrite(motorbl,HIGH);
    digitalWrite(motorfr,HIGH);
  }
  if (vright == 0) { // if right button is pressed then robot will move right
    digitalWrite(motorfl,HIGH);
    digitalWrite(motorbr,HIGH);
  }
}