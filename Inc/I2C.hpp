#include "Comum.hpp"

#ifdef HAL_I2C_MODULE_ENABLED
#include "stm32f1xx_hal_i2c.h"

#ifndef TAL_I2C
#define TAL_I2C

#include <stdlib.h>
#include <stdint.h>

class I2C {
    private:
        uint32_t delay;
        I2C_HandleTypeDef *handler;
        uint16_t endereco;

    public:
        I2C(I2C_HandleTypeDef* handler, uint16_t endereco, uint32_t delay);
        ~I2C();
        uint8_t *ler(uint16_t tam_registrador, uint16_t registrador, uint16_t tamanho);
        bool escrever(uint16_t tam_registrador, uint16_t registrador, uint16_t tamanho, uint8_t* dados);

};

#endif /* TAL_I2C */

#endif /* HAL_I2C_MODULE_ENABLED */
