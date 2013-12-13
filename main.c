#include <msp430.h> 
#include "ADC_Library.h"
#include "Motor_Driver.h"
/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initADC();
	initRobot();
	int outputCenter;
	int outputRight;
	int outputLeft;
	moveRobotForward();  //start off moving forward
  	while (1) {

		if (outputCenter < 0x205 && outputLeft < 0x190) {  //nothing in front or to the left
			TA0CCR1 = 32; // default left speed
			moveRobotForward();
			_delay_cycles(1500);

		}
		outputCenter = readCenterSensor();
		outputRight = readRightSensor();
		outputLeft = readLeftSensor();

		if (outputLeft > 0x190) {
			TA0CCR1 = 39; //medium right turn
			turnRobotRight();
			_delay_cycles(2000);

		} else if (outputCenter > 0x205) {
			TA0CCR1 = 57; //sharp right turn
			turnRobotRight();
			_delay_cycles(2500);

		} else {  //if nothing there, set left motor to its default setting
			TA0CCR1 = 32;
		}

	}
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
	__bic_SR_register_on_exit(CPUOFF);
// Clear CPUOFF bit from 0(SR)
}
