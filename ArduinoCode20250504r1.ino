//Programming for hand
#include <Servo.h>

#define THRESHOLD 150 //In order to determine the state of the hand (opened/closed)
#define EMGPIN 3 //Analog pin connected to Muscle Sensor V3 Board
#define LITTLEPIN  2 //Digital pin used by Little servo
#define RINGPIN    3 //Digital pin used by Ring servo
#define MIDDLEPIN  4 //Digital pin used by Middle servo
#define INDEXPIN   5 //Digital pin used by Index servo
#define THUMBPIN   6 //Digital pin used by Thumb servo
#define CLOSED 100
#define OPENED 0

Servo servoLittleFinger;         // Define servo fingers
Servo servoRingFinger;         // Define servo fingers
Servo servoMiddleFinger;         // Define servo fingers
Servo servoIndexFinger;         // Define servo fingers
Servo servoThumbFinger;         // Define servo fingers
char command;  // Stores the received command
char hand_state = OPENED;

// You have to rewrite properly the functions to open and close the fingers
// according of your assembly
// In my case, middle and index fingers are opened when servo is at 170 degrees and the others when servo is at 0 degrees
// I have used Towardpro MG996R servos


void setup(){
  
  Serial.begin(9600); //BAUDRATE set to 115200, remember it to set monitor serial properly (used this BaudRate and "NL&CR" option to visualize the values correctly)
  
  servoLittleFinger.attach(LITTLEPIN);  // Set Little finger servo to digital pin 3
  servoRingFinger.attach(RINGPIN);  // Set Ring finger servo to digital pin 5
  servoMiddleFinger.attach(MIDDLEPIN);  // Set Middle finger servo to digital pin 6
  servoIndexFinger.attach(INDEXPIN);  // Set Index finger servo to digital pin 9
  servoThumbFinger.attach(THUMBPIN);  // Set Thumb finger servo to digital pin 10
  Serial.println("Please enter command \n");
  hand_state = OPENED;
}

void loop() {

  if (Serial.available() > 0) 
  { //If data is available
    command = Serial.read();  // Read the command
    if ((command == 'C' )&& (hand_state == OPENED))  
    {
      Serial.println("Hand closing \n");
      servoLittleFinger.writeMicroseconds(1700);
      servoRingFinger.writeMicroseconds(1800); 
      servoMiddleFinger.writeMicroseconds(1800); 
      servoIndexFinger.writeMicroseconds(1700); 
      //servoThumbFinger.writeMicroseconds(1700); 

      delay(6000);
      servoLittleFinger.writeMicroseconds(1500);
      servoRingFinger.writeMicroseconds(1500);
      servoMiddleFinger.writeMicroseconds(1500);
      servoIndexFinger.writeMicroseconds(1500);
      //servoThumbFi nger.writeMicroseconds(1500);

      hand_state = CLOSED;
      Serial.println("Hand closed \n");
    }
    else if ((command == 'O')&& (hand_state == CLOSED)) 
    {
      Serial.println("Hand opening \n");
      servoLittleFinger.writeMicroseconds(1275);
      servoRingFinger.writeMicroseconds(1175);
      servoMiddleFinger.writeMicroseconds(1275);
      servoIndexFinger.writeMicroseconds(1275);
      //servoThumbFinger.writeMicroseconds(1275);
      delay(3000);
      servoLittleFinger.writeMicroseconds(1500);
      servoRingFinger.writeMicroseconds(1500);
      servoMiddleFinger.writeMicroseconds(1500);
      servoIndexFinger.writeMicroseconds(1500);
      //servoThumbFinger.writeMicroseconds(1500);

      hand_state = OPENED;
      Serial.println("Hand opened \n");
    }
  }
}