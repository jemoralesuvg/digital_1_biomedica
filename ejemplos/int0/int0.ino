void setup()
{
  DDRD &= ~(1 << PD2);   // Configura PD2 como entrada (PIN3)
  PORTD |= (1 << PD2);   // Habilita la resistencia de pull-up interna en PD2
  EICRA |= (1 << ISC01); // INT0 para que se active en flanco de bajada
  EIMSK |= (1 << INT0);  // Habilita la interrupción externa INT0
  //SREG |= (1<<7); //bit de interrupción
  //cli();  // disable interrupts
  sei();  // enable interrupts, equivalente a SREG |= (1<<7); 
  Serial.begin(9600);
}
// Función de interrupción para INT0
ISR(INT0_vect) {
  Serial.println ("interrupción");
  // Código que se ejecutará cuando se active la interrupción
}


void loop() {
  // put your main code here, to run repeatedly:

}
