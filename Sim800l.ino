/*
 * Codigo para modulo SIM800L envio e chamadas usando arduino
 * 
 * ZileFC
 * fczile@gmail.com
 */
#include <SoftwareSerial.h>
SoftwareSerial sim(10, 11);

String numero = "+258845686282";

void setup() {
  Serial.begin(9600);
  Serial.println("Aguarde uns instantes...");
  delay(5000);
  Serial.println("Sistema iniciado...");
  sim.begin(9600);
  delay(1000);
  Serial.println("Digite 'L' para ligar e 'M' para sms");
}

void loop() {
  if (Serial.available() > 0)
    switch (Serial.read())
    {
      case 'L':
        ligar();
        break;
      case 'M':
        mensagem();
        break;
    }
  if (sim.available() > 0)
    Serial.write(sim.read());
}

void mensagen()
{
  sim.println("AT+CMGF=1");
  delay(1000);
  sim.println("AT+CMGS=\"" + numero + "\"\r");
  delay(1000);
  String SMS = "Ola mundo, se esta a ler esta mensagem significa que esta tudo bem!";
  sim.println(SMS);
  delay(100);
  sim.println((char)26);
  delay(1000);
}

void ligar() {
  sim.print (F("ATD"));
  sim.print (numero);
  sim.print (F(";\r\n"));
}
