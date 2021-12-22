/** www.elegoo.com */
/** 2016.12.12 */

#include "Stepper.h"
#include "IRremote.h"

/*----- Variables, Pins -----*/
#define STEPS  32   /** Number of steps per revolution of Internal shaft */
int  step2take;  /** 2048 = 1 Revolution */
int  angle2take;  /** 360 = 1 Revolution */
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
        Serial.println("Power Pressed");
        break;

      case 0xFFE21D: /** Func/Stop */
        Serial.println("Func/Stop Pressed");
        break;

      case 0xFF22DD: /** Backward */
        Serial.println("Backward Pressed");
        break;

      case 0xFF02FD: /** Play/Pause */
        Serial.println("Play/Pause Pressed");
        break;

      case 0xFFC23D: /** Forward */
        Serial.println("Forward Pressed");
        break;

      case 0xFF629D: /** Volume Up */
        Serial.println("Volume Up Pressed");
        break;

      case 0xFFA857: /** Volume Down */
        Serial.println("Volume Down Pressed");
        break;

      case 0xFF906F: /** Up */
        Serial.println("Up Pressed");
        break;

      case 0xFFE01F: /** Down */
        Serial.println("Down Pressed");
        break;

      case 0xFF9867: /** EQ */
        Serial.println("EQ Pressed");
        break;

      case 0xFFB04F: /** Repeat */
        Serial.println("Repeat Pressed");
        break;

      case 0xFF6897: /** 0 */
        Serial.println("0 Pressed");
        small_stepper.setSpeed(500); /** Max seems to be 500 */
//        step2take = 2048;  /** Rotate Clockwise */
//        small_stepper.step(step2take);
        angle2take = 360;  /** Rotate Clockwise */
        small_stepper.angle(angle2take);
//        delay(1000);
        break;

      case 0xFF30CF: /** 1 */
        Serial.println("1 Pressed");
        small_stepper.setSpeed(500); /** Max seems to be 500 */
//        step2take = 1024;  /** Rotate Clockwise */
//        small_stepper.step(step2take);
        angle2take = 180;  /** Rotate Clockwise */
        small_stepper.angle(angle2take);
        break;

      case 0xFF18E7: /** 2 */
        Serial.println("2 Pressed");
        break;

      case 0xFF7A85: /** 3 */
        Serial.println("3 Pressed");
        break;

      case 0xFF10EF: /** 4 */
        Serial.println("4 Pressed");
        break;

      case 0xFF38C7: /** 5 */
        Serial.println("5 Pressed");
        break;

      case 0xFF5AA5: /** 6 */
        Serial.println("6 Pressed");
        break;

      case 0xFF42BD: /** 7 */
        Serial.println("7 Pressed");
        break;

      case 0xFF4AB5: /** 8 */
        Serial.println("8 Pressed");
        small_stepper.setSpeed(500); /** Max seems to be 500 */
//        step2take = -1024;  /** Rotate Clockwise */
//        small_stepper.step(step2take);
        angle2take = -180;  /** Rotate Clockwise */
        small_stepper.angle(angle2take);
        break;

      case 0xFF52AD: /** 9 */
        Serial.println("9 Pressed");
        small_stepper.setSpeed(500);
//        step2take = -2048;  /** Rotate Counter Clockwise */
//        small_stepper.step(step2take);
        angle2take = -360;  /** Rotate Clockwise */
        small_stepper.angle(angle2take);
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
