/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       LoJac10                                                   */
/*    Created:      17th Nov 2022                                             */
/*    Description:  Competition VRC Template for 650X "Xray". Template        */
/*                  includes options to select autonomous programs using      */
/*                  Jpearman 'buttons' & 'autonSelect' module.                */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                       
// LFmotor              motor         1
// LBmotor              motor         10 
// RFmotor              motor         11
// RBmotor              motor         19   
// Flywheel1            motor         8                          
// Indexer              motor         7
// Intake               motor         2   
// Inertial Sensor      sensor        3        
// Drivetrain           drivetrain    1, 10, 11, 19      
// ---- END VEXCODE CONFIGURED DEVICES ----

// ----| START CONTROLS INFO |----
// L1 Intake In
// L2 Intake Out
// R1 Indexer
// R2 Flywheel Control
// Tank Drive
// ----| END CONTROLS INFO |----


// VEX V5 C++ Project
#include "vex.h"
#include "auton.h"
#include "skills.h"
#include "operations.h"
#include "drive.h"

using namespace vex;

// A global instance of competition
competition Competition;

// state variable for alliance status
// 0 --> RED ALLIANCE 1--> BLUE ALLIANCE
int allianceStatus;

// state variable for autonomous selection
int autonomousProgramSelection = 0;

// state variable for escape from auton selection operation
// int manual_mode = false;

// collect data for on screen button
typedef struct _button 
{
    int    xpos;
    int    ypos;
    int    width;
    int    height;
    bool   state;
    vex::color color;
    const char *label;
} button;

// hexidecimal color variables
int hex_Red = 0xE00000;     // red HEX color        /* used for Red Autonomous Selection */
int hex_Blue = 0x0000E0;    // blue HEX color       /* used for Blue Autonomous Selection */
int hex_Green = 0x2228c22;  // green HEX color      /* used to indicate most reliable (MONEY) Autonomous Selection */

// Button definitions
button buttons[] = 
{
  // Red Auton Programs
  {   30,  30, 60, 60,  false, hex_Red, "RF1" },   // Red Far 1 Auton Program #1
  {  150,  30, 60, 60,  false, hex_Red, "RF2" },   // Red Far 2 Auton Program #2
  {  270,  30, 60, 60,  false, hex_Red, "RN1" },   // Red Near 1 Auton Program #3
  {  390,  30, 60, 60,  false, hex_Red, "RN2" },   // Red Near 2 Auton Program #4
  // Blue Auton Programs
  {   30, 150, 60, 60,  false, hex_Blue, "BF1" },   // Blue Far 1 Auton Program #5
  {  150, 150, 60, 60,  false, hex_Blue, "BF2" },   // Blue Far 2 Auton Program #6
  {  270, 150, 60, 60,  false, hex_Blue, "BN1" },   // Blue Near 1 Auton Program #7
  {  390, 150, 60, 60,  false, hex_Blue, "BN2" }    // Blue Near 2 Auton Program #8
};

/*-----------------------------------------------------------------------------*/
/** @brief      Check if touch is inside button                                */
/*-----------------------------------------------------------------------------*/
int findButton(  int16_t xpos, int16_t ypos ) 
{
  int nButtons = sizeof(buttons) / sizeof(button);

  for( int index=0; index < nButtons; index++) 
  {
    button *pButton = &buttons[ index ];
    if( xpos < pButton->xpos || xpos > (pButton->xpos + pButton->width) )
      continue;

    if( ypos < pButton->ypos || ypos > (pButton->ypos + pButton->height) )
      continue;
    
    return(index);
  }
  return (-1);
}

/*-----------------------------------------------------------------------------*/
/** @brief      Init button states                                             */
/*-----------------------------------------------------------------------------*/
void initButtons() 
{
  int nButtons = sizeof(buttons) / sizeof(button);

  for( int index=0; index < nButtons; index++) 
  {
    buttons[index].state = false;
  }
}

/*-----------------------------------------------------------------------------*/
/** @brief      Draw all buttons                                               */
/*-----------------------------------------------------------------------------*/
void displayButtonControls( int index, bool pressed ) 
{
  // variable for color
  color c;
    
  // used to outline buttons and write labels  
  Brain.Screen.setPenColor( color( white ) );    

  for( int i=0; i<sizeof(buttons)/sizeof(button); i++ ){
    if( buttons[i].state )
      c = buttons[i].color;
    else
      c = vex::color::black;

    Brain.Screen.setFillColor( c );

    // button fill
    if( i == index && pressed == true ){
      c = c + 0x404040; /* colors button from black (unselected) to gray (transition color) 
      for sec after touch until selection color is loaded into button after selection */
      Brain.Screen.drawRectangle( buttons[i].xpos, buttons[i].ypos, buttons[i].width, buttons[i].height, c );
    }
    else{
      Brain.Screen.drawRectangle( buttons[i].xpos, buttons[i].ypos, buttons[i].width, buttons[i].height );
    }
    // outline
    Brain.Screen.drawRectangle( buttons[i].xpos, buttons[i].ypos, buttons[i].width, buttons[i].height, color::transparent );

    // draw label
    if(  buttons[i].label != NULL )
      Brain.Screen.printAt( buttons[i].xpos + 5, buttons[i].ypos + buttons[i].height - 5, buttons[i].label );
  }
}

/*-----------------------------------------------------------------------------*/
/** @brief      Screen has been touched                                        */
/*-----------------------------------------------------------------------------*/
void userTouchCallbackPressed()
{
  int index;
  int xpos = Brain.Screen.xPosition();
  int ypos = Brain.Screen.yPosition();
  
  if( (index = findButton( xpos, ypos )) >= 0 ) 
  {
    displayButtonControls( index, true );
  }
}

/*-----------------------------------------------------------------------------*/
/** @brief      Screen has been (un)touched                                    */
/*-----------------------------------------------------------------------------*/
void userTouchCallbackReleased() 
{
  int index;
  int xpos = Brain.Screen.xPosition();
  int ypos = Brain.Screen.yPosition();
  
  if( (index = findButton( xpos, ypos )) >= 0 ) 
  {
    // clear all buttons to false, ie. unselected
    initButtons();

    // now set this one as true
    buttons[index].state = true;
    
    // save as auton selection
    autonomousProgramSelection = index;
    
    displayButtonControls( index, false );
  }
}

///////////////////////////////////////////////////////////////////
//
// ++++ Pre-Autonomous Functions  ++++ 
//
//  You may want to perform some actions before the      
//  competition starts. Do them in the following function.  
//  You must return from this function or the autonomous and        
//  usercontrol tasks will not be started.  This function is        
//  only called once after the V5 has been powered on and not 
//  every time that the robot is disabled.
//
////////////////////////////////////////////////////////////////////////////

void pre_auton(void) 
{
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

  vexcodeInit();  // Initializing Robot Configuration. DO NOT REMOVE!
  //calibrateInertialSensor();
  

  
}

/////////////////////////////////////////////////////////////
//
// ++++ Autonomous Task  ++++ 
//
//  This task is used to control your robot during the 
//  autonomous phase of a VEX Competition.       
//                              
//  You must modify the code to add your own robot specific 
//  commands here.
//
//////////////////////////////////////////////////////////////////////////////////////

void autonomous( void ) {
  int count = 0;
  while( true )
  {
    if( autonomousProgramSelection < 0 )
      Brain.Screen.printAt( 60,  125, "Auton not selected  " );
    else
      Brain.Screen.printAt( 60,  125, "Auton %d Running %5d", autonomousProgramSelection, count++ );
   switch( autonomousProgramSelection )
   {
           
    // Red Far 1 Auton Program       
    case 0:
      Auton_RF1();
      break;
           
    // Red Far 2 Auton Program       
    case 1:
      Auton_RF2();
      break;
           
    // Red Near 1 Auton Program       
    case 2:
      Auton_RN1();
      break;
           
    // Red Near 2 Auton Program       
    case 3:
      Auton_RN2();
      break;
    
    // Blue Far 1 Auton Program        
    case 4:
      Auton_BF1();
      break;
   
    // Blue Far 2 Auton Program       
    case 5:
      Auton_BF2();
      break;
    
    // Blue Near 1 Auton Program       
    case 6:
      Auton_BN1();
      break;
    
    // Blue Near 2 Auton Program 
    case 7:
      Auton_BN2();
      break; 
           
    }
      
    break;
  }
}

/////////////////////////////////////////////////////////////
//
//  ++++ User Control Task  ++++ 
//
//  This task is used to control your robot during the 
//  user control phase of a VEX Competition. 
//
//  You must modify the code to add your own robot specific commands here. 
//
//////////////////////////////////////////////////////////////////////////////////////

// This is the main execution loop for the user control program.
// Each time through the loop your program should update motor + servo
// values based on feedback from the joysticks.

// ........................................................................
// Insert user code here. This is where you use the joystick values to
// update your motors, etc.
// ........................................................................

void usercontrol(void) 
{
  Brain.Screen.clearScreen();
    
  // User control code here, inside the loop
  while ( true ) 
  {

    thread(drive_t) = thread(arcadeDrive_f);     // thread call to DRIVE FUNCTION
    thread(intake_t) = thread(intake_f);         // thread call to INTAKE FUNCTION
    thread(indexer_t) = thread(indexer_f);       // thread call to INDEXER FUNCTION
    thread(flywheel_t) = thread(flywheel_f);     // thread call to FLYWHEEL FUNCTION
    // ...
    // thread call name indicates mechanism #... for game specific usages
    // thread xxx_t = thread(xxxx_f);
    
    // sleep threads. Allow other tasks to run
    task::sleep( 100 ); 
  }

}

////////////////////////////////////////////////////////////////
//
//    --++| Main |++--
//
//    Main will set up the competition functions and callbacks.
//
//////////////////////////////////////////////////////////////////////////////////////

int main() 
{
  
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

    // run the pre-auton program
    // pre_auton();

    // register events
    Brain.Screen.pressed( userTouchCallbackPressed );
    Brain.Screen.released( userTouchCallbackReleased );
    
    // background
    Brain.Screen.setFillColor( vex::color(0x400000) );
    Brain.Screen.setPenColor( vex::color(0x400000) );
    Brain.Screen.drawRectangle( 0, 0, 480, 120 );
    Brain.Screen.setFillColor( vex::color(0x000040) );
    Brain.Screen.setPenColor( vex::color(0x000040) );
    Brain.Screen.drawRectangle( 0, 120, 480, 120 );

    // initial display
    displayButtonControls( 0, false );
    
    while( true ) {
      // Allow other tasks to run
      if( !Competition.isEnabled() )
        Brain.Screen.printAt( 60,  125, "Disabled. Make Auton Selection.        " );
      this_thread::sleep_for( 25 );
    }
}