/*
 * exercise.c
 *
 *  Created on: Sep 9, 2024
 *      Author: GIGABYTE
 */
#include "exercise.h"

int counter;
void init_exercise1(){
	 HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, RESET);
	 HAL_GPIO_WritePin(YELOW_LED_GPIO_Port, YELOW_LED_Pin, SET);
	 counter = 0;
}
void run_exercise1(){
	if (counter >= 2){
		 HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
		 HAL_GPIO_TogglePin(YELOW_LED_GPIO_Port, YELOW_LED_Pin);
	}
	counter++;
}
