#include "Autodoor.h"

Autodoor::Autodoor(int servoPin) {
    pin = servoPin;
    doorState = false; // Изначально дверь закрыта
}

void Autodoor::initialize() {
    servo.attach(pin);       // Подключаем сервопривод к пину
    close();                 // Убедимся, что дверь закрыта
    Serial.println("Автодверь инициализирована");
}

void Autodoor::open() {
    servo.write(openAngle);  // Поворот сервопривода на угол открытия
    doorState = true;
    Serial.println("Дверь открыта");
}

void Autodoor::close() {
    servo.write(closeAngle); // Поворот сервопривода на угол закрытия
    doorState = false;
    Serial.println("Дверь закрыта");
}

bool Autodoor::isOpen() {
    return doorState;
}
