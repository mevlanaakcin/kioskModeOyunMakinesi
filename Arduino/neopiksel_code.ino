#include<Servo.h>
#include <Adafruit_NeoPixel.h>
#define tetik 2
#define PIN 6
#define NUMPIXELS 11
int durum = 1;
String read_data = "";
int speed_neo = 100;
int show_time = 500;
int cisim = 10;
/*
  0----Paper
  1----Plastic
  8----Glass
  9----Organic
  10----Metal
*/
int dizi[5] = {0, 1, 8, 9, 10};
Adafruit_NeoPixel neo = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Servo mecservo;
Servo inservo;
Servo outservo;
void selection_close() {
  for (int i = 0; i < 6; i++) {
    neo.setPixelColor(dizi[i] , 0, 0, 0);
    neo.show(); delay(speed_neo);
  }
}
void selection() {

  for (int i = 0; i < 6; i++) {
    neo.setPixelColor(dizi[i] , 255, 255, 255);
    if (i != 0) {
      neo.setPixelColor(dizi[i - 1] , 0, 0, 0);
    } neo.show(); delay(speed_neo);
  }

}

void recycle_white() {
  for (int i = 2; i < 8; i++) {
    neo.setPixelColor(i , 255, 255, 255);
  } neo.show(); delay(speed_neo);
}
int parla() {

  for (int i = 2; i < 8; i++) {
    for (int j = 10; j < 255; j++) {
      neo.setPixelColor(i, 0, j, 0);
    } if (i != 7) {
      neo.setPixelColor(i + 1, 255, 255, 255);
    } neo.show(); delay(speed_neo);
  }
}
int son() {

  for (int i = 2; i < 8; i++) {
    for (int j = 255; j > 10; j--) {
      neo.setPixelColor(i, 0, j, 0);
    } neo.show(); delay(speed_neo);
  }
}
void recycle() {
  parla();
  son();
}

int paper = 0;
int cardboard = 30;
int glass = 60;
int metal = 90;
int plastic = 120;
int trash = 150;
void setup() {
  neo.setBrightness(100); //Parlaklık
  neo.begin();
  neo.show();
  mecservo.attach(10);
  inservo.attach(9);
  outservo.attach(11);
  pinMode(tetik, OUTPUT);
  Serial.begin(9600);
  inservo.write(0);
  outservo.write(0);
  mecservo.write(paper);
}


void loop() {
  while (durum == 1) {
    recycle();
    int butonread = digitalRead(tetik);
    delay(150);
    if (butonread == 1) {
      Serial.println("Sensor");
      inservo.write(90);
      delay(1000);
      recycle_white();
      durum = 0;
      break;
    }
  }

  if (Serial.available() > 0) {

    read_data = Serial.readStringUntil('\n');
    if (read_data == "cardboard") {
      cisim = 0;
    }
    else if (read_data == "glass") {
      cisim = 1;
    }

    else if (read_data == "metal") {
      cisim = 2;
    }
    else if (read_data == "paper") {
      cisim = 3;
    }
    else if (read_data == "plastic") {
      cisim = 4;
    }
    else if (read_data == "trash") {
      cisim = 5;
    }
    else{
      cisim=10;
    }




    switch (cisim) {
      case 0:
        neo.setPixelColor(dizi[0] , 0, 255, 0);
        neo.setPixelColor(dizi[1] , 0, 0, 0);
        neo.setPixelColor(dizi[2] , 0, 0, 0);
        neo.setPixelColor(dizi[3] , 0, 0, 0);
        neo.setPixelColor(dizi[4] , 0, 0, 0);
        neo.show(); delay(show_time);
        mecservo.write(cardboard);
        delay(1000);
        outservo.write(90);
        delay(2000);
        outservo.write(0);
        delay(2500);
        mecservo.write(paper);
        delay(1000);
        inservo.write(0);
        delay(500);
        durum = 1;
        cisim=10;
        selection_close();
        break;
      case 1:
        neo.setPixelColor(dizi[0] , 0, 0, 0);
        neo.setPixelColor(dizi[1] , 0, 0, 0);
        neo.setPixelColor(dizi[2] , 0, 255, 0);
        neo.setPixelColor(dizi[3] , 0, 0, 0);
        neo.setPixelColor(dizi[4] , 0, 0, 0);
        neo.show(); delay(show_time);
        mecservo.write(glass);
        delay(1000);
        outservo.write(90);
        delay(2000);
        outservo.write(0);
        delay(2500);
        mecservo.write(paper);
        delay(1000);
        inservo.write(0);
        delay(500);
        durum = 1;
        cisim=10;
        selection_close();
        break;
      case 2:
        neo.setPixelColor(dizi[0] , 0, 0, 0);
        neo.setPixelColor(dizi[1] , 0, 0, 0);
        neo.setPixelColor(dizi[2] , 0, 0, 0);
        neo.setPixelColor(dizi[3] , 0, 0, 0);
        neo.setPixelColor(dizi[4] , 0, 255, 0);
        neo.show(); delay(show_time);
        mecservo.write(metal);
        delay(1000);
        outservo.write(90);
        delay(2000);
        outservo.write(0);
        delay(2500);
        mecservo.write(paper);
        delay(1000);
        inservo.write(0);
        delay(500);
        durum = 1;
        cisim=10;
        selection_close();
        break;
      case 3:
        neo.setPixelColor(dizi[0] , 0, 255, 0);
        neo.setPixelColor(dizi[1] , 0, 0, 0);
        neo.setPixelColor(dizi[2] , 0, 0, 0);
        neo.setPixelColor(dizi[3] , 0, 0, 0);
        neo.setPixelColor(dizi[4] , 0, 0, 0);
        neo.show(); delay(show_time);
        mecservo.write(paper);
        delay(1000);
        outservo.write(90);
        delay(2000);
        outservo.write(0);
        delay(2500);
        mecservo.write(paper);
        delay(1000);
        inservo.write(0);
        delay(500);
        durum = 1;
        cisim=10;
        selection_close();
        break;
      case 4:
        neo.setPixelColor(dizi[0] , 0, 0, 0);
        neo.setPixelColor(dizi[1] , 0, 255, 0);
        neo.setPixelColor(dizi[2] , 0, 0, 0);
        neo.setPixelColor(dizi[3] , 0, 0, 0);
        neo.setPixelColor(dizi[4] , 0, 0, 0);
        neo.show(); delay(show_time);
        mecservo.write(plastic);
        delay(1000);
        outservo.write(90);
        delay(2000);
        outservo.write(0);
        delay(2500);
        mecservo.write(paper);
        delay(1000);
        inservo.write(0);
        delay(500);
        durum = 1;
        selection_close();
        break;
        cisim=10;
      case 5:
        neo.setPixelColor(dizi[0] , 0, 0, 0);
        neo.setPixelColor(dizi[1] , 0, 0, 0);
        neo.setPixelColor(dizi[2] , 0, 0, 0);
        neo.setPixelColor(dizi[3] , 255, 255, 255);
        neo.setPixelColor(dizi[4] , 0, 0, 0);
        neo.show(); delay(show_time);
        mecservo.write(trash);
        delay(1000);
        outservo.write(90);
        delay(2000);
        outservo.write(0);
        delay(2500);
        mecservo.write(paper);
        delay(1000);
        inservo.write(0);
        delay(500);
        selection_close();
        durum = 1;
        cisim=10;
        break;
    }

  }
  else {
    for (int i = 0; i < 20; i++) {
      selection();
    }
  }


}
