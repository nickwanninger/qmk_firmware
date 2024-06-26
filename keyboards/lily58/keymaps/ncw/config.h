/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

#define MK_KINETIC_SPEED
#define MOUSEKEY_INITIAL_SPEED 50
#define MOUSEKEY_DECELERATED_SPEED 100
#define MOUSEKEY_INTERVAL 8
#define MOUSEKEY_BASE_SPEED 200
#define MOUSEKEY_MOVE_DELTA 1

#define RGBLIGHT_LAYERS


#define USB_MAX_POWER_CONSUMPTION 500
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255

#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// split keyboard configuration
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE
