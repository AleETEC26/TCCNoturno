#include <Wire.h> //comunicação I2C para conversar com o ESP32
#include <BH1750.h>

BH1750 Sensor;

int saida = 14;
int luzmax = 50; //provisório
void setup() {
  Serial.begin(115200);
  Serial.println("Sistema iniciado");
  Wire.begin(21, 22); //define o barramento I2C nos pinos
  Sensor.begin();
  pinMode(saida, OUTPUT);
}

void loop() {
  float luznivel = Sensor.readLightLevel();
  Serial.print("Luz: ");
  Serial.println(luznivel);
  if (luznivel > luzmax){ // >
    digitalWrite(saida, LOW);
  }
  else {
    digitalWrite(saida, HIGH); 
  }
  delay(500);
}
