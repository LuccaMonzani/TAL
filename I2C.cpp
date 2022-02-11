#include "I2C.h"

I2C::I2C(I2C_HandleTypeDef* handler, uint16_t endereco, uint32_t delay){
    this->handler = handler;
    this->endereco = endereco;
    this->delay = delay;
}


I2C::~I2C() {
    HAL_I2C_DeInit(this->handler);
}


uint8_t *I2C::ler(uint16_t tam_registrador, uint16_t registrador, uint16_t tamanho) {
    uint8_t dados[tamanho];
	if(HAL_I2C_Mem_Read(this->handler, this->endereco, registrador, tam_registrador, dados, tamanho, this->delay) == HAL_OK)
        return dados;
    else    
        throw 0; //Resolve exception
}


bool I2C::escrever(uint16_t tam_registrador, uint16_t registrador, uint16_t tamanho, uint8_t* dados) {
    return (HAL_I2C_Mem_Write(this->handler, this->endereco, registrador, tam_registrador, dados, tamanho, this->delay) == HAL_OK)
}
