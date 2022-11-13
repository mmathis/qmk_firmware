#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL


const key_override_t space_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPACE, KC_BSPC);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&space_key_override,
	NULL // Null terminate the array of overrides!
};


enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  MY_PIPE,
  MY_LCBR
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRNS,                                 KC_TRNS, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRNS, 
    KC_TRNS, MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_D),KC_F,           KC_G,           KC_TRNS,                                                                 KC_TRNS, KC_H,           KC_J,           MT(MOD_LCTL, KC_K),MT(MOD_RALT, KC_L),MT(MOD_RGUI, KC_SCOLON),KC_TRNS, 
    KC_TRNS, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           MT(MOD_RCTL, KC_COMMA),MT(MOD_LALT, KC_DOT),KC_SLASH,       KC_TRNS, 
    TO(4),          KC_TRNS, KC_TRNS, KC_TRNS, KC_SPACE,       KC_TRNS,                                                                                                 KC_TRNS, OSM(MOD_LSFT),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    MO(1),          KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, TT(2)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRNS,                                 KC_TRNS, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_MINUS,       KC_EQUAL,       KC_TRNS, 
    KC_TRNS, MT(MOD_LGUI, KC_TAB),KC_TRNS, ST_MACRO_0,     ST_MACRO_1,     KC_TRNS, KC_TRNS,                                                                 KC_TRNS, KC_LEFT,        KC_DOWN,        MT(MOD_RCTL, KC_UP),MT(MOD_RALT, KC_RIGHT),MT(MOD_RGUI, KC_QUOTE),KC_TRNS, 
    KC_TRNS, US_EURO,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_HOME,        KC_END,         KC_PGUP,        KC_PGDOWN,      KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                                                 KC_TRNS, MT(MOD_LSFT, KC_DELETE),KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, MO(3)
  ),
  [2] = LAYOUT_moonlander(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_ESCAPE,      KC_BSLASH,      KC_LPRN,        KC_RPRN,        KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_TRNS, 
    KC_TRNS, MT(MOD_LGUI, KC_TAB), MY_PIPE,        MY_LCBR,        KC_RCBR,        KC_TRNS, KC_TRNS,                                                                 KC_TRNS, KC_TRNS, KC_4,           MT(MOD_RCTL, KC_5),MT(MOD_RALT, KC_6),MT(MOD_RGUI, KC_ENTER),KC_TRNS, 
    KC_TRNS, KC_GRAVE,       KC_TILD,        KC_LBRACKET,    KC_RBRACKET,    KC_TRNS,                                 KC_0,           KC_1,           KC_2,           MT(MOD_LALT, KC_3),KC_DOT,         KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPACE,      KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    MO(3),          KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [3] = LAYOUT_moonlander(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, RGB_MOD,        RGB_TOG,        KC_BRIGHTNESS_UP,RGB_VAI,        RGB_HUI,        KC_TRNS,                                 KC_TRNS, RESET,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRNS, 
    KC_TRNS, DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,KC_BRIGHTNESS_DOWN,RGB_VAD,        RGB_HUD,        KC_TRNS,                                                                 KC_TRNS, WEBUSB_PAIR,    KC_F4,          KC_F5,          KC_F6,          KC_F11,         KC_TRNS, 
    KC_TRNS, DYN_REC_START1, DYN_REC_START2, DYN_REC_STOP,   KC_MS_BTN3,     KC_TRNS,                                 KC_TRNS, KC_F1,          KC_F2,          KC_F3,          KC_F12,         KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [4] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRNS,                                 KC_TRNS, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_GRAVE,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_EQUAL,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLASH,      
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_TRNS, KC_HOME,                                                                        KC_END,         KC_TRNS, KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,       
    KC_LSHIFT,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSHIFT,      
    TO(0),          KC_LEFT,        KC_RIGHT,       KC_NO,          KC_TRNS, KC_TRNS,                                                                                                 KC_TRNS, MT(MOD_RALT, KC_LBRACKET),KC_RBRACKET,    KC_UP,          MT(MOD_RCTL, KC_DOWN),KC_TRNS, 
    KC_LCTRL,       KC_LALT,        KC_LGUI,                        KC_TRNS, KC_TRNS, KC_ENTER
  ),
};


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
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_SPACE));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(100) SS_TAP(X_SPACE));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


