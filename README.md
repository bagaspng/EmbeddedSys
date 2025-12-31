# ⚡ EmbeddedSystem - Flame Sensor

> Koleksi proyek sistem tertanam (embedded systems) menggunakan Arduino dengan fokus pada sensor monitoring dan safety systems

[![C++](https://img.shields.io/badge/C++-100%25-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)](https://github.com/bagaspng/EmbeddedSys)
[![Arduino](https://img.shields.io/badge/Arduino-Compatible-00979D?style=flat-square&logo=arduino&logoColor=white)](https://github.com/bagaspng/EmbeddedSys)
[![Embedded](https://img.shields.io/badge/Embedded-Systems-success?style=flat-square&logo=microchip&logoColor=white)](https://github.com/bagaspng/EmbeddedSys)

## 📋 Deskripsi

EmbeddedSys adalah kumpulan proyek embedded systems yang dikembangkan dengan Arduino IDE. Repositori ini berisi berbagai implementasi sensor monitoring dan safety systems untuk aplikasi IoT, home automation, dan industrial monitoring.  Semua kode ditulis dalam C++ dan compatible dengan berbagai board Arduino.

## 🎯 Proyek yang Tersedia

### 🌬️ **Air Quality Monitor**
- **File**: [`AirQuality.ino`](AirQuality.ino)
- **Fungsi**: Monitoring kualitas udara dengan sensor gas
- **Sensor**: MQ-series gas sensor
- **Fitur**: 
  - Real-time air quality monitoring
  - Threshold-based alert system
  - Serial output for data logging

### 🔥 **Fire Detection Systems**

#### 🚨 **Fire System with Relay Control**
- **File**: [`FireSystemRelay.ino`](FireSystemRelay.ino)
- **Fungsi**:  Sistem deteksi kebakaran dengan kontrol relay
- **Sensor**:  Flame sensor (IR-based)
- **Fitur**:
  - Automatic power cutoff when fire detected
  - Emergency shutdown system
  - Safety relay control

#### 🌡️ **Temperature-Based Fire System**
- **File**: [`FireSystemServo.ino`](FireSystemServo.ino)
- **Fungsi**:  Sistem kontrol berdasarkan suhu dengan servo actuator
- **Sensor**: DHT11/DHT22 temperature sensor + NTC thermistor
- **Fitur**:
  - Temperature-controlled ventilation
  - Servo-based actuator control
  - Dual sensor support (DHT + NTC)

#### 🔥 **Flame Sensor System**
- **File**: [`FlameSensor.ino`](FlameSensor.ino)
- **Fungsi**:  Dedicated flame detection system
- **Sensor**:  IR flame sensor
- **Fitur**:
  - Direct flame detection
  - Emergency response system
  - Relay-based safety shutdown

## 🛠️ Hardware Requirements

### 📟 **Microcontroller**
- **Arduino Uno R3** / Nano / Pro Mini
- **ESP32** / ESP8266 (untuk project dengan WiFi)
- **Power Supply**: 5V/3.3V stable power

### 🔍 **Sensors & Components**

| Project | Sensors | Additional Components |
|---------|---------|----------------------|
| **Air Quality** | MQ-2/MQ-135 Gas Sensor | LED indicators, Buzzer |
| **Fire Relay** | IR Flame Sensor | Relay module, Emergency switch |
| **Fire Servo** | DHT11/22, NTC Thermistor | Servo SG90, Ventilation system |
| **Flame Detection** | IR Flame Sensor | Relay, Safety switches |

### 🔌 **Common Components**
- **Resistors**: 220Ω, 10kΩ pull-up/pull-down
- **LEDs**: Red (alert), Green (normal)
- **Buzzer**: Active/Passive buzzer untuk alert
- **Relay Module**: 5V single/multi-channel
- **Servo Motor**: SG90 micro servo
- **Jumper Wires & Breadboard**

## 📦 Installation & Setup

### 🔧 **Arduino IDE Setup**

1. **Install Arduino IDE** (version 2.0+)
```bash
# Download dari:  https://www.arduino.cc/en/software
```

2. **Install Required Libraries**
```cpp
// Buka Library Manager (Ctrl+Shift+I)
// Install libraries berikut:
- DHT sensor library (by Adafruit)
- Servo library (built-in)
- Wire library (built-in)
```

3. **Board Configuration**
```cpp
// Tools > Board > Arduino Uno (atau board yang digunakan)
// Tools > Port > COM Port yang sesuai
// Tools > Programmer > Arduino as ISP
```

### 📥 **Clone Repository**

```bash
git clone https://github.com/bagaspng/EmbeddedSys.git
cd EmbeddedSys
```

### ⚡ **Upload Sketch**

1.  Buka file `.ino` di Arduino IDE
2. Pilih board dan port yang benar
3. Klik **Upload** (Ctrl+U)
4. Monitor Serial Output (Ctrl+Shift+M)

## 🔌 Wiring Diagrams

### 🌬️ **Air Quality Monitor Wiring**

```
Arduino Uno        MQ-2 Gas Sensor
├── 5V ──────────── VCC
├── GND ─────────── GND
└── A0 ──────────── AO (Analog Output)

Optional LED Indicators:
├── Pin 13 ────────── Green LED + 220Ω resistor → GND
└── Pin 12 ────────── Red LED + 220Ω resistor → GND
```

### 🔥 **Fire System Relay Wiring**

```
Arduino Uno        Flame Sensor        Relay Module
├── 5V ──────────── VCC               VCC
├── GND ─────────── GND               GND
├── A0 ──────────── AO                │
└── Pin 2 ─────────────────────────── IN

Relay Output:
├── COM ──────── Load (Pump/Fan/Alarm)
├── NO ───────── Power Source (+)
└── NC ───────── (Not used)
```

### 🌡️ **Temperature Fire System Wiring**

```
Arduino Uno        DHT11 Sensor       Servo Motor
├── 5V ──────────── VCC (Pin 1)      Red wire
├── GND ─────────── GND (Pin 4)      Black wire  
├── Pin 2 ───────── DATA (Pin 2)     │
└── Pin 9 ─────────────────────────── Signal (Orange/Yellow)

NTC Thermistor:
├── A0 ──────────── NTC + 10kΩ resistor to 5V
└── GND ─────────── NTC other terminal
```

## 💻 Code Examples & Usage

### 🌬️ **Air Quality Monitoring**

```cpp
// Threshold customization
if (nilaiGas > 400) {  // Adjust threshold as needed
    Serial.println("⚠️ Gas terdeteksi!");
    // Add buzzer or LED alert
    digitalWrite(BUZZER_PIN, HIGH);
} else {
    Serial.println("✅ Udara bersih.");
    digitalWrite(BUZZER_PIN, LOW);
}
```

### 🔥 **Fire Detection Logic**

```cpp
// Flame sensor reading (lower value = flame detected)
if (apiTerbaca < 500) {  
    // Fire detected - Emergency shutdown
    digitalWrite(relayPin, LOW);  // Cut power
    Serial.println("KEBAKARAN TERDETEKSI! MEMUTUS ALIRAN LISTRIK.");
    // Add additional emergency protocols
    activateAlarm();
    sendEmergencyAlert();
}
```

### 🌡️ **Temperature-Based Control**

```cpp
// Temperature-controlled servo operation
if (suhu > 30) {
    myServo.write(90);   // Open ventilation
    Serial. println("🔥 Suhu panas - Ventilasi dibuka");
} else if (suhu < 25) {
    myServo.write(0);    // Close ventilation  
    Serial.println("❄️ Suhu dingin - Ventilasi ditutup");
}
```

## 📊 Serial Monitor Output

### 🌬️ **Air Quality Output**
```
Nilai gas: 245
✅ Udara bersih. 
Nilai gas: 456
⚠️ Gas terdeteksi! 
Nilai gas: 521
⚠️ Gas terdeteksi!
```

### 🔥 **Fire Detection Output**
```
487
AMAN
234
KEBAKARAN TERDETEKSI! MEMUTUS ALIRAN LISTRIK.
156
KEBAKARAN TERDETEKSI! MEMUTUS ALIRAN LISTRIK.
```

### 🌡️ **Temperature Control Output**
```
Suhu: 28.50
✅ Suhu normal - Servo ke 0 derajat
Suhu: 32.10
🔥 Suhu panas - Servo ke 90 derajat
```

## ⚙️ Configuration & Customization

### 🎯 **Sensor Calibration**

```cpp
// Gas sensor threshold adjustment
const int GAS_THRESHOLD = 400;  // Adjust based on environment

// Flame sensor sensitivity  
const int FLAME_THRESHOLD = 500;  // Lower = more sensitive

// Temperature thresholds
const float TEMP_HIGH = 30.0;    // High temperature alert
const float TEMP_LOW = 25.0;     // Low temperature threshold
```

### ⏱️ **Timing Configuration**

```cpp
// Reading intervals
const int AIR_QUALITY_INTERVAL = 1000;    // 1 second
const int FIRE_CHECK_INTERVAL = 500;      // 0.5 second  
const int TEMP_READING_INTERVAL = 2000;   // 2 seconds
```

### 📡 **Adding WiFi Connectivity**

```cpp
// For ESP32/ESP8266 projects
#include <WiFi.h>
#include <HTTPClient.h>

// Send sensor data to server
void sendSensorData(float sensorValue) {
    HTTPClient http;
    http.begin("http://your-server.com/api/sensors");
    http.addHeader("Content-Type", "application/json");
    
    String payload = "{\"sensor\": \"" + String(sensorValue) + "\"}";
    int httpResponse = http.POST(payload);
    
    http.end();
}
```

## 🛡️ Safety & Best Practices

### ⚠️ **Safety Guidelines**

1. **Power Management**
   - Always use appropriate power supplies
   - Add fuses for high-current applications
   - Implement emergency shutdown procedures

2. **Sensor Placement**
   - Install gas sensors in proper ventilation areas
   - Mount flame sensors away from heat sources
   - Ensure temperature sensors are not in direct sunlight

3. **Testing Procedures**
   ```cpp
   // Always test emergency systems
   void testEmergencySystem() {
       Serial.println("🧪 Testing emergency systems...");
       digitalWrite(relayPin, LOW);   // Test relay
       delay(1000);
       digitalWrite(relayPin, HIGH);  // Restore normal
       Serial.println("✅ Emergency test completed");
   }
   ```


## 🚀 Advanced Features

### 📊 **Data Logging**

```cpp
// Log sensor data to SD card or EEPROM
#include <EEPROM.h>

void logSensorData(int gasValue, int flameValue, float temperature) {
    static int logIndex = 0;
    
    EEPROM.write(logIndex, gasValue);
    EEPROM.write(logIndex + 1, flameValue);
    EEPROM.write(logIndex + 2, (int)temperature);
    
    logIndex = (logIndex + 3) % 1024;  // Circular buffer
}
```

### 🔔 **Alert System**

```cpp
// Multi-level alert system
enum AlertLevel {
    NORMAL,
    WARNING, 
    CRITICAL,
    EMERGENCY
};

void handleAlert(AlertLevel level) {
    switch(level) {
        case WARNING:
            digitalWrite(LED_YELLOW, HIGH);
            tone(BUZZER_PIN, 1000, 500);
            break;
        case CRITICAL:
            digitalWrite(LED_RED, HIGH);
            tone(BUZZER_PIN, 2000, 1000);
            break;
        case EMERGENCY:
            // All alerts + shutdown
            activateEmergencyProtocol();
            break;
    }
}
```

## 🐛 Troubleshooting

### ❓ **Common Issues**

**Q:  Sensor readings are unstable? **
```cpp
// Add moving average filter
const int SAMPLES = 10;
int readings[SAMPLES];
int readIndex = 0;
int total = 0;

int getStableReading(int pin) {
    total -= readings[readIndex];
    readings[readIndex] = analogRead(pin);
    total += readings[readIndex];
    readIndex = (readIndex + 1) % SAMPLES;
    
    return total / SAMPLES;
}
```

**Q: Relay not switching properly?**
```cpp
// Add delay and verification
void safeRelayControl(int pin, bool state) {
    digitalWrite(pin, state ?  HIGH : LOW);
    delay(50);  // Allow relay to settle
    
    // Verify state if possible
    Serial.print("Relay state: ");
    Serial.println(state ?  "ON" : "OFF");
}
```

**Q: Serial communication issues?**
```cpp
// Check baud rate and add connection test
void setup() {
    Serial.begin(9600);
    while (!Serial) {
        ; // Wait for serial connection
    }
    Serial.println("🚀 System initialized");
}
```

## 🔮 Future Enhancements

- [ ] **Web Dashboard** - ESP32-based web interface
- [ ] **Mobile App** - Android/iOS monitoring app
- [ ] **Database Logging** - MySQL/InfluxDB integration
- [ ] **Machine Learning** - Predictive maintenance
- [ ] **Multi-Sensor Fusion** - Combine multiple sensor data
- [ ] **Wireless Mesh Network** - Multiple sensor nodes
- [ ] **Voice Alerts** - Text-to-speech notifications
- [ ] **Cloud Integration** - AWS IoT / Google Cloud

## 📚 Learning Resources

### 📖 **Documentation**
- [Arduino Official Documentation](https://www.arduino.cc/reference/en/)
- [ESP32 Programming Guide](https://docs.espressif.com/projects/esp-idf/en/latest/)
- [Sensor Interfacing Tutorials](https://learn.adafruit.com/)

### 🎓 **Tutorials**
- [Basic Arduino Programming](https://www.arduino.cc/en/Tutorial/HomePage)
- [Sensor Integration Patterns](https://randomnerdtutorials.com/)
- [IoT Development Best Practices](https://aws.amazon.com/iot-core/getting-started/)

## 🤝 Contributing

Contributions welcome! Here's how to contribute:

### 🔄 **Contribution Steps**
1. **Fork** the repository
2. **Create feature branch** (`git checkout -b feature/new-sensor`)
3. **Add your embedded project** with proper documentation
4. **Test thoroughly** on actual hardware
5. **Commit changes** (`git commit -m 'Add ultrasonic sensor project'`)
6. **Push to branch** (`git push origin feature/new-sensor`)
7. **Open Pull Request**

### 📋 **Contribution Guidelines**

```cpp
// Code style guidelines
// 1. Use meaningful variable names
int temperatureSensor = A0;  // Good
int a0 = A0;                 // Bad

// 2. Add comments for complex logic
if (sensorValue < threshold) {
    // Emergency shutdown procedure
    digitalWrite(emergencyRelay, LOW);
}

// 3. Include pin definitions at top
#define SENSOR_PIN A0
#define RELAY_PIN 2
#define LED_PIN 13
```

### 💡 **Project Ideas for Contributors**
- [ ] **Ultrasonic Distance Sensor** projects
- [ ] **Motion Detection** systems
- [ ] **Environmental Monitoring** (humidity, pressure)
- [ ] **Security Systems** (PIR, magnetic sensors)
- [ ] **Motor Control** projects (stepper, DC motors)
- [ ] **Communication** projects (RF, Bluetooth, LoRa)

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

```
MIT License - Feel free to use, modify, and distribute
Commercial use allowed with attribution
```

## 👨‍💻 Author

**Bagas Pangestu** ([@bagaspng](https://github.com/bagaspng))

- 📧 Email: bagaspangestu0407@gmail.com
- 💼 LinkedIn: [Bagas Pangestu](https://linkedin.com/in/bagaspng)
- 🌐 Portfolio: [bagaspng.dev](https://bagaspng.dev)
- 🎓 Expertise: Embedded Systems, IoT, Arduino Programming

## 🙏 Acknowledgments

- **Arduino Community** - For the amazing ecosystem and libraries
- **Sensor Manufacturers** - For comprehensive datasheets and examples
- **Open Source Contributors** - For inspiration and shared knowledge
- **Embedded Systems Community** - For best practices and guidance

## 📞 Support & Community

Need help? Join our community! 

- 📖 **Wiki**:  [Project Wiki](https://github.com/bagaspng/EmbeddedSys/wiki)
- 🐛 **Issues**: [Report Bugs](https://github.com/bagaspng/EmbeddedSys/issues)
- 💬 **Discussions**: [Q&A Forum](https://github.com/bagaspng/EmbeddedSys/discussions)
- 📧 **Direct Contact**: bagaspangestu0407@gmail.com

## 📊 Repository Stats

![Language Stats](https://github-readme-stats.vercel.app/api/top-langs/?username=bagaspng&repo=EmbeddedSys&layout=compact&theme=tokyonight)

---

<div align="center">

**⚡ Building the Future with Embedded Systems ⚡**

[![GitHub stars](https://img.shields.io/github/stars/bagaspng/EmbeddedSys? style=social)](https://github.com/bagaspng/EmbeddedSys/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/bagaspng/EmbeddedSys?style=social)](https://github.com/bagaspng/EmbeddedSys/network/members)

**Made with ❤️ for the Embedded Systems Community**

</div>

