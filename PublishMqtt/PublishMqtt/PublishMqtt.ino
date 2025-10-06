#include <WiFi.h>
#include <PubSubClient.h>

//const char* ssid = "mglzin";
//const char* password = ".";

//const char* mqttServer = ""; // IP do seu servidor MQTT
//const int mqttPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi");

  client.setServer(mqttServer, mqttPort);
}

void loop() {
  if (!client.connected()) {
    while (!client.connect("ESP32_Client")) {
      Serial.println("Tentando conectar ao MQTT...");
      delay(3000);
    }
    Serial.println("Conectado ao MQTT");
  }


]]q 

  // Enviar dados
  String payload = "{\"sensor\": \"temperatura\", \"valor\": 26.5}";
  client.publish("iot/esp32", payload.c_str());

  delay(5000);
}