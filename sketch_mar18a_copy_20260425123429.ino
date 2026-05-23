#include <Wire.h> //comunicação I2C para conversar com o ESP32
#include <BH1750.h>

BH1750 Sensor;

int saida = 14;
int luzmax = 50; //valor provisório
void setup() {
  Serial.begin(115200);
  Serial.println("Sistema iniciado");
  Wire.begin(21, 22); //define o barramento I2C nos pinos (SDA, SCL)
  Sensor.begin();
  pinMode(saida, OUTPUT);
//linha 15 a 21: teste de funcionamento do ESP32
  digitalWrite(saida,HIGH); 
  delay(1000);
  digitalWrite(saida,LOW);
  delay(1000);
  digitalWrite(saida,HIGH);
  delay(1000);
  digitalWrite(saida,LOW);
}

void loop() {
  float luznivel = Sensor.readLightLevel();
  Serial.print("Luz: ");
  Serial.println(luznivel);
  if (luznivel > luzmax){ 
    digitalWrite(saida, LOW);
  }
  else {
    digitalWrite(saida, HIGH); 
  }
  delay(5500); //para o código por 5,5 segundos
}
