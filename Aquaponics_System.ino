#include <DHT.h>
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
#define pad 36
DHT dht2(0, DHT11);
BluetoothSerial SerialBT;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
#define relay1 32
#define relay2 33
#define relay3 25
#define waterlevel 39
#define waterlevel2 34
#define phsensor 35
char selection = 'A';
char a;
char d;
uint8_t temprature_sens_read();
const int rs = 23, en = 22, d4 = 18, d5 = 19, d6 = 5, d7 = 21;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int led = 2;
const char* ssid = "A & Z";
const char* password = "pakistan";
WiFiServer server(80);
String ClientRequest;
WiFiClient client;
String myresultat;
int rel1 = 1;
int rel2 = 1;
int rel3 = 1;

int p = 1;
int t1;
int h1;
int level;
int level2;
int ph;
float phvalue;
void setup() {
  SerialBT.begin("Ali "); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  ClientRequest = "";
  Serial.begin(115200);
  lcd.begin(16, 2);
  pinMode(2, OUTPUT);
  pinMode(pad, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(waterlevel, INPUT);
  pinMode(waterlevel2, INPUT);
  pinMode(phsensor, INPUT);
}
void loop() {
  int value = analogRead(pad);
  Serial.println(value);

  Serial.println("In main loop");
  Serial.print("Selection: ");
  Serial.println(selection);
  //for initial start display
  if (p == 1) {
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Welcome");
    delay(2000);
    p = 0;
  }
  d = 0;
  delay(2000);

  displayOnLCD();
}
