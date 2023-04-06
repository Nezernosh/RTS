int leds[] = {3, 5, 6, 9, 10, 11};
int ledsState[] = {LOW, LOW, LOW, LOW, LOW, LOW};
long intervals[] = {60, 900, 1200, 15000, 80000, 210000};
unsigned long previousIntervals[] = {0, 0, 0, 0, 0, 0};
unsigned long currentTime;

void setup() {
  /*назначем пины 1 (serial transmit) и 2..7 как Output,
  но оставляем пин 0 (serial receive) как Input
  (в противном случае serial port перестанет работать!)
  Регистр DDR - дописываем букву порта - DDRD, DDRB
  */
  DDRD = B01101000;  //цифровые пины 6,5,3 как OUTPUT
  DDRB = B00001110; //цифровые пины 11,10,9 как OUTPUT
}

void loop() {
  currentTime = micros();
  if (currentTime - previousIntervals[0] >= intervals[0]) {
      previousIntervals[0] = currentTime;

      ledsState[0] = !ledsState[0];
      if (ledsState[0]) {
        PORTD |= B00001000;
      }
      else {
        PORTD &= ~B00001000;
      }
  }
    if (currentTime - previousIntervals[1] >= intervals[1]) {
      previousIntervals[1] = currentTime;

      ledsState[1] = !ledsState[1];
      if (ledsState[1]) {
        PORTD |= B00100000;
      }
      else {
        PORTD &= ~B00100000;
      }
  }
    if (currentTime - previousIntervals[2] >= intervals[2]) {
      previousIntervals[2] = currentTime;

      ledsState[2] = !ledsState[2];
      if (ledsState[2]) {
        PORTD |= B01000000;
      }
      else {
        PORTD &= ~B01000000;
      }
  }
    if (currentTime - previousIntervals[3] >= intervals[3]) {
      previousIntervals[3] = currentTime;

      ledsState[3] = !ledsState[3];
      if (ledsState[3]) {
        PORTB |= B00000010;
      }
      else {
        PORTB &= ~B00000010;
      }
  }
    if (currentTime - previousIntervals[4] >= intervals[4]) {
      previousIntervals[4] = currentTime;

      ledsState[4] = !ledsState[4];
      if (ledsState[4]) {
        PORTB |= B00000100;
      }
      else {
        PORTB &= ~B00000100;
      }
  }
    if (currentTime - previousIntervals[5] >= intervals[5]) {
      previousIntervals[5] = currentTime;

      ledsState[5] = !ledsState[5];
      if (ledsState[5]) {
        PORTB |= B00001000;
      }
      else {
        PORTB &= ~B00001000;
      }
  }
}