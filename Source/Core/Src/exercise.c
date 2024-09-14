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



void clearAllClock(){
	  for (int i = 0; i < 12; i++){
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN[i], RESET);
	  }
}
void setNumberOnClock(int num){
	if (num > 0 && num < 12)
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN[num - 1], SET);

	else if (num == 0)
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN[11], SET);

}
void clearNumberOnClock(int num){
	if (num > 0 && num < 12)
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN[num - 1], RESET);

	else if (num == 0)
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN[11], RESET);
}

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


void run_exercise7(){
	if (counter >= 12){
		counter = 0;
		clearAllClock();
	}
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN[counter], SET);
	counter++;
}


void run_exercise8(){
	if (counter >= 12){
		counter = 0;
		clearAllClock();
	}
	setNumberOnClock(counter);
	counter++;
}


void init_exercise9(){
	counter = 0;
	  for (int i = 0; i < 12; i++){
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN[i], SET);
	  }
}
void run_exercise9(){
	if (counter >= 12){
		counter = 0;
	}
	clearNumberOnClock(counter);
	counter++;
}
