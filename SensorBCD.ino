#include <Servo.h>                    // Incluir la librería Servo
Servo servo1;                         // Crear un objeto tipo Servo llamado servo1
int angulo = 0 ;
int boton_entrada = 0;
int boton4 = 2;

int espacio_rest = 3;                   //Espacios totales
int cajon1 = 0;
int cajon2 = 0;
int cajon3 = 0;
int sensor_cajon1 = 0;
int sensor_cajon2 = 0;
int sensor_cajon3 = 0;

int boton_cajon1 = 0;                   //BOTON 1
int boton1 = 5;
unsigned long previousMillis = 0;      
const long interval = 250;
int ledState = LOW;

int boton_cajon2 = 0;                   //BOTON 2
int boton2 = 4;
unsigned long previousMillis2 = 0;      
const long interval2 = 250;
int ledState2 = LOW;

int boton_cajon3 = 0;                   //BOTON 3
int boton3 = 3;
unsigned long previousMillis3 = 0;      
const long interval3 = 250;
int ledState3 = LOW;

void setup() {
pinMode (0, OUTPUT);  //Rojo Cajon1
pinMode (1, OUTPUT);  //Verde Cajon 2
pinMode (2, OUTPUT);  //Rojo Cajon2
pinMode (3, OUTPUT);  //Verde Cajon 2
pinMode (11, OUTPUT); //Rojo Cajon 3
pinMode (12, OUTPUT); //Verde Cajon 3
  
pinMode (4, OUTPUT); // B
pinMode (5, OUTPUT); // C
pinMode (6, OUTPUT); // D
pinMode (7, OUTPUT); // A

pinMode (8, INPUT);  //Sensor 1
pinMode (13, INPUT);  //Sensor 2
pinMode (10, INPUT); //Sensor 3

servo1.attach(9) ;
}

void loop() {
sensor_cajon1 = digitalRead(8); //Lectura sensores
sensor_cajon2 = digitalRead(13);
sensor_cajon3 = digitalRead(10);

unsigned long currentMillis = millis(); 
unsigned long currentMillis2 = millis();
unsigned long currentMillis3 = millis();

boton_cajon1 = analogRead(boton1);  //Lectura botones
boton_cajon2 = analogRead(boton2);
boton_cajon3 = analogRead(boton3);

if (sensor_cajon1 == HIGH){         //Sensor 1 High
  cajon1 = 1;
  digitalWrite (0, HIGH);
  digitalWrite (1, LOW);
  }else{
    if (boton_cajon1 > 100){        //Boton 1 High
    cajon1 = 1;
    if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;   
    if (ledState == LOW) {
      ledState = HIGH;
    } else {                        //Boton 1 Low
      ledState = LOW;
    }
    digitalWrite (0, ledState);
    digitalWrite (1, LOW);
    }}
    else{                           //Sensor 1 Low
  cajon1 = 0;
  digitalWrite (0, LOW);
  digitalWrite (1, HIGH);
  }}

if (sensor_cajon2 == HIGH){
  cajon2 = 1;
  digitalWrite (2, HIGH);
  digitalWrite (3, LOW);
  }else{
    if (boton_cajon2 > 100){
    cajon2 = 1;
    if (currentMillis2 - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis2;   
    if (ledState2 == LOW) {
      ledState2 = HIGH;
    } else {
      ledState2 = LOW;
    }
    digitalWrite (2, ledState2);
    digitalWrite (3, LOW);
    }}
    else{
  cajon2 = 0;
  digitalWrite (2, LOW);
  digitalWrite (3, HIGH);
  }} 

if (sensor_cajon3 == HIGH){
  cajon3 = 1;
  digitalWrite (11, HIGH);
  digitalWrite (12, LOW);
  }else{
    if (boton_cajon3 > 100){
    cajon3 = 1;
    if (currentMillis3 - previousMillis3 >= interval3) {
    previousMillis3 = currentMillis3;   
    if (ledState3 == LOW) {
      ledState3 = HIGH;
    } else {
      ledState3 = LOW;
    }
    digitalWrite (11, ledState3);
    digitalWrite (12, LOW);
    }}
    else{
  cajon3 = 0;
  digitalWrite (11, LOW);
  digitalWrite (12, HIGH);
  }}

boton_entrada = analogRead(boton4);

if (boton_entrada > 100){
  if(angulo <= 105){  
    servo1.write(angulo);
    delay(25);
    angulo = angulo + 1;}
  else{
    angulo = 105;}}

if (boton_entrada < 100){
  if(angulo > 0){
    servo1.write(angulo);
    delay(25);
    angulo = angulo- 1;}
  else{
    angulo = 0;}}

espacio_rest = 3;
espacio_rest = espacio_rest - cajon1 - cajon2 - cajon3;  

if (espacio_rest == 0){
digitalWrite (4, LOW);    //0
digitalWrite (5, LOW);
digitalWrite (6, LOW);
digitalWrite (7, LOW);
}

if (espacio_rest == 1){
digitalWrite (4, LOW);    //1
digitalWrite (5, LOW);
digitalWrite (6, LOW);
digitalWrite (7, HIGH);
}

if (espacio_rest == 2){
digitalWrite (4, HIGH);   //2
digitalWrite (5, LOW);
digitalWrite (6, LOW);
digitalWrite (7, LOW);
}

if (espacio_rest == 3){
digitalWrite (4, HIGH);   //3
digitalWrite (5, LOW);
digitalWrite (6, LOW);
digitalWrite (7, HIGH);
}

}
