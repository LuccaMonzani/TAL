#include "Comum.hpp"

#ifdef HAL_ADC_MODULE_ENABLED

#ifndef TAL_ADC
#define TAL_ADC

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
	void Set_sens_vec();
	uint32_t* Get_buffer();
	void Set_buffer();
	void Ler_DMA();
	void Parar_DMA();

private:
	uiunt8_t sens_num;
	ADC_HandleTypeDef *hadc;
	uint32_t sens_vec_val[sens_num];
	uint32_t buffer[10];

};

#endif /* TAL_ADC */

#endif /* HAL_ADC_MODULE_ENABLED */
