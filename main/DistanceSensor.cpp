#include "DistanceSensor.h"
#include <Arduino.h>

// Конструктор
DistanceSensor::DistanceSensor(int trigPin, int echoPin)
  : trigPin(trigPin), echoPin(echoPin), duration(0) {}

// Инициализация пинов
void DistanceSensor::initialize() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

// Метод для получения расстояния
float DistanceSensor::getDistance() {
    // Сначала генерируем короткий импульс длительностью 2-5 микросекунд
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Измеряем время задержки акустического сигнала
    duration = pulseIn(echoPin, HIGH);

    // Преобразуем время в расстояние (в сантиметрах)
    return (duration / 2.0) / 29.1;
}
