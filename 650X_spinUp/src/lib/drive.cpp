/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       drive.cpp                                                 */
/*    Author:       NMS_RP                                                    */
/*    Created:      28 Nov 2022                                               */
/*    Description:  Operation control file for all driver functions           */
/*                  and thread calls                                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
using namespace vex;

//////////////////////////////////////////////////
//
// Set Motor Functions
//
//  - this sets motors between -12000 and 12000.  i'm used to
//  - -100 to 100, so the "scale" variable lets me use that as
//  - inputs and scales it to -12000 to 12000
//
////////////////////////////////////////////////////////////////////////////////

// Set voltage
const int SCALE = 120;
const int DEADBAND = 15;


// set drive voltage
void set_drive_pow(int l, int r) 
{
  LeftFront.spin(fwd, l * SCALE, voltageUnits::mV);
  LeftBack.spin(fwd, l * SCALE, voltageUnits::mV);
  RightFront.spin(fwd, r * SCALE, voltageUnits::mV);
  RightBack.spin(fwd, r * SCALE, voltageUnits::mV);
}

/*
// set tank drive control
void tank_drive()
{
  int l_joy = abs(Controller1.Axis3.value()) > DEADBAND ? Controller1.Axis3.value() : 0;
  int r_joy = abs(Controller1.Axis2.value()) > DEADBAND ? Controller1.Axis2.value() : 0;
  set_drive_pow(l_joy, r_joy);
}
*/

// set arcade drive control
void right_arcade_drive()
{
  // fwd Axis2 + Axis1
  int l_joy = abs(Controller1.Axis2.value() + Controller1.Axis1.value()) > DEADBAND ? Controller1.Axis2.value() + Controller1.Axis1.value() : 0;
  // turn Axis2 - Axis1
  int r_joy = abs(Controller1.Axis2.value() - Controller1.Axis1.value()) > DEADBAND ? Controller1.Axis2.value() - Controller1.Axis1.value() : 0;
  set_drive_pow(l_joy, r_joy);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** --- arcadeDrive_f is a callback function ---
  * Description:
  *   Function for arcade drive for right joystick. Function to be registered to a thread for continuous use.
  *   Function registered to thread arcadeDrive_t
  */
int arcadeDrive_f()
{
  int count = 0;
  while(true)
  {
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print("Arcade Drive has iterated %d times", count);
    count++;


    right_arcade_drive();
    /* You must sleep threads by using the 'this_thread::sleep_for(unit in
    msec)' command to prevent this thread from using all of the CPU's
    resources. */
    this_thread::sleep_for( 25 );
  }

  /* A threads's callback must return an int, even though the code will never
  get here. You must return an int here. Threads can exit, but this one does not. */
  return( 0 );
}