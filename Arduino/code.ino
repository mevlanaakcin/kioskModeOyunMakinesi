#include<EEPROM.h>
#include<Servo.h>
//Butonların pinleri belirlendi
#define buton1 3
#define buton2 4
#define buton3 5
#define buton4 6
#define buton5 7
#define buton6 8
char key[10];
int servo_delay = 500; // Servo motorun ödülü bırakması için tayin edilen süre
int baslangic = 150;
int bitis = 50;
//Servo isimleri tayin edildi
Servo  servo1;
Servo  servo2;
Servo  servo3;
Servo  servo4;
Servo  servo5;
Servo  servo6;
//EEPROM temizleme fonksiyonu
void eepromClear() {
  for (int i = 0; i < EEPROM.length(); i++) {
    EEPROM.update(i, 0);
  }
}
//EEPROM kayıt fonksiyonu
void eepromWrite() {
  for (int i = 0; i < 10; i++) {
    EEPROM.write(i, key[i]);
    delay(50);
  }
}
//EEPROM güncelleme fonksiyonu
void eepromUpdate() {
  for (int i = 0; i < 10; i++) {
    EEPROM.update(i, key[i]);
    delay(50);
  }
}
//EEPROM okuma fonksiyonu
String eepromRead() {
  String data_eeprom;
  for (int k = 0; k < 10; ++k) {
    char a = char(EEPROM.read(k));
    delay(50);
    data_eeprom += a;
  }
  return data_eeprom;
}


void setup() {
  Serial.begin(9600);
  //Butonlar giriş olarak ayarlandı
  pinMode(buton1, INPUT); pinMode(buton2, INPUT); pinMode(buton3, INPUT);
  pinMode(buton4, INPUT); pinMode(buton5, INPUT); pinMode(buton6, INPUT);

  //Servo çıkış pinleri ayarlandı
  //servo1.attach(A0); servo2.attach(A1); servo3.attach(A2);
  //servo4.attach(A3); servo5.attach(A4); servo6.attach(A5);

  //Servo motorlar 0 derece konumuna çekildi
  // servo1.write(baslangic); servo2.write(baslangic); servo3.write(baslangic);
  //servo4.write(baslangic); servo5.write(baslangic); servo6.write(baslangic);
  servo1.attach(A0); servo1.write(baslangic); delay(100); servo1.detach();
  servo2.attach(A1); servo2.write(baslangic); delay(100); servo2.detach();
  servo3.attach(A2); servo3.write(baslangic); delay(100); servo3.detach();
  servo4.attach(A3); servo4.write(baslangic); delay(100); servo4.detach();
  servo5.attach(A4); servo5.write(baslangic); delay(100); servo5.detach();
  servo6.attach(A5); servo6.write(baslangic); delay(100); servo6.detach();
}



void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    if (data.toInt() == 101) {
      servo1.attach(A0);
      servo1.write(bitis);
      delay(servo_delay);
      servo1.write(baslangic);
      delay(servo_delay);
      servo1.detach();
      Serial.println("0");
    }
    else if (data.toInt() == 202) {
      servo2.write(bitis);
      servo2.attach(A1);
      delay(servo_delay);
      servo2.write(baslangic);
      delay(servo_delay);
      servo2.detach();
      Serial.println("0");
    }
    else if (data.toInt() == 303) {
      servo3.attach(A2);
      servo3.write(bitis);
      delay(servo_delay);
      servo3.write(baslangic);
      delay(servo_delay);
      servo3.detach();
      Serial.println("0");
    }
    else if (data.toInt() == 404) {
      servo4.attach(A3);
      servo4.write(bitis);
      delay(servo_delay);
      servo4.write(baslangic);
      delay(servo_delay);
      servo4.detach();
      Serial.println("0");
    }
    else if (data.toInt() == 505) {
      servo5.attach(A4);
      servo5.write(bitis);
      delay(servo_delay);
      servo5.write(baslangic);
      delay(servo_delay);
      servo5.detach();
      Serial.println("0");
    }
    else if (data.toInt() == 606) {
      servo6.attach(A5);
      servo6.write(bitis);
      delay(servo_delay);
      servo6.write(baslangic);
      delay(servo_delay);
      servo6.detach();
      Serial.println("0");
    }
    else if (data.toInt() == 707) {
      eepromClear();
      Serial.println("0");
    }
    else if (data.toInt() == 808) {
      String a = eepromRead();
      Serial.println(a);
    }
    else if (data.length() == 11) {
      for (int y = 0; y < 10; y++) {
        key[y] = data.charAt(y);
      }
      String val = eepromRead();
      if (val.length() > 9) {
        eepromUpdate();
      }
      else {
        eepromWrite();
      }
      Serial.println("0");
    }
    else {

    }

  }

  else {
    if (digitalRead(buton1) == LOW) {
      servo1.attach(A0);
      servo1.write(bitis);
      delay(servo_delay);
      servo1.write(baslangic);
      delay(servo_delay);
      servo1.detach();
    }
    else if (digitalRead(buton2) == LOW) {
      servo2.attach(A1);
      servo2.write(bitis);
      delay(servo_delay);
      servo2.write(baslangic);
      delay(servo_delay);
      servo2.detach();
    }
    else if (digitalRead(buton3) == LOW) {
      servo3.attach(A2);
      servo3.write(bitis);
      delay(servo_delay);
      servo3.write(baslangic);
      delay(servo_delay);
      servo3.detach();
    }
    else if (digitalRead(buton4) == LOW) {
      servo4.attach(A3);
      servo4.write(bitis);
      delay(servo_delay);
      servo4.write(baslangic);
      delay(servo_delay);
      servo4.detach();
    }
    else if (digitalRead(buton5) == LOW) {
      servo5.attach(A4);
      servo5.write(bitis);
      delay(servo_delay);
      servo5.write(baslangic);
      delay(servo_delay);
      servo5.detach();
    }
    else if (digitalRead(buton6) == LOW) {
      servo6.attach(A5);
      servo6.write(bitis);
      delay(servo_delay);
      servo6.write(baslangic);
      delay(servo_delay);
      servo6.detach();
    }
    else {
      //servo1.attach(A0); servo1.write(baslangic); delay(100); servo1.detach();
      //servo2.attach(A1); servo2.write(baslangic); delay(100); servo2.detach();
      // servo3.attach(A2); servo3.write(baslangic); delay(100); servo3.detach();
      // servo4.attach(A3); servo4.write(baslangic); delay(100); servo4.detach();
      // servo5.attach(A4); servo5.write(baslangic); delay(100); servo5.detach();
      // servo6.attach(A5); servo6.write(baslangic); delay(100); servo6.detach();

    }

  }
}
