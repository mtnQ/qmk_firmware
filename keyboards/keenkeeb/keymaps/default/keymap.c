#include "keenkeeb.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

/***********************************************************************
 * Layers
 **********************************************************************/
 
#define FN_SPC  LT(_FN, KC_SPC)

typedef enum {
    _BASE = 0,
    _MEDIA,
    _FN
} __LAYERS;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 //    1        2        3        4        5        6        7        8        9       1 0      1 1      1 2      1 3   
    
 [_BASE] = {    
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS },
  { KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
  { KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
  { KC_LCTL, KC_LGUI, XXXXXXX, KC_LALT, XXXXXXX, XXXXXXX, MO(_FN), XXXXXXX, KC_SPC,  KC_RALT, KC_RGUI, KC_APP,  KC_RCTL },
 },
 
 /*
 [_MEDIA] = {
  { _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU },
  { _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
 },
  */
 
 [_FN] = {
  { KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  },
  { KC_PSCR, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, XXXXXXX, XXXXXXX, KC_PGUP, KC_UP,   KC_PGDN, XXXXXXX, KC_SLCK },
  { KC_DEL , XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_MOD, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_INS  },
  { _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, KC_CAPS },
  { _______, _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_ENT,  _______, _______, XXXXXXX, _______ },
 },
     
};

const uint16_t PROGMEM fn_actions[] = {

};

/***********************************************************************
 * Macros
 **********************************************************************/

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    return MACRO_NONE;    
};
