/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion
#define WIN 3 // window manager (stump)
#define TEN 4 // ten key

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * | L1/ESC |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * | TEN/BS |   A  |   S  |ALT/D |CTL/F |   G  | RMB  |           |      |   H  |CTL/J |ALT/K |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | LMB  |           |      |   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .----------.                                 .----------.   .------.
 *                    | SHIFT    |   |SYMB/Space|                                 |SYMB/Space|   |SHIFT |
 *                    '----------'   '----------'                                 `----------.   '------'
 *                                        ,-------.                      ,-------.
 *                                        |       |                      |       |
 *                                 ,------|-------|                      |-------|------.
 *                                 | NUMB | CTRL/ |                      | WIN/  | NUMB |
 *                                 | ESC  | ALT/  |                      | TAB   |Enter |
 *                                 |      | '     |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[BASE] = LAYOUT_gergo(
LT(NUMB, KC_TAB),  KC_Q,  KC_W,   KC_E,           KC_R,         KC_T,                                             KC_Y, KC_U,         KC_I,         KC_O,   KC_P,    KC_PIPE,
LT(TEN, KC_BSPC),  KC_A,  KC_S,   LALT_T(KC_D),   LCTL_T(KC_F), KC_G, TT(TEN),                          KC_TRNS,  KC_H, RCTL_T(KC_J), LALT_T(KC_K), KC_L,   KC_SCLN, KC_QUOT,
KC_RSFT,           KC_Z,  KC_X,   KC_C,           KC_V,         KC_B, KC_BTN1, KC_TRNS,       KC_BSPC,  KC_BSPC,  KC_N, KC_M,         KC_COMM,      KC_DOT, KC_SLSH, KC_MINS,

           KC_RSFT, LT(SYMB, KC_BSPC), LT(NUMB, KC_ESC), KC_LGUI,                                             KC_TAB, LT(NUMB, KC_ENT), LT(SYMB, KC_SPC), KC_RSFT),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                         |      |  M1  |  M2  |  M3  |  M4  |  M5    |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |      |           |      |   +  |  -   |  /   |  *   |  %   |  _     |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |   &  |  =   |  ,   |  .   |  /   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   | DEL |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |   ;  |   =   |                     |   =   |   ;  |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[SYMB] = LAYOUT_gergo(
KC_TRNS, KC_EXLM, KC_AT,  KC_LCBR,KC_RCBR, KC_PIPE,                                           KC_TRNS, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5),
KC_TRNS, KC_HASH, KC_DLR, KC_LPRN,KC_RPRN, KC_GRV,  KC_TRNS,                         KC_TRNS, KC_PLUS, KC_MINS,    KC_SLSH,    KC_ASTR,    KC_PERC,    KC_UNDS,
KC_TRNS, KC_PERC, KC_CIRC,KC_LBRC,KC_RBRC, KC_TILD, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_AMPR, KC_EQL,     KC_COMM,    KC_DOT,     KC_SLSH,    KC_TRNS,

                                   KC_TRNS, KC_TRNS, KC_SCLN, KC_EQL,       KC_EQL, KC_SCLN, KC_PGUP, KC_DEL),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |  F1    |  F2  | F3   | F4   | F5   | F6   | BTN1 |           |      | LEFT | DOWN |  UP  | RIGHT|VolDn | VolUp  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |  F7    |  F8  | F9   | F10  | F11  | F12  | BTN2 |           |      | M 6  | M 1  | M 2  | M 3  | M 4  |  M  5  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[NUMB] = LAYOUT_gergo(
KC_TRNS, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                              KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_TRNS,
KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                          KC_TRNS,  KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_VOLD,    KC_VOLU,
KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_TRNS,       KC_TRNS, KC_TRNS,  LALT(KC_6), LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5),

                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_PGUP, KC_TRNS, KC_MS_BTN1, KC_MS_BTN2),


/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 */
[WIN] = LAYOUT_gergo(
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,

                                                  KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,
                                                           KC_TRNS,       KC_TRNS,
                                                  KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS),


[TEN] = LAYOUT_gergo(
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS,

                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_0, KC_DOT)
};
