#ifndef ADS1115_REGS_H
#define ADS1115_REGS_H

#include <stdint.h>

// ===== Parameterized shift macros =====
#define ADS1115_OS(x) ((uint16_t)(x) << 15)
#define ADS1115_MUX(x) ((uint16_t)(x) << 12)
#define ADS1115_PGA(x) ((uint16_t)(x) << 9)
#define ADS1115_MODE(x) ((uint16_t)(x) << 8)
#define ADS1115_DR(x) ((uint16_t)(x) << 5)
#define ADS1115_COMP_MODE(x) ((uint16_t)(x) << 4)
#define ADS1115_COMP_POL(x) ((uint16_t)(x) << 3)
#define ADS1115_COMP_LAT(x) ((uint16_t)(x) << 2)
#define ADS1115_COMP_QUE(x) ((uint16_t)(x) << 0)

// ===== Predefined values for each field =====

// OS
#define ADS1115_OS_NOEFFECT 0
#define ADS1115_OS_SINGLE 1 // start single conversion

// MUX
#define ADS1115_MUX_P0_N1 0
#define ADS1115_MUX_P0_N3 1
#define ADS1115_MUX_P1_N3 2
#define ADS1115_MUX_P2_N3 3
#define ADS1115_MUX_P0_NG 4
#define ADS1115_MUX_P1_NG 5
#define ADS1115_MUX_P2_NG 6
#define ADS1115_MUX_P3_NG 7

// PGA
#define ADS1115_PGA_6_144V 0
#define ADS1115_PGA_4_096V 1
#define ADS1115_PGA_2_048V 2 // default
#define ADS1115_PGA_1_024V 3
#define ADS1115_PGA_0_512V 4
#define ADS1115_PGA_0_256V 5
#define ADS1115_PGA_0_256VB 6
#define ADS1115_PGA_0_256VC 7

// MODE
#define ADS1115_MODE_CONTINUOUS 0
#define ADS1115_MODE_SINGLE 1

// Data rate
#define ADS1115_DR_8SPS 0
#define ADS1115_DR_16SPS 1
#define ADS1115_DR_32SPS 2
#define ADS1115_DR_64SPS 3
#define ADS1115_DR_128SPS 4 // default
#define ADS1115_DR_250SPS 5
#define ADS1115_DR_475SPS 6
#define ADS1115_DR_860SPS 7

// Comparator mode
#define ADS1115_COMP_MODE_TRADITIONAL 0
#define ADS1115_COMP_MODE_WINDOW 1

// Comparator polarity
#define ADS1115_COMP_POL_ACTIVE_LOW 0
#define ADS1115_COMP_POL_ACTIVE_HIGH 1

// Comparator latching
#define ADS1115_COMP_LAT_NON_LATCHING 0
#define ADS1115_COMP_LAT_LATCHING 1

// Comparator queue / disable
#define ADS1115_COMP_QUE_1 0
#define ADS1115_COMP_QUE_2 1
#define ADS1115_COMP_QUE_4 2
#define ADS1115_COMP_QUE_DISABLE 3

// masks
#define ADS1115_OS_MASK 0x8000
#define ADS1115_MUX_MASK 0x7000
#define ADS1115_PGA_MASK 0x0E00
#define ADS1115_MODE_MASK 0x0100
#define ADS1115_DR_MASK 0x00E0
#define ADS1115_COMP_MODE_MASK 0x0010
#define ADS1115_COMP_POL_MASK 0x0008
#define ADS1115_COMP_LAT_MASK 0x0004
#define ADS1115_COMP_QUE_MASK 0x0003

// ===== Optional helper macro to build full config =====
#define ADS1115_CONFIG(os, mux, pga, mode, dr, comp_mode, comp_pol, comp_lat,  \
                       comp_que)                                               \
  (ADS1115_OS(os) | ADS1115_MUX(mux) | ADS1115_PGA(pga) | ADS1115_MODE(mode) | \
   ADS1115_DR(dr) | ADS1115_COMP_MODE(comp_mode) |                             \
   ADS1115_COMP_POL(comp_pol) | ADS1115_COMP_LAT(comp_lat) |                   \
   ADS1115_COMP_QUE(comp_que))

#define ADS1115_DEFAULT_CONFIG()                                               \
  (ADS1115_OS(ADS1115_OS_SINGLE) | ADS1115_MUX(ADS1115_MUX_P0_NG) |            \
   ADS1115_PGA(ADS1115_PGA_2_048V) | ADS1115_MODE(ADS1115_MODE_SINGLE) |       \
   ADS1115_DR(ADS1115_DR_128SPS) | ADS1115_COMP_MODE(0) |                      \
   ADS1115_COMP_POL(0) | ADS1115_COMP_LAT(0) |                                 \
   ADS1115_COMP_QUE(ADS1115_COMP_QUE_DISABLE))

// device address
#define ADS1115_ADDRESS_ADDR_GND 0x48 // address pin low (GND)
#define ADS1115_ADDRESS_ADDR_VDD 0x49 // address pin high (VCC)
#define ADS1115_ADDRESS_ADDR_SDA 0x4A // address pin tied to SDA pin
#define ADS1115_ADDRESS_ADDR_SCL 0x4B // address pin tied to SCL pin
#define ADS1115_DEFAULT_ADDRESS ADS1115_ADDRESS_ADDR_GND

#define ADS1115_CONFIG_REG 0x1
#define ADS1115_CONV_REG 0x0

#endif // ADS1115_REGS_H
