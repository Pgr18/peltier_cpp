/*
 * DRV8833.hpp
 *
 *  Created on: Jul 6, 2025
 *      Author: paulr
 */
#include "main.h"
#ifndef INC_DRV8833_HPP_
#define INC_DRV8833_HPP_


#define DRV8833_nSLEEP_PORT PEL_nSLEEP_GPIO_Port
#define DRV8833_nSLEEP_PIN PEL_nSLEEP_Pin

#define DRV8833_WKP() HAL_GPIO_WritePin(DRV8833_nSLEEP_PORT,DRV8833_nSLEEP_PIN,GPIO_PIN_SET);
#define DRV8833_SLP() HAL_GPIO_WritePin(DRV8833_nSLEEP_PORT,DRV8833_nSLEEP_PIN,GPIO_PIN_RESET);

void _PELTIER_HEAT(void);
void _PELTIER_COOL(void);

void _PELTIER_STOP(void);
#endif /* INC_DRV8833_HPP_ */
