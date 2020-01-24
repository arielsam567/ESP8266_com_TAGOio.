#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <PubSubClient.h>
#include <Wire.h>
#include "SSD1306Wire.h"



const char* mqttServer = "mqtt.tago.io";// Servidor MQTT
const int mqttPort = 1883;// porta MQTT // pode ser passado qualquer valor como user
const char* mqttUser = "Default"; // Token do device no Tago.io
const char* mqttPassword = "df6b8d67-7e11-459e-9411-ab0d19a24f9c";
char topic[] = "tago/data/post";// Tópico MQTT a ser enviado para o Tago.io
char mytopic[] = "tago/my_topic";// Tópico MQTT a ser enviado para o Tago.io


float umidade;
float temperatura;
int luminosidade;
String str_sta = "estado";
String str_umi = "umidade";
String str_temp = "temperatura";
String str_lum = "luminosidade";
#define LED 14



long previewMillis;
#define tempoMQTT  10000
int x, minX;
bool estado = false;
long currentMillisDisplay;
long previewMillisDisplay;
int tempoDisplay = 50;
String textoLed = "";

WiFiClient espClient;
PubSubClient client(espClient);
ESP8266WiFiMulti wifiMulti;
SSD1306Wire  display(0x3c, D1, D2);

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  setupDisplay();
  setupWifi();
  setupCliente();
}



void loop() {
  Serial.println(analogRead(A0));
  currentMillisDisplay =  millis();
  if (currentMillisDisplay - previewMillisDisplay > tempoDisplay) {
    if (estado == false) {
      textoLed = "LED apagado";
    } else {
      textoLed = "LED acesso";
    }
    previewMillisDisplay = currentMillisDisplay;
    String texto  = "Conectado a " + String( WiFi.SSID());
    minX = -6 * texto.length();
    display.clear();//Apaga o display
    display.drawString(x, 0, texto);
    display.drawString(x, 15, textoLed);
    display.display();
    x = x - 2;
    if (x < minX) {
      x = 128;
    }
  }

  client.loop();
  long currentMillis =  millis();
  if (currentMillis - previewMillis > tempoMQTT) {
    previewMillis = currentMillis;
    verificaWifi();
    verificaCliente();
    umidade++;
    temperatura++;
    luminosidade = analogRead(A0);
    enviaDado(str_lum, luminosidade);
  }
}



void enviaDado(String variable, float dado) {
  String dadoString = String(dado);
  String dadoXXX = "[{\"variable\":\"" + variable + "\",\"value\":" + dadoString + "}]";

  Serial.print("Enviando payload: ");
  Serial.println(dadoXXX);
  if (client.publish(topic, (char*) dadoXXX.c_str())) {
    Serial.println(String("Publish  " + dadoXXX + " ok"));
  } else {
    Serial.println(String("Publish " + dadoXXX + " failed"));
  }
}
