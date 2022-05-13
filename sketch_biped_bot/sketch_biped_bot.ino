#include <Servo.h> 
#include <SoftwareSerial.h>

Servo servo1;  
Servo servo2;
Servo servo4;
Servo servo5;

long gmotor,gnum1,gnum2;
int pos,pos2;
int flag=0; 
int poss1,poss2,poss3,poss4;
int b = 49;

void setup() 
{
   servo1.attach(3);
   servo2.attach(5);
   servo4.attach(9);
   servo5.attach(10);

   servo1.write(110);
   servo2.write(100);
   servo4.write(90);
   servo5.write(80);

    Serial.begin(9600); 
 }

void call(int motor, int num1, int num2){
flag =0;
switch (motor) 
  {  
    case 1:
      { 
        if(num1<num2)
  { for ( pos =num1; pos<=num2; pos+=1)
  {
    servo1.write(pos);
    delay( 20);
  }}

if(num1>num2)
  {
  for ( pos =num1; pos>=num2; pos-=1)
  {
    servo1.write(pos);
    delay( 20);
  }}
      break;
      }     

       
    case 2:    
      {
        if(num1<num2)
  {
  for ( pos =num1; pos<=num2; pos+=1)
  {
    servo2.write(pos);
    delay( 20);
  }}
if(num1>num2)
  {
  for ( pos =num1; pos>=num2; pos-=1)
  {
    servo2.write(pos);
    delay( 20);
  }}
      break;
      }     
      
           
    case 4:   
      {
        if(num1<num2)
  {
  for ( pos =num1; pos<=num2; pos+=1)
  {
    servo4.write(pos);
    delay (20);
  }}

if(num1>num2)
  {
  for ( pos =num1; pos>=num2; pos-=1)
  {
    servo4.write(pos);
    delay (20);
  }}
      break;
      }
      
      case 5:   
      {
        
  {
  for ( pos =num1; pos<=num2; pos+=1)
        if(num1<num2)
  {
    servo5.write(pos);
    delay (20);
  }}

if(num1>num2)
  {
  for ( pos =num1; pos>=num2; pos-=1)
  {
    servo5.write(pos);
    delay (20);
  }}
      break;
      }
  }
}

void loop()
{

  if(Serial.available()>0)
  {
  gmotor= Serial.parseInt();    
  gnum1= Serial.parseInt();   
  gnum2= Serial.parseInt();   
   flag=1;
   }

   
if (flag ==1 )
call(gmotor,gnum1,gnum2);

if (gmotor ==10)
left_leg_up();  

if (gmotor ==11)
right_leg_up();  

if (gmotor ==12)
move_left_front();

if (gmotor ==13)
move_right_front();

if (b ==49 || gmotor ==49)
say_hi();

if (b ==50 || gmotor ==50)
walk1();

if (b ==51 || gmotor ==51)
walk2();

if (b ==52 || gmotor ==52)
dance1();

if (b ==53 || gmotor ==53)
dance2();

if (b ==54 || gmotor ==54)
{test();test();test();}

//End of executions//

gmotor=0; //To prevet repetetion
b = 0;
//stay_put(); //bring the Bot to initial posotion if required

}

 

/*---------------------------------------------------------------------------*/

 

// Code for Bot Functions......

//***Function to lift the left leg**//
void stay_put()
{
   servo5.attach(10);
   servo1.write(110);
   servo2.write(100);
   servo4.write(90);
   servo5.write(80);
   delay(20);
}
//**_____End of Function______**//

//***Function to lift the left lef**//
void left_leg_up()
{
    poss1 = 80;
    poss2 = 110;
   do{
    servo5.write(poss1);
    servo4.write(poss2);
    poss1++;
    poss2++;
    delay(20);
   }while(poss1 <100 || poss2<140);
   call(4,130,100);
}
//**_____End of Function______**//

//***Function to lift the left lef**//
void right_leg_up()
{
    poss1 = 80;
    poss2 = 100;
   do{
    servo4.write(poss2);
    servo5.write(poss1);
    poss1--;
    poss2--;
    delay(20);
   }while(poss1 >50 || poss2>60); 
   call(5,50,80);
}
//**_____End of Function______**//

//***Function to lift the left lef**//
void move_left_front()
{
    poss1=120;poss2=110;poss3=110;
       do{
    servo2.write(poss1);
    servo1.write(poss2);
    servo5.write(poss3);
    poss1--;
    poss2--;
    poss3--;
    delay(20);
   }while(poss1 >100 || poss2>80 || poss3>80  );
}
//**_____End of Function______**//

//***Function to lift the left lef**//
void  move_right_front()
{
    poss1=80;poss2=100;poss3=60;
       do{
    servo1.write(poss1);
    servo2.write(poss2);
    servo4.write(poss3);
    poss1++;
    poss2++;
    poss3++;
    delay(20);
   }while(poss1 <110 || poss2<120 || poss3<90);    
}
//**_____End of Function______**//

//***Function to lift the left lef**//
void say_hi()
{
  stay_put();
  right_leg_up();
  call(5,80,50); //wave up
  call(5,50,80); //wave down 
  call(5,80,50); //wave up 
  call(5,50,80); //wave down
  stay_put();  
}
//**_____End of Function______**//

//***Function to lift the left lef**//
void walk1()
{
  stay_put();
  char temp=10; //number of steps to make * 2
  do{
  right_leg_up();
  move_right_front();
  left_leg_up();
  move_left_front();  
  temp--;
  }while(temp>0);
}
//**_____End of Function______**//

//***Function to lift the left lef**//
void walk2()
{
  stay_put();
  char temp=10; //number of steps to make * 2
  do{
  move_right_front();
  move_left_front();  
  temp--;
  }while(temp>0);
}
//**_____End of Function______**//

//***Function to lift the left lef**//
void dance1()
{
  stay_put();
  char temp=3; //number of steps to make * 2
  do{
    poss1 = 80;
    poss2 = 60;
   do{
    servo1.write(poss1);
    servo2.write(poss2);
    poss1++;
    poss2++;
    delay(20);
   }while(poss1 <140 || poss2<120);
   
    poss1 = 140;
    poss2 = 120;
   do{
    servo1.write(poss1);
    servo2.write(poss2);
    poss1--;
    poss2--;
    delay(20);
   }while(poss1 >80 || poss2>60);
  temp--;
  }while(temp>0);
  stay_put();
}
//**_____End of Function______**//

//***Function to lift the left lef**//
void dance2()
{
  stay_put();
  char temp=3; //number of steps to make * 2
  do{
  right_leg_up(); right_leg_up();
  stay_put();
  left_leg_up();left_leg_up();
  stay_put();
  temp--;
  }while(temp>0);
  stay_put();
}
//**_____End of Function______**//

//***Function to lift the left lef**//
void test()
{
    poss1 = 40;
    poss2 = 130;
   do{
    servo5.write(poss1);
    servo4.write(poss2);
    poss1++;
    poss2--;
    delay(5);
   }while(poss1 <120 || poss2>50);
   poss1 = 120;
   poss2 = 50;
   do{
    servo5.write(poss1);
    servo4.write(poss2);
    poss1--;
    poss2++;
    delay(5);
   }while(poss1 >40 || poss2<130); 
}
