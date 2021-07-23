/* Copyright 2021 Christian Sandven
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
};

enum custom_keycodes {
    ALT_TAB = SAFE_RANGE,
};

#define LOWER LT(_LOWER, KC_SPC)
#define RAISE LT(_RAISE, KC_SPC)
#define CMD   MO(_CMD)

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp  |
     * |------+------+------+------+------+------+------+------+------+------+------+-------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  UP  | Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+-------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  | Left | Down | Right |
     * |------+------+------+------+------+------+------+------+------+------+------+-------'
     * | Ctrl |       |    LOWER    | SPC  |       RAISE       |
     * `-------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_UP,   KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_LEFT, KC_DOWN, KC_RIGHT,
        KC_LCTL,          LOWER,             KC_SPC,           RAISE
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * | `    |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp  |
     * |------+------+------+------+------+------+------+------+------+------+------+-------|
     * |AltTab|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \    |
     * |------+------+------+------+------+------+------+------+------+------+------+-------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |   ,  |   .  |   /  | ISO / |
     * |------+------+------+------+------+------+------+------+------+------+------+-------'
     * |      |       |             |      |                   |
     * `-------------------------------------------------------'
    */
    [_LOWER] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        ALT_TAB, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_COMM, KC_DOT,  KC_SLSH, KC_NUBS,
        _______,          _______,           _______,          _______
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del   |
     * |------+------+------+------+------+------+------+------+------+------+------+-------|
     * |AltTab|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |    |
     * |------+------+------+------+------+------+------+------+------+------+------+-------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |       |
     * |------+------+------+------+------+------+------+------+------+------+------+-------'
     * |      |       |             |      |                   |
     * `-------------------------------------------------------'
    */
    [_RAISE] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
        ALT_TAB, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END, _______,
        MU_TOG,           _______,           _______,          _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
