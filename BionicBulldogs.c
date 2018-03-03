#pragma config(Motor,  port1,           backRightMotor, tmotorVex393HighSpeed_HBridge, openLoop, reversed, driveRight)
#pragma config(Motor,  port2,           frontRightMotor, tmotorVex393HighSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port3,           rightLiftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           mobileGoal,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           fourBar, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           goliathIntake, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftChainBar,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           leftLiftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           frontLeftMotor, tmotorVex393HighSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port10,          backLeftMotor, tmotorVex393HighSpeed_HBridge, openLoop, driveLeft)
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

void driveMode(){
	while (1==1){
		///Drive Train
		motor[frontRightMotor] = vexRT[Ch2];		//Front Right Wheel
		motor[backRightMotor]  = vexRT[Ch2];		//Back Right Wheel
		motor[frontLeftMotor] = vexRT[Ch3];			//Front Left Wheel
		motor[backLeftMotor]  = vexRT[Ch3];			//Back Left Wheel

		//Mobile Goal Intake
		if(vexRT[Btn7D] == 1)       	//If button 7R is pressed...
		{
			motor[mobileGoal] = 127;		//...pick up mobile goal
		}
		else if(vexRT[Btn7R] == 1)  	//Else, if button 7D is pressed...
		{
			motor[mobileGoal] = -127;		//...lower mobile goal
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[mobileGoal] = 0;			//...stop the mobile goal.
		}
		//4 bar Movement
if(vexRT[Btn6U] == 1)
		{
			motor[fourBar] = -127;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[fourBar] = 127;
		}
		else
		{
			motor[fourBar] = 0;
		}
		//Goliath
		if(vexRT[Btn8D] == 1)
		{
			motor[goliathIntake] = -127; //pick up cone
		}
		else if(vexRT[Btn8R] == 1)
		{
			motor[goliathIntake] = 127; // drop cone
		}
		else
		{
			motor[goliathIntake] = 0; //stop goliath
		}
		//Double Reverse 4 Bar Lift

		if(vexRT[Btn5D] == 1)								//If button 5U is pressed...
		{
			motor[rightLiftMotor] = 127;			//...raise the lift.
			motor[leftLiftMotor] = -127;
		}
		else if(vexRT[Btn5U] ==1)						//Else, if button 5D is pressed...
		{
			motor[rightLiftMotor] = -127;			//...lower the lift.
			motor[leftLiftMotor] = 127;
		}
		else																//Else (neither button is pressed)...
		{
			motor[rightLiftMotor] = 0;				//...stop the lift.
			motor[leftLiftMotor] = 0;
		}


	}
}
	void stackAutomation(){
		while(1 == 1){
			//Arcade Drive Trade
			motor[backLeftMotor]= vexRT[Ch3Xmtr2] - vexRT[Ch1Xmtr2];
			motor[frontLeftMotor]= vexRT[Ch3Xmtr2] - vexRT[Ch1Xmtr2];
			motor[backRightMotor]= vexRT[Ch3Xmtr2] + vexRT[Ch1Xmtr2];
			motor[frontRightMotor]= vexRT[Ch3Xmtr2] + vexRT[Ch1Xmtr2];

			//Double Reverse 4 Bar Lift
		if(vexRT[Btn5D] == 1)								//If button 5U is pressed...
		{
			motor[rightLiftMotor] = 127;			//...raise the lift.
			motor[leftLiftMotor] = -127;
		}
		else if(vexRT[Btn5U] ==1)						//Else, if button 5D is pressed...
		{
			motor[rightLiftMotor] = -127;			//...lower the lift.
			motor[leftLiftMotor] = 127;
		}
		else																//Else (neither button is pressed)...
		{
			motor[rightLiftMotor] = 0;				//...stop the lift.
			motor[leftLiftMotor] = 0;
		}


	}
}
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	/*---------------------------------------------------------------------------*/
	/*                          Pre-Autonomous Functions                         */
	/*                                                                           */
	/*  You may want to perform some actions before the competition starts.      */
	/*  Do them in the following function.  You must return from this function   */
	/*  or the autonomous and usercontrol tasks will not be started.  This       */
	/*  function is only called once after the cortex has been powered on and    */
	/*  not every time that the robot is disabled.                               */
	/*---------------------------------------------------------------------------*/

	void pre_auton()
	{
		// Set bStopTasksBetweenModes to false if you want to keep user created tasks
		// running between Autonomous and Driver controlled modes. You will need to
		// manage all user created tasks if set to false.
		bStopTasksBetweenModes = true;

		// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
		// used by the competition include file, for example, you might want
		// to display your team name on the LCD in this function.
		// bDisplayCompetitionStatusOnLcd = false;

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

	task autonomous()
	{
		// ..........................................................................
		// Insert user code here.
		// ..........................................................................

		// Remove this function call once you have "real" code.
		AutonomousCodePlaceholderForTesting();
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
	task usercontrol()
	{
		while(1 == 1){
			bool currentMode = true;

			if(vexRT[Btn7U] == 1){
				currentMode = (!currentMode);
				switch(currentMode)
				{
				case true:
					driveMode();
					break;
				case false:
					stackAutomation();
					break;
				default:
					driveMode();
				}
			}
		}
	}
