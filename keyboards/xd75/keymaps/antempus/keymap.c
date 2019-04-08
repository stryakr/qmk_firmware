/* Copyright 2018 darm
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

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
#define _BASE_MAC 0
#define _BASE_WIN 1
#define _LOWER 2
#define _RAISE 3
#define _FN 4
#define _EMOJIFY 5

enum emoji_map
{
  UNAM, // unamused 😒
  HEYE, // smiling face with heart shaped eyes 😍
  OK,   // ok hand sign 👌
  SMIR, // smirk 😏
  PRAY, // pray 🙏
  CELE, // celebration 🙌
  COOL, // smile with sunglasses 😎
  EYES, // eyes
  THNK, // BIG THONK
  NAIL, // Nailcare 💅
};
const uint16_t PROGMEM fn_actions[] = {};

const uint32_t PROGMEM unicode_map[] = {
    [UNAM] = 0x1F612,
    [HEYE] = 0x1f60d,
    [OK] = 0x1F44C,
    [SMIR] = 0x1F60F,
    [PRAY] = 0x1F64F,
    [CELE] = 0x1F64C,
    [COOL] = 0x1F60E,
    [EYES] = 0x1F440,
    [THNK] = 0x1F914,
    [NAIL] = 0x1F485,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY-Mac
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |   `    | 1      | 2      | 3      | 4      | 5`     | 6      | 7      | 8      | 9      | 0      | -      | =      | Cut    | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |  ESC   | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | {      | }      | Copy   | Paste  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |  TAB   | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | ENTER  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | \      | RSHIFT | UP     | SAVE   |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |   FN   | LCTL   |  LALT 	|	 LGUI  | _LOWER | SPACE  | SPACE  | _RAISE | LEFT   |  DOWN  |   UP   | RIGHT  | LEFT  | DOWN    | RIGHT   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
    /* QWERTY MAC*/
    [_BASE_MAC] = KEYMAP(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, _______, _______, _______,
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, _______, _______, _______,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, _______, _______, _______,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, _______, _______, _______,
        _______, KC_LCTL, KC_LALT, KC_LGUI, _LOWER, KC_SPC, KC_SPC, _RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______),

    /* QWERTY-Win
  * .--------------------------------------------------------------------------------------------------------------------------------------.
  * | ESC    | 1      | 2      | 3      | 4      | %      | 6     | 7      | 8      | 9      | 0       | -       | =     |         |       |
  * |--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+---------+--------+--------+-----------------|
  * | TAB    | Q      | W      | E      | R      | T      | Y     | U      | I      | O      | P       | {      | }      |        |        |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
  * | CAP LK | A      | S      | D      | F      | G      | H     | J      | K      | L      | ;       | '      |        |        |        |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
  * | LSHIFT | Z      | X      | C      | V      | B      | N     | M      | ,      | .      | /       | \      |  ENTER |        |        |
  * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-------+---------+--------+--------|
  * |        | LGUI   | LALT   |  LCTL  |  LOWER |      SPACE      |  RAISE | LEFT  | DOWN   | UP   |  RIGHT   |        |        |         |
  * '--------------------------------------------------------------------------------------------------------------------------------------'
  */
    /*QWERTY WIN */
    [_BASE_WIN] = KEYMAP(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, _______, _______, _______,
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, _______, _______, _______,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, _______, _______, _______,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, _______, _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, _LOWER, KC_SPC, KC_SPC, _RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______),

    /* LOWER
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

    [_LOWER] = KEYMAP(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /* RAISED
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

    [_RAISE] = KEYMAP(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |  RESET |        |        |        |        |        |        |        |        |        |        |   MAC  |   WIN  |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
    /* OSLAYOUT + NUMPAD + MEDIA + LIGHTING */
    [_FN] = KEYMAP(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _BASE_MAC, _BASE_WIN, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)};

void matrix_init_user(void)
{
  _delay_ms(20); // Gets rid of tick
  set_unicode_input_mode(UC_LNX);
}

/* Template for future layers
 [_LAYER_NAME] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
 }
};
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case _BASE_MAC:
    if (record->event.pressed)
    {
      set_single_persistent_default_layer(_BASE_MAC);
    }
    return false;
    break;
  case _BASE_WIN:
    if (record->event.pressed)
    {
      set_single_persistent_default_layer(_BASE_WIN);
    }
    return false;
    break;
  case _LOWER:
    if (record->event.pressed)
    {
      layer_on(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _FN);
    }
    else
    {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _FN);
    }
    return false;
    break;
  case _RAISE:
    if (record->event.pressed)
    {
      layer_on(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _FN);
    }
    else
    {
      layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _FN);
    }
    return false;
    break;
  }
  return true;
};
