#Lab8
##API

C2C John Miller, ECE 382
Code to navigate the maze of doom in the ECE382 lab
	
-initializes the ADC system and motor code

-starts off the motor in the forward positions, the duty cycles are set up to make left curve by default

-checks the left and front sensors against a pretermined threshold
	-if both are under the threshold, make left turns
	
	-if the left sensor is over the threshold, make a slight right turn
	
	-if the center sensor is over the threshold, make a sharp right turn