/*Carrinho Seguidor de Linha
 * Primeira tarefa foi a configuração do sensor ultrasonico par aque ele possa desviar dos obstáculos 
 * caso eles apareçam.
 * 
 */

#include <Ultrasonic.h>


//Motores
int IN1 = 3;
int IN2 = 5;
int IN3 = 6;
int IN4 = 9;

//Sensores infravermelho
float sesquerdo = A0;
float scentral = A1;
float sdireito = A2;

//estado do sensores
float stdoesq = 0;
float stdocent = 0;
float stdodir = 0;

Ultrasonic ultrasonic(2,4); //declarando variavel do tipo Ultrasonic (Trig, eco)
float cmMsec;
long microsec;


void setup() {
 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  

}

void loop() {

  //recebendo distância da função timing da biblioteca Ultrasonic
  microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // convertendo em centimetros

  stdoesq = analogRead(sesquerdo);
  stdocent = analogRead(scentral);
  stdodir = analogRead(sdireito);

  Serial.print("Sensor Esquerdo: ");
  Serial.print(stdoesq);
  Serial.print("|");
  Serial.print("Sensor Central: ");
  Serial.print(stdocent);
  Serial.print("|");
  Serial.print("Sensor Direito: ");
  Serial.println(stdodir);

  delay(1000);


  
//  Serial.print ("Distância do objeto:  ");
//  Serial.println(cmMsec);
//  delay(1000);




//frente
  if (cmMsec >= 10){
  analogWrite(IN1, LOW);
  analogWrite(IN2, 75);
  analogWrite(IN3, 75);
  analogWrite(IN4, LOW);
  }

//com obstáculo à frente. dar ré, rotacionar e depois voltar andar para frente;
//ré  

  if (cmMsec <10){
    if (cmMsec <10){ //duas verificações para não bater.
  analogWrite(IN1, 75);
  analogWrite(IN2, LOW );
  analogWrite(IN3, LOW);
  analogWrite(IN4, 75 );
  delay(1000);

//virando no eixo
  analogWrite(IN1, LOW );
  analogWrite(IN2, 75);
  analogWrite(IN3, LOW);
  analogWrite(IN4, 75);
  delay(1500);
  
  }
      
  }
}
