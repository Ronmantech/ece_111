#include "mbed.hpp"
/*! Music class.
 *  Used for playing musical notes with the FRDM-KL46Z.
 */



class Music
{
public:
    /**
     * @param mySpeaker selects a DigitalOut to toggle at the selected frequency (in Music.h).
     */
    Music(PinName mySpeaker);
    
    /**
     * @param There is no parameter for this deconstructor.
     */
    ~Music(void);
    
    /**
     * @param note plays a note from the standard piano.
     * Input notes range from 1 to 88.
     * Set to zero to turn off the note.
     * Sourced from: https://en.wikipedia.org/wiki/Piano_key_frequencies
     * @returns
     *   1 on success.
     *   0 on error, typically outside of the max range of 88.
     */
    int playNote(int note);
    
private:
    DigitalOut _mySpeaker;  //This is the private DigitalOut that toggles
    //the output connect to the speaker.
}; //end of Music class
