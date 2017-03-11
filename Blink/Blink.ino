/**********************************************************************************
 * Blink
 * Ejercicio básico que consiste en encender y apagar un led de manera intermitente.
 * El tiempo de encendido y apagado es de 1 segundo. 
 * 
 **********************************************************************************/

/*
 * Función setup, solo se ejecuta una vez al principio del programa.
 * Si se pulsa el botón reset o se vuelve a conectar la corriente se ejecutará de nuevo.
 * Sirve para inicializar variables, inicializar librerias, configurar pines, etc.
 */
void setup() {
  //inicializa el pin 13 a modo salida, al ser digital 
  //solo puede tener 2 valores alto(HIGH) y bajo(LOW)
  pinMode(13, OUTPUT);
}

/*
 * Función loop, es la función principal del programa.
 * Se ejecuta justo después la función setup, de manera indefinida
 */
void loop() {
  digitalWrite(13, HIGH);   // enciendo el LED (HIGH pasa corriente)
  delay(1000);              // espero 1000 ms (estará ese tiempo encendido el LED)
  digitalWrite(13, LOW);    // apago el LED (LOW no pasa corriente) 
  delay(1000);              // espero 1000 ms
}
