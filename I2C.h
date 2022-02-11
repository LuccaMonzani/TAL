#ifndef I2C_H
#define I2C_H

#include <stdint.h>

class I2C {
    private:
        uint32_t delay;
        I2C_HandleTypeDef *handler;
        uint16_t endereco;

    public:
        I2C(I2C_HandleTypeDef* handler, uint16_t endereco, uint32_t delay); //Definir i2c_config
        ~I2C();
        uint8_t *ler(uint16_t tam_registrador, uint16_t registrador, uint16_t tamanho);
        bool escrever(uint16_t tam_registrador, uint16_t registrador, uint16_t tamanho, uint8_t* dados);

};

#endif