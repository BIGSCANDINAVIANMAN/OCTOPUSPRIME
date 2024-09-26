/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       zhang769641                                               */
/*    Created:      22/09/2024, 16:31:55                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void)
{

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void)
{
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       zhang769641                                               */
/*    Created:      18/09/2024, 11:53:52                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;

// define your global instances of motors and other devices here
motor frontLeft = motor(19);
motor frontRight = motor(16, true);
motor backLeft = motor(20);
motor backRight = motor(9, true);
motor_group allWheels = motor_group(frontLeft, frontRight, backLeft, backRight);
controller Controller1 = controller(primary);

void usercontrol(void)
{
  double rx = Controller1.Axis1.position(percent);
  double ry = Controller1.Axis2.position(percent);
  double lx = Controller1.Axis4.position(percent);
  double ly = Controller1.Axis3.position(percent);

  while (1)
  { // hi heny
    double velocity1 = sqrt(2) / 2 * (ry - rx);
    double velocity2 = sqrt(2) / 2 * (ry + rx);

    frontLeft.setVelocity(velocity1, percent);
    backRight.setVelocity(velocity1, percent);

    frontRight.setVelocity(velocity2, percent);
    backLeft.setVelocity(velocity2, percent);

    allWheels.spin(forward);
  }
}

int main()
{
  while (1)
  {

    // Allow other tasks to run
    this_thread::sleep_for(10);
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, msec);
  }
}
