#include "note.h"
#include "mario.h"

#define melodyPin 3
int BPM = 150;

Note test_melody[] = {
{NOTE_E7, 16 },
{NOTE_D7, 8 }};

void setup(void)
{
  pinMode(3, OUTPUT);//buzzer
  pinMode(13, OUTPUT);//led indicator when singing a note
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
      int noteDuration = (int)((1000 * (60 * 4 / BPM)) / song[thisNote].duration + 0.);
      buzz(melodyPin, song[thisNote].pitch, noteDuration);

      // to separate the notes, set a minimum time between them. + 30% seems to work well.
      delay(noteDuration * 1.30);
      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);
     }
}

void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(13, LOW);

}
