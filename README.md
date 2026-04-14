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
- <img width="1100" height="768" alt="image" src="https://github.com/user-attachments/assets/1d9970d3-95e1-41f4-8876-c74d1778e23c" />


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
  - <img width="375" height="622" alt="Screenshot 2025-03-28 173821" src="https://github.com/user-attachments/assets/858ce5a5-addd-4884-8158-ef55f3c26a2d" />

---

### 🏭 Simulation Layer (Digital Twin)
- **Proteus** → Circuit simulation  
- **Factory I/O** → Industrial system layout

- (https://github.com/user-attachments/assets/1aab1bed-c034-4cc7-9b68-5a0131a69c41)



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

---

## ⚙️ Setup Guide

### 🔌 Hardware Setup
1. Connect DHT11 → Pin 7  
2. Connect MQ-2 → A0  
3. Connect HC-06 → Pins 2 (RX), 3 (TX)  
4. Connect LCD via I2C (0x27)  
5. Connect LEDs & buzzer  

---

### 💻 Firmware Setup
1. Install Arduino IDE  
2. Install libraries:
   - DHT  
   - LiquidCrystal_I2C  
3. Upload `code_pfe.ino`  

---

### 📱 Mobile App Setup
1. Install APK on Android  
2. Enable Bluetooth  
3. Connect to HC-06  
4. Launch app


---

## 🏗️ Platform Design 

👉 (https://github.com/user-attachments/assets/c0b3048e-fb46-4cde-9fed-3599f9c0ac5f)


---

## 🚀 Future Improvements
- Replace Bluetooth with Wi-Fi (ESP32)  
- Cloud integration (IoT platforms)  
- Push notifications  
- Data logging system  
- AI-based anomaly detection  

---

## 🌍 Project Context
This project was developed as part of my personal portfolio in Electrical Engineering, focusing on IoT systems, embedded programming, and smart industrial applications.

---

## 👤 Author
**Amine Ouklilane**  
Electrical Engineering Student  

- Interested in IoT, Embedded Systems, and Smart Technologies  
- Building projects for international academic and career opportunities  

---

## 💡 Portfolio Note
This project demonstrates my ability to design and implement **end-to-end IoT systems**, combining hardware, software, and simulation tools to solve real-world problems.
