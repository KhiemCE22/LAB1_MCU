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

void display7SEG(int num){

	GPIO_TypeDef* GPIO_Port[7] = {SEG_0_GPIO_Port,
								  SEG_1_GPIO_Port,
								  SEG_2_GPIO_Port,
								  SEG_3_GPIO_Port,
								  SEG_4_GPIO_Port,
								  SEG_5_GPIO_Port,
								  SEG_6_GPIO_Port};
	uint16_t GPIO_Pin[7] = {SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, SEG_3_Pin, SEG_4_Pin, SEG_5_Pin, SEG_6_Pin};
	// Turn off all segments
	for (int i = 0; i < 7; i++){
		HAL_GPIO_WritePin(GPIO_Port[i], GPIO_Pin[i], SET);
	}
	// Turn on specific segments based on the number
	switch (num) {
		case 0:
			for (int i = 0; i < 6; i++){
				HAL_GPIO_WritePin(GPIO_Port[i], GPIO_Pin[i], RESET);
			}
			break;
		case 1: // SEG_1. SEG_2
			HAL_GPIO_WritePin(GPIO_Port[1], GPIO_Pin[1], RESET);
			HAL_GPIO_WritePin(GPIO_Port[2], GPIO_Pin[2], RESET);
			break;
		case 2: // SEG_0, SEG_1, SEG_3, SEG_4, SEG_6
			HAL_GPIO_WritePin(GPIO_Port[0], GPIO_Pin[0], RESET);
			HAL_GPIO_WritePin(GPIO_Port[1], GPIO_Pin[1], RESET);
			HAL_GPIO_WritePin(GPIO_Port[3], GPIO_Pin[3], RESET);
			HAL_GPIO_WritePin(GPIO_Port[4], GPIO_Pin[4], RESET);
			HAL_GPIO_WritePin(GPIO_Port[6], GPIO_Pin[6], RESET);
			break;
		case 3: //SEG_0, SEG_1, SEG_2, SEG_3, SEG_6
			HAL_GPIO_WritePin(GPIO_Port[0], GPIO_Pin[0], RESET);
			HAL_GPIO_WritePin(GPIO_Port[1], GPIO_Pin[1], RESET);
			HAL_GPIO_WritePin(GPIO_Port[2], GPIO_Pin[2], RESET);
			HAL_GPIO_WritePin(GPIO_Port[3], GPIO_Pin[3], RESET);
			HAL_GPIO_WritePin(GPIO_Port[6], GPIO_Pin[6], RESET);
			break;
		case 4: // SEG_1, SEG_2, SEG_5, SEG_6
			HAL_GPIO_WritePin(GPIO_Port[1], GPIO_Pin[1], RESET);
			HAL_GPIO_WritePin(GPIO_Port[2], GPIO_Pin[2], RESET);
			HAL_GPIO_WritePin(GPIO_Port[5], GPIO_Pin[5], RESET);
			HAL_GPIO_WritePin(GPIO_Port[6], GPIO_Pin[6], RESET);
			break;
		case 5: //SEG_0, SEG_2, SEG_3, SEG_5, SEG_6
			HAL_GPIO_WritePin(GPIO_Port[0], GPIO_Pin[0], RESET);
			HAL_GPIO_WritePin(GPIO_Port[2], GPIO_Pin[2], RESET);
			HAL_GPIO_WritePin(GPIO_Port[3], GPIO_Pin[3], RESET);
			HAL_GPIO_WritePin(GPIO_Port[5], GPIO_Pin[5], RESET);
			HAL_GPIO_WritePin(GPIO_Port[6], GPIO_Pin[6], RESET);
			break;
		case 6: //SEG_0, SEG_2, SEG_3, SEG_4, SEG_5, SEG_6
			HAL_GPIO_WritePin(GPIO_Port[0], GPIO_Pin[0], RESET);
			HAL_GPIO_WritePin(GPIO_Port[2], GPIO_Pin[2], RESET);
			HAL_GPIO_WritePin(GPIO_Port[3], GPIO_Pin[3], RESET);
			HAL_GPIO_WritePin(GPIO_Port[4], GPIO_Pin[4], RESET);
			HAL_GPIO_WritePin(GPIO_Port[5], GPIO_Pin[5], RESET);
			HAL_GPIO_WritePin(GPIO_Port[6], GPIO_Pin[6], RESET);
			break;
		case 7: //SEG_0. SEG_1, SEG_2
			HAL_GPIO_WritePin(GPIO_Port[0], GPIO_Pin[0], RESET);
			HAL_GPIO_WritePin(GPIO_Port[1], GPIO_Pin[1], RESET);
			HAL_GPIO_WritePin(GPIO_Port[2], GPIO_Pin[2], RESET);
			break;
		case 8: // all segments
			for (int i = 0; i < 7; i++){
				HAL_GPIO_WritePin(GPIO_Port[i], GPIO_Pin[i], RESET);
			}
			break;
		case 9: //SEG_0, SEG_1, SEG_2, SEG_3, SEG_5, SEG_6
			HAL_GPIO_WritePin(GPIO_Port[0], GPIO_Pin[0], RESET);
			HAL_GPIO_WritePin(GPIO_Port[1], GPIO_Pin[1], RESET);
			HAL_GPIO_WritePin(GPIO_Port[2], GPIO_Pin[2], RESET);
			HAL_GPIO_WritePin(GPIO_Port[3], GPIO_Pin[3], RESET);
			HAL_GPIO_WritePin(GPIO_Port[5], GPIO_Pin[5], RESET);
			HAL_GPIO_WritePin(GPIO_Port[6], GPIO_Pin[6], RESET);
			break;
		default:
			break;
	}

}

void run_exercise4(){
	control_1_Light(&counter_x, &status_x, 0);
	// just display 1 7-segment led for demo
	display7SEG(counter_x);
	control_1_Light(&counter_y, &status_y, 1);
	counter_x++;
	counter_y++;
}
