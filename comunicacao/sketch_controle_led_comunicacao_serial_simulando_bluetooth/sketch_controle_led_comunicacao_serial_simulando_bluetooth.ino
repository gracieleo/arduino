/* 
 Controle de LED por comunicação serial

 led está conectado diretamente entre os pinos 13 e GND da arduino
 
*/

char valorSerial = ""; //guarda valores lidos na porta serial (monitor)
int pinoLED = 13;

void setup() {
  Serial.begin(9600); //inicia comunicação com taxa de transmissão desejada
  pinMode(pinoLED, OUTPUT); //saida digital
}
 
void loop() {
  if (Serial.available() > 0) { //verifica se há informações chegando
        valorSerial = Serial.read();//le informsção e armazena
        if (valorSerial == 'l') {
            digitalWrite(pinoLED, HIGH); //acende o led
            Serial.println("LED da Arduino ligado!");//msg no monitor serial
        }
        else if (valorSerial == 'd') {
            digitalWrite(pinoLED, LOW);//apaga o led
            Serial.println("LED da Arduino desligado!");
        }
  }
  delay(1000);//aguarda 1 segundo entre cada passo do loop
}
