/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

#include QMK_KEYBOARD_H

#include <stdbool.h>
#include <stdint.h>

#define _QWERTY 0
#define _FUNCTION 1
#define EMOD 2
#define _CADET 3

enum custom_keycodes {
    // Keycode to enable the EMOD layer
    KC_EMOD = SAFE_RANGE
};

// escape
// #define ESC_MOD LT(EMOD, KC_ESC)

// cadet
#define CAD_MOD MO(_CADET)

// This is so that H(xxxx) has the same width as _______, which makes the grids more legible.
#define H(x) UC(0x##x)
#define MO_FN MO(_FUNCTION)
#define KC_LLCK KC_LAYER_LOCK

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

			//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
			//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
			//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
			//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
			//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
			//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_EMOD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),


		// "ESC" layer
		// Holding caps (escape) will enter this mode and allow me to use a few vim features
    [EMOD] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            KC_BTN1,                             KC_BTN2, _______, _______, _______, _______, _______
    ),

		/* The Cadet layers. Again, we show the QWERTY layer and the two cadet layers.
		 * ,----------------------------------------------------------------------------
		 * | ` |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|HOM|END|PGU|PGD|MUT|BRK|  QWERTY
		 * | ∅ |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |  SHIFTCADET
		 * | ¬ |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |  CADET
		 * |---------------------------------------------------------------------------|
		 * | ` | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | + | BKSPC |LCK| / | * | - |
		 * | ` | ¡ |   | £ |   |   |   |   | ° |   |   | * | ∓ | BKSPC |LCK|   |   |   |
		 * |   |   |   |   |   |   |   |   |   |   |   |   | ± | BKSPC |LCK|   | × |   |
		 * |---------------------------------------------------------------------------|
		 * | TAB  | Q | W | E | R | T | Y | U | I | O | P | [ | ] |  \ | 7 | 8 | 9 |   |
		 * |      | ℚ |   |   | ℝ | ⊆ | ⊇ |   | ℵ | ∄ |   | ∉ |   |    | * | * | * |   |
		 * |      | ∧ | ∨ | ∩ | ∪ | ⊂ | ⊃ | ∀ | ∞ | ∃ | ∂ | ∈ |   |    | * | * | * |   | [1]
		 * |-----------------------------------------------------------------------| + |
		 * | CTRL   | A | S | D | F | G | H | J | K | L | ; | ' |  RET | 4 | 5 | 6 | ⊕ |
		 * | CTRL   | Å |   | ∇ |   | ⇑ | ⇓ | ⇐ | ⇒ | ⇔ |   |   |  RET | * | * | * |   |
		 * | CTRL   | ⟘ | ⊤ | ⊢ | ⊣ | ↑ | ↓ | ← | → | ↔ |   |   |  RET | * | * | * |   | [1]
		 * |-----------------------------------------------------------------------|---|
		 * | SHIFT   | Z | X | C | V | B | N | M | , | . | / |SHFT | ↑ | 1 | 2 | 3 |   |
		 * | SHIFT   | ℤ | ℂ |   | ≉ | ≢ | ℕ |   |   |   |   |SHFT |   | * | * | * |   |
		 * | SHIFT   |   | ≠ |   | ≈ | ≡ | ≤ | ≥ |   |   | ÷ |SHFT |   | * | * | * |   | [1]
		 * |-----------------------------------------------------------------------|ENT|
		 * | CTL | ALT| CMD|         SPACE         | α | β | γ | ← | ↓ | → | 0 | . |   |
		 * | CTL | ALT| CMD|         SPACE         | α | β | γ |   |   |   |   |   |   |
		 * | CTL | ALT| CMD|         SPACE         | α | β | γ |   |   |   |   |   |   |
		 * `---------------------------------------------------------------------------'
		 * [1] CADET + numpad moves the mouse. SHIFT+CADET+NUMPAD moves it more quickly. CADET+5
		 * clicks the mouse, and SHIFT+CADET+FIVE right-clicks.
		 */
    [_CADET] = LAYOUT(
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
			_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, H(00b1), _______,          _______,
			_______, H(2227), H(2228), H(2229), H(222a), H(2282), H(2283), H(2200), H(221e), H(2203), H(2202), H(2208), XXXXXXX, _______,          _______,
			_______, H(22a5), H(22a4), H(22a2), H(22a3), H(2191), H(2193), H(2190), H(2192), H(2194), XXXXXXX, XXXXXXX,          _______,          _______,
			_______,          XXXXXXX, H(2260), XXXXXXX, H(2248), H(2261), H(2264), H(2265), XXXXXXX, XXXXXXX, H(00f7),          _______, _______, _______,
			_______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

		/*
		[_CADET] = LAYOUT(
			H(00AC), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
			KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, H(00b1),          _______, _______, XXXXXXX, H(00d7), XXXXXXX,
			_______, H(2227), H(2228), H(2229), H(222a), H(2282), H(2283), H(2200), H(221e), H(2203), H(2202), H(2208), XXXXXXX,          XXXXXXX, KC_P7,   KC_P8,   KC_P9,
			_______, H(22a5), H(22a4), H(22a2), H(22a3), H(2191), H(2193), H(2190), H(2192), H(2194), XXXXXXX, XXXXXXX,                   _______, KC_P4,   KC_P5,   KC_P6,   XXXXXXX,
			_______,          XXXXXXX, H(2260), XXXXXXX, H(2248), H(2261), H(2264), H(2265), XXXXXXX, XXXXXXX, H(00f7), _______,          _______, KC_P1,   KC_P2,   KC_P3,
			_______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_PENT
		),
		*/

};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool left_shift_pressed  = false;
    static bool right_shift_pressed = false;
    static bool emod_used           = false;

    if (record->event.pressed && layer_state_is(EMOD)) {
        emod_used = true;
    }

    bool *shift_pressed = &right_shift_pressed;

    switch (keycode) {
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
                layer_on(EMOD);
            } else {
                layer_off(EMOD);
                if (!emod_used) tap_code(KC_ESC);
            }
            break;

        default:
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods = get_mods();

    if (layer_state_is(EMOD)) {
        uint16_t k = clockwise ? KC_DOWN : KC_UP;
        uint8_t  n = mods & MOD_MASK_ALT ? 12 : 1;
        unregister_mods(MOD_MASK_ALT);
        for (uint8_t i = 0; i < n; i++) {
            tap_code(k);
        }
        set_mods(mods);
    } else if (mods & (MOD_MASK_CTRL | MOD_MASK_ALT)) {
        if (!clockwise) {
            register_mods(MOD_MASK_SHIFT);
        }
        tap_code(KC_TAB);
        set_mods(mods);
    } else if (mods & MOD_MASK_SHIFT) {
        unregister_mods(MOD_MASK_SHIFT);
        register_mods(MOD_MASK_CTRL);
        tap_code(clockwise ? KC_EQUAL : KC_MINUS);
        set_mods(mods);
    } else {
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
    }
    return false;
}
#endif // ENCODER_ENABLE
