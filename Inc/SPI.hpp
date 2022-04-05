#include "Comum.hpp"

#ifdef HAL_SPI_MODULE_ENABLED
#include "stm32f1xx_hal_spi.h"

#ifndef TAL_SPI
#define TAL_SPI

#include "GPIO.hpp"
#include <vector>
#include <string>

class SPI {
private:
    SPI_HandleTypeDef* hspi;
public:

    std::string buffer;
    uint32_t default_timeout = HAL_MAX_DELAY;
    std::vector<GPIO> chip_select;

    SPI(){};
    SPI(SPI_HandleTypeDef* _hspi, uint8_t tamanho_buffer, uint32_t timeout)
    : hspi(_hspi), default_timeout(timeout) {buffer.resize(tamanho_buffer);};
    SPI(SPI_HandleTypeDef* _hspi, std::vector<GPIO> _chip_select, uint8_t tamanho_buffer, uint32_t timeout)
    : hspi(_hspi), default_timeout(timeout), chip_select(_chip_select) {buffer.resize(tamanho_buffer);};

    ~SPI(){};


    void enviar_buffer();
    void enviar(uint8_t* mensagem, uint8_t tamanho_da_mensagem);


    void receber_em_buffer();
    void receber(uint8_t* destino, uint8_t tamanho_da_mensagem);
};


#endif /* TAL_SPI */

#endif /* HAL_SPI_MODULE_ENABLED */
