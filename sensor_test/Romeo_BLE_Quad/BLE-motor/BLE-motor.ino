/*
* @file Motor driver HR8833-Test.ino
* @brief Motor control program for Romeo BLE Quard V1.0
*
* control motor positive inversion
* 
* @author akash.banglagmail.com
* @version  V1.0
* @date  2017-01-01
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
 
void setup() {
  //use four motor
     pinMode(IA1, OUTPUT);
     pinMode(IA2, OUTPUT);
     pinMode(IB1, OUTPUT);
     pinMode(IB2, OUTPUT);
     pinMode(IC1, OUTPUT);
     pinMode(IC2, OUTPUT);
     pinMode(ID1, OUTPUT);
     pinMode(ID2, OUTPUT);
}

void loop() {
 MA1_Forward(200);//Motor MA1 forward; PWM speed control
 delay(1000);
 MA2_Backward(200);//Motor MA1 backward; PWM speed control
 delay(1000); 
 MB1_Forward(200);//Motor MB1 forward; PWM speed control
 delay(1000);
 MB2_Backward(200);//Motor MB1 backward; PWM speed control
 delay(1000);
 MC1_Forward(200);//Motor MC1 forward; PWM speed control
 delay(1000);
 MC2_Backward(200);//Motor MC1 backward; PWM speed control
 delay(1000); 
 MD1_Forward(200);//Motor MD1 forward; PWM speed control
 delay(1000);
 MD2_Backward(200);//Motor MD1 backward; PWM speed control
 delay(1000); 
}

void MA1_Forward(int Speed1)  //fast decay; Speed = High duty-cycle 
{
     analogWrite(IA1,Speed1);
     digitalWrite(IA2,LOW);  
  }
  
void MA2_Backward(int Speed1)  //slow decay; Speed = Low duty-cycle 
{    
    int Speed2=255-Speed1;
    analogWrite(IA1,Speed2);
    digitalWrite(IA2,HIGH); 
  }
  
void MB1_Forward(int Speed1)
{
     analogWrite(IB1,Speed1);
     digitalWrite(IB2,LOW);  
  }
  
void MB2_Backward(int Speed1)
{    
    int Speed2=255-Speed1;
    analogWrite(IB1,Speed2);
    digitalWrite(IB2,HIGH);   
  }

void MC1_Forward(int Speed1)
{
     analogWrite(IC1,Speed1);
     digitalWrite(IC2,LOW);  
  }
  
void MC2_Backward(int Speed1)
{    
    int Speed2=255-Speed1;
    analogWrite(IC1,Speed2);
    digitalWrite(IC2,HIGH);   
  }
void MD1_Forward(int Speed1)
{
     analogWrite(ID1,Speed1);
     digitalWrite(ID2,LOW);  
  }
  
void MD2_Backward(int Speed1)
{    
    int Speed2=255-Speed1;
    analogWrite(ID1,Speed2);
    digitalWrite(ID2,HIGH);   
  }
