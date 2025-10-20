#include "ads1115_hal.h"
#include <stdio.h>

#include "ads_defs.h"
#include "stm32f4xx_hal.h" // or your MCU series header
I2C_HandleTypeDef *hi2c1;
int main(void) {

  ADS1115_HandleTypeDef ads;
  ads1115_hal_init(&ads, hi2c1, ADS1115_DEFAULT_CONFIG());

  ads.setPGA(&ads, ADS1115_PGA_4_096V);

  int32_t raw;
  if (ads1115_read_P0N1(&ads, &raw) == 0) {
    printf("Channel 0 raw = %ld\n", (long)raw);
  } else {
    printf("Failed to read channel\n");
  }

  for (int i = 0; i < 4; i++) {
    if (ads1115_read_single_ended(&ads, i, &raw) == 0) {
      printf("Channel %d raw = %ld\n", i, (long)raw);
    } else {
      printf("Failed to read channel %d\n", i);
    }
  }

  ads1115_hal_deinit(&ads);
  return 0;
}
