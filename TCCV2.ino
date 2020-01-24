//#include <OneWire.h> //INCLUSÃO DE BIBLIOTECA
//#include <DallasTemperature.h> //INCLUSÃO DE BIBLIOTECA
//// Biblioteca para WIFI
//#include <ESP8266WiFi.h>
//// Biblioteca para o protocolo MQTT
//#include <PubSubClient.h>
//// Biblioteca sensor DHT
//#include "DHT.h"
//// O DHTPIN 2 representa a porta D4 
//#define DHTPIN 2
//// O DS18B20PIN 4 representa a porta D2
//#define DS18B20 4
//// Define o tipo do DHT (pode ser o 11 ou 22)
//#define DHTTYPE DHT11
//// Variaveis para iniciar o DHT
//DHT dht(DHTPIN, DHTTYPE);
//OneWire ourWire(DS18B20);
//DallasTemperature sensors(&ourWire);
//
//// SSID WIFI
//const char* ssid = "AHSJ - Corporativo";
//// Senha  WIFI
//const char* password = "teste*2018";
//// Servidor MQTT
//const char* mqttServer = "mqtt.tago.io";
//// porta MQTT
//const int mqttPort = 1883;
//// pode ser passado qualquer valor como user
//const char* mqttUser = "Default";
//// Token do device no Tago.io
//const char* mqttPassword = "7cc8289d-8a7a-4de0-825c-69b6cbcda9a6";
//// Tópico MQTT a ser enviado para o Tago.io
//char topic[] = "tago/data/post";
//
//// Variáveis auxiliares
//float umidadeDHT = 0;
//float temperaturaDHT = 0;
//float temperaturaDS = 0;
//
////strings para envio dos dados no JSON
//String Str1 = "temperaturaDHT";
//String Str2 = "umidadeDHT";
//String Str3 = "temperaturaDS";
//
//// Inicia o cliente WIFI
//WiFiClient espClient;
//// Inicia o cliente wifi na biblitoeca PuSub
//PubSubClient client(espClient);
//
//void setup() {
//  
//// Conecta-se a rede WIFI
//Serial.begin(115200);
//WiFi.begin(ssid, password);
//while (WiFi.status() != WL_CONNECTED) {
//delay(500);
//Serial.println("Conectando ao WiFi...");
//}
//Serial.println("Conectado ao WiFi");
//
//// Inicia o server e conecta-se ao broker MQTT do tago.io
//client.setServer(mqttServer, mqttPort);
//while (!client.connected()) {
//Serial.println("Conectando ao MQTT...");
//if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
//Serial.println("Conectado");
//} else {
//Serial.print("Falha na conexão MQTT: ");
//Serial.print(client.state());
//delay(2000);
//    }
//  }
//  
//dht.begin();
//// Inicia o DS
//sensors.begin();
//// Inicia DHT
//
//}
//
//// função para enviar os dados para a plataforma
//void enviaDado(float dado1, float dado2, float dado3) {
//
//  String payload = "[{\"" + Str1 + "\":";
//
//  payload += dado1;
//  payload += ", \"" + Str2 + "\":";
//  payload += dado2;
//  payload += ", \"" + Str3 + "\":";
//  payload += dado3;
//  payload += "}]";
//
//  Serial.print("Enviando payload: ");
//  Serial.println(payload);
//
//  // Envia o dado
//
//  if (client.publish(topic, (char*) payload.c_str())) {
//    Serial.println("Publish ok");
//  } else {
//    Serial.println("Publish failed");
//  }
//}
//
//void loop() {
//
//  if (!!!client.connected()) {
//
//   // Caso não esteja conectada, tenta a conexão
//
//    Serial.print("Reconectando-se em ");
//    Serial.println(mqttServer);
//    while (!!!client.connect("ESP8266Client", mqttUser, mqttPassword )) {
//      Serial.print(".");
//      delay(500);
//    }
//    Serial.println();
//  }
//  // Le os dados do DHT
//
//  umidadeDHT = LeUmidadeArDHT();
//  temperaturaDHT = LeTemperaturaDHT();
//  temperaturaDS = LeTemperaturaDS();
//
//  //__ Envia um dado para a cloud
//
//  enviaDado(temperaturaDHT, umidadeDHT, temperaturaDS);
//
//  //__ Faz o envio a cada 5 segundos.
//  delay(5000);
//
//}
//
//// lê a temperatura do DS
//float LeTemperaturaDS(){
//  
//  sensors.requestTemperatures();
//  float temperaturaDS = sensors.getTempCByIndex(0);
//  if (isnan(temperaturaDS)) // nan = not a number
//  {
//    Serial.println("Falha na leitura do DS...");
//  }
//  else
//  {
//    return temperaturaDS;
//  }
//}
//
//// lê a temperatura do DHT
//float LeTemperaturaDHT() {
//
//  float temperaturaDHT = dht.readTemperature();
//  if (isnan(temperaturaDHT)) // nan = not a number
//  {
//    Serial.println("Falha na leitura do DHT11...");
//  }
//  else
//  {
//    return temperaturaDHT;
//  }
//}
//
//// lê a umidade do DHT
//float LeUmidadeArDHT() {
//  float umidadeDHT = dht.readHumidity();
//  if (isnan(umidadeDHT)) // nan = not a number
//  {
//    Serial.println("Falha na leitura do DHT11...");
//  }
//  else
//  {
//    return umidadeDHT;
//  }
//}
