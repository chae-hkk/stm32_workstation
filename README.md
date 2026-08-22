# STM32 Nucleo64 C031C6 with Wokwi Simulation
## LED BLinking using register and No HAL


[![Build and Simulate in Wokwi](https://github.com/wokwi/stm32-hello-wokwi/actions/workflows/ci.yml/badge.svg)](https://github.com/wokwi/stm32-hello-wokwi/actions/workflows/ci.yml)

Blinking the onboard LED (LD4, PA5) on a NUCLEO-C031C6 board using direct register access — no HAL.
Built and simulated entirely in the browser via GitHub Codespaces + Wokwi, with no local installation required.


## Build & run
``` bash
sudo apt update && sudo apt install -y gcc-arm-none-eabi make
make
```

Then, with the Wokwi for VS Code extension installed:

1. F1 → Wokwi: Request a new License (once)
2. F1 → Wokwi: Start Simulator

## References
STM32C031C4/C6 Datasheet (DS14431)
RM0490 — STM32C0 Series Reference Manual
UM2953 — STM32 Nucleo-64 boards (MB1717) User Manual

## Credits

Forked from WelsTheory/stm32_hello_cmsis_wokwi.

## Write-up

Full walkthrough (in Korean): velog post
