#ifndef AUTODOOR_H
#define AUTODOOR_H

#include <ESP32Servo.h> // Подключаем библиотеку для управления сервоприводом

class Autodoor {
public:
    Autodoor(int servoPin);  // Конструктор принимает пин, к которому подключен сервопривод
    void initialize();       // Инициализация дверного модуля
    void open();             // Открыть дверь
    void close();            // Закрыть дверь
    bool isOpen();           // Проверить, открыта ли дверь

private:
    Servo servo;             // Объект для управления сервоприводом
    int pin;                 // Пин для подключения сервопривода
    bool doorState;          // Состояние двери: true — открыта, false — закрыта
    const int openAngle = 0;  // Угол открытия двери
    const int closeAngle = 180;  // Угол закрытия двери
};

#endif