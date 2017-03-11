/*
 * Ejercicio con dos leds (Pin 2 y 3) y un botón (Pin 4) conectados a la Arduino.
 * Mientras pulsemos el botón se encenderá el primer led y el segundo se apagará, 
 * si no se pulsa, el primer led se apagará y el segundo se encenderá. 
 */
void setup() {
  //ponemos los dos pines en modo salida
  pinMode(2,OUTPUT); //led 1
  pinMode(3,OUTPUT); //led 2
  pinMode(4,INPUT_PULLUP); //botón
}

void loop() {
  //Si se pulsa el botón el primer led se enciende y el segundo se apaga.
  if(digitalRead(4)){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
  }else{
    //Si no se pulsa el primer led se apaga y el segundo se enciende.
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
  }
}
