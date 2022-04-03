/*
 * ClassAdc.h
 *
 *  Created on: Feb 7, 2022
 *      Author: lucca
 */

#ifdef HAL_ADC_MODULE_ENABLED

#ifndef SRC_CLASSADC_H_
#define SRC_CLASSADC_H_

#include "stm32f1xx_hal.h"
#include <stdio.h>
#include <stdlib.h>

class ADC {

public:
	ADC(uint8_t sens_number, ADC_HandleTypeDef *hadcx);
	~ADC();
	uint8_t Get_sens_num();
	ADC_HandleTypeDef* Get_chanel();
	void Set_sens_num(uint8_t sens_number);
	uint32_t *Get_sens_vec_val();
	uint32_t* Get_buffer();
	void Ler_DMA();
	void Parar_DMA();

private:
	uiunt8_t sens_num;
	ADC_HandleTypeDef *hadc;
	uint32_t sens_vec_val[sens_num];
	uint32_t buffer[10];

};

#endif /* SRC_CLASSADC_H_ */

#endif /* HAL_ADC_MODULE_ENABLED */