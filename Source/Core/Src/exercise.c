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

int counter_x, counter_y;
int status_x, status_y;



void control_1_Light(int* counter, int* status_led, int order){

	GPIO_TypeDef* GPIO_Port[3][2] = {
								{RED_LED_X_GPIO_Port, RED_LED_Y_GPIO_Port},
								{GREEN_LED_X_GPIO_Port,GREEN_LED_Y_GPIO_Port},
								{YELOW_LED_X_GPIO_Port, YELOW_LED_Y_GPIO_Port}
									};
	uint16_t GPIO_PIN[3][2] = {
							{RED_LED_X_Pin,RED_LED_Y_Pin},
							{GREEN_LED_X_Pin,GREEN_LED_Y_Pin},
							{YELOW_LED_X_Pin,YELOW_LED_Y_Pin},
								};
	switch (*status_led) {
		case RED:
			if (*counter >=5 ){
				*status_led = GREEN;
				*counter = 0;
				HAL_GPIO_WritePin(GPIO_Port[GREEN][order], GPIO_PIN[GREEN][order], GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIO_Port[RED][order], GPIO_PIN[RED][order], GPIO_PIN_RESET);
			}
			break;
		case GREEN:
			if (*counter >= 3){
				*status_led = YELOW;
				*counter = 0;
				HAL_GPIO_WritePin(GPIO_Port[YELOW][order], GPIO_PIN[YELOW][order], GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIO_Port[GREEN][order], GPIO_PIN[GREEN][order], GPIO_PIN_RESET);
			}
			break;
		case YELOW:
			if (*counter >= 2){
				*status_led = RED;
				*counter = 0;
				HAL_GPIO_WritePin(GPIO_Port[RED][order], GPIO_PIN[RED][order], GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIO_Port[YELOW][order], GPIO_PIN[YELOW][order], GPIO_PIN_RESET);
			}
			break;
		default:
			break;
	}
}

void init_exercise3(){
	/*set Light X*/
	HAL_GPIO_WritePin(RED_LED_X_GPIO_Port, RED_LED_X_Pin, RESET);
	HAL_GPIO_WritePin(GREEN_LED_X_GPIO_Port, GREEN_LED_X_Pin, SET);
	HAL_GPIO_WritePin(YELOW_LED_X_GPIO_Port, YELOW_LED_X_Pin, RESET);
	counter_x = 0;
	status_x = GREEN;
	/*set Light Y*/
	HAL_GPIO_WritePin(RED_LED_Y_GPIO_Port, RED_LED_Y_Pin, SET);
	HAL_GPIO_WritePin(GREEN_LED_Y_GPIO_Port, GREEN_LED_Y_Pin, RESET);
	HAL_GPIO_WritePin(YELOW_LED_Y_GPIO_Port, YELOW_LED_Y_Pin, RESET);
	counter_y = 0;
	status_y = RED;
}

void run_exercise3(){
	control_1_Light(&counter_x, &status_x, 0);
	control_1_Light(&counter_y, &status_y, 1);
	counter_x++;
	counter_y++;
}
