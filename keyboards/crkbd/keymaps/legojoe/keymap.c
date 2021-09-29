/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_uk.h"

#define CTALTDL LCA(KC_DEL)
#define OS_LSFT OSM(MOD_LSFT)
// VS Code shortcuts
#define CTRL_L  C(KC_LEFT)
#define CTRL_R  C(KC_RIGHT)
#define COPY_UP LSA(KC_UP)
#define COPY_DN LSA(KC_DOWN)
#define EXPDSEL LSA(KC_RIGHT) // expand selection
#define DELLINE C(S(KC_K))
#define MOVE_UP A(KC_UP)
#define MOVE_DN A(KC_DOWN)
#define MTCHBRK C(S(UK_BSLS))
#define UNDO    C(KC_Z)
#define REDO    C(KC_Y)
#define GRT_THN S(KC_DOT)
// Windows shortcuts
#define VDESK_L G(C(KC_LEFT))
#define VDESK_R G(C(KC_RIGHT))

enum layers {
  _COLEMAK, // Colemak DH
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OS_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, UK_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   MO(2),  KC_SPC,     KC_SPC,   MO(3), KC_LGUI
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_PGUP, KC_HOME,   KC_UP,  KC_END, MOVE_UP,                      KC_PLUS,   KC_P7,   KC_P8,   KC_P9, KC_PERC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PGDN, KC_LEFT, KC_DOWN,KC_RIGHT, MOVE_DN,                      KC_MINS,   KC_P4,   KC_P5,   KC_P6, KC_COLN,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    UNDO,  CTRL_L, EXPDSEL,  CTRL_R, DELLINE,                        KC_P0,   KC_P1,   KC_P2,   KC_P3,  KC_DOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,   MO(4), _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM, UK_DQUO, KC_HASH,  KC_DLR, KC_PERC,                      KC_PLUS, KC_LPRN, KC_RPRN, COPY_UP, MTCHBRK, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, UK_CIRC, UK_PIPE, KC_AMPR,  KC_EQL, KC_UNDS,                      KC_MINS, KC_LCBR, KC_RCBR, COPY_DN, KC_COLN,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    REDO, UK_TILD, UK_HASH, KC_ASTR, UK_BSLS,                      KC_SLSH, KC_LBRC, KC_RBRC, GRT_THN, KC_QUES, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   MO(4), _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RGB_TOG,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, RGB_HUI, RGB_SAI, RGB_VAI, VDESK_L, KC_PSCR,                      XXXXXXX, VDESK_R, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,   DF(0),                        DF(1), XXXXXXX, XXXXXXX, CTALTDL, KC_NLCK,RGB_RMOD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OS_LSFT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, UK_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   MO(2),  KC_SPC,     KC_SPC,   MO(3), KC_LGUI
                                      //`--------------------------'  `--------------------------'
  )
};


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return OLED_ROTATION_270;
}

void oled_render_logo(void) {
  static const char PROGMEM corne_logo[] = {
                                                                                                                            //21
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x93,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB3,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD3,
    0};
  oled_write_P(corne_logo, false);
} 

void oled_render_mini_logo(void) {
  static const char PROGMEM mini_corne_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
  oled_write_P(mini_corne_logo, false);
  oled_write_P(PSTR("corne"), false);
}

void oled_render_layer_state(void) {
  static const char PROGMEM default_layer[] = {
    0x20, 0x94, 0x95, 0x96, 0x20,
    0x20, 0xb4, 0xb5, 0xb6, 0x20,
    0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
  static const char PROGMEM raise_layer[] = {
    0x20, 0x97, 0x98, 0x99, 0x20,
    0x20, 0xb7, 0xb8, 0xb9, 0x20,
    0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
  static const char PROGMEM lower_layer[] = {
    0x20, 0x9a, 0x9b, 0x9c, 0x20,
    0x20, 0xba, 0xbb, 0xbc, 0x20,
    0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
  static const char PROGMEM adjust_layer[] = {
    0x20, 0x9d, 0x9e, 0x9f, 0x20,
    0x20, 0xbd, 0xbe, 0xbf, 0x20,
    0x20, 0xdd, 0xde, 0xdf, 0x20, 0};

  switch (get_highest_layer(layer_state|default_layer_state)) {
    case _LOWER:
      oled_write_P(lower_layer, false);
      break;
    case _RAISE:
      oled_write_P(raise_layer, false);
      break;
    case _ADJUST:
      oled_write_P(adjust_layer, false);
      break;
    default:
      oled_write_P(default_layer, false);
  }
}

void oled_render_led_state(void) {
  // static const char PROGMEM numlock_on[] = {
  //   0x85, 0x86, 0x87, 0x88, 0x89,
  //   0xa5, 0xa6, 0xa7, 0xa8, 0xa9,
  //   0};
  // static const char PROGMEM numlock_off[] = {
  //   0x20, 0x20, 0x20, 0x20, 0x20,
  //   0x20, 0x20, 0x20, 0x20, 0x20,
  //   0};

  led_t led_state = host_keyboard_led_state();

  if (led_state.num_lock) {
    oled_write_P(PSTR(" num "), false);
  } else {
    oled_write_P(PSTR("     "), false);
  }
}

void oled_render_layout_state(void) {
  // static const char PROGMEM colemak[] = {
  //   0x8a, 0x8b, 0x8c, 0x8d, 0x8e,
  //   0xaa, 0xab, 0xac, 0xad, 0xae,
  //   0};
  // static const char PROGMEM qwerty[] = {
  //   0x20, 0x20, 0x20, 0x20, 0x20,
  //   0x20, 0x20, 0x20, 0x20, 0x20,
  //   0};

  switch (get_highest_layer(layer_state|default_layer_state)) {
    case _COLEMAK:
      oled_write_P(PSTR(" k:c "), false);
      break;
    case _QWERTY:
      oled_write_P(PSTR(" k:q "), false);
      break;
  }
}

void oled_render_space(void) {
  oled_write_P(PSTR("     "), false);
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_space();
    oled_render_space();
    oled_render_mini_logo();
    oled_render_space();
    oled_render_layer_state();
    oled_render_space();
    oled_render_led_state();
    oled_render_space();
    oled_render_layout_state();
  } else {
    oled_render_logo();
    oled_scroll_left();
  }
}

#endif // OLED_ENABLE

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
  
//   }

//   return true;
// }
