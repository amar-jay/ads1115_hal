#ifndef __ADS1115_HAL_H__
#define __ADS1115_HAL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#include "stm32f4xx_hal.h" // or your MCU series header

// =======================================================
// ---------------- STRUCTURE DEFINITIONS ----------------
// =======================================================

typedef struct {
  I2C_HandleTypeDef *i2c_handler;
  uint16_t config;
  uint16_t pga_coeff;

  // Config methods
  HAL_StatusTypeDef (*setConfig)(struct ADS1115_HandleTypeDef *ads,
                                 uint16_t config);
  uint16_t (*getConfig)(struct ADS1115_HandleTypeDef *ads);
  void (*setPGA)(struct ADS1115_HandleTypeDef *ads, uint16_t pga);

  // Conversion methods
  // HAL_StatusTypeDef (*readSingleEnded)(struct ADS1115_HandleTypeDef *ads,
  //                                     uint16_t mux, float *mv);
  // HAL_StatusTypeDef (*setConversionReadyPinMode)(
  //     struct ADS1115_HandleTypeDef *ads, uint16_t conv);

} ADS1115_HandleTypeDef;

// =======================================================
// ---------------- FUNCTION PROTOTYPES ------------------
// =======================================================

// Initialization
ADS1115_HandleTypeDef ads1115_hal_init(I2C_HandleTypeDef *handler,
                                       uint16_t config);

void ads1115_hal_deinit(ADS1115_HandleTypeDef *ads);

// Config access
HAL_StatusTypeDef ads1115_set_config(ADS1115_HandleTypeDef *ads,
                                     uint16_t config);
uint16_t ads1115_get_config(ADS1115_HandleTypeDef *ads);

// Conversion access
HAL_StatusTypeDef ads1115_set_conv(ADS1115_HandleTypeDef *ads, uint16_t conv);
HAL_StatusTypeDef ads1115_get_conv(ADS1115_HandleTypeDef *ads, uint16_t *conv);

// Single-ended and differential reads
HAL_StatusTypeDef ads1115_read_raw(ADS1115_HandleTypeDef *ads, uint16_t mux,
                                   uint8_t raw_buf[2]);
HAL_StatusTypeDef ads1115_read_single_ended(ADS1115_HandleTypeDef *ads,
                                            uint16_t mux, float *mv);

HAL_StatusTypeDef ads1115_read_P0N1(ADS1115_HandleTypeDef *ads, float *mv);
HAL_StatusTypeDef ads1115_read_P0N3(ADS1115_HandleTypeDef *ads, float *mv);
HAL_StatusTypeDef ads1115_read_P1N3(ADS1115_HandleTypeDef *ads, float *mv);
HAL_StatusTypeDef ads1115_read_P2N3(ADS1115_HandleTypeDef *ads, float *mv);

HAL_StatusTypeDef ads1115_read_P0NG(ADS1115_HandleTypeDef *ads, float *mv);
HAL_StatusTypeDef ads1115_read_P1NG(ADS1115_HandleTypeDef *ads, float *mv);
HAL_StatusTypeDef ads1115_read_P2NG(ADS1115_HandleTypeDef *ads, float *mv);
HAL_StatusTypeDef ads1115_read_P3NG(ADS1115_HandleTypeDef *ads, float *mv);

// Continuous read methods
HAL_StatusTypeDef ads1115_read_continuous(ADS1115_HandleTypeDef *ads,
                                          float *mv);
HAL_StatusTypeDef ads1115_start_continuous(ADS1115_HandleTypeDef *ads,
                                           uint16_t mux);

void ads1115_set_pga(ADS1115_HandleTypeDef *ads, uint16_t pga);
#ifdef __cplusplus
}
#endif

#endif /* ADS1115_HAL_H */
