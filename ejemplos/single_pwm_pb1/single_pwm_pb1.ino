void setup() {
  // Configurar el pin 9 como salida
  DDRB |= (1 << PB1);

  // Configurar el modo de operación del Timer1 en modo PWM
  //WGM13 12 11 10 = 1110 = fast PWM
  //CS12 11 10 = 011 = prescaler 64
  //COM1A1 0 = 10 = Clear OC1A on compare, Set OC1A at bottom
  TCCR1A |= (1 << COM1A1) | (1 << WGM11); //OC1A es el pin PB1
  TCCR1B |= (1 << WGM13)  | (1 << WGM12) | (1 << CS10) | (1 << CS11);
 
  // Configurar el periodo del PWM
  ICR1 = 5000; 
  // Frecuencia de reloj / (frecuencia del PWM * prescaler) - 1

  // Configurar el ancho de pulso del PWM
  OCR1A = 300; // ICR1 * ciclo de trabajo / 100 
//( 125 - 600, 0.5ms - 2.4ms)
  //Compara el OCR1A (ancho de pulso) con el ICR1 (periodo)
}

void loop() {
  // Código para el loop principal
}
