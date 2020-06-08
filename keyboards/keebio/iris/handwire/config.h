/*
Copyright 2019 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xCB10
#define PRODUCT_ID      0x4256
#define DEVICE_VER      0x0400
#define MANUFACTURER    Keebio
#define PRODUCT         Keebio Iris *Handwired*
#define DESCRIPTION     Split 50 percent ergonomic keyboard

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half

/*
 Pro Micro Pinout:

     D3 +--------+ RAW
     D2 | +----+ | GND
     GND|        | RST
     GND|        | VCC
SDA  D1 |        | F4
SCL  D0 |        | F5
     D4 |        | F6
     C6 |        | F7
     D7 |        | B1
     E6 |        | B3
     B4 |        | B2
     B5 +--------+ B6

*/
#define MATRIX_ROW_PINS        { B1, F7, F6, F5, F4 }
#define MATRIX_COL_PINS        { B3, B2, B6, E6, B4, B5 }
#define MATRIX_ROW_PINS_RIGHT  { B1, F7, F6, F5, F4 }
#define MATRIX_COL_PINS_RIGHT  { B3, B2, B6, E6, B4, B5 }
//#define SPLIT_HAND_PIN D5
//#define QMK_ESC_OUTPUT F1
//#define QMK_ESC_INPUT B1
//#define QMK_LED B0
//#define QMK_SPEAKER C6

//#define ENCODERS_PAD_A { B2 }
//#define ENCODERS_PAD_B { B3 }
#define ENCODERS_PAD_A {}
#define ENCODERS_PAD_B {}
//#define ENCODERS_PAD_A_RIGHT { F7 }
//#define ENCODERS_PAD_B_RIGHT { F6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
//#define DEBOUNCE 5
#define DEBOUNCE 0

/* serial.c configuration for split keyboard */
// #define SOFT_SERIAL_PIN D0

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

//#define BACKLIGHT_PIN B5
//#define BACKLIGHT_LEVELS 5

/* ws2812 RGB LED */
//#define RGB_DI_PIN D6
//#define RGBLED_NUM 12    // Number of LEDs
#define RGBLED_NUM 0
//#define RGBLED_SPLIT { 6, 6 }
//#define RGBLIGHT_ANIMATIONS

//#define SPLIT_USB_DETECT
//#define SPLIT_USB_TIMEOUT 2000
