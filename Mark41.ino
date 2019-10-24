/*Código  Gentilmente sedido pelos alunos da Escola  Técnica de Guaianazes (Marcos, Henrique e Matheus);
//Motores
int in1 = 10;
int in2 = 9;
int in3 = 6; 
int in4 = 5;
//Sensores
int sensorEsquerda = A2;//marrom;
int sensorDireita = A0;//branco;
int sensorCentro = A1;//amarelo;
//linha
int faixa = 400;
//Variaveis de controle
int valorEsquerda = 0;
int valorDireita = 0;
int valorCentro = 0;
//Velocidade do Motor
int velocidade = 50;
//A variavel "velocidade" define a velocidade do carrinho em uma linha reta
int diminuirVelocidade = velocidade;
int aumentarVelocidade = 80;
//A variavel "aumentarVelocidade" define a velocidade do carrinho nas curvas normais e nas curvas de 90 graus

void setup(){
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (sensorEsquerda, INPUT);
  pinMode (sensorCentro, INPUT);
  pinMode (sensorDireita, INPUT);
  Serial.begin (9600);
}


void loop(){

  //Leitura dos Sensores
  valorEsquerda = analogRead(sensorEsquerda);
  valorCentro = analogRead(sensorCentro);
  valorDireita = analogRead(sensorDireita);  

  /*
  Serial.print("Sensor Esquerda: ");
  Serial.println(valorEsquerda);
  Serial.print("Sensor Direita: ");
  Serial.println(valorDireita);
  Serial.print("Sensor Centro: ");
  Serial.println(valorCentro);
  */

  //Frente
  if (valorEsquerda < faixa && valorDireita < faixa){
    frente();
    Serial.println("Frente");
  }
  //Virar Esquerda 
  else if (valorEsquerda > faixa && valorDireita < faixa){
    if (valorCentro < faixa){
      virarEsquerda();
    }
  }
  //Virar Direita
  else if (valorEsquerda < faixa && valorDireita > faixa){
    if (valorCentro < faixa){
      virarDireita();
    } 
  }
  //Cruzamento
  else if (valorEsquerda > faixa && valorDireita > faixa){
    cruzamento();
    Serial.println("Cruzamento");
  }
   
}

//Metodos
void frente(){
  analogWrite (in1, velocidade); 
  analogWrite (in2, LOW); 
  analogWrite (in3, velocidade); 
  analogWrite (in4, LOW); 
}

void re(){
  analogWrite (in1, LOW); 
  analogWrite (in2, velocidade); 
  analogWrite (in3, LOW); 
  analogWrite (in4, velocidade); 
}

void parar(){
  analogWrite (in1, LOW); 
  analogWrite (in2, LOW); 
  analogWrite (in3, LOW); 
  analogWrite (in4, LOW);     
}

void esquerda(){
  analogWrite (in1, LOW); 
  analogWrite (in2, velocidade); 
  analogWrite (in3, velocidade); 
  analogWrite (in4, LOW); 
}

void direita(){
  analogWrite (in1, velocidade); 
  analogWrite (in2, LOW); 
  analogWrite (in3, LOW); 
  analogWrite (in4, velocidade); 
}

void virarEsquerda(){
  re();
  delay(40);

  while(valorCentro < faixa){
    velocidade = aumentarVelocidade;
    esquerda();
    delay(15);
    Serial.println("Esquerda");
    valorCentro = analogRead(sensorCentro);
  }
  velocidade = diminuirVelocidade;
}

void virarDireita(){
  re();
  delay(40);

  while(valorCentro < faixa){
    velocidade = aumentarVelocidade;
    direita();
    delay(15);
    Serial.println("Direita");
    valorCentro = analogRead(sensorCentro);
  }
  velocidade = diminuirVelocidade;
}

void cruzamento(){
  //Evento da Condicao do cruzamento
  parar();
  delay(100);

  //Aumenta a velocidade
  velocidade = aumentarVelocidade;
  direita();
  delay(600); 
  //Velocidade Normal
  velocidade = diminuirVelocidade;
}

void desviarObstaculo(){

  int virar90 = 1400;

  parar();
  delay(1000);

  velocidade = aumentarVelocidade;
  direita();
  delay(virar90);
  velocidade = diminuirVelocidade;

  parar();
  delay(500);

  frente();
  delay(1000);

  parar();
  delay(500);

  velocidade = aumentarVelocidade;
  esquerda();
  delay(virar90);
  velocidade = diminuirVelocidade;

  parar();
  delay(500);

  frente();
  delay(1500);

  parar();
  delay(500);

  velocidade = aumentarVelocidade;
  esquerda();
  delay(virar90);
  velocidade = diminuirVelocidade;

  parar();
  delay(500);

  frente();
  delay(1000);

  parar();
  delay(500);

  velocidade = aumentarVelocidade;
  direita();
  delay(virar90);
  velocidade = diminuirVelocidade;

  parar();
  delay(500); 

  re();
  delay(200); 
}
