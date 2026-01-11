# 🔥 EmbeddedSystem - Flame And Gas Sensor

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


---

## 👨‍💻 Author

**Bagas Pangestu** ([@bagaspng](https://github.com/bagaspng))


---

<div align="center">

**⚡ Building the Future with Embedded Systems ⚡**

[![GitHub stars](https://img.shields.io/github/stars/bagaspng/EmbeddedSys?style=social)](https://github.com/bagaspng/EmbeddedSys/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/bagaspng/EmbeddedSys?style=social)](https://github.com/bagaspng/EmbeddedSys/network/members)

**Made with ❤️ for the Embedded Systems Community**

</div>










