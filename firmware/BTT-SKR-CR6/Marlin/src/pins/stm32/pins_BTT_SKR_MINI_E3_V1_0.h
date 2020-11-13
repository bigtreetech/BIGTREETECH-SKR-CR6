/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "pins_BTT_SKR_MINI_E3.h"

#define BOARD_INFO_NAME "BIGTREE SKR Mini E3"

//
// EEPROM
//
/* I2C */
// #define I2C_EEPROM
// #define E2END 0x3FFF   // 16Kb (24c16)
#define MYI2C_EEPROM      // EEPROM on I2C-0
#define IIC_EEPROM_SDA       PB7
#define IIC_EEPROM_SCL       PB6

#define X_MIN_PIN          PC0
// #define X_MAX_PIN          PA7
#define Y_MIN_PIN          PC1

#ifdef BLTOUCH
  #define Z_MIN_PIN        PB1  // BLTouch IN PIN
  #define SERVO0_PIN       PB0  // BLTouch OUT PIN
#elif ENABLED(FIX_MOUNTED_PROBE)
  #define Z_MIN_PIN        PC2
  #define COM_PIN          PC14//PA1
#else
  #define Z_MIN_PIN        PA7
#endif

//
// Release PB4 (Z_STEP_PIN) from JTAG NRST role
//
#define DISABLE_DEBUG

//
// Temperature Sensors
//
#define TEMP_0_PIN         PA0   // TH1
#define TEMP_BED_PIN       PC3   // TB1

#define HEATER_0_PIN       PC8   // HEATER1
#define HEATER_BED_PIN     PC9   // HOT BED

#define FAN_PIN            PC7   // FAN
#define FAN_SOFT_PWM


/* SD card detect */
#define SD_DETECT_PIN      PC4

#define LED_CONTROL_PIN    PA8
#define CHECK_MATWEIAL     PC15
// #define OPTO_SWITCH_PIN    PB2   // certification
#define OPTO_SWITCH_PIN    PA1

/**
 * TMC2209 stepper drivers
 * Hardware serial communication ports.
 */
#if HAS_DRIVER(TMC2209)
  #define X_HARDWARE_SERIAL  Serial4
  #define Y_HARDWARE_SERIAL  Serial4
  #define Z_HARDWARE_SERIAL  Serial4
  #define E0_HARDWARE_SERIAL Serial4
#endif
