void setup() {
  // put your setup code here, to run once:
  // Configurar los pines OC1A a OC1F como salidas
  DDRB |= (1 << DDB5) | (1 << DDB6) | (1 << DDB7);
  DDRD |= (1 << DDD4) | (1 << DDD5) | (1 << DDD6);

  // Configurar el temporizador en modo Fast PWM de 10 bits
  TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << COM1C1) | (1 << WGM11) | (1 << WGM10);
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Divisor de reloj en 8

  // Configurar el valor máximo del contador para PWM de 10 bits
  ICR1 = 1023;

  // Configurar los valores de comparación para cada salida PWM
  OCR1A = 200;
  OCR1B = 400;
  OCR1C = 600;
  OCR1D = 800;
  OCR1E = 900;
  OCR1F = 1000;

}

void loop() {
  // put your main code here, to run repeatedly:

}
