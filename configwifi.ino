

void setupWifi() {
  wifiScan();
  WiFi.mode(WIFI_STA);
  wifiMulti.addAP("TP-LINK_355E", "campobauer");
  wifiMulti.addAP("Multilaser_2.4G_39C8D0", "12345678");
  wifiMulti.addAP("VIVO-1CD0", "V3XFWa9qXe");
  wifiMulti.addAP("Ariel", "arielariel");
  wifiMulti.addAP("NSI", "wickedbotz");
  Serial.println("\nConnecting Wifi...");
  while (wifiMulti.run() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando ao WiFi...");
  }
  if (wifiMulti.run() == WL_CONNECTED) {
    Serial.println("\nWiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    delay(2000);
  }
}

void wifiScan() {
  int n = WiFi.scanNetworks();
  display.clear();//Apaga o display
  display.drawString(0, 0, "scan done");
  display.display();
  if (n == 0) {
    display.drawString(0, 10, "no networks found");
    display.display();
  } else {
    String numberString = String(n);
    display.clear();//Apaga o display
    display.drawString(0, 0, numberString);
    display.drawString(5, 0, " networks found");
    int valor = 0;
    for (int i = 0; i < n; ++i) {
      String numberString = String((i + 1));
      String s =  WiFi.SSID(i);
      int a =  WiFi.RSSI(i);
      String ass = String(a);
      String text = String(numberString + ": " + s + "   (" + ass + ")");
      display.drawString(0, (i + 1) * 10, text);
      display.display();
    }
  }
}


void verificaWifi() {
  if (wifiMulti.run() != WL_CONNECTED) {
    Serial.println("REFAZENDO CONEXAO");
    display.clear();//Apaga o display
    display.drawString(0, 0, "DESCONECTADO");
    display.display();
    setupWifi();
  } else {
    Serial.println("CONECTADO");
  }
}
