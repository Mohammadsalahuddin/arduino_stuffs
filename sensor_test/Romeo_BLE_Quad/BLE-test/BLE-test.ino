/* ref
 *  Bluno BLE TEST Program
 *  https://www.dfrobot.com/wiki/index.php/Bluno_SKU:DFR0267
 *  need the mobile apps 
 *  BLE test    acts as a LED switch (comma means on the LED otherwise off the LED)
 */
byte byteRead;

void setup() {
  pinMode(13, OUTPUT);
  Serial1.begin(115200);  //initial the Serial
}

void loop() {
   /*  check if data has been sent from the computer: */
  if (Serial1.available()) {
    /* read the most recent byte */
    byteRead = Serial1.read();
    
    /*Listen for a comma which equals byte code # 44 */
    if(byteRead==44){
      Serial1.println();
      digitalWrite(13,HIGH);
    }else{
      /*ECHO the value that was read, back to the serial port. */
      Serial1.write(byteRead);
      digitalWrite(13,LOW);
    }
  }
}
