void setup() {
  // put your setup code here, to run once:
  // Vref = interno (5V), Justificado a la derecha, canal 0
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Configurar el prescaler a 128
  ADMUX = 8; //seleccionar canal de sensor de temperatura interno
  ADMUX |= (1<<REFS0);  //Vref 1.1v - para el sensor de temp
  ADMUX |= (1<<REFS1);
  ADMUX &= ~(1<<ADLAR); //ajuste a la derecha de la salida de 10 bits
  delay(20);  //esperar a que se estabilice el voltaje
  // Habilitar el ADC
  ADCSRA |= (1 << ADEN);

  Serial.begin(9600);

}

void loop() {
  // Iniciar la conversión
  ADCSRA |= (1 << ADSC);
  // Esperar a que la conversión termine
  while (ADCSRA & (1 << ADSC));
  float temperature = (ADC - 324.31) / 1.22;
  Serial.println(temperature);
  delay(200);
}
