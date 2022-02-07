/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _BASE,
  _BASE_ALT_LEFT,
  _BASE_ALT_RIGHT,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FKEYS,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  SEND_YES,
  SEND_NO,
  CUST_EQ,
};

#define EMDASH 0x2014
#define GBP 0x00A3

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define BAL MO(_BASE_ALT_LEFT)
#define BAR MO(_BASE_ALT_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   F  |   W  |   R  |      |      |      |      |   I  |   L  |   Y  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   T  | BAL  |      |      | BAR  |   E  |   N  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   G  |   C  |   D  | BAL  |      |      | BAR  |   U  |   H  |   M  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  OS  |Lower | Ctrl |Space |Raise | Alt  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    KC_GRV,  KC_F,    KC_W,    KC_R,          _______, BAL,           BAR,     _______, KC_I,          KC_L,    KC_Y,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_T,          BAL,     _______,       _______, BAR,     KC_E,          KC_N,    KC_O,    KC_QUOT,
    KC_LSFT, KC_G,    KC_C,    KC_D,          BAL,     _______,       _______, BAR,     KC_U,          KC_H,    KC_M,    KC_RSFT,
    _______, _______, _______, OSM(MOD_LGUI), LOWER,   OSM(MOD_LCTL), KC_SPC,  RAISE,   OSM(MOD_LALT), _______, _______, _______
),

/* Qwerty (Alternate Left)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |   Q  |   K  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   V  |   B  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   Z  |   X  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE_ALT_LEFT] = LAYOUT_planck_grid(
    _______, _______, KC_Q,    KC_K,    _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_V,    KC_B,    _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_Z,    KC_X,    _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Qwerty (Alternate Right)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |   J  |   ,  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   P  |   :  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   <  |   >  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE_ALT_RIGHT] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_J,    KC_COMM,         LSFT(KC_SLASH), _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P,    LSFT(KC_SCOLON), KC_SCOLON,        _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LT,   KC_GT,           _______,        _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______,        _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |      |      |      |      |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   _  |   +  |   -  |      |      |      |      |Enter |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ^  |   $  |   =  |      |      |      |      |Ctrl-L|   [  |   ]  |  &   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_EXLM, KC_AT,     KC_HASH, _______, _______, _______, _______, KC_ASTR,    KC_LPRN, KC_RPRN, LCTL(KC_BSPC),
    _______, KC_UNDS, KC_PLUS,   KC_MINS, _______, _______, _______, _______, KC_ENT,     KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_CIRC, KC_DOLLAR, CUST_EQ, _______, _______, _______, _______, LCTL(KC_L), KC_LBRC, KC_RBRC, KC_AMPR,
    _______, _______, _______,   _______, _______, _______, _______, _______, _______,    _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |      |      |      |      |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |S-Tab |   %  |   .  | Tab  |      |      |      |      | Down |  Up  |Right |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left |   4  |   5  |      |      |      |      |   6  |   7  | End  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______,      KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, KC_8,    KC_9,    KC_0,     _______,
    LSFT(KC_TAB), KC_PERC, KC_DOT,  KC_TAB,  _______, _______, _______, _______, KC_DOWN, KC_UP,   KC_RIGHT, KC_BSLS,
    _______,      KC_LEFT, KC_4,    KC_5,    _______, _______, _______, _______, KC_6,    KC_7,    KC_END,   KC_SLASH,
    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      | Yes  |  No  | Caps |Reset |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |C-S-L |C-S-R |F Keys|Debug |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |C-A-L |C-A-R |      |UOSX  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, SEND_YES,            SEND_NO,              KC_CAPS,     RESET,
    _______, _______, _______, _______, _______, _______, _______, _______, LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RIGHT)), OSL(_FKEYS), DEBUG,
    _______, _______, _______, _______, _______, _______, _______, _______, LCA(KC_LEFT),        LCA(KC_RIGHT),        _______,     UNICODE_MODE_OSX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,              _______,     _______
),

/* F Keys
 * ,-----------------------------------------------------------------------------------.
 * |      |      | F1   | F2   |      |      |      |      | F3   | F4   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | F5   | F6   |      |      |      |      | F7   | F8   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | F9   | F10  |      |      |      |      | F11  | F12  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FKEYS] = LAYOUT_planck_grid(
    _______, _______, KC_F1,   KC_F2,   _______, _______, _______, _______, KC_F3,   KC_F4,   _______, _______,
    _______, _______, KC_F5,   KC_F6,   _______, _______, _______, _______, KC_F7,   KC_F8,   _______, _______,
    _______, _______, KC_F9,   KC_F10,  _______, _______, _______, _______, KC_F11,  KC_F12,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case UNICODE_MODE_LNX:
      if (record->event.pressed){
        SEND_STRING("L");
      }
      // Continue to process the key as normal
      return true;
      break;
    case UNICODE_MODE_OSX:
      if (record->event.pressed){
        SEND_STRING("M");
      }
      // Continue to process the key as normal
      return true;
      break;
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;
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

    case CUST_EQ: {
      // Fixes some issues when typing equals straight after colon (because
      // colon is also the left shift)
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_EQUAL);
      } else {
        unregister_code(KC_EQUAL);
      }

      return false;
      break;
    }
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
