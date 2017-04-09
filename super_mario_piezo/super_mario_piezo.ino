#include "note.h"
#include "music_test.h"
#include "mario.h"

#define melodyPin 3
#define SECONDS_PER_MINUTE 60
#define BPM 200

TimeSignature defaultTimeSig;
Note test[] = {{NOTE_C6, 4}, {NOTE_A6, 4}};

void setup(void)
{
  Serial.begin(9600);
  pinMode(melodyPin, OUTPUT);   //buzzer
}
void loop()
{
//  play(noteRunThrough, 
//    sizeof(noteRunThrough)/sizeof(noteRunThrough[0]),
//    defaultTimeSig);
  play(mario_overworld_melody, 
    sizeof(mario_overworld_melody)/sizeof(mario_overworld_melody[1]),
    defaultTimeSig);
//  play(mario_underworld_melody, 
//    sizeof(mario_underworld_melody)/sizeof(mario_underworld_melody[0]),
//    defaultTimeSig);   
}

void play(Note song[], int numNotes, TimeSignature timeSig) {
  // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < numNotes; thisNote++) {
      // note duration in milliseconds
      // currently assumes quarter note gets the beat
      int beatsPerSecond = (int) (BPM / SECONDS_PER_MINUTE);
      int secondsPerMeasure = (int) timeSig.beatsPerMeasure / beatsPerSecond;
      // time signature beat length calc
      int adjDuration = song[thisNote].duration / (timeSig.beat/4.0);

      // note duration in milliseconds
      int noteDuration = (int) 1000 * secondsPerMeasure / (adjDuration + 0.);
      
      buzz(melodyPin, song[thisNote].pitch, noteDuration);
      // to separate the notes, set a minimum time between them. + 30% seems to work well.
      delay(noteDuration * 1.30);
      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);
    }
}

void buzz(int targetPin, long frequency, long length) {
  // 1E6 microseconds, divided by freq, div by 2 for 50% duty cycle
  long pulseWidth = 1E6 / (frequency + 0.0) / 2;
  // total cycles = frequency (cycle/sec) * number of seconds 
  // length in milliseconds -> convert to microseconds
  long numCycles = frequency * length / 1000;
  for (long i = 0; i < numCycles; i++) { 
    digitalWrite(targetPin, HIGH);
    delayMicroseconds(pulseWidth); 
    digitalWrite(targetPin, LOW); 
    delayMicroseconds(pulseWidth); 
  }
}
