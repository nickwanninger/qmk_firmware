/* Copyright 2022 Nick Wanninger
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

#include QMK_KEYBOARD_H
#include "print.h"

extern keymap_config_t keymap_config;

enum planck_layers { _QWERTY, _COLEMAK, _LOWER, _RAISE, _ADJUST, _EMOD, _FN };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define FUNCT MO(_FN)

enum custom_keycodes {
    // Keycode to enable the EMOD layer
    KC_EMOD = SAFE_RANGE,
    KC_NEWL, // type '\n'
    QWERTY,
    COLEMAK,
    COLCOL,
};

// #define KC_EMOD LT(_EMOD, KC_ESC)

// Screenshot keycode on macos (and windows if you install greenshot and configure it right...)
#define KC_SCRT LCTL(LSFT(KC_4))

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_EMOD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, FUNCT,   KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_EMOD, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, FUNCT,   KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


// KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_EQL
// I typically use the "lower" layer for symbols. The top row has the symbols in their order from querty,
// and the rest is based on my programming needs.
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, _______, _______, KC_LCBR, KC_RCBR, _______, _______, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL , _______,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_SCLN, KC_PIPE,
    _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, KC_COMM, KC_DOT,  KC_SLSH, KC_NEWL,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),


// Raise is meant for numbers and also contains some arrow keys so I don't have to move my hands so much.
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL , KC_BSPC,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0   , KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

// Adjust basically only exists to provide the RESET key.
// I sometimes activate it on accident when rolling between raise and lower, so having
// anything else on here will probably result in bad inputs :)
[_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SCRT, KC_DEL, // it also has del :)
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, COLCOL , _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET
),

[_EMOD] = LAYOUT_planck_grid(
    _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_BTN1, KC_BTN1, _______, _______, _______, _______, _______
),

[_FN] = LAYOUT_planck_grid(
    _______, QWERTY,  COLEMAK, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 , _______,
    _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


};

// clang-format on

void keyboard_post_init_user(void) {
    set_single_persistent_default_layer(_QWERTY);
    debug_enable = true;
}
dd-- yy -''-- --layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_EMOD: // EMOD is basically a new layer key, so we want it to enable instantly.
            uprintf("EMOD\n");
            return 100;
        default: // all other modtaps can wait the usual amount of time.
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool emod_used = false;

    if (record->event.pressed && layer_state_is(_EMOD)) {
        emod_used = true;
    }
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                uprintf("QWERTY\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return true;
        case COLEMAK:
            if (record->event.pressed) {
                uprintf("COLEMAK\n");
                set_single_persistent_default_layer(_COLEMAK);
            }
            return true;
        case COLCOL:
            if (record->event.pressed) SEND_STRING("::");
            break;
        case KC_NEWL:
            if (record->event.pressed) SEND_STRING("\\n");
            break;
        case KC_EMOD:
            if (record->event.pressed) {
                emod_used = false;
                layer_on(_EMOD);
            } else {
                layer_off(_EMOD);
                if (!emod_used) tap_code(KC_ESC);
            }
            break;
        default:
            break;
    }
    return true;
}
