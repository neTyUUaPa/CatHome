#include "Autodoor.h"
#include "Ventilation.h"
#include "ServerClass.h"
#include "DistanceSensor.h"
// Пины подключения
#define DOOR_SERVO_PIN 21
#define PIN_TRIG 18
#define PIN_ECHO 22
#define FAN_PIN1 19
#define FAN_PIN2 27

unsigned long doorOpenTime = 0;  // Время, когда дверь была открыта
const unsigned long doorCloseDelay = 60000; // Задержка в миллисекундах (1 минута)
bool ISawCat = false;
bool CatIsIn = false;

// Создаем объект класса
Autodoor door(DOOR_SERVO_PIN);
DistanceSensor distanceSensor(PIN_TRIG, PIN_ECHO);
Ventilation ventilation(FAN_PIN1, FAN_PIN2);
ServerClass myServer("Chel", "12345678");

void setup() {
    Serial.begin(115200);
    myServer.begin();
    distanceSensor.initialize();
    ventilation.initialize();
    door.initialize();
    
}

void loop() {
    float distance = distanceSensor.getDistance();
    delay(250);
    if (myServer.CatIsOnCamera() == true & door.isOpen() == false){
      door.open();
      ventilation.turnOn();
      myServer.clearMessage();
      doorOpenTime = millis();
      ISawCat = true;
    }

    myServer.clearMessage();

    if (door.isOpen()) 
      {
        if ((millis() - doorOpenTime >= doorCloseDelay && distance > 50) || distance <= 35) {
            door.close();
            ventilation.turnOff();
            ISawCat = false;
        }
    }  
}
