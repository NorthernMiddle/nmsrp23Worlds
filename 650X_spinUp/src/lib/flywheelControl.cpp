/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       flywheelControl.cpp                                        */
/*    Author:       LoJac10                                                   */
/*    Created:      6 December 2022                                           */
/*    Description:  Module to control flywheel                                */
/*----------------------------------------------------------------------------*/

/*
motor_group Flywheel = motor_group(Fly1, Fly2);
bool maintainSpeed = false;
double targetspeed = 600;

double kp = 0.5;    // error rate of proportion
double ki = 0.10;   // error rate of integral
double kd = 0.05;   // error rate of derivative

double preverror = 0.0;
double error = 0.0;
double totalError = 0.0; // += error
double derivative = 0.0; // = error-preverror
double flyspeed;
double Power = 0;

bool ReadyShoot = false;
int FlyPID(){
  while(maintainSpeed){
    flyspeed = (Fly1.velocity(rpm) + Fly2.velocity(rpm))/2; 
    error = targetspeed - flyspeed;
    if (error <= 0.1){
      ReadyShoot = true;
    }
    else{
      ReadyShoot = false;
    }
    
    Power = (error*kp + totalError * ki + (error - preverror) * kd)/12;
    Flywheel.spin(forward, Power, volt);
    
    preverror = error;
    totalError += error;
    
    vex::task::sleep(20);
  }
  return true;
}
*/