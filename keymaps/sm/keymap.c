#include QMK_KEYBOARD_H
#include "quantum.h"
#include "features/sentence_case.h"
#include "features/achordion.h"

enum klein_keymap_layers {
    L_BASE = 0,
    L_NAV,
    L_NUM,
    L_FUN,
    L_SYM,
    L_MEDIA,
};

/* Customization */
enum custom_keycodes {
    SM_LOCK = QK_USER,
    SM_CWTG,
};

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SN RCTL_T(KC_SCLN)

#define L1_ESC LT(1, KC_ESC)
#define L3_COMM LT(3, KC_COMM)

#define HYP_SPC HYPR_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐      [4]   [5]    ┌───┐
      *           │ 1 ├───┐           ┌───┤ 8 │
      *           └───┤ 2 ├───┐   ┌───┤ 7 ├───┘
      *               └───┤ 3 │   │ 6 ├───┘
      *                   └───┘   └───┘
      */
  [L_BASE] = LAYOUT_split_3x5_4(
  // ╭────────────────────────────────────────────╮                      ╭────────────────────────────────────────────╮
         KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                        KC_Y, KC_U,   KC_I,   KC_O,   KC_P,
  // ├────────────────────────────────────────────┤                      ├────────────────────────────────────────────┤
         HOME_A, HOME_S, HOME_D, HOME_F, KC_G,                        KC_H, HOME_J, HOME_K, HOME_L, HOME_SN,
  // ├────────────────────────────────────────────┤                      ├────────────────────────────────────────────┤
         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                        KC_N, KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
  // ╰────────────────────────────────────────────┤                      ╰────────────────────────────────────────────╯
         LT(L_MEDIA, KC_ESC), LT(L_NAV, KC_SPC), LT(L_NUM, KC_TAB), QK_BOOT,                QK_BOOT, LT(L_SYM, KC_ENT), LT(L_NUM, KC_BSPC), LT(L_FUN, KC_DEL)
  // ╰────────────────────────────────────────────╯              ╰────────────────────────────────────────────────────╯
  ),

    [L_NAV] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_CAPS, KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_INS,  KC_HOME, KC_PGUP, KC_PGDN, KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                      KC_NO, KC_NO, KC_NO, QK_BOOT,    QK_BOOT, KC_ENT, KC_BSPC, KC_DEL
  //                 ╰─────────────────────────────╯ ╰────────────────────────────────╯
  ),

   [L_NUM] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_LBRC,   KC_7, KC_8, KC_9,   KC_RBRC,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_SCLN,   KC_4, KC_5, KC_6,   KC_EQL,       KC_NO,   KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_GRV,    KC_1, KC_2, KC_3,   KC_BSLS,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                   KC_DOT, KC_0, KC_MINS, QK_BOOT,    QK_BOOT, KC_ENT, KC_BSPC, KC_DEL
  //              ╰────────────────────────────────╯ ╰────────────────────────────────╯
  ),

   [L_FUN] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_F12, KC_F7,   KC_F8,  KC_F9, KC_PSCR,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_F11, KC_F4,   KC_F5,  KC_F6, KC_SYRQ,      KC_NO,   KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_F10,  KC_F1,  KC_F2,  KC_F3, KC_PAUS,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                   KC_ESC, KC_SPC, KC_TAB, QK_BOOT,    QK_BOOT, KC_NO,   KC_NO,   KC_NO
  //              ╰────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

     [L_SYM] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_LCBR, KC_GRV,  KC_ASTR, KC_AMPR,KC_RCBR,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_COLN, KC_CIRC, KC_PERC, KC_DLR, KC_PLUS,    KC_NO,   KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_TILD, KC_HASH, KC_AT, KC_EXLM,  KC_PIPE,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                   KC_ESC, KC_SPC, KC_TAB, QK_BOOT,    QK_BOOT, KC_NO,   KC_NO,   KC_NO
  //              ╰────────────────────────────────╯ ╰──────────────────────────────────╯
  ),

    [L_MEDIA] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,    KC_NO,   KC_MPRV,  KC_VOLD, KC_VOLU, KC_MNXT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                      KC_NO, KC_NO, KC_NO, KC_MUTE,    KC_MUTE, KC_MSTP, KC_MPLY,  KC_M
  //                 ╰─────────────────────────────╯ ╰─────────────────────────────────╯
  ),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [L_BASE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [L_NAV] =    { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [L_NUM] =    { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [L_FUN] =    { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [L_SYM] =    { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [L_MEDIA] =  { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },

};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }
  if (!process_sentence_case(keycode, record)) { return false; }

  switch (keycode) {
    case SM_CWTG:
      if (record->event.pressed) {
        caps_word_on();
      }
    }
  return true;
};

void matrix_scan_user(void) {
  achordion_task();
};

// Eager achordion for mod + mouse click
bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LGUI:
    case MOD_RGUI:
      return true;  // Eagerly apply Shift and Ctrl mods.

    default:
      return false;
  }
};

static bool on_left_hand_sm(keypos_t pos) {
  return pos.row < 4;
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

  // Exceptionally consider the following chords as holds
  switch (tap_hold_keycode) {
    case HYP_SPC:
      return true;
  }

  // Exceptionally consider following rows key presses as holds
  switch (tap_hold_record->event.key.row) {
    case 3:
    case 7:
      return true;
  }

  return on_left_hand_sm(tap_hold_record->event.key) !=
         on_left_hand_sm(other_record->event.key);
}
