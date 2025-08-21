#ifndef VENTILATION_H
#define VENTILATION_H

class Ventilation {
  private:
    int motorPin1; // Пин управления мотором (подача напряжения)
    int motorPin2; // Пин управления мотором (земля)
    bool isOn;     // Состояние вентиляции (включена/выключена)

  public:
    Ventilation(int motorPin1, int motorPin2); // Конструктор
    void initialize(); // Инициализация пинов
    void turnOn();     // Включить вентилятор
    void turnOff();    // Выключить вентилятор
    bool isRunning();  // Проверить, работает ли вентилятор
};

#endif
