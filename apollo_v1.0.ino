float sensorCentro = A4;
float sensorPontaD = A3;
float sensorPontaE = A2;
int estado1;
int estado2;
int estado3;

int n1 = 3;
int n2 = 5;
int n3 = 6;
int n4 = 9;

int pwm = 80;
int nulo = 0;


void setup() {

 
  Serial.begin(9600);

  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(n4, OUTPUT);



}
void loop() {
  
  estado1 = analogRead(sensorCentro);
  estado2 = analogRead(sensorPontaD);
  estado3 = analogRead(sensorPontaE);

  Serial.print ("Centro ");
  Serial.print (estado1);
  Serial.print (" Direita ");
  Serial.print (estado2);
  Serial.print (" Esquerda ");
  Serial.println (estado3);
  delay(400);


    if ((estado2 < 100) && (estado3 < 100) && (estado1 > 100)) {
    frente(); 
     
    }else if ((estado2 > 100) && (estado3 < 100) && (estado1 < 100)){
      direita();
      
    }else if ((estado2 < 100) && (estado3 > 100) && (estado1 < 100)){
      esquerda();
      
    }else if ((estado2 > 100) && (estado3 > 100) && (estado1 > 100)){
      frente();
      
    }else if ((estado2 > 100) && (estado3 < 100) && (estado1 > 100)){
      frente();
      
    }else if ((estado2 < 100) && (estado3 > 100) && (estado1 > 100)){
      direita();
      
    }else if ((estado2 < 100) && (estado3 > 100) && (estado1 < 100)){
      esquerda();
      
    }else if ((estado2 > 100) && (estado3 > 100) && (estado1 > 100)){
      esquerda();
    }
}

  void frente(){
   analogWrite(n1, pwm); //motor A para frente
   analogWrite(n2, pwm); //motor B para frente
   analogWrite(n3, nulo); // motor A para tras
   analogWrite(n4, nulo); //motor B para trás

  }
  void direita(){
   analogWrite(n1, nulo); //motor A para frente
   analogWrite(n2, pwm); //motor B para frente
   analogWrite(n3, pwm); // motor A para tras
   analogWrite(n4, nulo); //motor B para trás

  }

  void esquerda(){
   analogWrite(n1, pwm); //motor A para frente
   analogWrite(n2, nulo); //motor B para frente
   analogWrite(n3, nulo); // motor A para tras
   analogWrite(n4, pwm); //motor B para trás

  }










  
