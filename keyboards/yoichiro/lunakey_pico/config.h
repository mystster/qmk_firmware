// Copyright 2022 Yoichiro Tanaka (@yoichiro)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

//#define SERIAL_DEBUG
#define RGBLIGHT_LAYERS
#define WS2812_PIO_USE_PIO1

#define RGBLIGHT_LED_MAP { 0, 1, 2, 3, 4, 5, \
                           11, 10, 9, 8, 7, 6 }

/* Audio support */
#ifdef AUDIO_ENABLE
  #define AUDIO_PIN GP8
  #define AUDIO_PWM_DRIVER PWMD4
  #define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
  #define AUDIO_INIT_DELAY
  #define STARTUP_SONG SONG(M__NOTE(_C7, 30), M__NOTE(_C6, 30))
#endif

// work around for can't input shifted key at remote desktop
// https://github.com/qmk/qmk_firmware/issues/13708
#define TAP_CODE_DELAY 10

#define TAPPING_TOGGLE 2

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
