#include <Servo.h>

const int In1_A = 6;  //A_output1
const int In2_A = 7;  //A_output2
const int In1_B = 8;  //B_output1
const int In2_B = 9;  //B_output2
#define L298N_ENA 10  //for L298N_A PWM signal
#define L298N_ENB 11  //for L298N_B PWM signal
Servo myservo;       //test dervo 
Servo half_moon; 
Servo push_servo;
Servo catch_servo;
int angle = 0;        //initial servo angle 
int n = 0;

void setup(){
  Serial.begin(115200);   //set baud rate
  pinMode(In1_A, OUTPUT);  
  pinMode(In2_A, OUTPUT);
  pinMode(L298N_ENA, OUTPUT);  

  pinMode(In1_B, OUTPUT);
  pinMode(In2_B, OUTPUT);
  pinMode(L298N_ENB, OUTPUT);  

  myservo.attach(9);      //test servo pin
  half_moon.attach(3);
  push_servo.attach(5);
  catch_servo.attach(6);
}

void loop(){
  //test
  // zero_servo();
  //gogogo
  half_moon_control();//設定仰角角度
  delay(10000);
  // catch_servo_control();//將球抓下來
  // push_motor_control();//推出去
      //射出去
}

void half_moon_control(){
  while(Serial.available()==0){
    Serial.println("set your department angle: ");  //print message
    delay(1000);//delay
  }
  delay(1000);//delay
  n = Serial.parseInt();//input the angle
  Serial.print("your department angle is: ");//print message 
  Serial.println(n);  
  half_moon.write(n); //set angle
}
void push_motor_control(){
  for(int i=0;i<179;i++){
    push_servo.write(i);
  }
  for(int i=179;i>0;i--){
    push_servo.write(i);
  } 
}
void catch_servo_control(){
  for(int i=0;i<30;i++){
    catch_servo.write(i);
  }
  for(int i=30;i>0;i--){
    catch_servo.write(i);
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
    for(int i =50;i<256;i++)  //increase pwm
    {
      analogWrite(L298N_ENA,i);
      analogWrite(L298N_ENB,i);
      Serial.println(i);
      delay(100);
    }
  Serial.println( "MAX");     //set pwm signal maxium
  for(int i =255;i>=50;--i)    //decrease pwm
    {
      analogWrite(L298N_ENA,i);
      analogWrite(L298N_ENB,i);
      Serial.println(i);
      delay(100);

    }
}
