//
// Created by 34254 on 2026/4/25.
//

#include "../Inc/delay.h"

void delay_ms(uint16_t ms) {
  DWT_Delay_ms(ms);
}
void delay_us(uint16_t us) {
  DWT_Delay_us(us);
}