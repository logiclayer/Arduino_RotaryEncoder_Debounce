#define A0 A_Girisi
#define A1 B_Girisi
#define A2 Buton
int sayac = 0;
long oncekiZaman;
boolean oncekiDurum;
boolean buttonSonDurum = HIGH;
boolean yazildimi = false;

void setup() {
  Serial.begin(9600);
  pinMode(A_Girisi, INPUT);
  pinMode(B_Girisi, INPUT);
  pinMode(Buton, INPUT_PULLUP);
  digitalWrite(A_Girisi, HIGH);
  digitalWrite(B_Girisi, HIGH);
}

void loop() {
  //Serial.print("Data : "); Serial.println(digitalRead(Data));
  //Serial.print("Clock : "); Serial.println(digitalRead(Clock));
  boolean a = digitalRead(A_Girisi);
  boolean b = digitalRead(B_Girisi);
  boolean c = debounce(Buton);
  if (c == LOW && yazildimi == false) {
    Serial.println("Butona basildi ! ");
    yazildimi = true;
  } else if (c == HIGH) {
    yazildimi = false;
  }
  
  if (millis() - oncekiZaman > 3) {
    if (b != oncekiDurum) {
      if (b == LOW) {
        if (a == HIGH) {
          sayac++;
          Serial.print(sayac);
          Serial.println(" : sag");
        } else {
          sayac--;
          Serial.print(sayac);
          Serial.println(" : sol");
        }
      } /*else {
        if (a == LOW) {
          s++;
          Serial.print(s);
          Serial.println(" : sag");
        } else {
          s--;
          Serial.print(s);
          Serial.println(" : sol");
        }
      } */
    }
    oncekiDurum = b;
    oncekiZaman = millis();
  }
}

boolean debounce(int pinNo) {
  boolean b_Durumu = digitalRead(pinNo);
  if (b_Durumu != buttonSonDurum) {
    delay(5);
    b_Durumu = digitalRead(pinNo);
    buttonSonDurum = b_Durumu;
  }
  return b_Durumu;
}

