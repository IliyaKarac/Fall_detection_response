
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
//  
#define Tiltsensor A0

const char* ssid = "";//put your hotspot ssid here
const char* password = "";// put your hotspot password here
const char* mqtt_server = "";


WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;
int threhold=10;
void setup_wifi() {
   delay(100);

    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) 
{
} 

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) 
  {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str()))
    {
      Serial.println("connected");

    } 
     else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 6 seconds before retrying
      delay(6000);
    }
  }
} //end reconnect()

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);//the default mqqt port is 1883.
  client.setCallback(callback);
}


int prev1=0;
int prev2=0;
int count=0;
 
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  long now = millis();
  //send data every 6 second

  
  if (now - lastMsg > 600) {
     lastMsg = now;
    int val=analogRead(Tiltsensor);
     String msg=" ";
     msg= msg+ val;
    Serial.println(msg);
    char message[58];

    if(val<1000 ){
      count++;
    }
    else if(val>1000){
      count = 0;
    }

    if(count>60){
       msg = "fall detected"; 
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish("User_falls", message);
      count = 0;
    }

    if(val>1000 && prev1<20 && prev2>1000){
       msg = "fall detected"; 
       msg.toCharArray(message,58);
       Serial.println(message);
      client.publish("User_falls", message);
    }
    else if(val<20 && prev1>1000 && prev2<20){
       msg = "fall detected"; 
      msg.toCharArray(message,58);
      Serial.println(message);
      client.publish("User_falls", message);
    }

    prev2 = prev1;
    prev1 = val;
     
     

  }
}
