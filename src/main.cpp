/* http://codius.ru/articles/GSM_модуль_SIM800L_часть_1*/


#include <Arduino.h>

#include <SoftwareSerial.h>
SoftwareSerial SIM800(8, 9);        // 8 - RX Arduino (TX SIM800L), 9 - TX Arduino (RX SIM800L)
void setup() {
  Serial.begin(9600);               // Скорость обмена данными с компьютером
  Serial.println("Start!");
  SIM800.begin(9600);               // Скорость обмена данными с модемом
  SIM800.println("AT");
}

void loop() {
  if (SIM800.available())           // Ожидаем прихода данных (ответа) от модема...
    Serial.write(SIM800.read());    // ...и выводим их в Serial
  if (Serial.available())           // Ожидаем команды по Serial...
    SIM800.write(Serial.read());    // ...и отправляем полученную команду модему
}
/* put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}*/