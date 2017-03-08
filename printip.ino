// Open a serial terminal and see the IP address printed out
void handler(const char *topic, const char *data) {
    Serial.println("received " + String(topic) + ": " + String(data));
}

void setup() {
    Serial.begin(115200);
    for(int i=0;i<5;i++) {
        Serial.println("waiting... " + String(5 - i));
        delay(1000);
    }

    Particle.subscribe("spark/", handler);
    Particle.publish("spark/device/ip");
}