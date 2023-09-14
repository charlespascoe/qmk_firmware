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

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum keycodes {
  SEND_YES = SAFE_RANGE,
  SEND_NO,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define CMD OSM(MOD_LGUI)
#define CTL OSM(MOD_LCTL)
#define ALT OSM(MOD_LALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
   * │ ` │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
   * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
   * │Esc│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
   * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
   * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
   * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
   *               ┌───┐                   ┌───┐
   *               │Cmd├───┐           ┌───┤Alt│
   *               └───┤Lwr├───┐   ┌───┤Rse├───┘
   *                   └───┤Ctl│   │Spc├───┘
   *                       └───┘   └───┘
   */
  [_QWERTY] = LAYOUT_split_3x6_3(
    KC_GRV,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,        KC_Y,   KC_U,  KC_I,          KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,  KC_F,  KC_G,        KC_H,   KC_J,  KC_K,          KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,        KC_N,   KC_M,  KC_COMM,       KC_DOT,  KC_SLSH, KC_RSFT,
                               CMD,   LOWER, CTL,         KC_SPC, RAISE, ALT
  ),

  /*
   * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
   * │   │ ! │ @ │ # │ $ │ % │       │ ^ │ & │ * │ ( │ ) │OBs│
   * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
   * │Cap│ _ │ + │ - │ = │   │       │   │   │Ent│ { │ } │ | │
   * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
   * │   │   │   │   │   │   │       │   │   │C-l│ [ │ ] │   │
   * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
   */
  [_LOWER] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,        KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN, LALT(KC_BSPC),
    KC_CAPS, KC_UNDS, KC_PLUS, KC_MINS, KC_EQL,  XXXXXXX,        XXXXXXX, XXXXXXX, KC_ENT,     KC_LCBR, KC_RCBR, KC_PIPE,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, LCTL(KC_L), KC_LBRC, KC_RBRC, XXXXXXX,
                               _______, _______, _______,        _______, _______, _______
  ),

  /*
   * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
   * │   │ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │   │
   * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
   * │   │   │STb│Tab│   │   │       │Lft│Dwn│Up │Rgt│End│ \ │
   * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
   * │   │   │   │   │   │   │       │   │   │CAL│CAR│   │   │
   * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
   */
  [_RAISE] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_1,    KC_2,         KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,         KC_9,          KC_0,     _______,
    XXXXXXX, XXXXXXX, LSFT(KC_TAB), KC_TAB,  XXXXXXX, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP,        KC_RIGHT,      KC_END,   KC_BSLS,
    XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, LCA(KC_LEFT), LCA(KC_RIGHT), XXXXXXX,  XXXXXXX,
                                    _______, _______, _______,    _______, _______, _______
  ),

  /*
   * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
   * │   │Rst│Dbg│   │   │   │       │Yes│   │   │   │   │   │
   * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
   * │F1 │F2 │F3 │F4 │F5 │F6 │       │   │   │CSL│CSR│   │   │
   * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
   * │F7 │F8 │F9 │F10│F11│F12│       │No │   │   │   │   │   │
   * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
   */
  [_ADJUST] = LAYOUT_split_3x6_3(
    XXXXXXX, QK_RBT, DB_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,    SEND_YES, XXXXXXX, XXXXXXX,             XXXXXXX,              XXXXXXX, KC_DEL,
    KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,      XXXXXXX,  XXXXXXX, LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RIGHT)), XXXXXXX, XXXXXXX,
    KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,  KC_F12,     SEND_NO,  XXXXXXX, XXXXXXX,             XXXXXXX,              XXXXXXX, XXXXXXX,
                              _______, _______, _______,    _______,  _______, _______
  ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SEND_YES:
      if (record->event.pressed) {
        SEND_STRING("y\n");
      }
      return false;
      break;
    case SEND_NO:
      if (record->event.pressed) {
        SEND_STRING("n\n");
      }
      return false;
      break;
  }

  return true;
}
