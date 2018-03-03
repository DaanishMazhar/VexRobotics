#pragma config(Motor,  port1,           backRightMotor, tmotorVex393HighSpeed_HBridge, openLoop, reversed, driveRight)
#pragma config(Motor,  port2,           frontRightMotor, tmotorVex393HighSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port3,           rightLiftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           mobileGoal,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightChainBar, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           goliathIntake, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftChainBar,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           leftLiftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           frontLeftMotor, tmotorVex393HighSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port10,          backLeftMotor, tmotorVex393HighSpeed_HBridge, openLoop, driveLeft)

task main()
{
			while(1 == 1){
		//Drive Train
		motor[frontRightMotor] = vexRT[Ch2];		//Front Right Wheel
		motor[backRightMotor]  = vexRT[Ch2];		//Back Right Wheel
		motor[frontLeftMotor] = vexRT[Ch3];			//Front Left Wheel
		motor[backLeftMotor]  = vexRT[Ch3];			//Back Left Wheel

		//Mobile Goal Intake
		if(vexRT[Btn7R] == 1)       	//If button 6U is pressed...
		{
			motor[mobileGoal] = 127;		//...raise the arm.
		}
		else if(vexRT[Btn7D] == 1)  	//Else, if button 6D is pressed...
		{
			motor[mobileGoal] = -127;		//...lower the arm.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[mobileGoal] = 0;			//...stop the arm.
		}
		//Chainbar Movement
		if(vexRT[Btn6U] == 1)       	//If button 6U is pressed...
		{
			motor[rightChainBar] = 127;
			motor[leftChainBar] = -127;//...raise the arm.
		}
		else if(vexRT[Btn6U] == 1)  	//Else, if button 6D is pressed...
		{
			motor[leftChainBar] = 127;
			motor[rightChainBar] = -127;//...lower the arm.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[leftChainBar] = 0;
			motor[rightChainBar] = 0;			//...stop the arm.
		}
		//Goliath
		if(vexRT[Btn8D] == 1)
		{
			motor[goliathIntake] = -127;
		}
		else if(vexRT[Btn8L] == 1)
		{
			motor[goliathIntake] = 127;
		}
		else
		{
			motor[goliathIntake] = 0;
		}
		//Double Reverse 4 Bar Lift
		if(vexRT[Btn5U] == 1)								//If button 5U is pressed...
		{
			motor[rightLiftMotor] = 127;			//...raise the lift.
			motor[leftLiftMotor] = -127;
		}
		else if(vexRT[Btn5D] ==1)						//Else, if button 5D is pressed...
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
