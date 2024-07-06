# npi-gpio
Simple GPIO access library for NanoPi NEO3 

 GPIO Pin table of NEO3
+---+-----------------------+-------++---+---------------------+-------+
|   |                       | Linux ||   |                     | Linux |
|Pin| Name                  |  GPIO ||Pin| Name                |  GPIO |
+---+-----------------------+------------++---+----------------+-------+
| 1 | 3.3V(Out)             |       || 2 | 5V(Out/In)          |       |
| 3 | I2C0_SDA              |       || 4 | 5V(Out/In)          |       |
| 5 | I2C0_SCL              |       || 6 | GND                 |       |
| 7 | GPIO2_A2/IR-RX        | 66    || 8 | GPIO3_A4/UART1_TX   | 100   |
| 9 | GND                   |       ||10 | GPIO3_A6/UART1_RX   | 102   |
|11 | GPIO2_B7/I2S1_MCLK)   | 79    ||12 | GPIO2_C3/I2S1_SDI   | 83    |
|13 | GPIO2_C1/I2S1_LRCK_TX | 81    ||14 | GND                 |       |
|15 | GPIO2_C2/I2S1_SCLK    | 82    ||16 | GPIO3_A5/UART1_RTSN | 101   |
|17 | 3.3V(Out)             |       ||18 | GPIO3_A7/UART1_CTSN | 103   |
|19 | GPIO3_A1/SPI_TXD      | 97    ||20 | GND                 |       |
|21 | GPIO3_A2/SPI_RXD      | 98    ||22 | GPIO2_C7/I2S1_SDO   | 87    |
|23 | GPIO3_A0/SPI_CLK      | 96    ||24 | GPIO3_B0/SPI_CSN0   | 104   |
|25 | GND                   |       ||26 | GPIO0_D3/SPDIF_TX   | 27    |
+---+-----------------------+-------++---+---------------------+-------+


