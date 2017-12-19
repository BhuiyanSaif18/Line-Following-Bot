#include <NewPing.h>

#include <Servo.h>

int Mtr11 = 5;
int Mtr12 = 6;
int Mtr21 = 9;
int Mtr22 = 10;
int trig=12;
int echo=11;
int i= 150;
int j= 8;
int k=0;
int ar[8]={0,0,0,0,0,0,0};
Servo srv;
NewPing sonar(11, 12, 25); 
void setup() 
{
  
  srv.attach(3);
  Serial.begin(115200);
  pinMode(trig , OUTPUT);
  pinMode (Mtr11 , OUTPUT);
  pinMode (Mtr12, OUTPUT);
  pinMode (Mtr21, OUTPUT);
  pinMode (Mtr22, OUTPUT);
  pinMode (13, OUTPUT);
}
void hard_left()
{
  //check
  analogWrite(Mtr11, 200);
  analogWrite(Mtr12, 0);
  analogWrite(Mtr21, 0);
  analogWrite(Mtr22, 200);
  //check
   /* digitalWrite(Mtr11, LOW);
    digitalWrite(Mtr12, HIGH);
    digitalWrite(Mtr21, HIGH);
    digitalWrite(Mtr22, LOW);*/
}
void hard_right()
{
  //check
  analogWrite(Mtr11, 0);
  analogWrite(Mtr12, 200);
  analogWrite(Mtr21, 200);
  analogWrite(Mtr22, 0);
  //check
    /*digitalWrite(Mtr11, LOW);
    digitalWrite(Mtr12, HIGH);
    digitalWrite(Mtr21, LOW);
    digitalWrite(Mtr22, HIGH);*/
}
void forward()
{
  //check
  analogWrite(Mtr11, 200);
  analogWrite(Mtr12, 0);
  analogWrite(Mtr21, 200);
  analogWrite(Mtr22, 0);
  //check
   /*digitalWrite(Mtr11, HIGH);
   digitalWrite(Mtr12, LOW);
   digitalWrite(Mtr21, HIGH);
   digitalWrite(Mtr22, LOW);*/
}
void medium_right()
{
  analogWrite(Mtr11, 200);
  analogWrite(Mtr12, 0);
  analogWrite(Mtr21, 180);
  analogWrite(Mtr22, 0);
}
void medium_left(){
  analogWrite(Mtr11, 180);
  analogWrite(Mtr12, 0);
  analogWrite(Mtr21, 200);
  analogWrite(Mtr22, 0);
}
void full_white()
{
    digitalWrite(Mtr11, HIGH);
    digitalWrite(Mtr12, LOW);
    digitalWrite(Mtr21, HIGH);
    digitalWrite(Mtr22, LOW); 
}
void full_black()
{
    digitalWrite(Mtr11, LOW);
    digitalWrite(Mtr12, LOW);
    digitalWrite(Mtr21, LOW);
    digitalWrite(Mtr22, LOW); 
}
void left(){
   analogWrite(Mtr11, 200);
  analogWrite(Mtr12, 0);
  analogWrite(Mtr21, 0);
  analogWrite(Mtr22, 0);
}
void right(){
   analogWrite(Mtr11, 0);
  analogWrite(Mtr12, 0);
  analogWrite(Mtr21, 200);
  analogWrite(Mtr22, 0);
}
void pwr_right(){
      digitalWrite(Mtr11, HIGH);
      digitalWrite(Mtr12, LOW);
      digitalWrite(Mtr21, LOW);
      digitalWrite(Mtr22, HIGH);
}
void pwr_left(){
      digitalWrite(Mtr11, LOW);
      digitalWrite(Mtr12, HIGH);
      digitalWrite(Mtr21, HIGH);
      digitalWrite(Mtr22, LOW);
}

void loop() 
{srv.write(0);
  delay(50);
  digitalWrite(13, HIGH);
int s = sonar.ping_cm();
int v1 = analogRead(A0);
int v2 = analogRead(A1);
int v3= analogRead(A2);
int v4= analogRead(A3);
int v5= analogRead(A4);
int v6=analogRead(A5);
//check
 Serial.print(v1);
  Serial.print("\t");
  Serial.print(v2);
  Serial.print("\t");
  Serial.print(v3);
  Serial.print("\t");
  Serial.print(v4);
  Serial.print("\t");
  Serial.print(v5);
  Serial.print("\t");
  Serial.print(v6);
  Serial.print("\t");
  Serial.println(s);
//check
if(v1>i && v2>i && v3<i &&v4<i && v5>i && v6>i){
    forward();
}
if(v1>i && v2>i && v3<i &&v4<i && v5>i && v6>i && s<15){
    obs();
}
else if(((v1<i && v2<i && v3<i &&v4<i && v5<i && v6>i )) ||(v1<i && v2<i && v3<i &&v4<i && v5>i && v6>i) || (v1<i && v2<i && v3<i &&v4>i && v5>i && v6>i) || (v1<i && v2<i && v3>i &&v4>i && v5>i && v6>i) || (v1<i && v2>i && v3>i &&v4>i && v5>i && v6>i))  {
      hard_left();     
}
else if( ((v1>i && v2<i && v3<i &&v4<i && v5<i && v6<i)) || ((v1>i && v2>i && v3<i &&v4<i && v5<i && v6<i) || (v1>i && v2>i && v3>i &&v4<i && v5<i && v6<i) || (v1>i && v2>i && v3>i &&v4>i && v5<i && v6<i) || (v1>i && v2>i && v3>i &&v4>i && v5>i && v6<i))){
     hard_right();
}
/*else if(v1<i && v2>i && v3<i &&v4<i && v5>i && v6>i){
  //pwr_left1
  k=1;
}
else if(v1>i && v2>i && v3<i &&v4<i && v5>i && v6<i){
  //pwr_right2
  k=2;
}
else if(v1>i && v2<i && v3<i &&v4<i && v5>i && v6>i){
  //pwr_left11
    if(k==1)
    {
      pwr_left();
      //delay(300);
      k=0;
      }
}
else if(v1>i && v2>i && v3<i &&v4<i && v5<i && v6>i){
  //pwr_right22
    if(k==2)
    {
      pwr_right();
      //delay(300);
      k=0;
      }
}*/
else if((v1<i && v2<i && v3<i &&v4>i && v5<i && v6<i) ){
  medium_left();  
}
else if((v1<i && v2<i && v3>i &&v4<i && v5<i && v6<i) ){
  medium_right();
}
else if((v1< i && v2>i && v3<i &&v4<i && v5<i  && v6<i)|| (v1< i && v2>i && v3>i && v4<i && v5<i  && v6<i)){
  left();
}
else if((v1< i && v2<i && v3<i && v4<i && v5>i  && v6<i)|| (v1< i && v2<i && v3<i && v4>i && v5>i  && v6<i)){
  right();
}

else if(v1<i && v2<i && v3<i &&v4<i  && v5 <i && v6<i ){
  delay(300);
  srv.write(80);
  if(s>>j){
    full_white();
     srv.write(0);
  }
  if(s>j){
    medium_right();
  }
  if(s<j){
    medium_left();
  }
}
 /*else if(v1> i && v2>i && v3>i &&v4>i && v5>i  && v6>i){
  //delay(3000);
  full_black();
  }*/
  /*else if(v1>i && v2>i && v3>i && v4>i  && v5 >i && v6>i ){
    left();
    }
    
  else if(v1>i && v2>i && v3>i && v4>i  && v5>i && v6>i && s>j){
    right();
    }*/
}
