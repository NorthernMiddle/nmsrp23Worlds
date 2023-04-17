using namespace vex;

// brain
extern brain Brain;

//////////////////////
//
// VEX Code Devices
//
//////////////////////

// controller
extern controller Controller1;

// sensors
extern optical rollerOptical;
extern rotation rotationSensor;
extern inertial DrivetrainInertial;

// motors
extern motor LeftFront;
extern motor LeftBack;
extern motor RightFront;
extern motor RightBack;
extern motor Indexer;
extern motor Intake;
extern motor Flywheel1;

// motor groups
extern motor_group LeftSide;
extern motor_group RightSide;

// drivetrain
extern smartdrive robotDrive;



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );