#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <SoftwareSerial.h>

#define dht_apin 7
#define DHTTYPE DHT11
#define MQ2_PIN A0
#define BUZZER_PIN 8
#define LED_RED_PIN 9
#define LED_GREEN_PIN 10
#define LED_YELLOW_PIN 11  // LED jaune pour gaz faible

// Déclaration du HC-06 (RX = 10, TX = 11)
SoftwareSerial BT(2, 3);

DHT dht(dht_apin, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
  delay(500);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);

  Serial.begin(9600);  // Pour le moniteur série
  BT.begin(9600);      // Pour la communication Bluetooth-
  
  // 🌟 Message de démarrage
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Systeme de");
  lcd.setCursor(0, 1);
  lcd.print("Detection de Gaz");
  delay(3500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Initialisation..");
  delay(2000);
  lcd.clear();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int gasValue = analogRead(MQ2_PIN);

  if (isnan(humidity) || isnan(temperature)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DHT11 Erreur!");
    delay(1000);
    return;
  }

  // Vérification des niveaux de gaz
  if (gasValue > 500) {
    // 🚨 Niveau DANGEREUX : Alarme activée, LED rouge, et buzzer
    lcd.clear();
    lcd.setCursor(4, 1);
    lcd.print("GAZ DANGER!!");
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_RED_PIN, HIGH);
    digitalWrite(LED_YELLOW_PIN, LOW);
    digitalWrite(LED_GREEN_PIN, LOW);

    Serial.println("GAZ DANGER!");
    BT.println("Alerte! Niveau de gaz DANGEREUX! 🚨");

    // Bloquer ici jusqu'à ce que le gaz disparaisse
    while (analogRead(MQ2_PIN) > 600) {
      delay(500);
      if (BT.available()) {
        char command = BT.read();
        if (command == 'S') { // Arrêter l'alarme manuellement
          digitalWrite(BUZZER_PIN, LOW);
          Serial.println("Alarme désactivée via Bluetooth");
          BT.println("Alarme désactivée ✅");
          break;
        }
      }
    }

    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_RED_PIN, LOW);
    digitalWrite(LED_GREEN_PIN, HIGH);
    lcd.clear();
  }
  else if (gasValue >= 550) {
    // ⚠ Niveau faible : LED jaune activée, affichage alerte gaz faible
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alerte Gaz");
    lcd.setCursor(0, 1);
    lcd.print("Faible Detecte");
    digitalWrite(LED_YELLOW_PIN, HIGH);
    digitalWrite(LED_RED_PIN, LOW);
    digitalWrite(LED_GREEN_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.println("Alerte Gaz Faible!");
    BT.println("Alerte: Gaz détecté ⚠️");
  }
  else {
    // ✅ Normal : LED verte activée, affichage "Gaz OK"
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hum: ");
    lcd.print(humidity);
    lcd.print("% ");

    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print((char)223);
    lcd.print("C ");

    lcd.setCursor(0, 2);
    lcd.print("Gaz: ");
    lcd.print(gasValue);
    lcd.print("   ");

    lcd.setCursor(0, 3);
    lcd.print("✅ Gaz OK");

    digitalWrite(LED_GREEN_PIN, HIGH);
    digitalWrite(LED_RED_PIN, LOW);
    digitalWrite(LED_YELLOW_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  Serial.print("Gas Value: ");
  Serial.println(gasValue);
 BT.print(temperature); //send distance to MIT App
 BT.print(";");
 BT.print(humidity); //send distance to MIT App 
 BT.println(";");

  BT.println(gasValue);

  delay(500); // Pause pour éviter une mise à jour trop rapide
}
