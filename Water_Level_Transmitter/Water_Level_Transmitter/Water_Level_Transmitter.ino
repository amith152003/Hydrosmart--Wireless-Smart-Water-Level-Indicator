//Smart Water Level Transmitter
//by
//Amith Mathew Titus & Mohamed Afran

#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(7,8); //CE and CSN
const byte address[] = "EggNog"; //Passcode(address) for transmission 👉uwu👈

struct PacketData 
{
  byte dry_run;
  byte level;  
  byte motor;
};
PacketData data;

//Initializing Pins
int in1 = A1;
int in2 = A2;
int in3 = A3;
int in4 = A4;
int in5 = A5;
int in6 = A6;
int in7 = A7;

void setup() {
  Serial.begin(9600); 
  radio.begin();
  radio.openWritingPipe(address);
  radio.setDataRate( RF24_250KBPS );
  //radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();   
    pinMode(in1, INPUT);
    pinMode(in2, INPUT);
    pinMode(in3, INPUT);
    pinMode(in4, INPUT);
    pinMode(in5, INPUT);
    pinMode(in6, INPUT);
    pinMode(in7, INPUT);
 }

//Transmission Line
void transmit(){
  radio.write(&data, sizeof(PacketData));
  Serial.print("dryrun : "); Serial.println(data.dry_run);
  Serial.print("level : "); Serial.println(data.level);
  delay(500);

}

//Main Transmission Logic process
void loop() {
 
 if(analogRead(in7) > 200){
  
  data.dry_run = 1;
  if(analogRead(in1) < 200 && analogRead(in2) < 200 && analogRead(in3) < 200 && analogRead(in4) < 200 && analogRead(in5) < 200 && analogRead(in6) < 200){
    data.level = 6;
    data.motor = 0;
    transmit();
   }

   else if(analogRead(in1) > 200 && analogRead(in2) < 200 && analogRead(in3) < 200 && analogRead(in4) < 200 && analogRead(in5) < 200 && analogRead(in6) < 200){
    data.level = 5;
    data.motor = 0;
    transmit();  
   }

   else if(analogRead(in1) > 200 && analogRead(in2) > 200 && analogRead(in3) < 200 && analogRead(in4) < 200 && analogRead(in5) < 200 && analogRead(in6) < 200){
    data.level = 4;
    data.motor = 0;
    transmit();
   }

   else if(analogRead(in1) > 200 && analogRead(in2) > 200 && analogRead(in3) > 200 && analogRead(in4) < 200 && analogRead(in5) < 200 && analogRead(in6) < 200){
    data.level = 3;
    data.motor = 0;
    transmit();
   }

   else if(analogRead(in1) > 200 && analogRead(in2) > 200 && analogRead(in3) > 200 && analogRead(in4) > 200 && analogRead(in5) < 200 && analogRead(in6) < 200){
    data.level = 2;
    data.motor = 0;    
    transmit();
   }

   else if(analogRead(in1) > 200 && analogRead(in2) > 200 && analogRead(in3) > 200 && analogRead(in4) > 200 && analogRead(in5) > 200 && analogRead(in6) < 200){
    data.level = 1;
    data.motor = 0;
    transmit();
   }
  }
 
 else{
  data.dry_run = 0;
  
   if(analogRead(in1) < 200 && analogRead(in2) < 200 && analogRead(in3) < 200 && analogRead(in4) < 200 && analogRead(in5) < 200 && analogRead(in6) < 200){
    data.level = 6;
    data.motor = 0;
    transmit();
   }

   else if(analogRead(in1) > 200 && analogRead(in2) < 200 && analogRead(in3) < 200 && analogRead(in4) < 200 && analogRead(in5) < 200 && analogRead(in6) < 200){
    data.level = 5;
    transmit();  
   }

   else if(analogRead(in1) > 200 && analogRead(in2) > 200 && analogRead(in3) < 200 && analogRead(in4) < 200 && analogRead(in5) < 200 && analogRead(in6) < 200){
    data.level = 4;
    transmit();
   }

   else if(analogRead(in1) > 200 && analogRead(in2) > 200 && analogRead(in3) > 200 && analogRead(in4) < 200 && analogRead(in5) < 200 && analogRead(in6) < 200){
    data.level = 3;
    transmit();
   }

   else if(analogRead(in1) > 200 && analogRead(in2) > 200 && analogRead(in3) > 200 && analogRead(in4) > 200 && analogRead(in5) < 200 && analogRead(in6) < 200){
    data.level = 2;
    data.motor = 1;
    transmit();
   }

   else if(analogRead(in1) > 200 && analogRead(in2) > 200 && analogRead(in3) > 200 && analogRead(in4) > 200 && analogRead(in5) > 200 && analogRead(in6) < 200){
    data.level = 1;
    data.motor = 1;
    transmit();
   }
 }
 }
