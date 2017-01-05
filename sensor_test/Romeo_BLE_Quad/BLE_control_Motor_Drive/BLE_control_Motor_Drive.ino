/*
* @file BLE-control_motord_rive.ino
* @brief Motor control program for Romeo BLE Quard V1.0 using Mobile Application via Bluethooth
* @Control Command  Use 'F'for Forward 'B' for backwoard 'L' for Left and 'R' for Right
* @ Here i use two Motor noly MA and MC possible to extend with forur Motor
* control motor using BLE via Bluno Test Apps
* 
* @author akash.bangla@gmail.com
* @version  V1.0
* @date  2017-01-05
* pin mapping ref: https://www.dfrobot.com/wiki/index.php/Romeo_BLE_Quad_Robot_Controller_SKU:_DFR0398 
* product wiki: https://www.dfrobot.com/wiki/index.php/Romeo_BLE_Quad_Robot_Controller_SKU:_DFR0398
*/
// motor one
const int IA1=8;  
const int IA2=23;
// motor Two
const int IB1=7;
const int IB2=9;
// motor Three
const int IC1=24;
const int IC2=14;
// motor four
const int ID1=4;
const int ID2=25;

byte byteRead;

void setup() {
  Serial1.begin(115200);  //initial the Serial
  //use four motor
     pinMode(IA1, OUTPUT);
     pinMode(IA2, OUTPUT);
     pinMode(IB1, OUTPUT);
     pinMode(IB2, OUTPUT);
     pinMode(IC1, OUTPUT);
     pinMode(IC2, OUTPUT);
     pinMode(ID1, OUTPUT);
     pinMode(ID2, OUTPUT);

      pinMode(13, OUTPUT); 
}
//use slow decay PWM value maximum 100  ref https://www.dfrobot.com/wiki/index.php/Dual_1.5A_Motor_Driver_-_HR8833_SKU:_DRI0040
void loop() {
  digitalWrite(13,LOW);
  Motor_reset();
   /*  check if data has been sent from the computer: */
  if (Serial1.available()) {
    /* read the most recent byte */
    byteRead = Serial1.read();
    
    /*Listen for a F which means Forward */
    if(byteRead== 'F'){
      Serial1.println("Moving Forward");
      digitalWrite(13,HIGH);
      MA_move(50,0);
      MC_move(50,0);
      delay(1000);
    }
    else if (byteRead == 'B')
      {
        Serial1.println("Moving Backword");
        MA_move(50,1);
        MC_move(50,1);
        delay(1000);
      }
       else if (byteRead == 'L')
        {
          
          Serial1.println("Moving Left");
          MA_move(50,0);
          MC_move(50,1);
          delay(1000);
          }
          else if (byteRead == 'R')
          {
            
            Serial1.println("Moving Right");
            MA_move(50,1);
            MC_move(50,0);
            delay(1000);
            }
            else{
      /*ECHO the value that was read, back to the serial port. */
      Serial1.write(byteRead);
      digitalWrite(13,LOW);
    }
  }

}
  

//fuction that reset all the motor 
void Motor_reset()
{
  //reset the motor A
  digitalWrite(IA1,LOW);
  digitalWrite(IA2,LOW);
  
  //reset the motor B
  digitalWrite(IB1,LOW);
  digitalWrite(IB2,LOW);
  
  //reset the motor C
  digitalWrite(IC1,LOW);
  digitalWrite(IC2,LOW);
  
  //reset the motor D
  digitalWrite(ID1,LOW);
  digitalWrite(ID2,LOW);
}
  
  

void MA_move(int Speed,int dir)  //for dir FALSE move forward, otherwise Backword 
{
     if (dir == 0)
     {
      analogWrite(IA1,Speed);    //set the PWM value
      digitalWrite(IA2,HIGH);  
     }
     else 
     {
      analogWrite(IA2,Speed);    //set the PWM value
      digitalWrite(IA1,HIGH);
     }
  }


void MB_move(int Speed,bool dir)  //for dir FALSE move forward, otherwise Backword 
{
     if (dir == 0)
     {
      analogWrite(IB1,Speed);    //set the PWM value
      digitalWrite(IB2,HIGH);  
     }
     else 
     {
      analogWrite(IB2,Speed);    //set the PWM value
      digitalWrite(IB1,HIGH);
     }
  }


void MC_move(int Speed,bool dir)  //for dir FALSE move forward, otherwise Backword 
{
     if (dir == 0)
     {
      analogWrite(IC1,Speed);    //set the PWM value
      digitalWrite(IC2,HIGH);  
     }
     else 
     {
      analogWrite(IC2,Speed);    //set the PWM value
      digitalWrite(IC1,HIGH);
     }
  }


void MD_move(int Speed,bool dir)  //for dir FALSE move forward, otherwise Backword 
{
     if (dir == 0)
     {
      analogWrite(ID1,Speed);    //set the PWM value
      digitalWrite(ID2,HIGH);  
     }
     else 
     {
      analogWrite(ID2,Speed);    //set the PWM value
      digitalWrite(ID1,HIGH);
     }
  }
