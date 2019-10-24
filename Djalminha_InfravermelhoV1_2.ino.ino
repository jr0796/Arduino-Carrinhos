/*
 * Carrinho seguidor de linha - versão 1.2
 * Atuando com os sensores infravermelhos;
 * Atuando com o sensor ultrasonico;
 * By Professor Junior Etec de Guaianazes - 2019.
 */

#include <Ultrasonic.h> //biblioteca  para o sensor ultrasonico.

Ultrasonic ultrasonic(2,4); //declarando variavel do tipo Ultrasonic (Trig, eco)
float cmMsec;
long microsec;


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




void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(sesquerdo, INPUT);
  pinMode(scentral, INPUT);
  pinMode(sdireito, INPUT);
  Serial.begin(9600);
  
}

void loop() {

//Leitura do sensores FeedBack;
//  Serial.print("Sensor Esquerdo: ");
//  Serial.print(stdoesq);
//  Serial.print(" |");
//  Serial.print(" Sensor Central: ");
//  Serial.print(stdocent);
//  Serial.print(" |");
//  Serial.print(" Sensor Direito: ");
//  Serial.println(stdodir);
//  delay(1000);

//recebendo distância da função timing da biblioteca Ultrasonic
  microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // convertendo em centimetros


//Imprimindo Distância
//  Serial.print ("Distância do objeto:  ");
//  Serial.println(cmMsec);
//  delay(1000);
//



//Atribuição das variáveis estado:
  stdoesq = analogRead(sesquerdo);
  stdocent = analogRead(scentral);
  stdodir = analogRead(sdireito);

if (cmMsec>=10 && stdoesq < 200 && stdocent > 200 && stdodir <200){
  frente();
  
}else if(cmMsec>=10 && stdoesq >200 && stdocent<200 && stdodir<200){
  esquerda();
}else if (cmMsec >=10 && stdoesq <200 && stdocent<200 && stdodir>200){
  direita();
}


//#############################
//Condições com o ultrasonico ligado
if (cmMsec<=10 && stdoesq < 200 && stdocent > 200 && stdodir <200){
  ultra();
}else if(cmMsec<=10 && stdoesq >200 && stdocent<200 && stdodir<200){
  ultra();
}else if (cmMsec <=10 && stdoesq <200 && stdocent<200 && stdodir>200){
  ultra();
}  




}//Chave do Loop

void ultra(){
//Saindo pela Direita
  analogWrite(IN1,00);
  analogWrite(IN2,250);
  analogWrite(IN3,00);
  analogWrite(IN4,250);
  delay(800);
//Andando para frente
  analogWrite(IN1,00);
  analogWrite(IN2,220); 
  analogWrite(IN3,220);
  analogWrite(IN4,00);
  delay(1000);
//Voltando, esquerda
  analogWrite(IN1,250);
  analogWrite(IN2,00); 
  analogWrite(IN3,250);
  analogWrite(IN4,00);
  delay(1500);
  //Andando para frente
  analogWrite(IN1,00);
  analogWrite(IN2,220); 
  analogWrite(IN3,220);
  analogWrite(IN4,00);
  delay(1000);
}




void frente(){
//Andando para frente
  analogWrite(IN1,00);
  analogWrite(IN2,120); //valor para começa a andar
  analogWrite(IN3,120);
  analogWrite(IN4,00);
}

void esquerda(){
//Viradno para Esquerda, inversão de modores oposto (Giro no eixo).  
  analogWrite(IN1,219);// os motores comça a responder a partir de PWM=179
  analogWrite(IN2,00); //optei por uzar 00 no lugar de LOW.
  analogWrite(IN3,219);
  analogWrite(IN4,00);
}

void direita(){
//Viradno para Direita
  analogWrite(IN1,00);
  analogWrite(IN2,219);
  analogWrite(IN3,00);
  analogWrite(IN4,219);
}

void cruzamento1(){ //Cruzamento à direita
  analogWrite(IN1,230);
  analogWrite(IN2,00); 
  analogWrite(IN3,230);
  analogWrite(IN4,00);
  delay(400);
}

void cruzamento2(){
  analogWrite(IN1,00);
  analogWrite(IN2,230);
  analogWrite(IN3,00);
  analogWrite(IN4,230);
  delay(300);
}


//EOF
