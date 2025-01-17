/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

// select hand configuration
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

#define LAYER_STATE_8BIT

#define OLED_TIMEOUT 10000

// prevent normal rollover on alphas from accidentally triggering mods
#define IGNORE_MOD_TAP_INTERRUPT

#define COMBO_COUNT 6

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define OLED_FONT_H "keyboards/crkbd/keymaps/getsetjoe/glcdfont.c"
