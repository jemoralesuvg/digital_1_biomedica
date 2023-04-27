void setup() {
  Serial.begin(9600);
 
  // Configurar el temporizador en modo CTC
  TCCR0A = 0;//(1 << WGM01) | (0 << WGM00);
  // Configurar el divisor de reloj en 64
  TCCR0B = (0 << WGM02); // modo CTC
  TCCR0B |= (1 << CS02)| (0 << CS01)| (1 << CS00); //prescaler 1024
  TCNT0  = 0; // initialize counter value to 0
  // Configurar el valor del límite superior en 255
  OCR0A = 155;
  // Habilitar la interrupción de comparación
  TIMSK0 = (1 << OCIE0A);

  // TIMER 1 for interrupt frequency 1 Hz:
  //cli(); // stop interrupts
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; // initialize counter value to 0
  // set compare match register for 1 Hz increments
  OCR1A = 62499; // = 16000000 / (256 * 1) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12, CS11 and CS10 bits for 256 prescaler
  TCCR1B |= (1 << CS12) | (0 << CS11) | (0 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  //sei(); // allow interrupts

  // TIMER 2 for interrupt frequency 1000 Hz:
  //cli(); // stop interrupts
  TCCR2A = 0; // set entire TCCR2A register to 0
  TCCR2B = 0; // same for TCCR2B
  TCNT2  = 0; // initialize counter value to 0
  // set compare match register for 1000 Hz increments
  OCR2A = 249; // = 16000000 / (64 * 1000) - 1 (must be <256)
  // turn on CTC mode
  TCCR2B |= (1 << WGM21);
  // Set CS22, CS21 and CS20 bits for 64 prescaler
  TCCR2B |= (1 << CS22) | (0 << CS21) | (0 << CS20);
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);
  sei(); // allow interrupts


}

void loop() {
  // put your main code here, to run repeatedly:

}

int count0 = 0;
int count1 = 0;
int count2 = 0;

ISR(TIMER0_COMPA_vect){ //100HZ
   //interrupt commands for TIMER 0 here
   count0++;
   if (count0 == 100){
      Serial.println("1 seg en TMR0");
      count0 = 0;
   }
}


ISR(TIMER1_COMPA_vect){ //1Hz
   //interrupt commands for TIMER 1 here
   count1++;
   if (count1 == 2){
      Serial.println("2 seg en TMR1");
      count1 = 0;
   }
}


ISR(TIMER2_COMPA_vect){//1000Hz
   //interrupt commands for TIMER 2 here
   count2++;
   if (count2 == 1000){
      Serial.println("1 seg en TMR2");
      count2 = 0;
   }
}


