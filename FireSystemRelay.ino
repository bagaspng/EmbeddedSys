int relayPin = 2;      // Relay terhubung ke pin digital 2
int flameSensor = A0;  // Sensor api terhubung ke pin analog A0
int apiTerbaca;        

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);  
  pinMode(flameSensor, INPUT);
  digitalWrite(relayPin, HIGH); // Mulai dengan relay ON (aktifkan perangkat)
}

void loop() {
  apiTerbaca = analogRead(flameSensor);
  Serial.println(apiTerbaca);

  if (apiTerbaca < 500) {  
    // Jika terdeteksi api (nilai kecil karena api menyerap cahaya IR)
    digitalWrite(relayPin, LOW);  // Relay OFF → aliran terputus → perangkat dimatikan
    Serial.println("KEBAKARAN TERDETEKSI! MEMUTUS ALIRAN LISTRIK.");
  } else {
    digitalWrite(relayPin, HIGH); // Relay ON → aliran nyambung → perangkat aktif
    Serial.println("AMAN");
  }

  delay(500);  // Delay kecil agar tidak terlalu sering membaca
}
