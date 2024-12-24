#include <ESP8266WiFi.h>  // ESP8266 WiFi library
#include <DHT.h>           // DHT sensor library

#define DHTPIN 2      // GPIO2 (D4 on NodeMCU)
#define DHTTYPE DHT11 // DHT11 sensor
#define MOISTURE_PIN A0 // Soil moisture sensor connected to analog pin A0

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Define WiFi and ThingSpeak details
const char* ssid = "mdhd";          // Replace with your WiFi SSID
const char* password = "0987654321";             // Replace with your WiFi password
const char* apiKey = "25OEIGY9S3H2PUYS"; // Replace with your ThingSpeak Write API Key
const char* server = "api.thingspeak.com"; // ThingSpeak server
const int channelId = 2785149; // Replace with your ThingSpeak channel ID (numeric)

// WiFi client object
WiFiClient wifiClient;

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(115200);
  Serial.println("DHT11 Sensor Setup");

  // Start the DHT sensor
  dht.begin();

  // Connect to WiFi
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
}

void loop() {
  // Wait a bit between readings
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Default is Celsius

  // Read soil moisture
  int moistureLevel = analogRead(MOISTURE_PIN);  // Read the value from the soil moisture sensor (0-1023)

  // Check if any readings failed and exit early
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the results to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.print("°C  Moisture Level: ");
  Serial.println(moistureLevel);

  // Send data to ThingSpeak
  if (wifiClient.connect(server, 80)) {
    String postStr = String("api_key=") + apiKey + 
                     "&field1=" + String(temperature) + 
                     "&field2=" + String(humidity) + 
                     "&field3=" + String(moistureLevel);

    // POST data to ThingSpeak channel
    wifiClient.println("POST /update HTTP/1.1");
    wifiClient.println("Host: api.thingspeak.com");
    wifiClient.println("Connection: close");
    wifiClient.println("Content-Type: application/x-www-form-urlencoded");
    wifiClient.print("Content-Length: ");
    wifiClient.println(postStr.length());
    wifiClient.println();
    wifiClient.print(postStr);

    Serial.println("Data sent to ThingSpeak");
    wifiClient.stop();
  } else {
    Serial.println("Failed to connect to ThingSpeak");
  }
}