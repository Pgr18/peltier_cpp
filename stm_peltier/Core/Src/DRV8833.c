/*
 * DRV8833.cpp
 *
 *  Created on: Jul 6, 2025
 *      Author: paulr
 */
#include <DRV8833.h>

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;

void _PELTIER_HEAT() {
	uint32_t val1 = TIM1->ARR * 50 / 100;
	uint32_t val2 = 0;
	DRV8833_WKP();
	if (HAL_TIM_Base_GetState(&htim1) != HAL_TIM_STATE_BUSY) {
		HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
		//HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, val1);
		//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, val2);
	} else {
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, val1);
		//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, val2);
	}
}

void _PELTIER_COOL() {
	uint32_t val1 = 0;
	uint32_t val2 = TIM1->ARR * 50 / 100;
	DRV8833_WKP();
	if (HAL_TIM_Base_GetState(&htim1) != HAL_TIM_STATE_BUSY) {
		//HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
		HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
		//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, val1);
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, val2);
	} else {
		//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, val1);
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, val2);
	}
}

void _PELTIER_STOP() {

	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
	DRV8833_SLP();
}
