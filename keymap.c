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

// define a custom Stumpwm mod key
// #define SWM(kc) SEND_STRING(SS_LCTRL("t") kc)

enum customKeycodes {
  CLOSE_FRAME = SAFE_RANGE,
  SWM_NEXT_WIN,
  SWM_PREV_WIN,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case CLOSE_FRAME:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x") "50");
    }
    break;
  case SWM_NEXT_WIN:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("t") "n");
    }
    break;
  case SWM_PREV_WIN:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("t") "p");
    }
    break;
  }
  return true;
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |  TAB   |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * | TEN/BS |   A  |   S  |ALT/D |CTL/F |   G  | Close|           |      |   H  |CTL/J |ALT/K |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | LMB  |           |      |   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *  .----------. .-----------. .----------. .---------.           .----------. .----------. .----------. .----------.
 *  |CTRL-ALT-'| |SYMB/BSpace| | NUMB/ESC | |  C-t    |           | LEADER   | |NUMB/Enter| |SYMB/Space| |   Shift  |
 *  '----------' '-----------' '----------' '---------'           '----------' '----------' '----------' '----------'
 */
[BASE] = LAYOUT_gergo(
KC_TAB,           KC_Q,  KC_W,   KC_E,           KC_R,         KC_T,                                              KC_Y, KC_U,         KC_I,         KC_O,   KC_P,    KC_BSLS,
LT(TEN, KC_TAB),  KC_A,  KC_S,   LALT_T(KC_D),   LCTL_T(KC_F), KC_G, CLOSE_FRAME,                      KC_TRNS, KC_H, LCTL_T(KC_J), LALT_T(KC_K), KC_L,   KC_SCLN, KC_QUOT,
KC_RSFT,          KC_Z,  KC_X,   KC_C,           KC_V,         KC_B, KC_BTN1, KC_TRNS,       KC_BSPC,  KC_TRNS,   KC_N, KC_M,         KC_COMM,      KC_DOT, KC_SLSH, KC_MINS,

LCA(KC_QUOT), LT(SYMB, KC_BSPC), LCTL(KC_T), LT(NUMB, KC_ESC),                                            KC_LEAD, LT(NUMB, KC_ENT), LT(SYMB, KC_SPC), KC_RSFT),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                         |  M6  |  M1  |  M2  |  M3  |  M4  |  M5    |
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
KC_TRNS, KC_EXLM, KC_AT,  KC_LCBR,KC_RCBR, KC_PIPE,                                           LALT(KC_6), LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5),
KC_TRNS, KC_HASH, KC_DLR, KC_LPRN,KC_RPRN, KC_GRV,  KC_TRNS,                         KC_TRNS, KC_PLUS,    KC_MINS,    KC_SLSH,    KC_ASTR,    KC_PERC,    KC_UNDS,
KC_TRNS, KC_PERC, KC_CIRC,KC_LBRC,KC_RBRC, KC_TILD, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_AMPR,    KC_EQL,     KC_COMM,    KC_DOT,     KC_SLSH,    KC_TRNS,

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

                                    KC_TRNS, KC_WH_U, KC_WH_D, KC_TRNS,      KC_PGDN, KC_PGUP, KC_MS_BTN1, KC_MS_BTN2),


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
KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                                 KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, SWM_PREV_WIN, KC_TRNS,
KC_TRNS, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), LALT(KC_6),                         KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,
KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_TRNS, KC_TRNS, SWM_NEXT_WIN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,

                                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),


[TEN] = LAYOUT_gergo(
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS,

                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_0, KC_DOT)
};


LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    // Replace the sequences below with your own sequences.
    SEQ_ONE_KEY(KC_X) {
      // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
      SEND_STRING(SS_LALT("x"));
    }
    SEQ_ONE_KEY(KC_O) {
      SEND_STRING(SS_LCTRL("x") "o");
    }
    SEQ_ONE_KEY(KC_K) {
      SEND_STRING(SS_LCTRL("x") "50");
    }
    SEQ_ONE_KEY(KC_M) {
      SEND_STRING(SS_LCTRL("x") "1");
    }
    SEQ_ONE_KEY(KC_COMM) {
      SEND_STRING(SS_LCTRL("x") "o" SS_LCTRL("x") "1");
    }
    // Note: This is not an array, you don't need to put any commas
    // or semicolons between sequences.
  }
}



/* LEADER_EXTERNS(); */

/* void matrix_scan_user(void) { */
/*   LEADER_DICTIONARY() { */
/*     leading = false; */
/*     leader_end(); */
/* _ */
/*     SEQ_ONE_KEY(KC_X) { */
/*   register_code(KC_LCTL); */
/*   register_code(KC_X); */
/*   unregister_code(KC_X); */
/*   unregister_code(KC_LCTL); */
/*     } */
/*   } */
/* }; */
