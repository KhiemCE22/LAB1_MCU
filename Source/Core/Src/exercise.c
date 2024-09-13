/*
 * exercise.c
 *
 *  Created on: Sep 9, 2024
 *      Author: GIGABYTE
 */
#include "exercise.h"

int counter;
uint16_t GPIO_PIN [12] = {LED_1_Pin, LED_2_Pin,  LED_3_Pin, LED_4_Pin,  LED_5_Pin, LED_6_Pin,
						 LED_7_Pin, LED_8_Pin, LED_9_Pin, LED_10_Pin, LED_11_Pin, LED_12_Pin};


void init_exercise6(){
	counter = 0;
}
void run_exercise6(){
	if (counter >= 12){
		counter = 0;
	}
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN[counter], SET);
	counter++;
}

void clearAllClock(){
	  for (int i = 0; i < 12; i++){
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN[i], RESET);
	  }
}

void run_exercise7(){
	if (counter >= 12){
		counter = 0;
		clearAllClock();
	}
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN[counter], SET);
	counter++;
}
