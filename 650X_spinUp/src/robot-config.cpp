#include "vex.h"
#include "inertialCalStats.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// controller
controller Controller1 = controller(primary);

// sensors
inertial DrivetrainInertial = inertial(PORT18);

// motors
motor LeftFront = motor(PORT1, ratio6_1, true);
motor LeftBack = motor(PORT10, ratio6_1, true);
motor RightFront = motor(PORT11, ratio6_1, false);
motor RightBack = motor(PORT19, ratio6_1, false);
motor Indexer = motor(PORT12, ratio36_1, false);
motor Intake = motor(PORT2, ratio6_1, false);
motor Flywheel1 = motor(PORT16, ratio6_1, false);

// grouping
motor_group LeftSide = motor_group(LeftFront, LeftBack);
motor_group RightSide = motor_group(RightFront, RightBack);

// constants
const double wheelTravel = 299.24; // 3.25-in wheels
const double trackWidth = 349.25;  // 13.75-inches
const double wheelBase = 241.30;   // 9.5-inches
const double gearRatio = 0.5;     // 36:72 --> 1:2

// drivetrain
smartdrive robotDrive = smartdrive(LeftSide, RightSide, DrivetrainInertial, wheelTravel, trackWidth, wheelBase, distanceUnits::mm, gearRatio);




// VEXcode generated functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);

  // calibrate the drivetrain Inertial
  wait(200, msec);
  inertialStartCal();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while ( DrivetrainInertial.isCalibrating() == true ) 
  {
    displayInertialStats_f();
    wait(25, msec);
  }

  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}