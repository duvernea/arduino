
#include "note.h"

//Mario main theme melody

Note mario_overworld_melody[] = {
{NOTE_E7, 12 },{NOTE_E7, 12},{0, 12},{NOTE_E7, 12},
{0, 12},{NOTE_C7, 12},{NOTE_E7, 12},{0, 12},
{NOTE_G7, 12},{0, 12},{0, 12},{0, 12},
{NOTE_G6, 12},{0, 12},{0, 12},{0, 12},

{NOTE_C7, 12},{0, 12},{0, 12},{NOTE_G6, 12},
{0, 12},{0, 12},{NOTE_E6, 12},{0, 12},
{0, 12},{NOTE_A6, 12},{0, 12},{NOTE_B6, 12},
{0, 12},{NOTE_AS6, 12},{NOTE_A6, 12},{0, 12},

{NOTE_G6, 9},{NOTE_E7, 9},{NOTE_G7, 9},
{NOTE_A7, 12},{0, 12},{NOTE_F7, 12},{NOTE_G7, 12},
{0, 12},{NOTE_E7, 12},{0, 12},{NOTE_C7, 12},
{NOTE_D7, 12},{NOTE_B6, 12},{0, 12},{0, 12},

{NOTE_C7, 12},{0, 12},{0, 12},{NOTE_G6, 12},
{0, 12},{0, 12},{NOTE_E6, 12},{0, 12},
{0, 12},{NOTE_A6, 12},{0, 12},{NOTE_B6, 12},
{0, 12},{NOTE_AS6, 12},{NOTE_A6, 12},{0, 12},

{NOTE_G6, 9},{NOTE_E7, 9},{NOTE_G7, 9},
{NOTE_A7, 12},{0, 12},{NOTE_F7, 12},{NOTE_G7, 12},
{0, 12},{NOTE_E7, 12},{0, 12},{NOTE_C7, 12},
{NOTE_D7, 12},{NOTE_B6, 12},{0, 12},{0, 12},
};

Note mario_underworld_melody[] = {
{NOTE_C4, 16},{NOTE_C5, 16},{NOTE_A3, 16},{NOTE_A4, 16},
{NOTE_AS3, 16},{NOTE_AS4, 16},{0, 4},{0, 2},

{NOTE_C4, 16},{NOTE_C5, 16},{NOTE_A3, 16},{NOTE_A4, 16},
{NOTE_AS3, 16},{NOTE_AS4, 16},{0, 4},{0, 2},

{NOTE_F3, 16},{NOTE_F4, 16},{NOTE_D3, 16},{NOTE_D4, 16},
{NOTE_DS3, 16},{NOTE_DS4, 16},{0, 4},{0, 2},

{NOTE_F3, 16},{NOTE_F4, 16},{NOTE_D3, 16},{NOTE_D4, 16},
{NOTE_DS3, 16},{NOTE_DS4, 16},{0, 4},{0, 2},

{0, 6},{NOTE_DS4, 24},{NOTE_D4, 24},{NOTE_CS4, 24},
{NOTE_C4, 8},{NOTE_DS4, 8},
{NOTE_D4, 8},{NOTE_GS3, 8},
{NOTE_G3, 8},{NOTE_CS4, 8},
{NOTE_C4, 24},{NOTE_FS4, 24},{NOTE_F4, 24},{NOTE_E3, 24},{NOTE_AS4, 24},{NOTE_A4, 24},
{NOTE_GS4, 12},{NOTE_DS4, 12},{NOTE_B3, 12},
{NOTE_AS3, 12},{NOTE_A3, 12},{NOTE_GS3, 12},
{0, 3},{0, 3},{0, 3}};

int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  
  0, NOTE_DS4, NOTE_D4, NOTE_CS4,
  NOTE_C4, NOTE_DS4,
  NOTE_D4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  16, 16, 16, 16,
  16, 16, 4,
  2,
  16, 16, 16, 16,
  16, 16, 4,
  2,
  16, 16, 16, 16,
  16, 16, 4,
  2,
  16, 16, 16, 16,
  16, 16, 4,
  6, 24, 24, 24,
  8, 8, 
  8, 8,
  8, 8,
  24, 24, 24, 24, 24, 24,
  12, 12, 12,
  12, 12, 12,
  3, 3, 3
};
