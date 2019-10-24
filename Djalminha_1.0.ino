/*Versão adaptada da internet - Djalminha 1.0 - em sua versão mais simplificada.
 * 
 */


#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial BT(10, 11); // RX, TX
String command = ""; // Stores response of bluetooth device

int IN1 = 3;
int IN2 = 5;
int IN3 = 6;
int IN4 = 9;


void setup()
{
  Serial.begin(9600);
  Serial.println("Type AT commands!");
  BT.begin(9600); // HC-05 usually default baud-rate
  
}


void loop()
{

  
  if (BT.available()){
    while(BT.available()){
     delay(15); 
     char c = BT.read(); 
     command = c; 
    } 
    //Serial.println(command);
    
    
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
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
}

void paraTrasOn(){
 digitalWrite(IN1, HIGH);
 digitalWrite(IN4, HIGH);
 
}


void virarEsquerdaOn(){
  digitalWrite(IN3, HIGH);
 
}

void virarDireitaOn(){

 digitalWrite(IN2, HIGH);
 
}

void parar(){
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
  
}
