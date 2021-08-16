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

#define _COLEMAK 0 // Colemak DH
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

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
// Windows shortcuts
#define VDESK_L G(C(KC_LEFT))
#define VDESK_R G(C(KC_RIGHT))


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
       KC_ESC, KC_PGUP, KC_HOME,   KC_UP,  KC_END, COPY_UP,                      KC_PLUS,   KC_P7,   KC_P8,   KC_P9,  KC_PERC,_______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PGDN, KC_LEFT, KC_DOWN,KC_RIGHT, COPY_DN,                      KC_MINS,   KC_P4,   KC_P5,   KC_P6, KC_COLN,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX,  CTRL_L, EXPDSEL,  CTRL_R, DELLINE,                        KC_P0,   KC_P1,   KC_P2,   KC_P3,  KC_DOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,   MO(4), _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM, UK_DQUO, KC_HASH,  KC_DLR, KC_PERC,                      KC_PLUS, KC_LPRN, KC_RPRN, MOVE_UP, MTCHBRK, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, UK_CIRC, UK_PIPE, KC_AMPR,  KC_EQL, KC_UNDS,                      KC_MINS, KC_LCBR, KC_RCBR, MOVE_DN, KC_COLN,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, UK_TILD, UK_HASH, KC_ASTR, UK_BSLS,                      KC_SLSH, KC_LBRC, KC_RBRC, _______, KC_QUES, _______,
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


#ifdef OLED_DRIVER_ENABLE
static uint32_t oled_timer = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
//   } else {
//     return OLED_ROTATION_270;
  }
  return rotation;
}


void oled_render_layer_state(void) {
    static const char PROGMEM qwerty_layer[] = {
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x01, 0x01, 0x01, 0x01,
        0};
    static const char PROGMEM colemak_layer[] = {
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x01,
        0x01, 0x01, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x01,
        0x01, 0x01, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0x01,
        0};
    static const char PROGMEM raise_layer[] = {
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x78, 0x79, 0x01, 0x01, 0x7b, 0x7c, 0x7d, 0x7e, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x98, 0x99, 0x01, 0x01, 0x9b, 0x9c, 0x9d, 0x9e, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xb8, 0xb9, 0x01, 0x01, 0xbb, 0xbc, 0xbd, 0xbe, 0x01, 0x01, 0x01, 0x01,
        0};
    static const char PROGMEM lower_layer[] = {
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x73, 0x74, 0x75, 0x76, 0x01, 0x01, 0x78, 0x79, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x93, 0x94, 0x95, 0x96, 0x01, 0x01, 0x98, 0x99, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0xb3, 0xb4, 0xb5, 0xb6, 0x01, 0x01, 0xb8, 0xb9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0};
    static const char PROGMEM adjust_layer[] = {
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x73, 0x74, 0x75, 0x76, 0x01, 0x01, 0x78, 0x79, 0x01, 0x01, 0x7b, 0x7c, 0x7d, 0x7e, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x93, 0x94, 0x95, 0x96, 0x01, 0x01, 0x98, 0x99, 0x01, 0x01, 0x9b, 0x9c, 0x9d, 0x9e, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0xb3, 0xb4, 0xb5, 0xb6, 0x01, 0x01, 0xb8, 0xb9, 0x01, 0x01, 0xbb, 0xbc, 0xbd, 0xbe, 0x01, 0x01, 0x01, 0x01,
        0};
    static const char PROGMEM numlock_on[] = {
        0xd4, 0xd5, 0xd6,
        0};
    static const char PROGMEM numlock_off[] = {
        0x01, 0x01, 0x01,
        0};

    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _COLEMAK:
            oled_write_P(colemak_layer, false);
            break;
        case _QWERTY:
            oled_write_P(qwerty_layer, false);
            break;
        case _LOWER:
            oled_write_P(lower_layer, false);
            break;
        case _RAISE:
            oled_write_P(raise_layer, false);
            break;
        case _ADJUST:
            oled_write_P(adjust_layer, false);
            break;
    }

    led_t led_state = host_keyboard_led_state();
    if (led_state.num_lock) {
        oled_write_P(numlock_on, false);
    } else {
        oled_write_P(numlock_off, false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}


void oled_task_user(void) {
    if (timer_elapsed32(oled_timer) > 60000) {
        oled_off();
        return;
    }

    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
}

#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        oled_timer = timer_read32();
#endif
  }

    return true;
}
