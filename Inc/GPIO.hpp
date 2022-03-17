/*
 * GPIO.hpp
 *
 *  Created on: Feb 3, 2022
 *      Author: Vitor Matias
 */

#ifdef HAL_GPIO_MODULE_ENABLED
#include "stm32f1xx_hal_gpio.h"


#ifndef INC_GPIO_HPP_
#define INC_GPIO_HPP_

#include <vector>
#include <stdint.h>



class GPIO
{
		private:
			GPIO_TypeDef *porta;
			uint16_t pino;

		public:
			GPIO(){};
			GPIO(GPIO_TypeDef *endereco_porta, uint16_t endereco_pino) : porta(endereco_porta), pino(endereco_pino) {}

			void escrever(GPIO_PinState estado);
			
			void multipla_escrita(std::vector<GPIO_TypeDef *> portas, std::vector<uint16_t> pinos, GPIO_PinState estado);

			bool ler(uint16_t pino);

			void toggle(uint32_t tempo_em_alto = 1000, uint32_t tempo_em_baixo = 1000);
};
 // namespace GPIO

#endif /* INC_GPIO_HPP_ */

#endif /* HAL_GPIO_MODULE_ENABLED */
