#include "GPIO.hpp"
#ifdef HAL_GPIO_MODULE_ENABLED

void GPIO::escrever(GPIO_PinState estado)
{
	/*Escre em um pino de GPIO*/
	HAL_GPIO_WritePin(this->porta, this->pino, estado);
}

void GPIO::multipla_escrita(std::vector<GPIO_TypeDef *> portas, std::vector<uint16_t> pinos, GPIO_PinState estado)
{
	for (auto porta : portas)
	{
		for (uint16_t pino : pinos)
			HAL_GPIO_WritePin(porta, pino, estado);
	}
}

bool GPIO::ler()
{
	/*Le os dados de uma GPIO*/
	return HAL_GPIO_ReadPin(this->porta, this->pino) == GPIO_PIN_SET;
}

void GPIO::toggle(uint32_t tempo_em_alto, uint32_t tempo_em_baixo)
{
	/*Faz com que um pino fique oscilando entre alto e baixo, por padrão essa isso acontece a cada 1s*/
	HAL_GPIO_WritePin(this->porta, this->pino, GPIO_PIN_SET);
	HAL_Delay(tempo_em_alto);
	HAL_GPIO_WritePin(this->porta, this->pino, GPIO_PIN_RESET);
	HAL_Delay(tempo_em_baixo);
}

#endif /* HAL_GPIO_MODULE_ENABLED */
