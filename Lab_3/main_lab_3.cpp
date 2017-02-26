#include "mbed.h"
#include "Music.h"
#include "AnalogIn.h"

/*! Main class.
 *  Creates an instance of the Music class, and then connects it to an output, which should
 *  be connected to a small speaker.
 * \author  Alex Hale
 *
 * \date    August 14th, 2016
 */

//#define  STARTING_NOTE      80

AnalogIn readVoltage(A0);
//DigitalOut mySpeaker(D0);

int main()
{
    Music myMusic(D0);
    
    while (true) {
        //myMusic.playNote(int(readValue.read()));
        myMusic.playNote(readVoltage.read()*80.f);
    }//end of while
}//end of main
