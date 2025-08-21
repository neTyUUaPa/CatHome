#include "Ventilation.h"
#include <Arduino.h>

// Конструктор
Ventilation::Ventilation(int motorPin1, int motorPin2)
  : motorPin1(motorPin1), motorPin2(motorPin2), isOn(false) {}

// Инициализация пинов
void Ventilation::initialize() {
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    turnOff(); // Убедимся, что вентилятор выключен при старте
}

// Включить вентилятор
void Ventilation::turnOn() {
    digitalWrite(motorPin1, HIGH); // Подать напряжение на мотор
    digitalWrite(motorPin2, LOW);  // Установить направление вращения
    isOn = true;
}

// Выключить вентилятор
void Ventilation::turnOff() {
    digitalWrite(motorPin1, LOW); // Отключить питание
    digitalWrite(motorPin2, LOW); // Отключить питание
    isOn = false;
}

// Проверить, работает ли вентилятор
bool Ventilation::isRunning() {
    return isOn;
}
