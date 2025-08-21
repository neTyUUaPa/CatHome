#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

class DistanceSensor {
  private:
    int trigPin; // Пин для TRIG
    int echoPin; // Пин для ECHO
    long duration; // Время задержки акустического сигнала

  public:
    DistanceSensor(int trigPin, int echoPin); // Конструктор

    void initialize(); // Инициализация пинов
    float getDistance(); // Возвращает расстояние в сантиметрах
};

#endif
