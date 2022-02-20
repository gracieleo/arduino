/* 
 Controlando o ângulo de um servo motor
 Em um loop, envia de 2 em 2 segundos os ângulos 180, 90 e 0 graus para o servo motor 
*/

// inclui uma biblioteca para controle do servo motor, ou seja, um conjunto de funções específicas para este motor
#include <Servo.h>

//variável para representar o servo motor. É ela quem recebe os comandos neste código para envaiá-las ao servo motor.
Servo myservo;

// variável para guardar o valor do ângulo a ser enviado ao servo motor
int angulo;

// configuração inicial
void setup()
{
  // configura o representante do servo no pino 9
  myservo.attach(9);  
 
}

void loop() 
{ 
  angulo = 120;               // a variável ângulo recebe o valor 180
  myservo.write(angulo);      // envia o comando "escrever ângulo" para o servo (180 graus)
  delay(2000);                // espera 2 segundos                        
  angulo = 90;
  myservo.write(angulo);      // motor vai para o ângulo 90
  delay(2000);
  angulo = 0;
  myservo.write(angulo);      // motor vai para o ângulo 0
  delay(2000);
} 
