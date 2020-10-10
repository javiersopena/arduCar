#include <Ultrasonic.h>

int SONIDO_OUT = 3;     //Emite sonido
int SONIDO_IN  = 2;     //Recibe sonido
int PULSADOR = 7;        //Pulsador de choque

int RIGHT      = 13;    //Derecha
int LEFT       = 10;    //Izquierda
int FORWARD    = 12;    //Adelante
int BACKWARD   = 11;    //Atras

int DISTANCIA_OBSTACULO          = 50;  //Distancia en centimetros a la que se para el coche al ver un obstaculo.
int TIEMPO_MUESTREO_ULTRASONIDOS = 10;  //Tiempo en milisegundos entre cada muestreo del sensor de ultrasonidos.
int TIEMPO_CAMBIAR_DIRECCION     = 500; //Tiempo en milisegundos de la duracion del movimiento de cambio de direccion.

Ultrasonic ultrasonic(SONIDO_OUT, SONIDO_IN); // (Trig PIN,Echo PIN)

// the setup routine runs once when you press reset:
void setup() {                
  pinMode(RIGHT, OUTPUT);
  pinMode(LEFT, OUTPUT);
  pinMode(FORWARD, OUTPUT);
  pinMode(BACKWARD, OUTPUT);
  pinMode(PULSADOR, INPUT);
  
  adelante();
  delay(500);
  atras();
  delay(500);
  parar();
  
  
  
  //randomSeed(analogRead(0));
}

// the loop routine runs over and over again forever:
void loop() {
  
  adelante();
  continuar();
  parar();
  cambiarDireccion();
  
}

void parar(){
  digitalWrite(FORWARD, LOW);
  digitalWrite(BACKWARD, LOW);
  digitalWrite(LEFT, LOW);
  digitalWrite(RIGHT, LOW);
}

void adelante(){
  digitalWrite(FORWARD, HIGH);
}

void atras(){
  digitalWrite(BACKWARD, HIGH);
}

void izquierda(){
  digitalWrite(LEFT, HIGH);
}

void derecha(){
  digitalWrite(RIGHT, HIGH); 
}

void continuar(){
  while((DISTANCIA_OBSTACULO < ultrasonic.Ranging(CM)) && (PULSADOR = LOW)){
    delay(TIEMPO_MUESTREO_ULTRASONIDOS);
  }
} 

void cambiarDireccion(){
  if(random(0, 2) < 1){
    izquierda();
    atras();
  } else {
    derecha();
    atras();
  }
  delay(TIEMPO_CAMBIAR_DIRECCION);
  parar();
  delay(2000);
}

