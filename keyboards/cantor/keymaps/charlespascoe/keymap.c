// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

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

#define GBP 0x00A3

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
                               CMD,   LOWER, CTL,         KC_SPC, RAISE, OSM(MOD_LALT)
  ),

  /*
   * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
   * │   │ ! │ @ │ # │ $ │ % │       │ ^ │ & │ * │ ( │ ) │OBs│
   * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
   * │Cap│ _ │ + │ - │ = │   │       │   │   │Ent│ { │ } │ | │
   * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
   * │   │   │   │   │ £ │   │       │   │   │C-l│ [ │ ] │   │
   * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
   */
  [_LOWER] = LAYOUT_split_3x6_3(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,        KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN, LALT(KC_BSPC),
    KC_CAPS, KC_UNDS, KC_PLUS, KC_MINS, KC_EQL,  _______,        _______, _______, KC_ENT,     KC_LCBR, KC_RCBR, KC_PIPE,
    _______, _______, _______, _______, UC(GBP), _______,        _______, _______, LCTL(KC_L), KC_LBRC, KC_RBRC, _______,
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
    _______, KC_1,    KC_2,         KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,         KC_9,          KC_0,     _______,
    _______, _______, LSFT(KC_TAB), KC_TAB,  _______, _______,    KC_LEFT, KC_DOWN, KC_UP,        KC_RIGHT,      KC_END,   KC_BSLS,
    _______, _______, _______,      _______, _______, _______,    _______, _______, LCA(KC_LEFT), LCA(KC_RIGHT), _______,  _______,
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
    _______, RESET, DB_TOGG, _______, _______, _______,    SEND_YES, _______, _______,             _______,              _______, KC_DEL,
    KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5,   KC_F6,      _______,  _______, LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RIGHT)), _______, _______,
    KC_F7,   KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,     SEND_NO,  _______, _______,             _______,              _______, _______,
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
