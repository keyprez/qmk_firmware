// Copyright 2022 keyprez (@keyprez)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap

enum layer_names {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _HRM,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWRTY = SAFE_RANGE,
    KC_COLMK,
    KC_HRM,
    KC_PRVWD,
    KC_NXTWD
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ESC_CTL MT(MOD_LCTL, KC_ESC)

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_QWERTY] = LAYOUT(
        KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                                      KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL ,
        KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                                      KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
        ESC_CTL,  HO_A,   HO_S,    HO_D,    HO_F,    KC_G,    KC_MUTE,                                      KC_QUOT, KC_H,    HO_J,    HO_K,    HO_L, HO_SCLN,  KC_RCTL,
        KC_LGUI,  KC_LSFT,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_COPY, KC_PSTE, KC_PGUP, KC_PGDN,  KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_HOME, KC_END,
                                            KC_LALT, LOWER,      KC_BSPC, KC_LSFT,             KC_ENT, KC_SPC,       RAISE, KC_RALT
    ),

    [_LOWER] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______,                                      _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______,                                      _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______,
        _______, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______,    _______, _______,            _______, _______,      _______, _______
    ),

    [_RAISE] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______,                                     _______, _______,KC_PRVWD,   KC_UP,KC_NXTWD, _______, _______,
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______,                                     _______, _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______, _______,
        _______, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______,  _______, _______,_______, _______, _______, _______, _______, _______, _______,
                                            _______, _______,    _______, _______,            _______, _______,     _______, _______
    ),

    [_ADJUST] = LAYOUT(
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,                                     RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
        _______, KC_QWRTY,KC_COLMK,_______, _______, _______, _______,                                     _______, _______,_______,   _______,_______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______,_______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,_______, _______, _______, _______, _______, _______, _______,
                                            _______, _______,    _______, _______,            RESET, _______,     _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWRTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLMK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_HRM:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_HRM);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_LEFT);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_LEFT);
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_RIGHT);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_RIGHT);
            }
            break;
    }
    return true;
}


