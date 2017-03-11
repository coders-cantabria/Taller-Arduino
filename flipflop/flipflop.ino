/*
 * Consiste en conectar a la Arduino dos leds (Pin 2 y 3). 
 * Mientras uno de los leds se encienda el otro se apagará, 
 * de manera cíclica (tiempo de 1 seg).
 */
void setup() {
  //Ponemos los dos pines en modo salida
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  //El primer led esta enciende y el segundo apagado, durante un 1 seg
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  delay(1000);
  
  //Primer led apagado y el segundo encendido, durante 1 seg
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(1000);

}
