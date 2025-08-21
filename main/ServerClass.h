#ifndef SERVERCLASS_H
#define SERVERCLASS_H

#include <WiFi.h>
#include <ESPAsyncWebServer.h>

class ServerClass {
  private:
    const char* ssid;      // Имя Wi-Fi сети
    const char* password;  // Пароль Wi-Fi сети
    AsyncWebServer server; // Объект веб-сервера
    String message;

    void configureRoutes(); // Метод настройки маршрутов
  public:
    ServerClass(const char* ssid, const char* password); // Конструктор
    bool CatIsOnCamera();
    void begin();          // Метод запуска Wi-Fi и сервера
    String getMessage() const { return message; }
    void clearMessage();
};

#endif