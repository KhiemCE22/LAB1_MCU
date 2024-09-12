/*
 * exercise.c
 *
 *  Created on: Sep 9, 2024
 *      Author: GIGABYTE
 */
#include "exercise.h"

#define RED 0
#define GREEN 1
#define YELOW 2

int counter;
int status_led;
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

void init_exercise2(){
	 HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(YELOW_LED_GPIO_Port, YELOW_LED_Pin, GPIO_PIN_SET);
	 HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_SET);
	 status_led = RED;
	 counter = 0;

}
void run_exercise2(){
	switch (status_led) {
		case RED:
			if (counter >=5 ){
				status_led = GREEN;
				counter = 0;
				HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
			}
			break;
		case GREEN:
			if (counter >= 3){
				status_led = YELOW;
				counter = 0;
				HAL_GPIO_WritePin(YELOW_LED_GPIO_Port, YELOW_LED_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_SET);
			}
			break;
		case YELOW:
			if (counter >= 2){
				status_led = RED;
				counter = 0;
				HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(YELOW_LED_GPIO_Port, YELOW_LED_Pin, GPIO_PIN_SET);
			}
			break;
		default:
			break;
	}
	counter++;
}
