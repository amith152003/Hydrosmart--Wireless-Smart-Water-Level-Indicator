#include <WiFi.h>

const char* ssid     = "Fatherordad";
const char* password = "mother123";

WiFiServer server(80);

int i1 = 32;
int i2 = 35;
int i3 = 34;
int o1 = 22;

void setup() {

  Serial.begin(115200);
  pinMode(i1, INPUT);
  pinMode(i2, INPUT);
  pinMode(i3, INPUT);
  pinMode(o1, OUTPUT);

  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
    
  server.begin();
  digitalWrite(o1, 0);
}



void loop() {
 WiFiClient client = server.available();  
  
  if (client) {                             
    String req = client.readStringUntil('\r');
    client.flush();
    if (req.indexOf("/motor/1") != -1)
     digitalWrite(o1, 1);
    else if (req.indexOf("/motor/2") != -1)
     digitalWrite(o1, 0);
    
  }
  /* if(digitalRead(i1)==0 && digitalRead(i2)==0 && digitalRead(i3)==0){
    client.println("0");
   }
   else if(digitalRead(i1)==0 && digitalRead(i2)==0 && digitalRead(i3)==1){
    client.println("1");
   }
   else if(digitalRead(i1)==0 && digitalRead(i2)==1 && digitalRead(i3)==0){
    client.println("2");
   }
   else if(digitalRead(i1)==0 && digitalRead(i2)==1 && digitalRead(i3)==1){
    client.println("3");
   }
   else if(digitalRead(i1)==1 && digitalRead(i2)==0 && digitalRead(i3)==0){
    client.println("4");
   }
   else if(digitalRead(i1)==1 && digitalRead(i2)==0 && digitalRead(i3)==1){
    client.println("5");
   }
   else if(digitalRead(i1)==1 && digitalRead(i2)==1 && digitalRead(i3)==0){
    client.println("6");
   }

   delay(2000);
   
  level_det();
  digitalWrite(o1, 1);
  delay(3000);
  digitalWrite(o1, 0);
  delay(3000); */

}

