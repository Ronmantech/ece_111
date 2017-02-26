#include "Music.h"
    
    /**
     * @param mySpeaker is the DigitalOut that is input into the Music class (in Music.cpp).
     * @param _mySpeaker is the private DigitalOut used by the Music class (in Music.cpp).
     */
     Music::Music(PinName mySpeaker) : _mySpeaker(mySpeaker){ 
      // The Music class is constructed.
    }
 
    Music::~Music(void){
      // The Music class is deconstructed.
    }
 
    /**
     * @param note plays a note from the standard piano.
     * Input notes range from 1 to 88.
     * Set to zero to turn off the note.
     * Sourced from: https://en.wikipedia.org/wiki/Piano_key_frequencies
     * @returns
     *   1 on success.
     *   0 on error, typically outside of the max range of 88.
     */
    int Music::playNote(int note) {
 
        /* Notes are defined as followed, {off, A0, A0#, B0, C1, C1#, D1#, E1, ....  A7, A7#, B7, C8} */
        float noteFrequencies [89] = {0,
                        //A=1      A#       B
          /* 0 Octave */ 27.5,    29.1352, 30.8677,   // notes 1-3
                        //C=4      C#       D        D#       E        F        F#       G        G#      A      A#       B
          /* 1 Octave */ 32.7032, 34.6478, 36.7081, 38.8909, 41.2034, 43.6535, 46.2493, 48.9994, 51.9131, 55,   58.2705, 61.7354, // notes 4  - 15
          /* 2 Octave */ 65.4064, 69.2957, 73.4162, 77.7817, 82.4069, 87.3071, 92.4986, 97.9989, 103.826, 110,  116.541, 123.471, // notes 16 - 27
          /* 3 Octave */ 130.813, 138.591, 146.832, 155.563, 164.814, 174.614, 184.997, 195.998, 207.652, 220,  233.082, 246.942, // notes 28 - 39
          /* 4 Octave */ 261.626, 277.183, 293.665, 311.127, 329.628, 349.228, 369.994, 391.995, 415.305, 440,  466.164, 493.883, // notes 40 - 51
          /* 5 Octave */ 523.251, 554.365, 587.33,  622.254, 659.255, 698.456, 739.989, 783.991, 830.609, 880,  932.328, 987.767, // notes 52 - 63
          /* 6 Octave */ 1046.5,  1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22, 1760, 1864.66, 1975.53, // notes 64 - 75
          /* 7 Octave */ 2093,    2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44, 3520, 3729.31, 3951.07, // notes 76 - 87
          /* 8 Octave */ 4186.01
         };    // note 88
 
        float period = 1/noteFrequencies[note];
        
        // Divide the period by two to get a square wave at the corrct frequency.
        wait(period/2.0f);
        _mySpeaker.write(!_mySpeaker.read());  // read the current _mySpeaker output and then toggle it.
        
        if(note>88)
            return 1;
        else
            return 0;
    }; //end of playNote