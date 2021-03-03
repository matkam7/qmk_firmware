/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
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
#include "version.h"

// enum layers {
//     BASE,  // default layer
//     SYMB,  // symbols
//     MDIA,  // media keys
// };

enum layers {
    COLEMAK,
    QWERTY,
    FN,
    CODE,
    NAV,
    NUMPAD,
    RECORD_1,
    RECORD_2,
};

enum combos {
  MATKAM_ESC,
  MATKAM_NAV,
  MATKAM_COPY,
  MATKAM_PASTE,
  MATKAM_SAVE,
  MATKAM_PALETTE,
  MATKAM_UNDO,
  MATKAM_UNDO2,
  MATKAM_CUT,
  MATKAM_FIND,
  MATKAM_REPLACE,
  MATKAM_CLOSE,
  MATKAM_ALL,
  MATKAM_LINE,
  MATKAM_CAPS,
  MATKAM_TAB,
  MATKAM_ADDRESS,
  MATKAM_KEY_TAB,
  MATKAM_KEY_UNTAB
};

const uint16_t PROGMEM nav_combo[] = {KC_BSPC, KC_A, COMBO_END};
const uint16_t PROGMEM escape_combo[] = {KC_A, KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_V, COMBO_END};
const uint16_t PROGMEM save_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_S, COMBO_END};
const uint16_t PROGMEM pallet_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM undo_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_Z, COMBO_END};
const uint16_t PROGMEM undo2_combo[] = {KC_X, KC_C, KC_D, KC_Z, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_X, COMBO_END};
const uint16_t PROGMEM find_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_F, COMBO_END};
const uint16_t PROGMEM replace_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_R, COMBO_END};
const uint16_t PROGMEM close_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_W, COMBO_END};
const uint16_t PROGMEM all_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_A, COMBO_END};
const uint16_t PROGMEM line_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_G, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_BSPC, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_T, COMBO_END};
const uint16_t PROGMEM address_combo[] = {KC_A, KC_R, KC_S, KC_T, KC_E, COMBO_END};
const uint16_t PROGMEM keytab_combo[] = {KC_S, KC_T, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM keyuntab_combo[] = {KC_A, KC_R, KC_N, KC_E, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [MATKAM_NAV] = COMBO_ACTION(nav_combo),
    [MATKAM_ESC] = COMBO(escape_combo, KC_ESC),
    [MATKAM_COPY] = COMBO_ACTION(copy_combo),
    [MATKAM_PASTE] = COMBO_ACTION(paste_combo),
    [MATKAM_SAVE] = COMBO_ACTION(save_combo),
    [MATKAM_PALETTE] = COMBO_ACTION(pallet_combo),
    [MATKAM_UNDO] = COMBO_ACTION(undo_combo),
    [MATKAM_UNDO2] = COMBO_ACTION(undo2_combo),
    [MATKAM_CUT] = COMBO_ACTION(cut_combo),
    [MATKAM_FIND] = COMBO_ACTION(find_combo),
    [MATKAM_REPLACE] = COMBO_ACTION(replace_combo),
    [MATKAM_CLOSE] = COMBO_ACTION(close_combo),
    [MATKAM_ALL] = COMBO_ACTION(all_combo),
    [MATKAM_LINE] = COMBO_ACTION(line_combo),
    [MATKAM_CAPS] = COMBO(caps_combo, KC_CAPS),
    [MATKAM_TAB] = COMBO_ACTION(tab_combo),
    [MATKAM_ADDRESS] = COMBO_ACTION(address_combo),
    [MATKAM_KEY_TAB] = COMBO_ACTION(keytab_combo),
    [MATKAM_KEY_UNTAB] = COMBO_ACTION(keyuntab_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case MATKAM_NAV:
            if (pressed) {
                layer_on(NAV);
            } else {
                layer_off(NAV);
            }
            break;
        case MATKAM_COPY:
            if (pressed) {
                tap_code16(LCTL(KC_C));
            }
            break;
        case MATKAM_PASTE:
            if (pressed) {
                tap_code16(LCTL(KC_V));
            }
            break;
        case MATKAM_SAVE:
            if (pressed) {
                tap_code16(LCTL(KC_S));
            }
            break;
        case MATKAM_PALETTE:
            if (pressed) {
                tap_code16(LCTL(KC_P));
            }
            break;
        case MATKAM_UNDO:
        case MATKAM_UNDO2:
            if (pressed) {
                tap_code16(LCTL(KC_Z));
            }
            break;
        case MATKAM_CUT:
            if (pressed) {
                tap_code16(LCTL(KC_X));
            }
            break;
        case MATKAM_FIND:
            if (pressed) {
                tap_code16(LCTL(KC_F));
            }
            break;
        case MATKAM_REPLACE:
            if (pressed) {
                tap_code16(LCTL(KC_R));
            }
            break;
        case MATKAM_CLOSE:
            if (pressed) {
                tap_code16(LCTL(KC_W));
            }
            break;
        case MATKAM_ALL:
            if (pressed) {
                tap_code16(LCTL(KC_A));
            }
            break;
        case MATKAM_LINE:
            if (pressed) {
                tap_code16(LCTL(KC_G));
            }
            break;
        case MATKAM_ADDRESS:
            if (pressed) {
                tap_code16(LCTL(KC_E));
            }
            break;
        case MATKAM_TAB:
            if (pressed) {
                tap_code16(LCTL(KC_T));
            }
            break;
        case MATKAM_KEY_TAB:
            if (pressed) {
                tap_code16(KC_TAB);
            }
            break;
        case MATKAM_KEY_UNTAB:
            if (pressed) {
                tap_code16(S(KC_TAB));
            }
            break;
    }
}

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
    MK_NO_COM,
    MK_YES_COM
};


//Tap Dance Declarations
enum {
  TD_ALT_WIN = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for alt, twice for windows
  [TD_ALT_WIN]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LGUI)
};



// clang-format off
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     [BASE] = LAYOUT_moonlander(
//         KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
//         KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(SYMB),         TG(SYMB), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
//         KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), LGUI_T(KC_QUOT),
//         KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
//     LT(SYMB,KC_GRV),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),    RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
//                                             KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
//     ),

//     [SYMB] = LAYOUT_moonlander(
//         VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//         _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
//         _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
//         _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
//         EEP_RST, _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
//                                             RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, _______
//     ),

//     [MDIA] = LAYOUT_moonlander(
//         LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
//         _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
//         _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
//         _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
//         _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
//                                             _______, _______, _______,           _______, _______, _______
//     ),
// };
// [NAV] = LAYOUT_moonlander(
//    _______, _______, _______, _______, _______, _______, _______,           _______, _______,    _______,    _______,    _______,    _______,    _______,
//    _______, _______, _______, _______, _______, _______, _______,           _______, _______,    _______,    _______,    _______,    _______,    _______,
//    _______, _______, _______, _______,  _______, _______, _______,           _______, _______,   _______,    _______,    _______,    _______,    _______,
//    _______, _______, _______, _______, _______, _______,                             _______,    _______,    _______,    _______,    _______,    _______,
//    _______, _______, _______, _______, _______,  LALT_T(KC_APP),             RCTL_T(KC_ESC),     _______,    _______,    _______,    _______,    _______,
//                                        _______,  _______, _______,           _______,  _______,  _______
// ),


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [COLEMAK] = LAYOUT_moonlander(
        KC_ESC,  _______, _______, _______, _______, _______, RGB_MOD,           RGB_TOG, _______, _______, _______, MK_YES_COM, MK_NO_COM, DF(QWERTY),
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    _______,           _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
        KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    _______,           KC_SLSH, KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_RSFT, KC_RSFT,
        KC_LCTL, WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  MO(RECORD_1),       MO(RECORD_2),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, KC_GRV,
                                            LT(CODE, KC_SPC),  _______, KC_LGUI,           MO(FN),  MO(NUMPAD),  LT(CODE, KC_SPC)
    ),
    [NAV] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______,    _______,    _______,    _______,    _______,    _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______,    _______,    _______,    _______,    _______,    _______,
        _______, _______, KC_HOME, KC_END,  _______, _______, _______,           _______, _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,
        KC_LSFT, _______, KC_LCTL, KC_LSFT, KC_LALT, _______,                             _______,    KC_RSFT,    KC_RCTL,    _______,    _______,    _______,
        KC_LCTL, _______, _______, _______, _______,  LALT_T(KC_APP),             RCTL_T(KC_ESC),     _______,    _______,    _______,    _______,    _______,
                                            KC_PGDN,  _______, _______,           _______,  _______,  KC_PGUP
    ),
    [CODE] = LAYOUT_moonlander(
       _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,                 _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
       _______, S(KC_COMM), KC_LBRC, KC_RBRC,    S(KC_DOT),S(KC_6), _______,               _______, _______,    _______,    _______,    _______,    _______,    _______,
        KC_DEL,  S(KC_9), S(KC_LBRC), S(KC_RBRC), S(KC_0), S(KC_2), S(KC_5),          _______,  S(KC_1), KC_EQL,  KC_SCLN,         S(KC_MINS),S(KC_7),    _______,
       _______, _______,  S(KC_8),    S(KC_EQL),  S(KC_3),_______,                                   _______,    S(KC_4), KC_MINS, KC_SLSH,    _______,    _______,
       _______, _______,  _______, _______, _______, LALT_T(KC_APP),                   RCTL_T(KC_ESC),     _______,    _______,    _______,    _______,    _______,
                                           _______,  _______, _______,                 _______,  _______,  _______
    ),
    [NUMPAD] = LAYOUT_moonlander(
       _______, _______, _______, _______, _______, _______, _______,           _______, _______,    _______,    _______,    _______,    _______,    _______,
       _______, _______, KC_7,    KC_8,    KC_9,    KC_TAB,  _______,           _______, _______,    _______,    _______,    _______,    _______,    _______,
       _______, _______, KC_4,    KC_5,    KC_6,    KC_ENT,  _______,           _______, _______,   _______,    _______,    _______,    _______,    _______,
       _______, _______, KC_1,    KC_2,    KC_3,    KC_DOT,                              _______,    _______,    _______,    _______,    _______,    _______,
       _______, _______, _______, _______, _______,  LALT_T(KC_APP),             RCTL_T(KC_ESC),     _______,    _______,    _______,    _______,    _______,
                                           KC_0  ,  _______, _______,           _______,  _______,  _______
    ),
    [QWERTY] = LAYOUT_moonlander(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DF(COLEMAK),
        KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,           _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LGUI_T(KC_QUOT),
        KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
        KC_GRV,WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),    RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, _______,
                                            KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
    ),
    [FN] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F11,           KC_F12, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______,    _______,    _______,    _______,    _______,    _______,
        _______, _______, _______, _______,  _______, _______, _______,           _______, _______,   _______,    _______,    _______,    _______,    _______,
        _______, _______, _______, _______, _______, _______,                             _______,    _______,    _______,    _______,    _______,    _______,
        _______, _______, _______, _______, _______,  LALT_T(KC_APP),             RCTL_T(KC_ESC),     _______,    _______,    _______,    _______,    _______,
                                            _______,  _______, _______,           _______,  _______,  _______
    ),
    [RECORD_2] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______,    _______,    _______,    _______,    _______,    _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______,    _______,    _______,    _______,    _______,    _______,
        _______, _______, _______, _______,  _______, _______, _______,           _______, _______,   _______,    _______,    _______,    _______,    _______,
        _______, _______, _______, _______, _______, _______,                             _______,    _______,    _______,    _______,    _______,    _______,
        _______, _______, _______, _______, _______,  _______,             _______,     _______,    _______,    _______,    _______,    _______,
                                            DM_REC2,  DM_RSTP, DM_PLY2,           _______,  _______,  _______
    ),
    [RECORD_1] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______,    _______,    _______,    _______,    _______,    _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______,    _______,    _______,    _______,    _______,    _______,
        _______, _______, _______, _______,  _______, _______, _______,           _______, _______,   _______,    _______,    _______,    _______,    _______,
        _______, _______, _______, _______, _______, _______,                             _______,    _______,    _______,    _______,    _______,    _______,
        _______, _______, _______, _______, _______,  _______,             _______,     _______,    _______,    _______,    _______,    _______,
                                            _______,  _______, _______,           DM_REC1,  DM_RSTP,  DM_PLY1
    ),
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case MK_NO_COM:
            if(record->event.pressed){
                combo_disable();
            }
            return false;
        case MK_YES_COM:
            if(record->event.pressed){
                combo_enable();
            }
            return false;
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
