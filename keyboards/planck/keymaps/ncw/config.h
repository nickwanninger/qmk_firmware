/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define MK_KINETIC_SPEED
#define MOUSEKEY_INITIAL_SPEED 50
#define MOUSEKEY_DECELERATED_SPEED 100
#define MOUSEKEY_INTERVAL 8
#define MOUSEKEY_BASE_SPEED 200
#define MOUSEKEY_MOVE_DELTA 1

// #define RGBLIGHT_LAYERS

// #define DEBOUNCE 2
#define TAPPING_TERM 200 // default tapping term. Overwritten per key in `get_tapping_term`
#define TAPPING_TERM_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT // this makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)

#define USB_MAX_POWER_CONSUMPTION 500
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 0