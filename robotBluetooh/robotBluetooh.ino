/**
 * Código para manejar un robot mediante bluetooth desde el móvil, con servos de rotación continua.
 * Aplicación Android: Arduino Bluetooth RC Car
 * 
 * Nota: En un transmisión serie la conexión es cruzada, es decir, Tx bluetooth con Rx Arduino y 
 * Rx bluetooth con Tx Arduino
 */

#include <SoftwareSerial.h> //Librería necesaria para bluetooth, ya que es una conexión serial.
#include <Servo.h>



/***   variables Globales   ***/
SoftwareSerial blueToothSerial(10, 11); //conexión Tx(transmisión) Rx(Recepción)

//objetos de tipo servo
Servo servoA, servoB; 

//pines a los que irán conectados los servos de rotación continua (motores)
int motorA = 8;
int motorB = 9;

/***    Declaración de funciones   ***/
void up ();
void back ();
void left ();
void right ();
void stop ();

void setup()
{
  Serial.begin(9600); //configuramos el modo monitor, para mostrar el texto en el pc 
  blueToothSerial.begin(9600); //ponemos los baudios a los que funciona el bluetooth
  blueToothSerial.flush(); //limpiamos el buffer del bluetooth por si hubiese algo
}
void loop()
{
  //si el bluetooth esta habilitado
  if (blueToothSerial.available()) {
    
    //hacemos una lectura de lo que recive el bluetooth
    char valor = blueToothSerial.read();
    
    //si recibe una F llamamos a la función up
    if (valor == 'F') {
      up();
    } else if (valor == 'B') { //si recibimos una B
      back();
    } else if (valor == 'L') { //si recibimos una L
      left();
    } else if (valor == 'R') { //si recibimos una R
      right();
    } else if (valor == 'S') { //si recibimos una S
      stop();
    }
    Serial.println(valor); //pinto en pantalla el valor recibido
    delay(15);
  }


}

/***   Functiones   ***/

//función hacia delante
void up () {
  //configuro a que pines esta conectado el servo de rotación continua
  servoA.attach(motorA); 
  servoB.attach(motorB);

  //Giro el servo de rotación continua en un sentido, al ser de rotación continua
  //no sabe cuantos grados gira y nunca para mientras siga la señal
  servoA.write(-180);  
  servoB.write(180); 
  
  Serial.println("up"); //imprimo por pantalla 
}

//función hacia atrás
void back () {
  servoA.attach(motorA);
  servoB.attach(motorB);
  servoA.write(180);
  servoB.write(-180);

  Serial.println("back");
}

//función ir a la izquierda
void left () {
  servoA.attach(motorA);
  servoB.attach(motorB);
  servoA.write(180);
  servoB.write(180);
  Serial.println("left");
}

//función ir a la derecha 
void right () {
  servoA.attach(motorA);
  servoB.attach(motorB);
  servoA.write(-180);
  servoB.write(-180);
  Serial.println("right");
}

//función parar
void stop () {
  //paro los servos desconectandoles
  servoA.detach(); 
  servoB.detach();
  Serial.println("stop");
}


