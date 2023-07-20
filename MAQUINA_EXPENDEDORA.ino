/*
FUNDACION KINAL
CENTRO EDUCATIVO TECNICO LARELEORAL KINAL
PERITO EN ELECTRONICA
QUINTO PERITO
SECCION: A
CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
ALUMNOS: ANGELLO MANSILLA, RUDY CANEL, PABLO HERNANDEZ, CHRISTIAN SOLORZANO, DAVID DEL CID, DIEGO QUEME.
CARNETS: 2022380, 2022449,2022472, 2022323, 2022482,2021430.
PROYECTO 2, MAQUINA EXPENDEDORA
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h> //Incluimos las librerias correspondientes.

const int boton1Pin = 2; //Pines de los botones
const int boton2Pin = 3;


const int motor1Pins[] = {4, 5, 6, 7}; //Pines para los motores steper.
const int motor2Pins[] = {8, 9, 10, 11}; 

const int SIGNALINPUT3 = A0; //Pines de salida y entrada para la intercomunicacion entre arduinos
const int SIGNALINPUT4 = A1;
const int SIGNALOUTPUT = A2;


const int obstaculoPin = 12; //Detector de monedas(el sensor de obstaculos

const char mensajeInicial[] = "SELECCIONE"; //Hacemos un const char con los mensajes, para ahorrar algo de tiempo.
const char mensajeInicial2[] = "PRODUCTO"; 
const char mensajeMoneda[] = "INSERTE MONEDA";
const char mensajeProcesando[] = "PROCESANDO...";

const char mensajePROD1[] = "S: PRODUCTO1"; //Hacemos unos const char con los mensajes de productos seleccionados.
const char mensajePROD2[] = "S: PRODUCTO2";
const char mensajePROD3[] = "S: PRODUCTO3";
const char mensajePROD4[] = "S: PRODUCTO4";


LiquidCrystal_I2C lcd(0x27, 16, 2); // Construimos el I2C


      int SELECMOTOR; //Variable que guardara la seleccion del usuario.
      int pos = 0; //Variable tipo contador para los ciclos de girado de los motores stepper.

      

void setup() {

  pinMode(boton1Pin, INPUT);   // Configurar los pines de los botones como entradas
  pinMode(boton2Pin, INPUT);


  for (int i = 0; i < 4; i++) {   // Configurar los pines de los motores stepper como salidas
    pinMode(motor1Pins[i], OUTPUT);
    pinMode(motor2Pins[i], OUTPUT);
  }


  pinMode(obstaculoPin, INPUT);   // Configurar el pin del detector de obstáculos como entrada
  pinMode(SIGNALINPUT3, INPUT);
  pinMode(SIGNALINPUT4, INPUT);
  pinMode(SIGNALOUTPUT, OUTPUT);  
  


  lcd.init();   // Inicializar el LCD
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(mensajeInicial); //Mostrar los mensajes iniciales.
  delay(100);
  lcd.setCursor(0,1);
  lcd.print(mensajeInicial2);
}

void loop() {
  
  if (digitalRead(boton1Pin) == HIGH) { //PRODUCTO UNO SELECCIONADO.
    SELECMOTOR = 1;
    lcd.clear();
    lcd.print(mensajeMoneda);
    delay(100);
    lcd.setCursor(0,1);
    lcd.print(mensajePROD1);  
    }

  if (digitalRead(obstaculoPin) == LOW) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(mensajeProcesando);
    ejecutarMotor();
    SELECMOTOR = 0;
    reiniciar();
    }  // FIN DEL PRODUCTO 1.
    



    if (digitalRead(boton2Pin) == HIGH) { //PRODUCTO DOS SELECCIONADO.
    SELECMOTOR = 2;
    lcd.clear();
    lcd.print(mensajeMoneda);
    delay(100);
    lcd.setCursor(0,1);
    lcd.print(mensajePROD2);       
    }
    
  if (digitalRead(obstaculoPin) == LOW) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(mensajeProcesando);
    ejecutarMotor();
    SELECMOTOR = 0;    
    reiniciar();
    }  // FIN DEL PRODUCTO 2.



    

  if (digitalRead(SIGNALINPUT3) == HIGH) { //PRODUCTO TRES SELECCIONADO.
    SELECMOTOR = 3;
    lcd.clear();
    lcd.print(mensajeMoneda);
    delay(100);
    lcd.setCursor(0,1);
    lcd.print(mensajePROD3);
    }

  if (digitalRead(obstaculoPin) == LOW) {
    digitalWrite(SIGNALOUTPUT, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(mensajeProcesando);
    ejecutarMotor();
    digitalWrite(SIGNALOUTPUT, LOW);
    SELECMOTOR = 0;    
    reiniciar();
    }  // FIN DEL PRODUCTO 3.





  if (digitalRead(SIGNALINPUT4) == HIGH) { //PRODUCTO CUATRO SELECCIONADO.
    SELECMOTOR = 4;
    lcd.clear();
    lcd.print(mensajeMoneda);
    delay(100);
    lcd.setCursor(0,1);
    lcd.print(mensajePROD4);       
    }


  if (digitalRead(obstaculoPin) == LOW) {
    digitalWrite(SIGNALOUTPUT, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(mensajeProcesando);
    ejecutarMotor();
    digitalWrite(SIGNALOUTPUT, LOW);    
    SELECMOTOR = 0;    
    reiniciar();
    }  // FIN DEL PRODUCTO 4.
    
}
    
    
  

void ejecutarMotor(void) { //Funcion para realizar los movimientos Stepper.

  
  int demora = 2; //Variable para provocar demora.


  if (SELECMOTOR == 1) {  
  for (pos = 0; pos <= 1000; pos += 1){

  digitalWrite(4, HIGH); //PASO 1
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(demora);

  digitalWrite(4, LOW); //PASO 2
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(demora);

  digitalWrite(4, LOW); //PASO 3
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(demora);

  digitalWrite(4, LOW); //PASO 4
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  delay(demora);

  digitalWrite(4, LOW); //PASO 5
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  delay(demora);

  digitalWrite(4, LOW); //PASO 6
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(demora);

  digitalWrite(4, HIGH); //PASO 7
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(demora);

  digitalWrite(4, HIGH); //PASO 8
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(demora);
      
    } }


  else if (SELECMOTOR == 2) {  
  for (pos = 0; pos <= 1000; pos += 1){

   digitalWrite(8, HIGH); //PASO 1
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(demora);

  digitalWrite(8, LOW); //PASO 2
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(demora);

  digitalWrite(8, LOW); //PASO 3
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  delay(demora);

  digitalWrite(8, LOW); //PASO 4
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(demora);

  digitalWrite(8, LOW); //PASO 5
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(demora);

  digitalWrite(8, LOW); //PASO 6
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(demora);

  digitalWrite(8, HIGH); //PASO 7
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(demora);

  digitalWrite(8, HIGH); //PASO 8
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(demora);
      
    } }

  else if (SELECMOTOR == 3) {  
    delay(4500);
  }

  else if (SELECMOTOR == 4) {  
     delay(4500);
  }
    

    else {
  digitalWrite(8, LOW); //PASO 8
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);

  digitalWrite(4, LOW); //PASO 8
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);  


      
      
    }




}

void reiniciar() { //Funcion para reiniciar
  pos = 0;
  SELECMOTOR = 0;
  digitalWrite(SIGNALOUTPUT, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(mensajeInicial);
  delay(100);
  lcd.setCursor(0,1);
  lcd.print(mensajeInicial2);
}

/* ATENCION, EL CODIGO SEGUIRA
 * EN EL SIGUIENTE CODIGO, EL SIGUIENTE 
 * CONTROLA LOS BOTONES 3 Y 4,
 * INCLUYENDO LOS MOTORES 3 Y 4, SI SE DESEARA
 * IMPLEMENTAR ESTE CODIGO EN UN ARDUINO, SE RECOMIENDA
 * USAR UN ARDUINO MEGA O GIGA EN SU DEFECTO, YA QUE
 * ESTOS POSEEN UNA CANTIDAD DE PINES EXTREMA,
 * O USAR UN EXPANSOR DE PINES, NO LO USAMOS AQUI
 * YA QUE SOLO SE NOS LIMITABA A EXPANSORES I2C, Y SE
 * DESCARTARON POR SU DIFICULTAD DE USO. 
 * 
 * CODIGO POR: Angello Gabriel Mansilla Dieguez.
 */
