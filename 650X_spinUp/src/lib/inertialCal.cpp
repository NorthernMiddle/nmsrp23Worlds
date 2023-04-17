/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       inertialCal.cpp                                           */
/*    Author:       LoJac10                                                   */
/*    Created:      6 December 2022                                           */
/*    Description:  Module to Calibrate Inertial Sensor and Display Data      */
/*----------------------------------------------------------------------------*/

#include "vex.h"
using namespace vex;


/////////////////////////////////////////////
//
// Inertial Sensor Calibration & Stats Get Function
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void inertialStartCal() {
  DrivetrainInertial.calibrate();
}

int displayInertialStats_f(){
  
  inertial::quaternion  Inertial_quaternion;

  while(1) {
    // get the quaternion data
    Inertial_quaternion = DrivetrainInertial.orientation();
    
    // =================================
    // +++++ V5 Brain Screen Print +++++ 
    // =================================

    // Screen setup
    Brain.Screen.clearScreen(); 
    Brain.Screen.setFont( mono15 );
    Brain.Screen.setPenColor( white );
    Brain.Screen.setFillColor( black );
    
    // Heading 
    Brain.Screen.printAt( 20, 25, "Inertial Sensor Stats");
    Brain.Screen.newLine();

    Brain.Screen.printAt( 20,  30, "GX  %8.3f", DrivetrainInertial.gyroRate( xaxis, dps ) );    
    Brain.Screen.printAt( 20,  45, "GY  %8.3f", DrivetrainInertial.gyroRate( yaxis, dps ) );
    Brain.Screen.printAt( 20,  60, "GZ  %8.3f", DrivetrainInertial.gyroRate( zaxis, dps ) );
    Brain.Screen.newLine();

    Brain.Screen.printAt( 20,  90, "AX  %8.3f", DrivetrainInertial.acceleration( xaxis ) );
    Brain.Screen.printAt( 20, 105, "AY  %8.3f", DrivetrainInertial.acceleration( yaxis ) );
    Brain.Screen.printAt( 20, 120, "AZ  %8.3f", DrivetrainInertial.acceleration( zaxis ) );
    Brain.Screen.newLine();

    Brain.Screen.printAt( 20, 150, "A   %8.3f", Inertial_quaternion.a );
    Brain.Screen.printAt( 20, 165, "B   %8.3f", Inertial_quaternion.b );
    Brain.Screen.printAt( 20, 180, "C   %8.3f", Inertial_quaternion.c );
    Brain.Screen.printAt( 20, 195, "D   %8.3f", Inertial_quaternion.d );
    Brain.Screen.newLine();

    Brain.Screen.printAt( 150, 30, "Roll     %7.2f", DrivetrainInertial.roll() );
    Brain.Screen.printAt( 150, 45, "Pitch    %7.2f", DrivetrainInertial.pitch() );
    Brain.Screen.printAt( 150, 60, "Yaw      %7.2f", DrivetrainInertial.yaw() );
    Brain.Screen.newLine();

    Brain.Screen.printAt( 150, 90, "Heading  %7.2f", DrivetrainInertial.heading() );
    Brain.Screen.printAt( 150,105, "Rotation %7.2f", DrivetrainInertial.rotation() );
    Brain.Screen.newLine();
    Brain.Screen.newLine();

    // =========================================
    // +++++ Console/Terminal Screen Print +++++ 
    // =========================================

    // heading
    printf("Inertial Sensor Stats:\n");
    printf("\n");

    printf("gyro refresh rate x-axis: %8.3f\n", DrivetrainInertial.gyroRate( xaxis, dps ) );                 
    printf("gyro refresh rate y-axis: %8.3f\n", DrivetrainInertial.gyroRate( yaxis, dps ) );
    printf("gyro refresh rate z-axis: %8.3f\n", DrivetrainInertial.gyroRate( zaxis, dps ) );
    printf("\n");

    printf("gyro accel x-axis: %8.3f\n", DrivetrainInertial.acceleration( xaxis ) );
    printf("gyro accel y-axis: %8.3f\n", DrivetrainInertial.acceleration( yaxis ) );
    printf("gyro accel z-axis: %8.3f\n", DrivetrainInertial.acceleration( zaxis ) );
    printf("\n");

    printf("inertial quaternion: A  %8.3f\n", Inertial_quaternion.a);
    printf("inertial quaternion: B  %8.3f\n", Inertial_quaternion.b);
    printf("inertial quaternion: C  %8.3f\n", Inertial_quaternion.c);
    printf("inertial quaternion: D  %8.3f\n", Inertial_quaternion.d);
    printf("\n");

    printf("Roll    %7.2f\n", DrivetrainInertial.roll() );
    printf("Pitch   %7.2f\n", DrivetrainInertial.pitch() );
    printf("Yaw     %7.2f\n", DrivetrainInertial.yaw() );
    printf("\n");
    
    printf("gyro Heading %7.2f\n", DrivetrainInertial.heading() );
    printf("gyro Rotation %7.2f\n", DrivetrainInertial.rotation() );
    printf("\n");
    printf("\n");

    if( DrivetrainInertial.isCalibrating())
    {
      Brain.Screen.printAt( 20, 225, "Calibration for Inertial Sensor for Drivetrain In Progress" );
    }
    else
    {
      Brain.Screen.printAt( 20,225, "Calibration  Done" );
    }

    Brain.Screen.render();

    // You must sleep threads by using the 'this_thread::sleep_for(unit in
    // msec)' command to prevent this thread from using all of the CPU's
    // resources.
    this_thread::sleep_for( 25 );
  }

  /* A threads's callback must return an int, even though the code will never
  get here. You must return an int here. Threads can exit, but this one does not. */
  return( 0 );
}