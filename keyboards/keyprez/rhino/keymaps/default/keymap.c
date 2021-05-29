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
    _BASE,
    _FN,
    _RAISE,
    _LOWER,
};

#define LOWER MO(_LOWER)
#define FN MO(_FN)
#define RAISE_SPC LT(_RAISE, KC_SPC)
#define TAB_CTL MT(MOD_LCTL, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * |                                                                                                                     KC_MUTE |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | GESC   | Q      | W      | E      | R      | T      | [      | ]      | Y      | U      | I      | O      | P      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | TAB    | A      | S      | D      | F      | G      | HOME   | PG UP  | H      | J      | K      | L      | ;      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | PG DN  | N      | M      | ,      | .      | /      | ENTER  |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * |        | LGUI   | FN     | LALT   | RAISE  |      SPACE      |      SPACE      | LEFT   | UP     | DOWN   | RIGHT  |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_ortho_2x2u(
                                                                                                                             KC_MUTE,
        KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
        TAB_CTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSPC,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                 KC_LGUI, FN,      KC_LALT, LOWER,       KC_SPC,   RAISE_SPC,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    )
};
