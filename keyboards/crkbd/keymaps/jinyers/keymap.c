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

// Left side HOME ROW
#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define SFT_D MT(MOD_LSFT, KC_D)
#define CTL_F MT(MOD_LCTL, KC_F)

// Right side HOME ROW
#define CTL_J    MT(MOD_RCTL, KC_J)
#define SFT_K    MT(MOD_RSFT, KC_K)
#define ALT_L    MT(MOD_RALT, KC_L)
#define GUI_SCLN MT(MOD_RGUI, KC_SCLN)

#define US_PRWD  C(KC_LEFT)
#define US_NXWD  C(KC_RIGHT)

#define KEYBOARD_CLEAR {0, 46, HSV_OFF}

enum layers {
    _BASE,
    _NUMB,
    _SYMB,
    _CTRL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3_ex2(
    KC_TAB,  KC_Q,  KC_W,  KC_E,    KC_R,      KC_T,   KC_NO,        KC_NO,    KC_Y,    KC_U,      KC_I,     KC_O,    KC_P,     KC_ESC,
    KC_LCTL, GUI_A, ALT_S, SFT_D,   CTL_F,     KC_G,   KC_NO,        KC_NO,    KC_H,    CTL_J,     SFT_K,    ALT_L,   GUI_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,  KC_X,  KC_C,    KC_V,      KC_B,                           KC_N,    KC_M,      KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
                          KC_CAPS, MO(_NUMB), KC_SPC,                           KC_ENT,  MO(_SYMB), KC_BSPC
  ),

  [_NUMB] = LAYOUT_split_3x6_3_ex2(
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,       KC_TRNS,   KC_6,    KC_7,       KC_8,    KC_9,     KC_0,    KC_TRNS,
    KC_TRNS, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_TRNS,       KC_TRNS,   KC_LEFT, KC_DOWN,    KC_UP,   KC_RIGHT, XXXXXXX, KC_TRNS,
    KC_TRNS, XXXXXXX, XXXXXXX, KC_INS,  KC_DEL,  XXXXXXX,                           US_PRWD, XXXXXXX,    XXXXXXX, US_NXWD,  XXXXXXX, KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, MO(_CTRL),  KC_TRNS
  ),

  [_SYMB] = LAYOUT_split_3x6_3_ex2(
// |       |        |    <   |    =   |    >    |    `   |        |      |       |    ^   |    [   |    ~   |    ]   |    ?   |        |
    KC_TRNS, XXXXXXX,  KC_LT,  KC_EQL,   KC_GT,   KC_GRV,  KC_TRNS,       KC_TRNS, KC_CIRC, KC_LBRC, KC_TILD, KC_RBRC, KC_QUES, KC_TRNS,
// |       |    \   |    (   |    -   |    )    |    +   |        |      |       |    %   |    {   |    _   |    }   |    !   |        |
    KC_TRNS, KC_NUHS, KC_LPRN, KC_MINS, KC_RPRN,  KC_PLUS, KC_TRNS,       KC_TRNS, KC_PERC, KC_LCBR, KC_UNDS, KC_RCBR, KC_EXLM, XXXXXXX,
// |       |        |    *   |    :   |    /    |    $   |        |      |       |    @   |    |   |    #   |    &   |        |        |
    KC_TRNS, XXXXXXX, KC_ASTR, KC_COLN, KC_SLSH,  KC_DLR,                          KC_DQUO, KC_PIPE, KC_HASH, KC_AMPR, XXXXXXX, XXXXXXX,
//                            |       |          |        |                       |       |        |        |
                              KC_TRNS, MO(_CTRL), KC_TRNS,                          KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_CTRL] = LAYOUT_split_3x6_3_ex2(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,       KC_TRNS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,       KC_TRNS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                              KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS
  )
};

const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  KEYBOARD_CLEAR
);
/*
  18, 17, 12, 11, 04, 03, 22,     45, 26, 27, 34, 35, 40, 41
  19, 16, 13, 10, 05, 02, 21,     44, 25, 28, 33, 36, 39, 42
  20, 15, 14, 09, 06, 01,             24, 29, 32, 37, 38, 43
              08, 07, 00              23, 30, 31
*/
const rgblight_segment_t PROGMEM number_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  KEYBOARD_CLEAR,
  // Left side
  { 2, 6, HSV_RED},
  { 9, 5, HSV_RED},
  {17, 1, HSV_RED},

  // Right side
  {24, 5, HSV_RED},
  {30, 1, HSV_RED},
  {33, 5, HSV_RED},
  {40, 1, HSV_RED}
);

const rgblight_segment_t PROGMEM symbols_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  KEYBOARD_CLEAR,
  // Left side
  { 1, 6, HSV_GREEN},
  { 9, 6, HSV_GREEN},
  {16, 1, HSV_GREEN},

  // Right side
  {24, 7, HSV_GREEN},
  {32, 6, HSV_GREEN},
  {39, 2, HSV_GREEN}
);

const rgblight_segment_t PROGMEM controls_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  KEYBOARD_CLEAR,
  {18, 1, HSV_YELLOW}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  base_layer,
  number_layer,
  symbols_layer,
  controls_layer
);

void keyboard_post_init_user(void) {
  rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(1, layer_state_cmp(state, _NUMB));
  rgblight_set_layer_state(2, layer_state_cmp(state, _SYMB));
  rgblight_set_layer_state(3, layer_state_cmp(state, _CTRL));
  return state;
}