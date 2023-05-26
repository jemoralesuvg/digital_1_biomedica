void setup() {
  // put your setup code here, to run once:
  // Configurar los pines 9 y 10 como salidas
  DDRB |= (1 << DDB1) | (1 << DDB2) ;

  // Configurar el temporizador en modo Fast PWM de 10 bits
  TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11) | (1 << WGM10);
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Divisor de reloj en 8

  // Configurar el valor máximo del contador para PWM de 10 bits
  ICR1 = 1023;

  // Configurar los valores de comparación para cada salida PWM
  OCR1A = 200;
  OCR1B = 400;

}

void loop() {
  // put your main code here, to run repeatedly:

}
