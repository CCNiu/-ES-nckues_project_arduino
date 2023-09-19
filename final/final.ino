#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo;        //test dervo 
Servo half_moon;
Servo push_servo;
Servo catch_servo;
int half_moon_angle = 0;        //initial servo angle 
int n = 0;
int L_i = 0;
int R_i = 0;
char command;
const int left_motor_PWM = 5;
const int right_motor_PWM = 6;
const int left_motor_Direction = 7;
const int right_motor_Direction = 8;
SoftwareSerial BT(9, 10); //(接收腳,傳送腳)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myservo.attach(1);      //test servo pin
  half_moon.attach(2);
  push_servo.attach(3);
  catch_servo.attach(4);
  pinMode(7,OUTPUT);//方向控制
  pinMode(8,OUTPUT);
  BT.begin(9600);//藍芽鮑率
  catch_servo.write(0);
  push_servo.write(0); 
}

void loop(){
  // put your main code here, to run repeatedly:
  if (BT.available()){
    command = BT.read();
    Serial.println( command );
  }
  switch ( command ){
    case 'U' : 
      if(half_moon_angle){
        half_moon_angle ++;
        half_moon.write(half_moon_angle);
        Serial.println( half_moon_angle );
      }
      break;
    case 'D' :
      if(half_moon_angle <= 0){
        half_moon_angle --;
        half_moon.write(half_moon_angle);
        Serial.println( half_moon_angle );
      }
      break;
    case 'F' :  //前進
      digitalWrite(7,HIGH); 
      digitalWrite(8,LOW);
      if(L_i<255 &&R_i<255) {
        L_i++;
        R_i++;
        analogWrite(left_motor_PWM,L_i);
        analogWrite(right_motor_PWM,R_i);
        delay(10);
      }
      analogWrite(left_motor_PWM,L_i);
      analogWrite(right_motor_PWM,R_i);
      Serial.println( L_i );
      Serial.println( R_i );
      break;
    case 'L' :  //左轉
      if(R_i<255) {
        R_i++;
        L_i=R_i/5;
        analogWrite(left_motor_PWM,L_i);
        analogWrite(right_motor_PWM,R_i);
        delay(10);
      }
      analogWrite(left_motor_PWM,L_i);
      analogWrite(right_motor_PWM,R_i);
      // Serial.println( L_i );
      // Serial.println( R_i );
      break;
    case 'R' :  //右轉
    if(L_i<255) {
        L_i++;
        R_i=L_i/5;
        analogWrite(left_motor_PWM,L_i);
        analogWrite(right_motor_PWM,R_i);
        delay(10);
      }
      analogWrite(left_motor_PWM,L_i);
      analogWrite(right_motor_PWM,R_i);
      break;  
    case 'B' :  //後退
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      if(L_i<255 &&R_i<255) {
        L_i++;
        R_i++;
        analogWrite(left_motor_PWM,L_i);
        analogWrite(right_motor_PWM,R_i);
        delay(10);
      }
      analogWrite(left_motor_PWM,L_i);
      analogWrite(right_motor_PWM,R_i);
      break;  
    case 'N' :  //抓球
      catch_servo_control();
      break;
    case 'P' : //推球
      push_motor_control();
      break;
    case 'S' : //停止
      if(L_i>0){
        L_i--;
        analogWrite(left_motor_PWM,L_i);
        delay(10);
      }
      if(R_i>0){
        R_i--;
        analogWrite(right_motor_PWM,R_i);
        delay(10);
      }
      analogWrite(left_motor_PWM,L_i);
      analogWrite(right_motor_PWM,R_i);
      Serial.println( L_i );
      Serial.println( R_i );
      break;
    case 'K': //待機
      delay(10);
      break;
  }
  int L_i = 0;
  int R_i = 0;
}
void catch_servo_control(){ //catch the ball from the top
  for(int i=0;i<110;i++){
    catch_servo.write(i);     //30 degrees
    delay(10);
  }
  for(int i=110;i>0;i--){
    catch_servo.write(i);     //recover to the default angle
    delay(10);
  } 
  command = "K";
}
void push_motor_control(){    //push the ball to the DC motor
  for(int p=0;p<60;p++){
    push_servo.write(p);      //push
    delay(10);
    // Serial.println(p);
  }
  for(int p=60;p>0;p--){
    push_servo.write(p);    //recover
    delay(10);
    // Serial.println(p);
  } 
}
