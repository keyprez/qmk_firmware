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
    _QWERTY_MOD,
    _SYM,
    _NAV,
    _FUNCTION,
    _ADJUST
};

enum custom_keycodes {
    KC_QWRTY = SAFE_RANGE,
    KC_QWRTY_MOD,
    KC_COLMK,
    KC_HRM,
    KC_PRVWD,
    KC_NXTWD,
    KC_GIT_COMMIT
};

enum myCombos {
    RT_LBRC,
    YU_RBRC,
    QW_GRV,
    AS_EXLM,
    WE_AT,
    GIT_COMMIT,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM lb_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM rb_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM gc_combo[] = {KC_G, KC_C, COMBO_END};

combo_t key_combos[] = {
  [RT_LBRC] = COMBO(lb_combo, KC_LBRC),
  [YU_RBRC] = COMBO(rb_combo, KC_RBRC),
  [QW_GRV] = COMBO(qw_combo, KC_GRV),
  [AS_EXLM] = COMBO(as_combo, KC_EXLM),
  [WE_AT] = COMBO(we_combo, KC_AT),
  [GIT_COMMIT] = COMBO(gc_combo, KC_GIT_COMMIT)
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
        KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T  ,                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_LBRC,
        CTL_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G  ,                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN, KC_QUOT,
        KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B  , KC_LBRC,      KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_BSLS,
                                  ALT_ENT ,   SYM,   KC_BSPC, FKEYS ,      ADJ_ENT, KC_SPC, NAV, KC_APP
    ),

    /*
    * Base Layer: QWERTY MOD
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
    [_QWERTY_MOD] = LAYOUT(
        KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T  ,                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_LBRC,
        CTL_ESC , HO_A ,  HO_S   ,  HO_D  ,   HO_F ,   KC_G  ,                        KC_H,   HO_J ,  HO_K ,   HO_L ,HO_SCLN, KC_QUOT,
        KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B  , KC_LBRC,      KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_BSLS,
                                  ALT_ENT ,   SYM,   KC_BSPC, FKEYS ,      ADJ_ENT, KC_SPC, NAV, KC_APP
    ),

    /*
    * Base Layer: Sym
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
    [_SYM] = LAYOUT(
        KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5  ,                         KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
        KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC ,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
        KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC , KC_LBRC,      KC_RBRC, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                  KC_LGUI , KC_LALT,  KC_BSPC, FKEYS ,      ADJ_ENT, KC_SPC,  KC_RGUI, KC_APP
    ),

    /*
    * Base Layer: Sym
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
    [_NAV] = LAYOUT(
        KC_TAB  , KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,   KC_T  ,                        KC_Y,   KC_PRVWD,   KC_UP,KC_NXTWD,  KC_P , KC_BSPC,
        CTL_ESC , KC_F5 ,  KC_F5 ,  KC_F6 ,  KC_F7 ,   KC_8  ,                        KC_H,   KC_LEFT, KC_DOWN, KC_RGHT ,HO_SCLN, KC_QUOT,
        KC_LSFT , KC_F9 ,  KC_F10 , KC_F11,  KC_F12 ,  KC_LCBR  , KC_LBRC,   KC_RBRC, KC_RCBR,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                  KC_LGUI , ALT_ENT,  KC_BSPC, FKEYS ,      ADJ_ENT, KC_SPC,  KC_RGUI, KC_APP
    ),

    /*
    * Base Layer: Sym
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
    [_FUNCTION] = LAYOUT(
        KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T  ,                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
        CTL_ESC , HO_A ,  HO_S   ,  HO_D  ,   HO_F ,   KC_G  ,                        KC_H,   HO_J ,  HO_K ,   HO_L ,HO_SCLN, KC_QUOT,
        KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B  , KC_LBRC,      KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                  KC_LGUI , ALT_ENT,  KC_BSPC, FKEYS ,      ADJ_ENT, KC_SPC,  KC_RGUI, KC_APP
    ),

    /*
    * Base Layer: Adjust
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
    [_ADJUST] = LAYOUT(
        KC_TAB  , KC_QWRTY, KC_QWRTY_MOD ,  KC_E  ,   KC_R ,   KC_T  ,                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
        RESET , HO_A ,  HO_S   ,  HO_D  ,   HO_F ,   KC_G  ,                        KC_H,   HO_J ,  HO_K ,   HO_L ,HO_SCLN, KC_QUOT,
        KC_LSFT , KC_Z ,  KC_X   ,  CMB_TOG  ,   KC_V ,   KC_B  , KC_LBRC,      KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                  KC_LGUI , ALT_ENT,  KC_BSPC, FKEYS ,      ADJ_ENT, KC_SPC,  KC_RGUI, KC_APP
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
        case KC_QWRTY_MOD:
             if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY_MOD);
            }
            break;
        case KC_QWRTY:
             if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            break;
        case KC_GIT_COMMIT:
             if (record->event.pressed) {
                 SEND_STRING("git commit -m ");
            }
            break;
    }
    return true;
}
