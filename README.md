# 🏠 Smart Home Environmental Monitoring System  
### IoT-Based Digital Twin (Simulation + Physical Prototype)

---

## 📌 Project Overview
This project presents a **low-cost, scalable IoT solution** for real-time environmental monitoring using a **Digital Twin approach** combining both simulation and physical implementation.

The system monitors:
- 🌡️ Temperature  
- 💧 Humidity  
- 🧪 Gas concentration (air quality)  

Data is displayed locally via LCD and transmitted wirelessly via Bluetooth to a mobile application.

---

## 🎯 Objectives
- Develop a real-time environmental monitoring system  
- Implement sensor-based automation using embedded systems  
- Create a mobile interface for remote monitoring  
- Simulate industrial deployment using digital tools  

---

## ⚙️ System Architecture

The system is composed of three main layers:

### 🔌 Hardware Layer
- Arduino UNO (microcontroller)  
- DHT11 sensor (temperature & humidity)  
- MQ-2 sensor (gas detection)  
- HC-06 Bluetooth module  
- LCD (I2C interface)  
- LEDs (status indicators)  
- Buzzer (alarm system)  

---

### 💻 Firmware Layer
- Developed in **C++ (Arduino Framework)**  
- Handles:
  - Sensor data acquisition  
  - Threshold-based decision logic  
  - Alarm triggering  
  - Bluetooth communication  

---

### 📱 Mobile Application
- Built using **MIT App Inventor**  
- Features:
  - Real-time data display  
  - Alerts for dangerous gas levels  
  - Simple user interface  

---

### 🏭 Simulation Layer (Digital Twin)
- **Proteus** → Circuit simulation  
- **Factory I/O** → Industrial system layout  

---

## 🧠 System Functionality

The system operates in three states:

### ✅ Normal Mode
- Displays temperature, humidity, and gas levels  
- Green LED ON  
- No alarm  

---

### ⚠️ Warning Mode (Gas Detected)
- Yellow LED ON  
- Notification sent via Bluetooth  
- LCD displays alert  

---

### 🚨 Danger Mode (High Gas Level)
- Red LED + Buzzer activated  
- Continuous alert until gas level decreases  
- Manual stop possible via Bluetooth command  

---

## 🔗 Communication (Arduino ↔ Mobile App)

The system uses the **HC-06 Bluetooth module** for communication.

### 📡 Data Format Sent:
