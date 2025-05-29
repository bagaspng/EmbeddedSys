#include <DHT.h>
#include <Servo.h>

#define DHTPIN 2        // Pin data DHT terhubung ke pin 2
#define DHTTYPE DHT11   // Gunakan DHT11 (bisa diganti DHT22 jika pakai itu)

DHT dht(DHTPIN, DHTTYPE);
Servo myServo;

void setup() {
  Serial.begin(9600);
  dht.begin();
  myServo.attach(9); // Servo di pin 9
}

void loop() {
  float suhu = dht.readTemperature();  // Baca suhu (dalam Celcius)

  // Validasi pembacaan
  if (isnan(suhu)) {
    Serial.println("Gagal membaca dari sensor DHT!");
    return;
  }

  Serial.print("Suhu: ");
  Serial.println(suhu);

  // Logika penggerak servo berdasarkan suhu
  if (suhu > 30) {
    myServo.write(90);  // Misalnya buka ventilasi
    Serial.println("🔥 Suhu panas - Servo ke 90 derajat");
  } else {
    myServo.write(0);   // Tutup ventilasi
    Serial.println("✅ Suhu normal - Servo ke 0 derajat");
  }

  delay(2000);  // Baca tiap 2 detik
}
