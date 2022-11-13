#include QMK_KEYBOARD_H
#include "version.h"
//#include "keymap_us_international.h"
#include "sendstring_us_international.h"

enum combo_events {
  WR_COMBO,
  IO_COMBO,
  OP_COMBO,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};

combo_t key_combos[] = {
        [WR_COMBO] = COMBO(wr_combo, KC_LEAD),
        [IO_COMBO] = COMBO(io_combo, KC_ENTER),
        [OP_COMBO] = COMBO(op_combo, LSFT(LCTL(KC_MINUS)))
};


const key_override_t space_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPACE, KC_BSPC);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&space_key_override,
	NULL // Null terminate the array of overrides!
};


enum custom_keycodes {
  ST_MACRO_QUOTE = SAFE_RANGE,
  ST_MACRO_DQUOTE,
  MY_PIPE,
  MY_LCBR
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(KC_Q, KC_W, KC_E, KC_R, KC_T,                                KC_Y, KC_U, KC_I, KC_O, KC_P,
                                 LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), KC_F, KC_G,        KC_H, KC_J, LCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
                                 KC_Z, KC_X, KC_C, KC_V, KC_B,                                KC_N, KC_M, RCTL_T(KC_COMM), LALT_T(KC_DOT), KC_SLSH,
                                 KC_SPC, MO(1),                                               TT(2), OSM(MOD_LSFT)),
        
	[1] = LAYOUT_split_3x5_2(KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,
                                 LGUI_T(KC_TAB), KC_NO, KC_NO, KC_NO, KC_NO,                  KC_LEFT, KC_DOWN, RCTL_T(KC_UP), RALT_T(KC_RGHT), RGUI_T(KC_QUOT),
                                 US_EURO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_NO,
                                 KC_TRNS, KC_TRNS,                                            MO(3), LSFT_T(KC_DEL)),
        
	[2] = LAYOUT_split_3x5_2(KC_ESC, KC_BSLS, KC_LPRN, KC_RPRN, ST_MACRO_DQUOTE,          KC_NO, KC_7, KC_8, KC_9, KC_ASTR,
                                 LGUI_T(KC_TAB), MY_PIPE, MY_LCBR, KC_RCBR, ST_MACRO_QUOTE,   KC_NO, KC_4, KC_5, KC_6, KC_ENT,
                                 KC_GRV, KC_TILD, KC_LBRC, KC_RBRC, KC_NO,                    KC_0, KC_1, KC_2, LALT_T(KC_3), KC_DOT,
                                 KC_SPC, MO(3),                                               KC_TRNS, KC_TRNS),
        
	[3] = LAYOUT_split_3x5_2(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                           RESET, KC_F7, KC_F8, KC_F9, KC_F10,
                                 DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, KC_NO, KC_NO, KC_NO,       KC_NO, KC_F4, KC_F5, KC_F6, KC_F11,
                                 DM_REC1, DM_REC2, DM_RSTP, KC_NO, KC_NO,                     KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,
                                 KC_TRNS, KC_TRNS,                                            KC_TRNS, KC_TRNS),

       	[4] = LAYOUT_split_3x5_2(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                           KC_NO, KC_NO, KC_MS_UP, KC_NO, KC_NO,
                                 KC_NO, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_NO,      KC_NO, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_NO,
                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                 TO(0), KC_MS_BTN3,                                           KC_MS_BTN1, KC_MS_BTN2)
};

LEADER_EXTERNS();
void matrix_scan_user(void) {
        LEADER_DICTIONARY() {
                leading = false;
                leader_end();
                SEQ_ONE_KEY(KC_O) {
                        layer_invert(4);
                }
                SEQ_TWO_KEYS(KC_W, KC_M) {
                        SEND_STRING("mathis@mptechnology.ch");
                }
                SEQ_THREE_KEYS(KC_W, KC_M, KC_H) {
                        SEND_STRING("michel.mathis@helvetia.ch");
                }
                SEQ_TWO_KEYS(KC_W, KC_P) {
                        SEND_STRING("+41 44 296 67 05");
                }

                SEQ_TWO_KEYS(KC_P, KC_M) {
                        SEND_STRING("michel@mathisweb.ch");
                }
                SEQ_TWO_KEYS(KC_P, KC_P) {
                        SEND_STRING("+41 79 819 64 75");
                }
                SEQ_THREE_KEYS(KC_P, KC_P, KC_H) {
                        SEND_STRING("+41 32 510 27 13");
                }
        }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        static uint16_t my_pipe_timer;
        static uint16_t my_lcbr_timer;

        switch (keycode) {
        case MY_PIPE:
                if(record->event.pressed) {
                        my_pipe_timer = timer_read();
                        register_code(KC_LALT); // Change the key to be held here
                } else {
                        unregister_code(KC_LALT); // Change the key that was held here, too!
                        if (timer_elapsed(my_pipe_timer) < TAPPING_TERM) {
                                SEND_STRING("|"); // Change the character(s) to be sent on tap here
                        }
                }
                return false; // We handled this keypress

        case MY_LCBR:
                if(record->event.pressed) {
                        my_lcbr_timer = timer_read();
                        register_code(KC_LCTRL); // Change the key to be held here
                } else {
                        unregister_code(KC_LCTRL); // Change the key that was held here, too!
                        if (timer_elapsed(my_lcbr_timer) < TAPPING_TERM) {
                                SEND_STRING("{"); // Change the character(s) to be sent on tap here
                        }
                }
                return false; // We handled this keypress
                //
        case ST_MACRO_QUOTE:
                if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_SPACE));
                }
                break;
        case ST_MACRO_DQUOTE:
                if (record->event.pressed) {
                        SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(100) SS_TAP(X_SPACE));
                }
                break;
        }
        return true;
}





