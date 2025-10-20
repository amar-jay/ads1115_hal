ADS1115 HAL (STM32F4) - Minimal CMake scaffold

This repository provides a tiny, portable CMake scaffold for an ADS1115 HAL
wrapper built on top of a platform ADC driver. It includes:

- A static library target `ads1115_hal` (CMake)
- Public headers in `include/`
- Stub ADC driver implementation in `src/` for host builds
- An example executable in `examples/`

Building (host):

```bash
mkdir build && cd build
cmake ..
cmake --build .
./examples/example_adc
```

Cross-compiling for STM32F4:

- Replace the files in `src/adc_driver.c` with STM32 HAL-based implementations.
- Pass STM32 include and source paths to CMake via `-DSTM32F4_HAL_INCLUDE_DIR` and
  `-DSTM32F4_HAL_SRC_DIR` or add them to your toolchain files.
