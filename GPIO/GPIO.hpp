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

#define _A ((GPIO_TypeDef *)GPIOA_BASE)
#define _B ((GPIO_TypeDef *)GPIOB_BASE)
#define _C ((GPIO_TypeDef *)GPIOC_BASE)
#define _D ((GPIO_TypeDef *)GPIOD_BASE)
#define _E ((GPIO_TypeDef *)GPIOE_BASE)

#define PIN_0 ((uint16_t)0x0001)   /* Pin 0 selected    */
#define PIN_1 ((uint16_t)0x0002)   /* Pin 1 selected    */
#define PIN_2 ((uint16_t)0x0004)   /* Pin 2 selected    */
#define PIN_3 ((uint16_t)0x0008)   /* Pin 3 selected    */
#define PIN_4 ((uint16_t)0x0010)   /* Pin 4 selected    */
#define PIN_5 ((uint16_t)0x0020)   /* Pin 5 selected    */
#define PIN_6 ((uint16_t)0x0040)   /* Pin 6 selected    */
#define PIN_7 ((uint16_t)0x0080)   /* Pin 7 selected    */
#define PIN_8 ((uint16_t)0x0100)   /* Pin 8 selected    */
#define PIN_9 ((uint16_t)0x0200)   /* Pin 9 selected    */
#define PIN_10 ((uint16_t)0x0400)  /* Pin 10 selected   */
#define PIN_11 ((uint16_t)0x0800)  /* Pin 11 selected   */
#define PIN_12 ((uint16_t)0x1000)  /* Pin 12 selected   */
#define PIN_13 ((uint16_t)0x2000)  /* Pin 13 selected   */
#define PIN_14 ((uint16_t)0x4000)  /* Pin 14 selected   */
#define PIN_15 ((uint16_t)0x8000)  /* Pin 15 selected   */
#define PIN_All ((uint16_t)0xFFFF) /* All pins selected */

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

			void toogle(uint32_t tempo_em_alto = 1000, uint32_t tempo_em_baixo = 1000)
			{
				/*Faz com que um pino fique oscilando entre alto e baixo, por padrão essa isso acontece a cada 1s*/
				HAL_GPIO_WritePin(this->porta, this->pino, GPIO_PIN_SET);
				HAL_Delay(tempo_em_alto);
				HAL_GPIO_WritePin(this->porta, this->pino, GPIO_PIN_RESET);
				HAL_Delay(tempo_em_baixo);
			}
	};

} // namespace GPIO

#endif /* INC_GPIO_HPP_ */
