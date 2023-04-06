#include <TaskManagerIO.h>

int leds[] = {3, 5, 6, 9, 10, 11};
int ledsState[] = {LOW, LOW, LOW, LOW, LOW, LOW};

void setup() {
  /*назначем пины 1 (serial transmit) и 2..7 как Output,
  но оставляем пин 0 (serial receive) как Input
  (в противном случае serial port перестанет работать!)
  Регистр DDR - дописываем букву порта - DDRD, DDRB*/
  DDRD = B01101000;  //цифровые пины 6,5,3 как OUTPUT
  DDRB = B00001110; //цифровые пины 11,10,9 как OUTPUT
  
  taskManager.scheduleFixedRate(60, [] {
    led(ledsState[0], leds[0]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(900, [] {
    led(ledsState[1], leds[1]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(1200, [] {
    led(ledsState[2], leds[2]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(15000, [] {
    led(ledsState[3], leds[3]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(80000, [] {
    led(ledsState[4], leds[4]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(210000, [] {
    led(ledsState[5], leds[5]);
  }, TIME_MICROS);
}

void loop() {
  taskManager.runLoop();
}

void led(int &ledState, int led)
{
  ledState = !ledState;
  if (ledState) {
    if (led == 3) {
      PORTD |= B00001000;
    }
    if (led == 5) {
      PORTD |= B00100000;
    }
    if (led == 6) {
      PORTD |= B01000000;
    }
    if (led == 9) {
      PORTB |= B00000010;
    }
    if (led == 10) {
      PORTB |= B00000100;
    }
    if (led == 11) {
      PORTB |= B00001000;
    }
  }
  else {
    if (led == 3) {
      PORTD &= ~B00001000;
    }
    if (led == 5) {
      PORTD &= ~B00100000;
    }
    if (led == 6) {
      PORTD &= ~B01000000;
    }
    if (led == 9) {
      PORTB &= ~B00000010;
    }
    if (led == 10) {
      PORTB &= ~B00000100;
    }
    if (led == 11) {
      PORTB &= ~B00001000;
    }
  }
}