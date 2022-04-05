#include "Comum.hpp"

#ifdef HAL_CAN_MODULE_ENABLED
#include "stm32f1xx_hal_can.h"


#ifndef TAL_CAN
#define TAL_CAN

#include "stm32f1xx_hal.h"
#include <stdlib.h>
#include <stdint.h>

class Can {
private:
    CAN_HandleTypeDef *handler;
    CAN_FilterTypeDef filtro;

    CAN_TxHeaderTypeDef tx_header;
    CAN_RxHeaderTypeDef rx_header;
    uint32_t mailbox;

    uint32_t interrupt;
    bool lock;

public:
    Can(CAN_HandleTypeDef *handler, uint32_t interrupt, uint32_t id);
    void iniciar(uint32_t interrupt, uint32_t id);

    void setup(uint32_t interrupt, uint32_t id_high, uint32_t id_low, uint32_t mask_high, uint32_t mask_low);

    uint8_t *ler();
    bool enviar(uint8_t *dados, uint8_t tamanho);

    void esperar();
    virtual ~Can();
};

#endif /* TAL_CAN */

#endif /* HAL_CAN_MODULE_ENABLED */
