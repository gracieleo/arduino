/*
  Modos:
  
  FIX_MODE: The color doesn't change. 
  RANDOM_HUE_MODE: Color fades to random hue. 
  RAINBOW_HUE_MODE: Fading from red to red, going through all hue values.
  RED_MODE: Random fade between redish colors.
  BLUE_MODE: Random fade between blueish colors.
  GREEN_MODE: Random fade between greenish colors.
  FIRE_MODE: Fire effect. Like an electronic candle.


  Consulta: http://colorizer.org/   escala - HSV/HSB
  Hue - matiz, tonalidade
  Saturation - saturação
  Value/Brightness - brilho
*/


#include <RGBMood.h>

int redPin  = 11;  //R
int greenPin = 10; //G
int bluePin = 9;  //B

int ldrPin = 0; //fotorresistência sensor 


RGBMood mood(redPin, greenPin, bluePin); 



void setup() {  // inicialização

  pinMode(ldrPin, INPUT); //leitura
  mood.setMode(RGBMood::RANDOM_HUE_MODE); //modo (comportamento) de coloração
  mood.setHoldingTime(2000); //quanto tempo mantém a mesma cor antes de mudar = 2s
  mood.setFadingSteps(150); //passos para fazer as mudanças de cor
  mood.setFadingSpeed(50); //quanto dura cada passo anterior =  150x50 = 7.0s
  mood.setHSB(random(359), 255, 255); //cor aleatório inicial (random(valor_aleatorio_0_a_359),100%, 100%)
 
}

void loop() {
  
    int ambientLight = analogRead(ldrPin); //lê valor da resistência 
    if(ambientLight > 600)
    {
      mood.tick();
    }
    else     //ambientLight recebe quantidade maior de luz
    {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
    }

}
