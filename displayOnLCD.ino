void displayOnLCD(){
   if (Serial.available()) {
    // SerialBT.write('y');
  }
  if (SerialBT.available()) {
    d = SerialBT.read();

  }
  if (analogRead(pad) < 4000) {
    selection = readhexpad();
    Serial.println(selection);

  }
  switch (selection) {
    case '1':
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Bluetooth menu selected");
      Serial.print("Bluetooth menu selected");
      delay(1000);
      if (d == 'a') {
        if (rel1 == 1) {
          rel1 = 0;
          digitalWrite(relay1, LOW);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("PUMP1 ON");
        } else {
          rel1 = 1;
          digitalWrite(relay1, HIGH);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Pump1 off");

        }
      }
      if (d == 'b') {
        if (rel2 == 1) {
          rel2 = 0;
          digitalWrite(relay2, LOW);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("PUMP2 ON");
        } else {
          rel2 = 1;
          digitalWrite(relay2, HIGH);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Pump2 off");

        }

      }
      if (d == 'c') {
        if (rel3 == 1) {
          rel3 = 0;
          digitalWrite(relay3, LOW);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("PUMP3 ON");
        } else {
          rel3 = 1;
          digitalWrite(relay3, HIGH);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Pump3 off");

        }
  

      }
      break;
    case '2':
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("2");
      break;
    case '3':
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("3");
      break;
    case 'A':
      lcd.clear();
      lcd.setCursor(0, 0)
      ;
      lcd.print("Ali");
      break;
    case '4':
      t1 = (dht2.readTemperature( ));
      h1 = (dht2.readHumidity( ));
      Serial.println("Temperatuer:");
      Serial.println(t1);
      Serial.println("Humidity");
      Serial.println(h1);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      lcd.setCursor(6, 0);
      lcd.print(t1);
      lcd.setCursor(0, 1);
      lcd.print("Humidity: ");
      lcd.setCursor(10, 1);
      lcd.print(h1);
      delay(2000);
      SerialBT.write(t1);
      break;
    case '5':
      level = analogRead(waterlevel);
      level = 5000
              - level;
      Serial.println(level);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Water level 1: ");
      lcd.setCursor(14, 0);
      lcd.print(level);
      SerialBT.write(level);
      delay(2000);
      break;
    case '6':
      level2 = analogRead(waterlevel2);
      level2 = 5000
               - level2;
      Serial.println(level2);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Water level 2: ");
      lcd.setCursor(14, 0);
 
      lcd.print(level2);
      SerialBT.write(level2);
      delay(2000);
      break;
    case 'B':
      break;
    case '7':
      selection = 'm';
      if (rel1 == 1) {
        rel1 = 0;
        digitalWrite(relay1, LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("PUMP1 ON");
      } else {
        rel1 = 1;
        digitalWrite(relay1, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Pump1 off");

      }
      break;
    case '8':
      selection = 'm';
      if (rel2 == 1) {
        rel2 = 0;
        digitalWrite(relay2, LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("PUMP2 ON");
      } else {
        rel2 = 1;
        digitalWrite(relay2, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Pump2 off");

      }
      break;
    case '9':
      selection = 'm';
      if (rel3 == 1) {
        rel3 = 0;
        digitalWrite(relay3, LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("PUMP3 ON");
      } else {
        rel3 = 1;
        digitalWrite(relay3, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Pump3 off");

      }
      break;
    case 'C':
      break;
  
    case '*':
      break;
    case '0':
      ph = analogRead(phsensor);
      phvalue = ((-0.014286 * float(ph)) + 43.8 + 22);
      Serial.println("PH = ");
      Serial.println(ph);
      Serial.println(phvalue);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ph: ");
      lcd.setCursor(4, 0);
      lcd.print(phvalue);
      SerialBT.write(phvalue);
      break;
    case '#':
      break;
    case 'D':
      break;
    default:
      break;
  }
  delay(1000);
}
  }
