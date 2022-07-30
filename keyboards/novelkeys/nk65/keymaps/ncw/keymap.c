/* Copyright 2019 Yiancar
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

enum custom_keycodes {
    // Keycode to enable the EMOD layer
    KC_EMOD = SAFE_RANGE,
    KC_DDOT, // type ../
    KC_NEWL, // type \n
};

enum layers {
    // Default layer
    _QWERTY = 0,
    // Function layer
    _FN = 1,
    // Layer to enable the EMOD layer
    _EMOD = 2,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_65_ansi( /* Base */
 // _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
    KC_EMOD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LCTL,          KC_UP,   MO(_FN),
    KC_LCTL, KC_LALT, KC_LGUI,                KC_SPC,                                KC_RALT, KC_HYPR, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

[_FN] = LAYOUT_65_ansi( /* FN */
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_MUTE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   KC_VOLU,
    _______, _______, _______, _______, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  _______, _______, _______, _______,          _______, KC_VOLD,
    _______, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  BR_DEC,  BR_INC,  ES_DEC,  ES_INC,  _______,          _______, _______,
    KC_VOLU, KC_VOLD, KC_MUTE,                _______,                               _______, _______, _______, _______, _______, _______),

[_EMOD] = LAYOUT_65_ansi( /* EMOD */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          KC_NEWL, _______,
    _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, _______, _______, _______, KC_DDOT, _______, _______,          _______, _______,
    _______, _______, _______,                KC_BTN1,                               _______, _______, _______, _______, _______, _______),

[3] = LAYOUT_65_ansi( /* Empty for dynamic keymaps */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______,                _______,                               _______, _______, _______, _______, _______, _______),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool left_shift_pressed  = false;
    static bool right_shift_pressed = false;
    static bool emod_used           = false;

    if (record->event.pressed && layer_state_is(_EMOD)) {
        emod_used = true;
    }

    bool *shift_pressed = &right_shift_pressed;

    switch (keycode) {
        case KC_DDOT:
            if (record->event.pressed) SEND_STRING("../");
            break;
        case KC_NEWL:
            if (record->event.pressed) SEND_STRING("\\n");
            break;
            // Enable hitting both shift keys to toggle caps lock
        case KC_LSFT:
            shift_pressed = &left_shift_pressed;
            // fallthrough
        case KC_RSFT:
            *shift_pressed = record->event.pressed;
            if (left_shift_pressed && right_shift_pressed) tap_code(KC_CAPS);
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
