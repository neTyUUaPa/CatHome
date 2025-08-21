#include "ServerClass.h"



ServerClass::ServerClass(const char* ssid, const char* password)
  : ssid(ssid), password(password), server(80), message("") {}

void ServerClass::begin() {
  Serial.begin(115200);

  // Подключение к Wi-Fi
  WiFi.setHostname("esp32-device");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Подключение к Wi-Fi...");
  }
  Serial.println("Подключено к Wi-Fi!");
  Serial.println(WiFi.localIP());

  // Настройка маршрутов
  configureRoutes();

  // Запуск сервера
  server.begin();
}

void ServerClass::configureRoutes() {
  server.on("/CatCool", HTTP_POST, [this](AsyncWebServerRequest* request) {
    message = "Не указано";
    if (request->hasParam("message", true)) {
      message = request->getParam("message", true)->value();
    }

    // Выводим сообщение
    Serial.println(message);

    // Ответ клиенту
    request->send(200, "text/plain", "OK");
  });
}
bool ServerClass::CatIsOnCamera(){
  // Управление светодиодом
    if (message == "Cat obnarujen") {
      //digitalWrite(LED_BUILTIN, HIGH); // Включаем светодиод
      message == "";
      return true;
    } 
    else {
      //digitalWrite(LED_BUILTIN, LOW); // Выключаем светодиод
      return false;
    }
}
void ServerClass::clearMessage() {
  message = ""; // Сбрасываем сообщение
}
