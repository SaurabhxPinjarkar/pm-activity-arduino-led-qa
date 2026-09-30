// AI-assisted QA revision. Target: Arduino Uno R3 built-in LED.
const unsigned long BLINK_INTERVAL_MS = 1000UL;
unsigned long previousMillis = 0;
bool ledOn = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  previousMillis = millis();
}

void loop() {
  const unsigned long now = millis();
  if (now - previousMillis >= BLINK_INTERVAL_MS) {
    previousMillis = now;
    ledOn = !ledOn;
    digitalWrite(LED_BUILTIN, ledOn ? HIGH : LOW);
  }
}
