#include QMK_KEYBOARD_H

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    ALT_LAST,              //last default alt keyboard special key
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

#define LAYER_COLEMAK 0
#define LAYER_QWERTY 1
#define LAYER_FN 2
#define LAYER_CODE 3
#define LAYER_NAV 4
#define LAYER_NUMPAD 5

const uint16_t PROGMEM nav_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM escape_combo[] = {KC_A, KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_V, COMBO_END};
const uint16_t PROGMEM save_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_S, COMBO_END};
const uint16_t PROGMEM pallet_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM undo_combo[] = {KC_N, KC_E, KC_I, KC_O, KC_Z, COMBO_END};
const uint16_t PROGMEM undo2_combo[] = {KC_X, KC_C, KC_D, KC_V, COMBO_END};
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


void process_combo_event(uint8_t combo_index, bool pressed) {
    switch(combo_index) {
        case MATKAM_NAV:
            if (pressed) {
                layer_on(LAYER_NAV);
            } else {
                layer_off(LAYER_NAV);
            }
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

enum my_keycodes {
  MK_NO_COM = ALT_LAST,
  MK_YES_COM
};

keymap_config_t keymap_config;


//Tap Dance Declarations
enum {
  TD_ALT_WIN = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for alt, twice for windows
  [TD_ALT_WIN]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LGUI)
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_COLEMAK] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,          KC_2,         KC_3,    KC_4,    KC_5,    KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,          KC_W,         KC_F,    KC_P,    KC_B,    KC_LBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT, KC_BSLS, KC_HOME, \
        KC_BSPC, KC_A,          KC_R,         KC_S,    KC_T,    KC_G,    KC_RBRC, KC_K,    KC_N,    KC_E,    KC_I,    KC_O,             KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_X,          KC_C,         KC_D,    KC_V,    KC_Z,    KC_SLSH, KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_LCTL, TD(TD_ALT_WIN),MO(LAYER_NAV),                           KC_SPC,                             MO(3),   MO(2),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [LAYER_QWERTY] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             MO(3),   MO(2),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [LAYER_FN] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,  \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END,  \
        KC_CAPS, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END   \
    ),
    [LAYER_CODE] = LAYOUT_65_ansi_blocker(
        _______, _______,  _______,   _______,    _______, _______, _______, _______, _______, _______,         _______,   _______, _______, _______, DF(0), \
        _______, S(KC_COMM), KC_LBRC, KC_RBRC,    S(KC_DOT),S(KC_6),_______, _______, _______, MO(LAYER_NUMPAD),_______,   _______, _______, _______, DF(1), \
        KC_DEL,  S(KC_9), S(KC_LBRC), S(KC_RBRC), S(KC_0), S(KC_2), S(KC_5), S(KC_1), KC_EQL,  KC_SCLN,         S(KC_MINS),S(KC_7),          _______, MK_YES_COM, \
        _______, _______, S(KC_8),    S(KC_EQL),  S(KC_3), _______, _______, S(KC_4), KC_MINS, KC_SLSH,         _______,   _______,          _______, MK_NO_COM, \
        _______, _______, MO(LAYER_NAV),                            _______,                                    _______,   _______, _______, _______, _______  \
    ),
    [LAYER_NAV] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, \
        _______, _______, _______, KC_HOME, KC_END,  _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,          _______, _______, \
        KC_LSFT, _______, KC_LCTL, KC_LSFT, KC_LALT, _______, _______, _______, KC_RSFT, KC_RCTL, _______, _______,          _______, _______, \
        KC_LCTL, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    [LAYER_NUMPAD] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DM_REC1, \
        _______, _______, KC_7,    KC_8,    KC_9,    KC_TAB,  _______, _______, _______, _______, _______, _______, _______, _______, DM_RSTP, \
        KC_BSPC, _______, KC_4,    KC_5,    KC_6,    KC_ENT,  _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, KC_1,    KC_2,    KC_3,    KC_DOT,  _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            KC_0,                               _______, _______, _______, _______, DM_PLY1  \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

// TODO ez ctrl+shift
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

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

        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
