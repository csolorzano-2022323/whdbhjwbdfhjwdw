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

const int boton3Pin = 2; //Pines de los botones
const int boton4Pin = 3;

const int motor1Pins[] = {4, 5, 6, 7}; //Pines para los motores steper.
const int motor2Pins[] = {8, 9, 10, 11}; 

const int obstaculoPin = 12; //Pin del detector de obstaculos del ARDUINO PRIMARIO.

const int SIGNALOUTPUT3 = A0; //Pines de salida digital para el ARDUINO PRIMARIO.
const int SIGNALOUTPUT4 = A1;

    int SELECMOTOR; 
    int pos = 0;
/*
 * ESTE ES UN CODIGO REPLICA DEL PRIMER CODIGO
 * SALVO POR ALGUNOS CAMBIOS COMO LA ELIMINACION
 * DE VARIABLES INNECESARIAS PARA ESTE SIGUIENTE CODIGO
 * LIBRERIAS, Y TEXTOS, PERO ES MUY SIMILAR.
 * POR LO QUE SE OPTO POR AHORRAR COMENTARIOS SALVO EN
 * ALGUNAS VARIANTES QUE PODRIAN RESULTAR RARAS POR EL 
 * LECTOR.
 */ 

void setup() {


  pinMode(boton3Pin, INPUT_PULLUP);
  pinMode(boton4Pin, INPUT_PULLUP);


  for (int i = 0; i < 4; i++) {
    pinMode(motor1Pins[i], OUTPUT);
    pinMode(motor2Pins[i], OUTPUT);
  }


  pinMode(obstaculoPin, INPUT);
  pinMode(SIGNALOUTPUT3, OUTPUT);
  pinMode(SIGNALOUTPUT4, OUTPUT);  
}

void loop() {
  if (digitalRead(boton3Pin) == HIGH) {
    SELECMOTOR = 1;
    digitalWrite(SIGNALOUTPUT3, HIGH);
  }
  if (SIGNALOUTPUT3,HIGH) {
    delay(100);
    digitalWrite(SIGNALOUTPUT3, LOW);
  }


  if (digitalRead(obstaculoPin) == HIGH) {
    ejecutarMotor();
    SELECMOTOR = 0;
    reiniciar();
    }  
    
    if (digitalRead(boton4Pin) == HIGH) {
    SELECMOTOR = 2;
    digitalWrite(SIGNALOUTPUT4, HIGH);
    }
  if (SIGNALOUTPUT4,HIGH) {
    delay(100);
    digitalWrite(SIGNALOUTPUT4, LOW);
  }

  if (digitalRead(obstaculoPin) == HIGH) {

    ejecutarMotor();
    SELECMOTOR = 0;    
    reiniciar();
    } }
  

void ejecutarMotor(void) {
  
  int demora = 100;


  if (SELECMOTOR == 1) {  
  for (pos = 0; pos <= 10; pos += 1){

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
  for (pos = 0; pos <= 10; pos += 1){

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

}


/* ATENCION, ESTE ES EL CODIGO SECUNDARIO DE ARDUINO,
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
