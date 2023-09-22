#include <Servo.h>

const int In1_A = 1;  //A_output1
const int In2_A = 2;  //A_output2
const int In1_B = 3;  //B_output1
const int In2_B = 4;  //B_output2

Servo myservo;        //test dervo 
Servo half_moon; 
Servo push_servo;
Servo catch_servo;
int angle = 0;        //initial servo angle 
int n = 0;

void setup(){
  Serial.begin(115200);   //set baud rate
  pinMode(In1_A, OUTPUT);  
  pinMode(In2_A, OUTPUT);
  // pinMode(L298N_ENA, OUTPUT);  

  pinMode(In1_B, OUTPUT);
  pinMode(In2_B, OUTPUT);
  // pinMode(L298N_ENB, OUTPUT);  

  myservo.attach(5);      //test servo pin
  half_moon.attach(6);
  push_servo.attach(7);
  catch_servo.attach(8);
}
void loop(){
  // test
  // zero_servo();
  // gogogo
  // PIKACHU();
   half_moon_control();//設定仰角角度
  // delay(10000);
  // catch_servo_control();//將球抓下來
  // push_motor_control();//推出去
  //射出去
}
void half_moon_control(){   //0~65
  while(Serial.available()==0){
    Serial.println("set your department angle: ");  //print message
    delay(1000);//delay
  }
  delay(1000);//delay
  int half_moon_motor_angle = Serial.parseInt();//input the angle
  Serial.print("your department angle is: ");//print message 
  Serial.println(half_moon_motor_angle);  
  half_moon.write(half_moon_motor_angle); //set angle
  delay(100);
}

void catch_servo_control(){ //catch the ball from the top
  for(int i=0;i<30;i++){
    catch_servo.write(i);     //30 degrees
  }
  for(int i=30;i>0;i--){
    catch_servo.write(i);     //recover to the default angle
  } 
}
void push_motor_control(){    //push the ball to the DC motor
  for(int p=0;p<60;p++){
    push_servo.write(p);      //push
    delay(10);
    Serial.println(p);
  }
  for(int p=60;p>0;p--){
    push_servo.write(p);    //recover
    delay(10);
    Serial.println(p);
  } 
}

//  test 
void stop(){
  digitalWrite(In1_A, LOW);
  digitalWrite(In2_A, LOW);
  digitalWrite(In1_B, LOW);
  digitalWrite(In2_B, LOW);
}
void Servoo(){        //servo test 
  myservo.write(0); // move MG996R's shaft to angle 0°
  delay(1000); // wait for one second
  Serial.println( "0");
  myservo.write(45); // move MG996R's shaft to angle 45°
  delay(1000); // wait for one second 
  Serial.println( "450");
  myservo.write(90); // move MG996R's shaft to angle 90°
  delay(1000); // wait for one second
  Serial.println( "90");
  myservo.write(135); // move MG996R's shaft to angle 135°
  delay(1000); // wait for one second
  Serial.println( "135");
  myservo.write(179); // move MG996R's shaft to angle 180°
  delay(1000); // wait for one second
  Serial.println( "179");
}
void PIKACHU(){       //dc motor test
  digitalWrite(In1_A, HIGH);
  digitalWrite(In2_A, LOW);
  digitalWrite(In1_B, HIGH);
  digitalWrite(In2_B, LOW);
}
void zero_servo(){
  myservo.write(0); // move MG996R's shaft to angle 0°
  delay(1000);
}
void teaa(){          //L298N PWM  test
  Serial.println( "MIN");   //set pwm minium
  for(int i =50;i<256;i++){  //increase pwm
      // analogWrite(L298N_ENA,i);
      // analogWrite(L298N_ENB,i);
      Serial.println(i);
      delay(100);
    }
  Serial.println( "MAX");     //set pwm signal maxium
  for(int i =255;i>=50;--i){    //decrease pwm
    // analogWrite(L298N_ENA,i);
    // analogWrite(L298N_ENB,i);
    Serial.println(i);
    delay(100);
    }
}
