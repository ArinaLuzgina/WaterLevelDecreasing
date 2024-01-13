#define dirPin 11              // Номер вывода, определяющий направление подачи раствора
#define speedPin 10            // Номер вывода, определяющий скорость мотора
#define resPin A0              // Номер вывода, к которому подключен потенциометр
#include <Battery_Shield.h>              // Подключаем библиотеку Battery_Shield.
Battery_Shield pwrBank;  

void setup() {
  // Устанавливаем пинам 9 и 10 частоту ШИМ 62.5кГц, чтобы избавиться от писка обмоток мотора при стандартном ШИМ
  TCCR1A = 0b00000001;  
  TCCR1B = 0b00001001;  
  pwrBank.begin(0.0128f);
  pinMode (dirPin, OUTPUT);    // Оба пина - выход 
  pinMode (speedPin, OUTPUT);
}
 
void loop(){
  int res = analogRead(resPin);                         // Считываем значение с потенциометра
    analogWrite(speedPin, map(res, 0, 1023, 0, 255)); // Подаём на выход задания скорости значение с потенциометра, переведённое в дипазон 0...255
    digitalWrite(dirPin, false);                        // Задаём направление вращения мотора
delay(100);
}
