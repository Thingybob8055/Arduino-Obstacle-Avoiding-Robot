// connect motor controller pins to Arduino digital pins
// motor A
int in1 = 8;
int in2 = 9;
// motor B
int in3 = 10;
int in4 = 11;

// IR sensors, left, right and centre
int LeftIR;
int RightIR;
int MiddleIR;

// Flag variables for the IR sensors
int LFlag;
int RFlag;
int MFlag;

void setup()
{
  // set all the motor control pins to outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600);

  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}

void moveForward() //This function makes the robot move forward
{
  //turn on motor A
  Serial.println("Forward");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void reverse() //This function moves the robot backwards
{
  //both motors go backwards
  Serial.println("Reverse");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(1000);
}

void turnRight() //This function first reverses the robot and then moves right
{
  Serial.println("Right");
  // now change motor directions.
  //motor A is reversed, motor B is forwards
  reverse();
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(300);
}

void turnLeft()  //This function first reverses the robot and then moves left
{
  //motor B is reversed, motor A is forwards
  Serial.println("Left");
  reverse();
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(300);
}

void loop() //The main leep of the program
{
  //Reading analog data from the IR sensors
  LeftIR = analogRead(A0);
  MiddleIR = analogRead(A1);
  RightIR = analogRead(A2); 
  
  if (LeftIR < 200)
  {
    LFlag = 1;
  }
  else
  {
    LFlag = 0;
  }

  if (RightIR < 200)
  {
    RFlag = 1;
  }
  else
  {
    RFlag = 0;
  }

  if (MiddleIR < 200)
  {
    MFlag = 1;
  }
  else
  {
    MFlag = 0;
  }

  if(LFlag == 1 || RFlag == 1 || MFlag == 1)
  {
    if (MFlag == 1)
    {
      if (LFlag == 1)
      {
        turnRight();
      }
      else if(RFlag == 1)
      {
        turnLeft();
      }
      else
      {
        turnLeft();
      }
    }

  else if(LFlag == 1)
  {
    turnRight();
  }
  else if(RFlag == 1)
  {
    turnLeft();
  }
  else
  {
    turnLeft();
  }
  }
  else
  {
    moveForward();
  }

}
