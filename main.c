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
	moveRobotForward();
	while (1) {

		if (outputCenter < 0x205 && outputLeft < 0x190) {
			TA0CCR1 = 32;
			moveRobotForward();
			_delay_cycles(1500);

		}
		outputCenter = readCenterSensor();
		outputRight = readRightSensor();
		outputLeft = readLeftSensor();

		if (outputLeft > 0x190) {
			TA0CCR1 = 39;
			turnRobotRight();
			_delay_cycles(2000);

		} else if (outputCenter > 0x205) {
			TA0CCR1 = 57;
			turnRobotRight();
			_delay_cycles(2500);

		} else {
			TA0CCR1 = 32;
		}
//			else if (outputRight < 0x320) {
//			turnRobotRight(10000);
//			_delay_cycles(10000);
//		}
	}
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
	__bic_SR_register_on_exit(CPUOFF);
// Clear CPUOFF bit from 0(SR)
}
