/** www.elegoo.com */
/** 2016.12.12 */

#include "Stepper.h"
#include "IRremote.h"

/*----- Variables, Pins -----*/
#define STEPS  32   /** Number of steps per revolution of Internal shaft */
int  Steps2Take;  /** 2048 = 1 Revolution */
int receiver = 12; /** Signal Pin of IR receiver to Arduino Digital Pin 6 */

/*-----( Declare objects )-----*/
/** Setup of proper sequencing for Motor Driver Pins */
/** In1, In2, In3, In4 in the sequence 1-3-2-4 */

Stepper small_stepper(STEPS, 8, 10, 9, 11);
IRrecv irrecv(receiver);    /** create instance of 'irrecv' */
decode_results results;     /** create instance of 'decode_results' */

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); /** Start the receiver */
}

void loop()
{
  /** have we received an IR signal? */
  if (irrecv.decode(&results)) {

    Serial.println(results.value, HEX);

    switch (results.value) {

      case 0xFFA25D: /** Power */
        break;

      case 0xFFE21D: /** Func/Stop */
        break;

      case 0xFF22DD: /** Backward */
        break;

      case 0xFF02FD: /** Play/Pause */
        break;

      case 0xFFC23D: /** Forward */
        break;

      case 0xFFA857: /** Volume Up */
        break;

      case 0xFF629D: /** Volume Down */
        break;

      case 0xFF906F: /** Up */
        break;

      case 0xFFE01F: /** Down */
        break;

      case 0xFF9867: /** EQ */
        break;

      case 0xFFB04F: /** Repeat */
        break;

      case 0xFF6897: /** 0 */
        Serial.println("0 Pressed");
        small_stepper.setSpeed(500); /** Max seems to be 500 */
        Steps2Take = 2048;  /** Rotate Clockwise */
        small_stepper.step(Steps2Take);
//        delay(1000);
        break;

      case 0xFF30CF: /** 1 */
        break;

      case 0xFF18E7: /** 2 */
        break;

      case 0xFF7A85: /** 3 */
        break;

      case 0xFF10EF: /** 4 */
        break;

      case 0xFF38C7: /** 5 */
        break;

      case 0xFF5AA5: /** 6 */
        break;

      case 0xFF42BD: /** 7 */
        break;

      case 0xFF4AB5: /** 8 */
        break;

      case 0xFF52AD: /** 9 */
        Serial.println("9 Pressed");
        small_stepper.setSpeed(500);
        Steps2Take = -2048;  /** Rotate Counter Clockwise */
        small_stepper.step(Steps2Take);
//        delay(1000);
        break;

    }

    /** Receive the next value */
    irrecv.resume();
    /** Stop Motor */
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }


}/* --end main loop -- */
