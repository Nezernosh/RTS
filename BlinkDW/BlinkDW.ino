int leds[] = {3, 5, 6, 9, 10, 11};
int ledsState[] = {LOW, LOW, LOW, LOW, LOW, LOW};
long intervals[] = {60, 900, 1200, 15000, 80000, 210000};
unsigned long previousIntervals[] = {0, 0, 0, 0, 0, 0};
unsigned long currentTime;

void setup() {
  for (int ledN = 0; ledN < 6; ledN++)
  {
    pinMode(leds[ledN], OUTPUT);
  }
}

void loop() {
  currentTime = micros();
  if (currentTime - previousIntervals[0] >= intervals[0]) {
      previousIntervals[0] = currentTime;

      ledsState[0] = !ledsState[0];
      digitalWrite(leds[0], ledsState[0]);
  }
  if (currentTime - previousIntervals[1] >= intervals[1]) {
      previousIntervals[1] = currentTime;

      ledsState[1] = !ledsState[1];
      digitalWrite(leds[1], ledsState[1]);
  }
  if (currentTime - previousIntervals[2] >= intervals[2]) {
      previousIntervals[2] = currentTime;

      ledsState[2] = !ledsState[2];
      digitalWrite(leds[2], ledsState[2]);
  }
  if (currentTime - previousIntervals[3] >= intervals[3]) {
      previousIntervals[3] = currentTime;

      ledsState[3] = !ledsState[3];
      digitalWrite(leds[3], ledsState[3]);
  }
  if (currentTime - previousIntervals[4] >= intervals[4]) {
      previousIntervals[4] = currentTime;

      ledsState[4] = !ledsState[4];
      digitalWrite(leds[4], ledsState[4]);
  }
  if (currentTime - previousIntervals[5] >= intervals[5]) {
      previousIntervals[5] = currentTime;

      ledsState[5] = !ledsState[5];
      digitalWrite(leds[5], ledsState[5]);
  }
}