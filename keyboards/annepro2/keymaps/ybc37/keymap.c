#include QMK_KEYBOARD_H
#include "config.h"

enum anne_pro_layers {
  BASE_LAYER,
  FN1_LAYER,
  MOUSE_LAYER,
  NUM_LAYER,
  FN2_LAYER,
  DIRECT_LAYER,
};

enum {
    TD_LSFT_CAPS
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};


// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |q/Num|  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Esc/Ctrl|  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift/Caps |z/MS |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |             Space/FN1           |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [BASE_LAYER] = LAYOUT_60_ansi( /* Base */
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, LT(NUM_LAYER, KC_Q), KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    MT(MOD_LCTL,KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    TD(TD_LSFT_CAPS), LT(MOUSE_LAYER, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, LT(FN1_LAYER,KC_SPC), KC_RALT, MO(FN1_LAYER), MO(FN2_LAYER), KC_RCTL
),

  /*
  * Layer FN1_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |q/Num|MSTP |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc/Crtl|MPRV |MPLY |MNXT |  f  |  g  |LEFT |DOWN | UP  |RIGHT| PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift/Caps |V-UP |V-DWN|MUTE |  v  |  b  |  n  | APP |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |             Space/FN1           |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
[FN1_LAYER] = LAYOUT_60_ansi(
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    KC_TRNS, KC_TRNS, KC_MSTP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_PAUSE,
    KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_APP, KC_TRNS, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

  /*
  * Layer MOUSE_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |q/Num|  w  |  e  |  r  |  t  |  y  |MWHL | MUP |MWHR |MWHU |  [  |  ]  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc/Crtl|  a  |  s  |  d  |  f  |  g  |  h  |MLEFT|MDOWN|MRGHT|MWHD |  '  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift/Caps |z/MS |x/MB1|c/MB2|v/MB3|  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |             Space/MB1           |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [MOUSE_LAYER] = LAYOUT_60_ansi(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_WH_LEFT, KC_MS_UP, KC_MS_WH_RIGHT, KC_MS_WH_UP, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

  /*
  * Layer NUM_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |q/Num|  w  |  e  |  r  |  t  |  y  |  7  |  8  |  9  |  p  |  [  |  ]  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc/Crtl|  a  |  s  |  d  |  f  |  g  |  0  |  4  |  5  |  6  |  ;  |  '  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift/Caps |z/MS |  x  |  c  |  v  |  b  |  n  |  1  |  2  |  3  |  /  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |             Space/FN1           |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [NUM_LAYER] = LAYOUT_60_ansi(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

  /*
  * Layer FN2_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 |  F7 |LEDOF|LEDON|LEDIN|LEDSP| F12 |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |q/Num|  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc/Ctrl|  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift/Caps |z/MS |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |             Space/FN1           |  Alt  |DIRECT |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN2_LAYER] = LAYOUT_60_ansi(
    KC_TRNS, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AP_RGB_MOD, KC_AP_RGB_TOG, KC_AP_RGB_VAD, KC_AP_RGB_VAI, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_PAUSE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(DIRECT_LAYER), KC_TRNS, KC_TRNS
 ),

 [DIRECT_LAYER] = LAYOUT_60_ansi(
    QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, TG(DIRECT_LAYER), KC_TRNS, KC_RCTL
),

};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

// // Code to run after initializing the keyboard
// void keyboard_post_init_user(void) {
//     // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"
//
//     // annepro2-shine disables LEDs by default. Uncomment this function to enable them at startup.
//     annepro2LedEnable();
//
//     // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
//     // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
//     annepro2LedSetProfile(0);
//
//     // TODO: Set intensity to lowest
//     // Looping doesn't seem to work reliable
//     // for (int i = 0; i < 7; i++) {
//     //     annepro2LedNextIntensity();
//     // }
// }

// layer_state_t layer_state_set_user(layer_state_t layer) {
//     return layer;
// }

// void keyboard_post_init_user(void) {
//     ap2_led_enable();
//     ap2_led_set_profile(7);
//     ap2_led_set_foreground_color(0xcc, 0xcc, 0xcc);
//     ap2_led_reset_foreground_color();
//
//     const ap2_led_t color = {
//         .p.red = 0xff,
//         .p.green = 0xff,
//         .p.blue = 0xff,
//         .p.alpha = 0x01
//     };
//     ap2_led_mask_set_mono(color);
// }

// bool led_update_user(led_t leds) {
//   if (leds.caps_lock) {
//     const ap2_led_t color = {
//         .p.red = 0xff,
//         .p.green = 0x00,
//         .p.blue = 0x00,
//         .p.alpha = 0xff
//     };
//
//     ap2_led_sticky_set_key(3, 0, color);
//   } else {
//     // const annepro2Led_t color = {
//     //     .p.red = 0xff,
//     //     .p.green = 0x00,
//     //     .p.blue = 0x00,
//     //     .p.alpha = 0x00
//     // };
//
//     ap2_led_unset_sticky_key(3, 0);
//   }
//
//   return true;
// }

// // The function to handle the caps lock logic
// // It's called after the capslock changes state or after entering layers 1 and 2.
// bool led_update_user(led_t leds) {
//     if (leds.caps_lock) {
//         // Set the caps-lock to red
//         const ap2_led_t color = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};
//         ap2_led_sticky_set_key(2, 0, color);
//         /* NOTE: Instead of colouring the capslock only, you can change the whole
//            keyboard with ap2_led_mask_set_mono */
//     } else {
//         // Reset the capslock if there is no layer active
//         ap2_led_unset_sticky_key(2, 0);
//     }
//
//     return true;
// }
