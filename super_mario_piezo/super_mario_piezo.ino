#include "note.h"
#include "mario.h"

#define melodyPin 3
#define SECONDS_PER_MINUTE 60

int BPM = 150;

Note test_melody[] = {
{NOTE_E7, 16 },
{NOTE_D7, 8 }};

void setup(void)
{
  pinMode(melodyPin, OUTPUT);   //buzzer
}
void loop()
{
  //sing the tunes
  sing(mario_overworld_melody);
  sing(mario_underworld_melody);
}

void sing(Note song[]) {
  // iterate over the notes of the melody:
    int size = sizeof(song) / sizeof(song[0]);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      // note duration in milliseconds
      int beatsPerMeasure = 4;
      // currently assumes quarter note gets the beat
      int beatsPerSecond = (int)(BPM / SECONDS_PER_MINUTE);
      int secondsPerMeasure = (int) beatsPerMeasure/beatsPerSecond;
      int noteDuration = (int)secondsPerMeasure / (song[thisNote].duration + 0.);
      buzz(melodyPin, song[thisNote].pitch, noteDuration);

      // to separate the notes, set a minimum time between them. + 30% seems to work well.
      delay(noteDuration * 1.30);
      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);
    }
}

void buzz(int targetPin, long frequency, long length) {
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1E6 microseconds, divided by freq, div by 2 for 50% duty cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// total cycles = frequency (cycle/sec) * number of seconds 
  for (long i = 0; i < numCycles; i++) { 
    digitalWrite(targetPin, HIGH);
    delayMicroseconds(delayValue); 
    digitalWrite(targetPin, LOW); 
    delayMicroseconds(delayValue); 
  }
}
