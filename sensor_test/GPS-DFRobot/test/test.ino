#include <TinyGPS.h>

TinyGPS gps;

int led = 13;

long lat, lon;
unsigned long fix_age, time, date, speed, course;
unsigned long chars;
unsigned short sentences, failed_checksum;
//int year;
//byte month, day, hour, minute, second, hundredths;

int DEG;
int MIN1;
int MIN2;
 
void LAT(){                       //Latitude state
  DEG=lat/1000000;
  MIN1=(lat/10000)%100;
  MIN2=lat%10000;

  Serial.print("LAT:");              
  Serial.print(DEG);
  Serial.print(MIN1);
  Serial.print(".");
  Serial.print(MIN2);
  Serial.print("'   ");
}

void LON(){                        //Longitude state
  DEG=lon/1000000;
  MIN1=(lon/10000)%100;
  MIN2=lon%10000;

 
  Serial.println("LON:");              
  Serial.print(DEG);
  Serial.print(MIN1);
  Serial.print(".");
  Serial.print(MIN2);
  Serial.print("'   ");
}



void setup()
{
  Serial.begin(9600);            //Set the GPS baud rate.

  pinMode(led, OUTPUT);  

  
  Serial.print("GPS test");          // print a simple message on the LCD 
  delay(2000);
}

void loop()
{
  while (Serial.available())
  {
    digitalWrite(led, HIGH);
    int c = Serial.read();                   // Read the GPS data
    if (gps.encode(c))                        // Check the GPS data
    {
      // process new gps info here
    }

  }
  digitalWrite(led, LOW);
  gps.get_position(&lat, &lon, &fix_age);     // retrieves +/- lat/long in 100000ths of a degree
  gps.get_datetime(&date, &time, &fix_age);   // time in hhmmsscc, date in ddmmyy

  //gps.crack_datetime(&year, &month, &day,    //Date/time cracking
  //&hour, &minute, &second, &hundredths, &fix_age);  

LAT();
LON();

}
