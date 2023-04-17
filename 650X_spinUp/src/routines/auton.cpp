/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       auton.cpp                                                 */
/*    Author:       NMS_RP                                                    */
/*    Created:      28 Nov 2022                                               */
/*    Description:  15-Second Autonomous Routines                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "inertialCalStats.h"
#include "operations.h"
using namespace vex;


/////////////////////////////////////////////////////////
//
// Auton 1: Red Far 1
// Objective(s): 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
void Auton_RF1(){
  Brain.Screen.newLine();
  Brain.Screen.setCursor(1,1);
  Brain.Screen.print("Auton Red Far #1 is running"); 

  
  // ...
  // ...
  // ...

  robotDrive.stop();          // program stop
  task::sleep(500);   
}

/////////////////////////////////////////////////////////
//
// Auton 2: Red Far 2
// Objective(s): 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
void Auton_RF2(){
  Brain.Screen.newLine();
  Brain.Screen.setCursor(1,1);
  Brain.Screen.print("Auton Red Far #2 is running"); 

  // ...
  // ...
  // ...

  robotDrive.stop();          // program stop
  task::sleep(500);   
}


/////////////////////////////////////////////////////////
//
// Auton 3: Red Near 1
// Objective(s): 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
void Auton_RN1(){
  Brain.Screen.newLine();
  Brain.Screen.setCursor(1,1);
  Brain.Screen.print("Auton Red Near #1 is running"); 

  // ...
  // ...
  // ...

  robotDrive.stop();          // program stop
  task::sleep(500);   

}


/////////////////////////////////////////////////////////
//
// Auton 4: Red Near 2
// Objective(s): 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
void Auton_RN2(){
  Brain.Screen.newLine();
  Brain.Screen.setCursor(1,1);
  Brain.Screen.print("Auton Red Near #2 is running"); 

  // ...
  // ...
  // ...

  robotDrive.stop();          // program stop
  task::sleep(500);   
}


/////////////////////////////////////////////////////////
//
// Auton 5: Blue Far 1
// Objective(s): ** EASY SCORE OPTION ** 
//               Start flywheel, shoot 2 disc to blue goal
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
void Auton_BF1(){
  Brain.Screen.newLine();
  Brain.Screen.setCursor(1,1);
  Brain.Screen.print("Auton Blue Far #1 is running"); 


  // ...
  // ...
  // ...

  
  task::sleep(500);   
}


/////////////////////////////////////////////////////////
//
// Auton 6: Blue Far 2
// Objective(s): 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
void Auton_BF2(){
  Brain.Screen.newLine();
  Brain.Screen.setCursor(1,1);
  Brain.Screen.print("Auton Blue Far #2 is running"); 

  // ...
  // ...
  // ...

  robotDrive.stop();          // program stop
  task::sleep(500);   
}


/////////////////////////////////////////////////////////
//
// Auton 7: Blue Near 1
// Objective(s): ** EASY SCORE OPTION ** 
//               Starting in Front in Roller, Roll fwd and capture roller for Blue color, 
//               turn left, position to shoot 2 disc to blue goal.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
void Auton_BN1(){
  Brain.Screen.newLine();
  Brain.Screen.setCursor(1,1);
  Brain.Screen.print("Auton Blue Near #1 is running"); 

  robotDrive.driveFor( forward, 10, inches, 5, rpm, false );
  robotDrive.driveFor( forward, 20, inches, 10, rpm, false );
  robotDrive.driveFor( forward, 50, inches, 20, rpm, false );
  robotDrive.driveFor( forward, 80, inches, 90, rpm, true ); 

  intakeAuton_DOWN( 90, 1500 ); // run intake for 1.5 sec backward to spit out disc into low goal area

  robotDrive.driveFor( reverse, 10, inches, 5, rpm, false );
  robotDrive.driveFor( reverse, 20, inches, 10, rpm, false );
  robotDrive.driveFor( reverse, 50, inches, 20, rpm, false );
  robotDrive.driveFor( reverse, 80, inches, 90, rpm, true ); 

  robotDrive.stop();

  // sleep thread to not hog CPU
  task::sleep(500);   
}


/////////////////////////////////////////////////////////
//
// Auton 8: Blue Near 2
// Objective(s): 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
void Auton_BN2(){
  Brain.Screen.newLine();
  Brain.Screen.setCursor(1,1);
  Brain.Screen.print("Auton Blue Near #2 is running"); 

  // ...
  // ...
  // ...

  robotDrive.stop();          // program stop
  task::sleep(500);   
}
