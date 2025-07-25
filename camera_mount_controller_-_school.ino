#include <Servo.h>



#define IN1 3 // motor 1 on DRV8833 motor board
#define IN2 5  // motor 1 on DRV8833 motor board

#define JoyRotate A1
#define JoyUpDown A2

#define servoPin 6


Servo myservo;


int Pos; 

int xVal;
int yVal;

int CW;
int CCW;



//////////////////// FUNCIONS /////////////////////////

  
void Rotate () {


  yVal = analogRead(JoyRotate);
  Serial.println(yVal);

  CW = constrain(map(yVal,550,1023,0,255),0,255);
  CCW = constrain(map(yVal,500,0,0,255),0,255);




  if (yVal > 550) {
    analogWrite(IN1,CW);
    digitalWrite(IN2,LOW);
  }

  else if (yVal < 500) {
    digitalWrite(IN1,LOW);
    analogWrite(IN2,CCW);
  }

  else{
    digitalWrite(IN1,LOW);
    analogWrite(IN2,LOW);
    
  }

//  analogWrite(IN1, CW);
//  analogWrite(IN2, CCW);

}

void ServoCon() {

    xVal = analogRead(JoyUpDown);

    Pos = constrain(Pos,0,180);

    if (xVal < 500) {
      Pos = Pos - 1;

      myservo.write(Pos);

      delay(150);
      
    }

    if (xVal > 550) {
      Pos = Pos + 1;

      myservo.write(Pos);

      delay(250);

   
    }
}



void setup() {
   

  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT);

  pinMode(JoyRotate, INPUT);
  pinMode(JoyUpDown, INPUT);


  Pos = 150;
 
  myservo.write(Pos);
  myservo.attach(servoPin);



  

  Serial.begin(9600);


   
}

void loop() {

  Rotate();
  
//  xVal = analogRead(JoyUpDown);
//  yVal = analogRead(JoyRotate);

  ServoCon();

//  Serial.print(xVal);
//  Serial.print("  ");
//  Serial.print(yVal);
//  Serial.print("  ");
//  Serial.println(Pos);

//   digitalWrite(IN2, LOW);
//   digitalWrite(IN1, LOW);
//   Serial.println("stopped");
//   delay(2000);
//   analogWrite(IN2,100);
//   digitalWrite(IN1, LOW);
//   Serial.println("half");
//   delay(2000);
//   analogWrite(IN2, 255);
//   digitalWrite(IN1, LOW);
//   Serial.println("full");
//   delay(1000);
  
}
