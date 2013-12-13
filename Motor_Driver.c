/*
 * Motor_Driver.c
 *
 *  Created on: Nov 20, 2013
 *      Author: Administrator
 */

#include <msp430.h>
#include "Motor_Driver.h"
void initRobot() {

	P1DIR |= BIT1;                // TA0CCR1 on P1.1
	P1SEL |= BIT1;                // TA0CCR1 on P1.1
	P1DIR |= BIT2;                // TA0CCR1 on P1.2
	P1SEL |= BIT2;                // TA0CCR1 on P1.2
	P2DIR |= BIT1;                // TA0CCR1 on P1.2
	P2SEL |= BIT1;                // TA0CCR1 on P1.2
	P2DIR |= BIT0;                // TA0CCR1 on P1.2
	P2SEL |= BIT0;                // TA0CCR1 on P1.2

	TA0CTL &= ~MC1 | MC0;
	TA1CTL &= ~MC1 | MC0;

	TA0CTL |= TACLR;                // clear timer A0
	TA1CTL |= TACLR;                // clear timer A0

	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA1CTL |= TASSEL1;           // configure for SMCLK

	TA0CCR0 = 100;
	TA0CCR1 = 32;
	TA1CCR0 = 100;
	TA1CCR1 = 33;

	TA0CCTL1 &= ~OUTMOD_5;
	TA0CCTL0 &= ~OUTMOD_5;
	TA1CCTL1 &= ~OUTMOD_5;
	TA1CCTL0 &= ~OUTMOD_5;

	TA0CTL |= MC0;
	TA1CTL |= MC0;               // count up

}

void leftMotorForward() {
	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;

	TA0CCTL0 |= OUTMOD_5;
	TA0CCTL1 |= OUTMOD_7;

	TA0CTL |= MC0; // count up
	TA1CTL |= MC0;
}

void leftMotorReverse() {
	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;

	TA0CCTL0 &= ~OUTMOD_4;
	TA0CCTL0 &= ~OUTMOD_5;
	TA0CCTL1 &= ~OUTMOD_7;
	TA0CCTL1 &= ~OUTMOD_5;

	TA0CCTL0 |= OUTMOD_4;  //reset/set mode
	TA0CCTL1 |= OUTMOD_5;

	TA0CTL |= MC0; // count up
	TA1CTL |= MC0;
}

void leftMotorStop() {
	TA0CCTL1 &= ~(OUTMOD_5);
	TA0CCTL0 &= ~(OUTMOD_5);
}

void rightMotorStop() {
	TA1CCTL1 &= ~(OUTMOD_5);
	TA1CCTL0 &= ~(OUTMOD_5);
}

void rightMotorForward() {
	TA1CTL &= ~MC0;
	TA1CTL &= ~MC1;

	TA1CCTL0 &= ~OUTMOD_4;
	TA1CCTL0 &= ~OUTMOD_5;
	TA1CCTL1 &= ~OUTMOD_7;
	TA1CCTL1 &= ~OUTMOD_5;

	TA1CCTL0 |= OUTMOD_4;  //reset/set mode
	TA1CCTL1 |= OUTMOD_5;

	TA0CTL |= MC0; // count up
	TA1CTL |= MC0;
}

void rightMotorReverse() {
	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;

	TA1CCTL0 |= OUTMOD_5;
	TA1CCTL1 |= OUTMOD_7;

	TA0CTL |= MC0; // count up
	TA1CTL |= MC0;
}

void moveRobotBackward() {

	rightMotorReverse();
	leftMotorReverse();
}

void moveRobotForward() {

	rightMotorForward();
	leftMotorForward();

}

void turnRobotLeft() {
	leftMotorReverse();
	rightMotorForward();
}
void turnRobotRight() {

	leftMotorForward();
	rightMotorReverse();

}

