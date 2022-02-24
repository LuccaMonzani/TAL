#ifdef HAL_SPI_MODULE_ENABLED
#include "stm32f1xx_hal_spi.h"

void SPI::enviar_buffer()
{
    HAL_SPI_Transmit(hspi, (uint8_t*)buffer.c_str(), buffer.size(), timeout)
}
void SPI::enviar(uint8_t* mensagem, uint8_t tamanho_da_mensagem)
{
    HAL_SPI_Transmit(hspi, mensagem, tamanho_da_mensagem, timeout)
}

void SPI::receber_em_buffer(uint8_t tamanho_da_mensagem)
{
    HAL_SPI_Receive(hspi, (uint8_t*)buffer.c_str(), buffer.size(), timeout)
}
void SPI::receber(uint8_t* destino, uint8_t tamanho_da_mensagem)
{
    HAL_SPI_Receive(hspi, destino, tamanho_da_mensagem, timeout)
}

#endif /* HAL_SPI_MODULE_ENABLED */
