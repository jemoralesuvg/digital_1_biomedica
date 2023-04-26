void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  DDRB = 0b00001111;  // 0 input 1 output
  PORTB = 0b00110011; // clk, clk, Pullup, Pullup, 0, 0, 1, 1
  /*Ouput? 1 = High 0 = LOW 
  if (output)
    1 = high, 0 = low
  if (input)
    1 = pullup, 0 = Hi-Z
  */
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = PINB;
  Serial.println (i);
  delay(200);
}
