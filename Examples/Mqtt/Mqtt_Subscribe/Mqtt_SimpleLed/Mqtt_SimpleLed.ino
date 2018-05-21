
#include <ESP8266WiFi.h>
#include <MQTTClient.h>

const char client_id[] = "microcontroller1";     //arbitrary identification
const char client_key[] = "64784166";            //token KEY from shiftr.io
const char client_secret[] = "bc053907fe6941d8"; //token SECRET from shiftr.io

const char ssid[] = "Play android"; //name of the used Wi-Fi network
const char pass[] = "";             //password of the Wi-Fi network

WiFiClient net;
MQTTClient client;

void connectWIFI()
{
    Serial.print("Connecting Wi-Fi: ");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" Wi-Fi connected!");
}

void connectMQTT()
{
    Serial.print("Connecting MQTT: ");
    while (!client.connect(client_id, client_key, client_secret))
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" MQTT connected!");
}

void setup()
{
    Serial.begin(115200);
    WiFi.begin(ssid, pass);
    connectWIFI();

    client.begin("broker.shiftr.io", net);
    client.onMessage(messageReceived);
    connectMQTT();

    pinMode(16, OUTPUT);
    client.subscribe("/SimpleLed");
}

void loop()
{
    client.loop();
    if (WiFi.status() != WL_CONNECTED)
    {
        connectWIFI();
    }    
    if (!client.connected())
    {
        connectMQTT();
    }
}

void messageReceived(String &topic, String &payload)
{
    Serial.println("New message: " + topic + " - " + payload);
    if(payload=="1") {
        digitalWrite(16, HIGH);
        delay(500);
    }
    else {
        digitalWrite(16, LOW);
        delay(500);
    }    
}

