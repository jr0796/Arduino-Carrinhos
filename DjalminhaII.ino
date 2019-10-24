#include "SoftwareSerial.h" //biblioteca para ajudar no controle do Bluetooth

//#define led 2
int IN1 = 3;
int IN2 = 5;
//Rodas Esquerda


int IN3 = 6;
int IN4 = 9;
//Rodas Direita
//==========================================================

SoftwareSerial minhaSerial(10,11); //Portas para TX e RX
String command = ""; //variável do tipo stringo (vazia)


//Sirene
int frequencia = 0;
int falante = 5;
#define tempo 10

int lanterna = 7;

int seta = 6;



void setup() {
  
  Serial.begin(9600);
  Serial.println("Tipo de Comandos!");
  minhaSerial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(falante, OUTPUT);
  pinMode(lanterna, OUTPUT);
  pinMode(seta, OUTPUT);
}

void loop() {

 
  
  if (minhaSerial.available()){
    while(minhaSerial.available()){
        command =char(minhaSerial.read());
    }  
    
//
//
//   //virando o carro para direita
//   
//  if (command == "R"){
// 
//
//  digitalWrite(IN3, LOW);
//  digitalWrite(IN4, LOW);
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, HIGH);
// 
//     
//    }
//    
////Virando o carro para esquerda.
//    if (command == "L"){
// 
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, LOW);
//  digitalWrite(IN3, HIGH);
//  digitalWrite(IN4, LOW);
//  
//
//     
//    }
//
//
// //Parando o carro.
//    if (command == "X"){
// 
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, LOW);
//  digitalWrite(IN3, LOW);
//  digitalWrite(IN4, LOW);
//  
//
//     
//    }
//
////Andando para frente.
//    if (command == "F"){
// 
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, HIGH);
//  digitalWrite(IN3, HIGH);
//  digitalWrite(IN4, LOW);
//  
//
//     
//    }
//
////Andando para Trás.
//    if (command == "B"){
// 
//  digitalWrite(IN1, HIGH);
//  digitalWrite(IN2, LOW);
//  digitalWrite(IN3, LOW);
//  digitalWrite(IN4, HIGH);
//  
//
//     
//    }
//
////Ancendendo Lanterna.
//    if (command == "U"){
//        digitalWrite(lanterna, HIGH);
//    }
// //Apagando lanterna.
//    if (command == "u"){
//        digitalWrite(lanterna, LOW);
//    }
//
//
////Ancendendo cetas.
//    if (command == "W"){
//        digitalWrite(seta, HIGH);
//    }
// //Apagando lanterna.
//    if (command == "w"){
//        digitalWrite(seta, LOW);
//    }
//    
//    //Pisca Alerta.
//    if (command == "X"){
//      
//
//      
//      //while (command == "X"){
//        digitalWrite(seta, HIGH);
//        digitalWrite(lanterna, HIGH);
//        delay(500);
//        digitalWrite(seta, LOW);
//        digitalWrite(lanterna, LOW);
//        delay(500);
//
//        //command == command;
//       //}
//    }
//    
//
//    
//
//    
//    if (command =="x"){
//        digitalWrite(seta, LOW);
//        digitalWrite(lanterna, LOW);
//    }
// 
// 
//  
//
////BUZINA.
//    if (command == "V"){
//   tone(5,300,200);
//   delay(400);
//   tone(5,300,300);
//    }
//
//   if (command == "5"){
//   tone(5,100,500);
//   delay(500);
//   tone(5,100,700);
//    }
//    
//
//    if (command =="8" ){
//
//   for (frequencia = 150; frequencia < 1800; frequencia +=1)
// {  
//  tone (falante, frequencia,tempo);
//  delay(1);
//  
//  }
//
//  
// for (frequencia = 1800; frequencia > 150; frequencia -=1)
// {
//  
//  tone(falante, frequencia, tempo);
//  delay(1);
//
//  //para parar o tone utilizar a função "notone"
//  } 
//
//     
//    
//
    } 


  Serial.println(command);
 
    
    //command  = ""; //limpando a variável Command


//     if (Serial.available()){
//      delay(10);
//      minhaSerial.write(Serial.read());
  }
  




 
