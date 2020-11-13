/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
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

/**
 * CREALITY (STM32F103) board pin assignments
 */

#ifndef __STM32F1__
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#endif

#if HOTENDS > 1 || E_STEPPERS > 1
  #error "CREALITY supports up to 1 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_NAME "CREALITY"

//
// EEPROM
//
/* I2C */
// #define I2C_EEPROM
// #define E2END 0x3FFF   // 16Kb (24c16)
//#define MYI2C_EEPROM      // EEPROM on I2C-0
#define IIC_EEPROM_SDA       PB7
#define IIC_EEPROM_SCL       PB6

/* SPI */
//#define SPI_EEPROM  // EEPROM on SPI-0
//#define SPI_CHAN_EEPROM1        ?
//#define SPI_EEPROM1_CS          ?
// 2K EEPROM
//#define SPI_EEPROM2_CS          ?
// 32Mb FLASH
//#define SPI_FLASH_CS            ?

/* FLASH */
// Enable EEPROM Emulation for this board
// This setting should probably be in configuration.h
// but it is literally the only board which uses it.
//#define FLASH_EEPROM_EMULATION


//
// Limit Switches
//
#define X_MIN_PIN          PC0
// #define X_MAX_PIN          PA7
#define Y_MIN_PIN          PC1
#ifdef BLTOUCH
  #define Z_MIN_PIN        PB1  // BLTouch IN PIN
  #define SERVO0_PIN       PB0  // BLTouch OUT PIN
#elif ENABLED(FIX_MOUNTED_PROBE)
  #define Z_MIN_PIN        PC14
  #define COM_PIN          PA1
#else
  #define Z_MIN_PIN        PA7
#endif

#define CONTROLLER_FAN_PIN  PC7
// #define FLASH_EEPROM_EMULATION
// #define EEPROM_PAGE_SIZE     uint16(0x800) // 2KB
// #define EEPROM_START_ADDRESS uint32(0x8000000 + (STM32_FLASH_SIZE) * 1024 - 2 * EEPROM_PAGE_SIZE)
// #undef E2END
// #define E2END                (EEPROM_PAGE_SIZE - 1) // 2KB

// Onboard I2C EEPROM
//#if NO_EEPROM_SELECTED
  #define I2C_EEPROM
  #define MARLIN_EEPROM_SIZE 0x1000                 // 4KB
  #define E2END                (MARLIN_EEPROM_SIZE - 1) // 2KB
//  #undef NO_EEPROM_SELECTED
//#endif
//
// Steppers
//
#define X_ENABLE_PIN        PB14
#define X_STEP_PIN          PB13
#define X_DIR_PIN           PB12

#define Y_ENABLE_PIN        PB11
#define Y_STEP_PIN          PB10
#define Y_DIR_PIN           PB2

//#define Z_ENABLE_PIN        PA0
#define Z_ENABLE_PIN        PB1
#define Z_STEP_PIN          PB0
#define Z_DIR_PIN           PC5

#define E0_ENABLE_PIN       PD2
#define E0_STEP_PIN         PB3
#define E0_DIR_PIN          PB4

#if HAS_TMC220x

  //
  // TMC2208 mode
  //
  // #define TMC2208_STANDALONE

  #define X_HARDWARE_SERIAL  MSerial4
  #define Y_HARDWARE_SERIAL  MSerial4
  #define Z_HARDWARE_SERIAL  MSerial4
  #define E0_HARDWARE_SERIAL MSerial4

  //
  // TMC2208 Software serial
  //
  // #define HAVE_SW_SERIAL

  // Reduce baud rate to improve software serial reliability
  // #define TMC_BAUD_RATE 19200

#endif

//
// Release PB4 (Z_STEP_PIN) from JTAG NRST role
//
#define DISABLE_DEBUG

//
// Temperature Sensors
//
#define TEMP_0_PIN         PA0   // TH1
//#define TEMP_0_PIN         PB1   // TH1
#define TEMP_BED_PIN       PC3   // TB1

//
// Heaters / Fans
/*certification*/
// #define HEATER_0_PIN       PB14  // HEATER1
// #define HEATER_BED_PIN     PB13  // HOT BED

// #define FAN_PIN            PB15  // FAN
// #define FAN_SOFT_PWM

#define HEATER_0_PIN       PC8   // HEATER1
#define HEATER_BED_PIN     PC9   // HOT BED

#define FAN_PIN            PC6   // FAN
#define FAN_SOFT_PWM


#if ENABLED(CR10_STOCKDISPLAY)

    #define BTN_ENC            PA15
    #define BTN_EN1            PA9
    #define BTN_EN2            PA10

    #define LCD_PINS_RS        PB8
    #define LCD_PINS_ENABLE    PB15
    #define LCD_PINS_D4        PB9

    #define BEEPER_PIN          PB5

#endif

/* RET6 12864 LCD */
// #define LCD_PINS_RS        PB12
// #define LCD_PINS_ENABLE    PB15
// #define LCD_PINS_D4        PB13

// #define BTN_ENC            PB2
// #define BTN_EN1            PB10
// #define BTN_EN2            PB14

// #define BEEPER_PIN         PC6


/* VET6 12864 LCD */
// #define LCD_PINS_RS        PA4
// #define LCD_PINS_ENABLE    PA7
// #define LCD_PINS_D4        PA5

// #define BTN_ENC            PC5  
// #define BTN_EN1            PB10
// #define BTN_EN2            PA6


/* RET6 DWIN ENCODER LCD */
// #define BTN_ENC            PB14  
// #define BTN_EN1            PB15
// #define BTN_EN2            PB12

// #define BEEPER_PIN         PB13


/* VET6 DWIN ENCODER LCD */
// #define BTN_ENC            PA6
// #define BTN_EN1            PA7
// #define BTN_EN2            PA4

// #define BEEPER_PIN         PA5

//
// USB connect control
//
#define USB_CONNECT_PIN    PA14
#define USB_CONNECT_INVERTING false



#define LED_CONTROL_PIN    PA13
#define CHECK_MATWEIAL     PC15
// #define OPTO_SWITCH_PIN    PB2   // certification
#define OPTO_SWITCH_PIN    PC2


//
// SD Support
//
#define HAS_ONBOARD_SD

#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION ONBOARD
#endif

#define ON_BOARD_SPI_DEVICE 1    // SPI1
#define ONBOARD_SD_CS_PIN  PA4   // Chip select for "System" SD card
/* SD card detect */
#define SD_DETECT_PIN      PC4A
#define NEOPIXEL_PIN       PA8     
