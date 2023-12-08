#include <stdio.h>
#include "pico/stdlib.h"
#include "mcp2515/mcp2515.h"

/*
MCP2515(
    spi_inst_t* CHANNEL = spi0,
    uint8_t CS_PIN = PICO_DEFAULT_SPI_CSN_PIN,
    uint8_t TX_PIN = PICO_DEFAULT_SPI_TX_PIN,
    uint8_t RX_PIN = PICO_DEFAULT_SPI_RX_PIN,
    uint8_t SCK_PIN = PICO_DEFAULT_SPI_SCK_PIN,
    uint32_t _SPI_CLOCK = DEFAULT_SPI_CLOCK
);
*/

MCP2515 can0(spi0, 5, 3, 4, 2);

struct can_frame rx;
struct can_frame tx;

uint8_t counter = 0;

int main() {
    stdio_init_all();

    //Initialize interface
    can0.reset();
    can0.setBitrate(CAN_1000KBPS, MCP_8MHZ);
    can0.setNormalMode();

    tx.can_id = 0x0A;
    tx.can_dlc = 1;

    //Listen loop
    while(true) {
        // counter++;
        // if (counter >= 32) counter = 0;
        // tx.data[0] = counter;

        // printf("sending %d\n", counter);
        // can0.sendMessage(&tx);
        // sleep_ms(1000);

        if(can0.readMessage(&rx) == MCP2515::ERROR_OK) {
            printf("id %x :: dlc %d :: data[0] %d \n", rx.can_id, rx.can_dlc, rx.data[0]);
            
        }

    }

    return 0;
}
