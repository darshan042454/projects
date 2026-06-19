//update 1
#include <Arduino.h>
#include <WiFi.h>
#include <stdio.h>
#include <ArduinoOTA.h>
#include <WebServer.h>

//#include <DHT.h>


#define DHTPIN 22
#define DHTTYPE DHT11
//DHT dht(DHTPIN, DHTTYPE);


const char* ssid = "wifiname ";
const char* password = "password";

const int LED_PIN = 2;
const int ge =12;
const int whi=32;
const int blue =33;
const int red = 26;

int ledon(int bin[],int led[]);

void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
     pinMode(ge, OUTPUT);
      pinMode(whi, OUTPUT);
       pinMode(blue, OUTPUT);
        pinMode(red, OUTPUT);

    WiFi.begin(ssid, password);
       // dht.begin();

    Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi Connected");

    Serial.print("ESP32 IP Address: ");
    Serial.println(WiFi.localIP());

     ArduinoOTA.begin();

      Serial.println("Ota ready");
}
void loop()
{
       ArduinoOTA.handle();
    int num=9;
   int zero=0;
   int one=0;
   int two=0;
   int three=0;
   int bin[10]={0};
   int led[4]={red,blue,whi,ge};

printf("Enter a number:\n");
while (!Serial.available());
  
 num = Serial.parseInt();

Serial.print("Got ");
Serial.println(num);

   for(int i=3;num>0;i--)
   {
      if(num%2==0)
      bin[i]=0;
        else
        bin[i]=1;
        num/=2;
        printf("%d\t",bin[i]);
 }
    printf("got the binay\n");

    for(int i=0;i<10;i++){

        printf("bin[%d]=%d\n",i,bin[i]);
    }
  
     ledon(bin,led);
  
    digitalWrite(ge, LOW);
    digitalWrite(whi, LOW); 
    digitalWrite(blue, LOW);
    digitalWrite(red, LOW);
    printf("All LED OFF\n");
}


    int ledon(int bin[],int led[]){
        for(int i=3;i>=0;i--){

    if(bin[i]==1){
    digitalWrite(led[i], HIGH);
     printf("Executed LED %d\n", i+1);
 }
    else
    digitalWrite(led[i], LOW);
 }
    delay(1500);
    return 0;
    }

