/*
 * GPIO.hpp
 *
 *  Created on: Feb 3, 2022
 *      Author: Vitor Matias
 */

#ifndef INC_GPIO_HPP_
#define INC_GPIO_HPP_

#include "stm32f1xx_hal.h"
#include <vector>


namespace GPIO
{
	class dispositivo
	{
		private:
			GPIO_TypeDef *porta;
			uint16_t pino;

		public:
			dispositivo(GPIO_TypeDef *endereco_porta, uint16_t endereco_pino) : porta(endereco_porta), pino(endereco_pino) {}

			void escrever(GPIO_PinState estado)
			{
				/*Escre em um pino de GPIO*/
				HAL_GPIO_WritePin(this->porta, this->pino, estado);
			}

			void multipla_escrita(std::vector<GPIO_TypeDef *> portas, std::vector<uint16_t> pinos, GPIO_PinState estado)
			{
				for (auto porta : portas)
				{
					for (uint16_t pino : pinos)
						HAL_GPIO_WritePin(porta, pino, estado);
				}
			}

			bool ler(uint16_t pino)
			{
				/*Le os dados de uma GPIO*/
				return (bool)HAL_GPIO_ReadPin(this->porta, this->pino);
			}

			void toogle(uint32_t tempo_em_alto, uint32_t tempo_em_baixo)
			{
				/*Faz com que um pino fique oscilando entre alto e baixo, por padrão essa isso acontece a cada 1s*/
				HAL_GPIO_WritePin(this->porta, this->pino, GPIO_PIN_SET);
				HAL_Delay(tempo_em_alto);
				HAL_GPIO_WritePin(this->porta, this->pino, GPIO_PIN_RESET);
				HAL_Delay(tempo_em_baixo);
			}

			void toogle(void)
			{
				/*Faz com que um pino fique oscilando entre alto e baixo, por padrão essa isso acontece a cada 1s*/

				const uint32_t tempo_em_alto = 1000;
				const uint32_t tempo_em_baixo = 1000

				HAL_GPIO_WritePin(this->porta, this->pino, GPIO_PIN_SET);
				HAL_Delay(tempo_em_alto);
				HAL_GPIO_WritePin(this->porta, this->pino, GPIO_PIN_RESET);
				HAL_Delay(tempo_em_baixo);
			}
	};

} // namespace GPIO

#endif /* INC_GPIO_HPP_ */
