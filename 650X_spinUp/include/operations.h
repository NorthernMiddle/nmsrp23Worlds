/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       inertialCalStats.h                                        */
/*    Author:       LoJac10                                                   */
/*    Date:         9 December 2022                                           */
/*    Description:  module to calibrate inertial sensor and display stats     */
/*                                                                            */
/*----------------------------------------------------------------------------*/


////////////////////////////////////////////////////////////////
//
// function prototype for operation functions for both autonomous and driver control
//
/////////////////////////////////////////////////////////////////////////////////////////

  // function prototypes for thread calls for driver period
  void set_flywheel(int input);
  int flywheel_f(); 
  int intake_f();
  int indexer_f();

  // function prototypes for autonomous period
  void intakeAuton_UP( int I, int runTime );
  void intakeAuton_DOWN( int I, int runTime );
  void flywheelShoot( int I, int runTime );
  int roller();
