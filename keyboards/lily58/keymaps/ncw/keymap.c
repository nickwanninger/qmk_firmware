/* Copyright 2020 Naoki Katahira
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
#include <stdio.h>

// extern uint8_t is_master;

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _EMOD,
    _FN,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define FUNCT MO(_FN)

enum custom_keycodes {
    // Keycode to enable the EMOD layer
    KC_EMOD = SAFE_RANGE,
    KC_NEWL,
    KC_CESC, // Control when held, escape when tapped.
    KC_ARRW, // Control when held, escape when tapped.
};
#define KC_SCRT LCTL(LSFT(KC_4))

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define EMOD MO(_EMOD)
#define CTRESC MT(MOD_LCTL, KC_ESC)
#define KC_SCRT LCTL(LSFT(KC_4))

#define MT_R MT(MOD_LGUI, KC_R)
#define MT_E MT(MOD_LALT, KC_E)
#define MT_W MT(MOD_LCTL, KC_W)
#define MT_Q MT(MOD_LSFT, KC_Q)

#define MT_U MT(MOD_LGUI, KC_U)
#define MT_I MT(MOD_LALT, KC_I)
#define MT_O MT(MOD_LCTL, KC_O)
#define MT_P MT(MOD_LSFT, KC_P)

// clang-format off

#define _____________ARROWS_______________ KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
#define ___________TMUX_ARROWS____________ A(KC_LEFT), A(KC_DOWN), A(KC_UP),  A(KC_RIGHT)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_EMOD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, FUNCT,   KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_LBRC, KC_RBRC, KC_LCTL, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
                               _______, _______, _______, _______, _______, _______, _______,_______
),
[_LOWER] = LAYOUT(
    KC_TILD, _______, _______, KC_LCBR, KC_RCBR, _______,                   _______, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL , _______,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_SCLN, KC_PIPE,
    _______, _______, _______, KC_LBRC, KC_RBRC, _______,                   _______, _______, KC_COMM, KC_DOT,  KC_SLSH, KC_NEWL,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MPLY,
                               _______, _______, _______, _______, _______, _______, _______, _______
),
[_RAISE] = LAYOUT(
    KC_GRV,  _______, _______, _______, _______, _______,                   _______, _______, _______, KC_MINS, KC_EQL , KC_BSPC,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0   , KC_BSLS,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MPLY,
                               _______, _______, _______, _______, _______, _______, _______, _______
),
[_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, KC_SCRT, KC_DEL, 
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______
),
[_EMOD] = LAYOUT(
    _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______,
    _______, _______, _______, _______, _______, _______,                   A(KC_LEFT), A(KC_DOWN), A(KC_UP), A(KC_RIGHT), _______, _______,
    _______, _______, _______, _______, _______, KC_BTN1, _______, _______, KC_BTN2, _______, _______, KC_PGDN, KC_PGUP, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______
),
[_FN] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 , _______,
    _______, KC_F11,  KC_F12,  _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, C(A(S(KC_M))), C(S(KC_TAB)), _______, _______, C(KC_TAB),
                               _______, _______, _______, _______, _______, _______, _______, _______
)
};

// clang-format on

#include "./bongo.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180; // flips the display 180 degrees if offhand

    // return OLED_ROTATION_270;
    return rotation;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

unsigned ncw_key_presses = 0;

void fmt_int(int n, char out[4]) {
    out[3] = '\0';
    out[2] = '0' + n % 10;
    out[1] = (n /= 10) % 10 ? '0' + (n) % 10 : (n / 10) % 10 ? '0' : ' ';
    out[0] = n / 10 ? '0' + n / 10 : ' ';
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_ln_P(PSTR("Default"), false);
                break;
            case _RAISE:
                oled_write_ln_P(PSTR("Raise"), false);
                break;
            case _LOWER:
                oled_write_ln_P(PSTR("Lower"), false);
                break;
            case _ADJUST:
                oled_write_ln_P(PSTR("Adjust"), false);
                break;
            case _EMOD:
                oled_write_ln_P(PSTR("Escape"), false);
                break;
            default:
                oled_write_ln_P(PSTR("Undefined"), false);
        }

        char out[4];
        fmt_int(get_current_wpm(), out);
        oled_write_P(PSTR("WPM:   "), false);
        oled_write(out, false);

        fmt_int(ncw_key_presses, out);
        oled_write_P(PSTR("\nCOUNT: "), false);
        oled_write(out, false);

    } else {
        render_bongo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // static bool cesc_used = false;

    static bool emod_used = false;

    if (record->event.pressed) ncw_key_presses++;

    if (record->event.pressed && layer_state_is(_EMOD)) {
        emod_used = true;
    }
    switch (keycode) {
        case KC_ARRW:
            if (record->event.pressed) SEND_STRING("->");
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
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default: // all other modtaps can wait the usual amount of time.
            return TAPPING_TERM;
    }
}
