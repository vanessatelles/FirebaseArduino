ram#include <FirebaseArduino.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include  <ESP8266WiFi.h>

WiFiUDP udp;//Cria um objeto "UDP".
NTPClient ntp(udp, "a.st1.ntp.br", -3 * 3600, 60000);//Cria um objeto "NTP" com as configurações.

#define FIREBASE_HOST "imunode-eb93f.firebaseio.com"
#define WIFI_SSID "Nome da rede aqui " // Change the name of your WIFI
#define WIFI_PASSWORD "senhaaqui" // Change the password of your WIFI

String hora;//Váriavel que armazenara o horario do NTP;

void setup() {

   Serial.begin(115200);
   WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Start1");
  }
  Serial.println ("Start");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST);

  ntp.begin();//Inicia o NTP.
  ntp.forceUpdate();//Força o Update.

  
}
  
void loop() {
 
   hora = ntp.getFormattedTime();//Armazena na váriavel HORA, o horario atual.
   Serial.println(hora);//Printa a hora já formatada no monitor.

       
     Firebase.pushString ("Hora",hora);
     //Firebase.pushFloat ("Humidity",h);
     delay(1000);
  
  delay(200);
}
