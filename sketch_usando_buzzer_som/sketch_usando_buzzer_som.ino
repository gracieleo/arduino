/*
Código p/ emissão de tom conforme frequência informada podemos ouvir entre 20 e 20 mil Hz

880 Hz = mais aguda 1/8 acima 
440 Hz = nota lá de um telefone
220 Hz = mais grave 1/8 abaixo
*/

int pinoFalante = 11;

void setup() {
  pinMode(pinoFalante, OUTPUT);
  Serial.begin(9600); //inicio da comunicação
  Serial.println("Insira a frequência que quer ouvir: ");   //saida no monitor serial, onde vamos informar a frequencia 
}

void loop() {    //espera o valor de frequencia que será informado
  if (Serial.available()) { //só é verdadeiro qdo há informação chegando 
  int duracao = 2000;
  int frequencia = Serial.parseInt(); //transforma frequencia em numero inteiro
  tone(pinoFalante, frequencia, duracao); //tocar a nota
  delay(duracao);
  noTone(pinoFalante);//interromper o som 
  }
}
