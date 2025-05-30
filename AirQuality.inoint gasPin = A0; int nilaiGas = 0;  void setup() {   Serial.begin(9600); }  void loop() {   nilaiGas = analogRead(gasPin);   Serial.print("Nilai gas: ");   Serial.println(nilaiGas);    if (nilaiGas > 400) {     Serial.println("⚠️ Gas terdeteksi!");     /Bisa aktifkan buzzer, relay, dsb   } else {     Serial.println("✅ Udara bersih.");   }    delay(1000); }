int gasPin = A0;
int nilaiGas = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  nilaiGas = analogRead(gasPin);
  Serial.print("Nilai gas: ");
  Serial.println(nilaiGas);

  if (nilaiGas > 400) {
    Serial.println("⚠️ Gas terdeteksi!");
    // Bisa aktifkan buzzer, relay, dsb
  } else {
    Serial.println("✅ Udara bersih.");
  }

  delay(1000);
}
