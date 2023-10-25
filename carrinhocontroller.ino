#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial BT(6, 7); // RX, TX
String command = ""; 

int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;


void setup()
{
  Serial.begin(9600);
  Serial.println("COmandos do Módulo !");
  BT.begin(9600); 
}


void loop()
{

  
  if (BT.available()){
    while(BT.available()){
     delay(15); 
     char c = BT.read(); 
     command = c; 
    } 
    Serial.println(command);
    
    
    if(command=="F"){
      emFrenteOn();
    }else if(command=="S"){
      parar();
    }else if(command=="B"){
      paraTrasOn();
    }else if(command=="L"){
      virarEsquerdaOn();
    }else if(command=="R"){
      virarDireitaOn();
    }else if(command=="X"){
//     parar(); 
    }else if(command=="x"){
//     parar(); 
    }else{
      parar();
    }
    command = ""; 

  
  }
}

void emFrenteOn(){
 
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
}

void paraTrasOn(){
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 
}


void virarEsquerdaOn(){

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
 
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 
}

void virarDireitaOn(){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
 
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
 
}

void parar(){
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
  
}