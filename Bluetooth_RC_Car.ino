


/*
 * Program written by: Abdul Lutfi
 * Email: abdul.lutfi146@gmail.com
 * abdullutfiblog.wordpress.com
 * 
 * Last updated: 7 September 2017
*/

//Define Direction & Speed: Results from Serial Reading from Bluetooth
//F,B,L,R, etc are commands sent out by the phone app to the arduino. Do not change!

#define forward 'F'
#define backward 'B'
#define left 'L'
#define right 'R'
#define forwardRight 'I'
#define forwardLeft 'G'
#define backwardLeft 'J'
#define backwardRight 'H'
#define Stop 'S'



//Define Pinout Motor Control: Deviations due to different arduino shields possible & motor connection
//To other Users, Change leftMotor and rightMotor accordingly

#define rightMotor 10
#define leftMotor 11
#define rightDirection 12                      // Right Motor: HIGH = Backwards, LOW = Forward
#define leftDirection 13                       // Left Motor : HIGH = Forward  , LOW = Backwards

char data = 0;
void setup() {
  // put your setup code here, to run once:
  //Serial1.begin(9600);              
  Serial.begin(9600);

  pinMode(rightDirection,OUTPUT);              // Defining rightDirection's Pin as Output
  pinMode(leftDirection,OUTPUT);               // Defining leftDirection's Pin as Output

}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available())                       // Check availability of serial input (BlueTooth)
  { 
    data = Serial.read();                      // Read values from serial interface of BlueTooth
    Serial.println(data);                      // Print Values on Serial Monitor (Can run Headless)
    Stopped();

    //Below is the switch statements to execute commands accordingly. 

    if (data == forward)Forward();
    if (data == backward)Backward();
    if (data == left)Left();
    if (data == right)Right();
    if (data == forwardRight)ForwardRight();
    if (data == forwardLeft)ForwardLeft();
    if (data == backwardLeft)BackwardLeft();
    if (data == backwardRight)BackwardRight();
    if (data == Stop)Stopped();
  }
}



void Forward()
{
  digitalWrite(rightDirection,HIGH);  digitalWrite(leftDirection,LOW);
  analogWrite(leftMotor,255); analogWrite(rightMotor,255);
}

void Backward()
{
  digitalWrite(rightDirection,LOW); digitalWrite(leftDirection,HIGH);
  analogWrite(leftMotor,255); analogWrite(rightMotor,255);
}


void Left()
{
  digitalWrite(rightDirection,LOW); digitalWrite(leftDirection,LOW);
  analogWrite(leftMotor,255); analogWrite(rightMotor,255);
}


void Right()
{
  digitalWrite(rightDirection,HIGH); digitalWrite(leftDirection,HIGH);
  analogWrite(leftMotor,255); analogWrite(rightMotor,255);
}


void ForwardRight()
{
  digitalWrite(rightDirection,HIGH); digitalWrite(leftDirection,LOW);
  analogWrite(leftMotor,100); analogWrite(rightMotor,255);
}


void ForwardLeft()
{
  digitalWrite(rightDirection,HIGH); digitalWrite(leftDirection,LOW);
  analogWrite(leftMotor,255); analogWrite(rightMotor,100);
}


void BackwardLeft()
{
  digitalWrite(rightDirection,LOW); digitalWrite(leftDirection,HIGH);
  analogWrite(leftMotor,100); analogWrite(rightMotor,255);
}


void BackwardRight()
{
  digitalWrite(rightDirection,LOW); digitalWrite(leftDirection,HIGH);
  analogWrite(leftMotor,255); analogWrite(rightMotor,100);
}


void Stopped()
{
  analogWrite(leftMotor,0);analogWrite(rightMotor,0);
}
