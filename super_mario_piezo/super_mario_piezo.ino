#include "note.h"
#include "music_test.h"
#include "mario.h"

#define melodyPin 3
#define SECONDS_PER_MINUTE 60
#define BPM 150

Note test[] = {{NOTE_C4, 4}, {NOTE_B4, 4}};

void setup(void)
{
  Serial.begin(9600);
  pinMode(melodyPin, OUTPUT);   //buzzer
}
void loop()
{
   play(test);
  // play(mario_overworld_melody);
  // play(mario_underworld_melody);
}

void play(Note song[]) {
  // iterate over the notes of the melody:
    int sizetemp = sizeof(song);
    int sizeeach = sizeof(song[0]);
        Serial.println(sizetemp);

    int size = sizeof(song);
    Serial.println(size);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      // note duration in milliseconds
      int beatsPerMeasure = 4;
      // currently assumes quarter note gets the beat
      int beatsPerSecond = (int)(BPM / SECONDS_PER_MINUTE);
      int secondsPerMeasure = (int) beatsPerMeasure/beatsPerSecond;
      int noteDuration = (int) 1000000 * secondsPerMeasure / (song[thisNote].duration + 0.);
      Serial.println(noteDuration);
      buzz(melodyPin, song[thisNote].pitch, noteDuration);

      // to separate the notes, set a minimum time between them. + 30% seems to work well.
      delay(noteDuration * 1.30);
      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);
    }
}

void buzz(int targetPin, long frequency, long length) {
  // 1E6 microseconds, divided by freq, div by 2 for 50% duty cycle
  long pulseWidth = 1000000 / frequency / 2;
  // total cycles = frequency (cycle/sec) * number of seconds 
  long numCycles = frequency * length;
  for (long i = 0; i < numCycles; i++) { 
    digitalWrite(targetPin, HIGH);
    delayMicroseconds(pulseWidth); 
    digitalWrite(targetPin, LOW); 
    delayMicroseconds(pulseWidth); 
  }
}
