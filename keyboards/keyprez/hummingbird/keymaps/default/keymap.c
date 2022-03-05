// Copyright 2022 Christian Sandven (@keyprez)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Left-hand home row mods
#define HO_A LGUI_T(KC_A)
#define HO_S LALT_T(KC_S)
#define HO_D LCTL_T(KC_D)
#define HO_F LSFT_T(KC_F)

// Right-hand home row mods
#define HO_J RSFT_T(KC_J)
#define HO_K RCTL_T(KC_K)
#define HO_L LALT_T(KC_L)
#define HO_SCLN RGUI_T(KC_SCLN)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define ADJ_ENT  LT(ADJUST, KC_ENT)

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _SYM,
    _NAV,
    _FUNCTION,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * Base Layer: QWERTY
    *
    * ,-------------------------------------------.                    ,-------------------------------------------.
    * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
    * |--------+------+------+------+------+------|                    |------+------+------+------+------+--------|
    * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
    * |--------+------+------+------+------+------+------.      ,-------------+------+------+------+------+--------|
    * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |      |  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
    * `----------------------+------+------+------+------|      |------+------+------+------+------+---------------'
    *                        | LGUI | Alt/ | Bksp/| Fun  |      |Adjust| Space| RGUI | Menu |
    *                        |      | Enter| Enter|      |      | Enter|      |      |      |
    *                        `---------------------------'      `---------------------------'
    */
    [_QWERTY] = LAYOUT(
        KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T  ,                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
        CTL_ESC , HO_A ,  HO_S   ,  HO_D  ,   HO_F ,   KC_G  ,                        KC_H,   HO_J ,  HO_K ,   HO_L ,HO_SCLN, KC_QUOT,
        KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B  , KC_LBRC,      KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                  KC_LGUI , ALT_ENT,  KC_BSPC, FKEYS ,      ADJ_ENT, KC_SPC,  KC_RGUI, KC_APP
    ),
};
