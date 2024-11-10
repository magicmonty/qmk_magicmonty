// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "oled_driver.h"
#include "process_tap_dance.h"
#include "quantum.h"
#include "rgblight.h"
#include QMK_KEYBOARD_H

#include "keymap.h"
#include "oled.h"

// Additional Features double tap guard

enum {
  U_TD_BOOT,
  U_TD_U_BASE,
  U_TD_U_EXTRA,
  U_TD_U_NAV,
  U_TD_U_MEDIA,
  U_TD_U_NUM,
  U_TD_U_SYM,
  U_TD_U_FUN,
};

void u_td_fn_U_BOOT(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

void u_td_fn_U_BASE(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    default_layer_set((layer_state_t)1 << U_BASE);
  }
}

void u_td_fn_U_EXTRA(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    default_layer_set((layer_state_t)1 << U_EXTRA);
  }
}

void u_td_fn_U_NAV(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    default_layer_set((layer_state_t)1 << U_NAV);
  }
}

void u_td_fn_U_MEDIA(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    default_layer_set((layer_state_t)1 << U_MEDIA);
  }
}

void u_td_fn_U_NUM(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    default_layer_set((layer_state_t)1 << U_NUM);
  }
}

void u_td_fn_U_SYM(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    default_layer_set((layer_state_t)1 << U_SYM);
  }
}

void u_td_fn_U_FUN(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    default_layer_set((layer_state_t)1 << U_FUN);
  }
}

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_U_BOOT), [U_TD_U_BASE] = ACTION_TAP_DANCE_FN(u_td_fn_U_BASE), [U_TD_U_EXTRA] = ACTION_TAP_DANCE_FN(u_td_fn_U_EXTRA), [U_TD_U_NAV] = ACTION_TAP_DANCE_FN(u_td_fn_U_NAV), [U_TD_U_MEDIA] = ACTION_TAP_DANCE_FN(u_td_fn_U_MEDIA), [U_TD_U_NUM] = ACTION_TAP_DANCE_FN(u_td_fn_U_NUM), [U_TD_U_SYM] = ACTION_TAP_DANCE_FN(u_td_fn_U_SYM), [U_TD_U_FUN] = ACTION_TAP_DANCE_FN(u_td_fn_U_FUN),
};

// keymap

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [U_BASE] = LAYOUT_split_3x6_3(
    //,---------+--------------+--------------+----------------+--------------+-----------.                        ,-----------+--------------+--------------+---------------+--------------+---------.
       _______,  KC_Q,          KC_W,          KC_F,            KC_P,          KC_B,                                KC_J,       KC_L,          KC_U,          KC_Y,           KC_QUOT,       _______,
    //|---------+--------------+--------------+----------------+--------------+-----------|                        |-----------+--------------+--------------+---------------+--------------+---------|
       _______,  LGUI_T(KC_A),  LALT_T(KC_R),  LCTL_T(KC_S),    LSFT_T(KC_T),  KC_G,                                KC_M,       LSFT_T(KC_N),  LCTL_T(KC_E),  LALT_T(KC_I),   LGUI_T(KC_O),  _______,
    //|---------+--------------+--------------+----------------+--------------+-----------|                        |-----------+--------------+--------------+---------------+--------------+---------|
       _______,  KC_Z,          ALGR_T(KC_X),  KC_C,            KC_D,          KC_V,                                KC_K,       KC_H,          KC_COMM,       ALGR_T(KC_DOT), KC_SLSH,       _______,
    //|---------+--------------+--------------+----------------+--------------+-----------+--------|   |-----------+-----------+--------------+--------------+---------------+--------------+---------|
                                                                U_MEDIA_ESC,   U_NAV_SPC,  KC_TAB,      U_SYM_ENT,  U_NUM_BSP,  U_FUN_DEL
                                                             //`--------------+-----------+--------|   |-----------+-----------+-------------'
  ),

  [U_EXTRA] = LAYOUT_split_3x6_3(
    //,---------+--------------+--------------+--------------+--------------+-----------.                           ,-----------+--------------+--------------+----------------+-----------------+---------.
       _______,  KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,                                   KC_Z,       KC_U,          KC_I,          KC_O,            KC_P,             _______,
    //|---------+--------------+--------------+--------------+--------------+-----------|                           |-----------+--------------+--------------+----------------+-----------------+---------|
       _______,  LGUI_T(KC_A),  LALT_T(KC_S),  LCTL_T(KC_D),  LSFT_T(KC_F),  KC_G,                                   KC_H,       LSFT_T(KC_J),  LCTL_T(KC_K),  LALT_T(KC_L),    LGUI_T(KC_QUOT),  _______,
    //|---------+--------------+--------------+--------------+--------------+-----------|                           |-----------+--------------+--------------+----------------+-----------------+---------|
       _______,  KC_Y,          ALGR_T(KC_X),  KC_C,          KC_V,          KC_B,                                   KC_N,       KC_M,          KC_COMM,       ALGR_T(KC_DOT),  KC_SLSH,          _______,
    //|---------+--------------+--------------+--------------+--------------+-----------+-----------|   |-----------+-----------+--------------+--------------+----------------+-----------------+---------|
                                                              U_MEDIA_ESC,   U_NAV_SPC,  KC_TAB,         U_SYM_ENT,  U_NUM_BSP,  U_FUN_DEL
                                                           //`--------------+-----------+-----------|   |-----------+-----------+--------------'
    ),

  [U_NAV] = LAYOUT_split_3x6_3(
    //,------------------+----------+---------+------------------+-----------------+---------.                      ,---------+---------+---------+---------+---------+---------.
       TD(U_TD_BOOT),     _______,   _______,  TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),  _______,                         U_RDO,    U_PST,    U_CPY,    U_CUT,    U_UND,    _______,
    //|------------------+----------+---------+------------------+-----------------+---------|                      |---------+---------+---------+---------+---------+---------|
       _______,           KC_LGUI,   KC_LALT,  KC_LCTL,           KC_LSFT,          _______,                         CW_TOGG,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,
    //|------------------+----------+---------+------------------+-----------------+---------|                      |---------+---------+---------+---------+---------+---------|
       _______,           _______,   KC_ALGR,  TD(U_TD_U_NUM),    TD(U_TD_U_NAV),   _______,                         KC_INS,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,
    //|------------------+----------+---------+------------------+-----------------+---------+---------|   |--------+---------+---------+---------+---------+---------+---------|
                                                                  _______,          _______,  _______,      KC_ENT,  KC_BSPC,  KC_DEL
                                                               //`-----------------+---------+---------|   |--------+---------+---------'
    ),

  [U_MEDIA] = LAYOUT_split_3x6_3(
    //,---------------+---------+---------+------------------+------------------+---------.                       ,---------+---------+---------+---------+---------+---------.
       TD(U_TD_BOOT),  _______,  _______,  TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   _______,                          RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,
    //|---------------+---------+---------+------------------+------------------+---------|                       |---------+---------+---------+---------+---------+---------|
       _______,        KC_LGUI,  KC_LALT,  KC_LCTL,           KC_LSFT,           _______,                          _______,  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  _______,
    //|---------------+---------+---------+------------------+------------------+---------|                       |---------+---------+---------+---------+---------+---------|
       _______,        _______,  KC_ALGR,  TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA), _______,                           OU_AUTO,  _______,  _______,  _______,  _______,  _______,
    //|---------------+---------+---------+------------------+------------------+---------+---------|   |---------+---------+---------+---------+---------+---------+---------|
                                                              _______,           _______,  _______,      KC_MSTP,  KC_MPLY,  KC_MUTE
                                                           //`------------------+---------+---------|   |---------+---------+---------'
    ),

  [U_NUM] = LAYOUT_split_3x6_3(
    //,---------+--------+------+------+--------+---------.                       ,---------+-----------------+------------------+---------+---------+---------.
       _______,  KC_LBRC, KC_7,  KC_8,  KC_9,    KC_RBRC,                          _______,  TD(U_TD_U_BASE),  TD(U_TD_U_EXTRA),  _______,  _______,  _______,
    //|---------+--------+------+------+--------+---------|                       |---------+-----------------+------------------+---------+---------+---------|
       _______,  KC_SCLN, KC_4,  KC_5,  KC_6,    KC_EQL,                           _______,  KC_LSFT,          KC_LCTL,           KC_LALT,  KC_LGUI,  _______,
    //|---------+--------+------+------+--------+---------|                       |---------+-----------------+------------------+---------+---------+---------|
       _______, KC_GRV,   KC_1,  KC_2,  KC_3,    KC_BSLS,                          _______,  TD(U_TD_U_NUM),   TD(U_TD_U_NAV),    KC_ALGR,  _______,  _______,
    //|---------+--------+------+------+--------+---------+---------|   |---------+---------+-----------------+------------------+---------+---------+---------|
                                        KC_DOT,  KC_0,     KC_MINS,      _______,  _______,  _______
                                     //`--------+---------+---------|   |---------+---------+-----------------'
    ),

  [U_SYM] = LAYOUT_split_3x6_3(
    //,---------+---------+---------+---------+----------+----------.                       ,---------+-----------------+------------------+---------+---------+---------.
       _______,  KC_LCBR,  KC_AMPR,  KC_ASTR,  KC_LPRN,   KC_RCBR,                           _______,  TD(U_TD_U_BASE),  TD(U_TD_U_EXTRA),  _______,  _______,  _______,
    //|---------+---------+---------+---------+----------+----------|                       |---------+-----------------+------------------+---------+---------+---------|
       _______,  KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,   KC_PLUS,                           _______,  KC_LSFT,          KC_LCTL,           KC_LALT,  KC_LGUI,  _______,
    //|---------+---------+---------+---------+----------+----------|                       |---------+-----------------+------------------+---------+---------+---------|
       _______,  KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,   KC_PIPE,                           _______,  TD(U_TD_U_SYM),   _______,           KC_ALGR,  _______,  _______,
    //|---------+---------+---------+---------+----------+----------+---------|   |---------+---------+-----------------+------------------+---------+---------+---------|
                                               KC_LPRN,   KC_RPRN,   KC_UNDS,      _______,  _______,  _______
                                            //`----------+----------+---------|   |---------+---------+-----------------'
    ),

  [U_FUN] = LAYOUT_split_3x6_3(
    //,---------+--------+-------+-------+--------+---------.                      ,---------+-----------------+------------------+---------+---------+---------.
       _______,  KC_F12,  KC_F7,  KC_F8,  KC_F9,   KC_PSCR,                         _______,  TD(U_TD_U_BASE),  TD(U_TD_U_EXTRA),  _______,  _______,  _______,
    //|---------+--------+-------+-------+--------+---------|                      |---------+-----------------+------------------+---------+---------+---------|
       _______,  KC_F11,  KC_F4,  KC_F5,  KC_F6,   KC_SCRL,                         _______,  KC_LSFT,          KC_LCTL,           KC_LALT,  KC_LGUI,  _______,
    //|---------+--------+-------+-------+--------+---------|                      |---------+-----------------+------------------+---------+---------+---------|
       _______,  KC_F10,  KC_F1,  KC_F2,  KC_F3,   KC_PAUS,                         _______,  TD(U_TD_U_FUN),   TD(U_TD_U_MEDIA),  KC_ALGR,  _______,  _______,
    //|---------+--------+-------+-------+--------+---------+--------|   |---------+---------+-----------------+------------------+---------+---------+---------|
                                          KC_APP,  KC_SPC,   KC_TAB,      _______,  _______,  _______
                                       //`--------+---------+--------|   |---------+---------+-----------------'
    )
};

// clang-format on

// shift functions

// const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

// const key_override_t **key_overrides = (const key_override_t *[]){&capsword_key_override, NULL};

// OLED

#define L_BASE U_BASE
#define L_EXTRA 1 << U_EXTRA
#define L_NAV 1 << U_NAV
#define L_MEDIA 1 << U_MEDIA
#define L_NUM 1 << U_NUM
#define L_SYM 1 << U_SYM
#define L_FUN 1 << U_FUN

void render_layer_state(void) {
  switch (layer_state) {
    case 0:
      switch (default_layer_state) {
        case 1 << U_BASE:
          oled_write_P(PSTR("COLMK"), false);
          break;
        case L_EXTRA:
          oled_write_P(PSTR("QWRTZ"), false);
          break;
        case L_NAV:
          oled_write_P(PSTR(" NAV "), false);
          break;
        case L_MEDIA:
          oled_write_P(PSTR("MEDIA"), false);
          break;
        case L_NUM:
          oled_write_P(PSTR(" NUM "), false);
          break;
        case L_SYM:
          oled_write_P(PSTR(" SYM "), false);
          break;
        case L_FUN:
          oled_write_P(PSTR(" FUN "), false);
          break;
        default:
          oled_write_P(PSTR("!!!!!"), false);
          break;
      }
      break;
    case L_NAV:
      oled_write_P(PSTR(" NAV "), false);
      break;
    case L_MEDIA:
      oled_write_P(PSTR("MEDIA"), false);
      break;
    case L_NUM:
      oled_write_P(PSTR(" NUM "), false);
      break;
    case L_SYM:
      oled_write_P(PSTR(" SYM "), false);
      break;
    case L_FUN:
      oled_write_P(PSTR(" FUN "), false);
      break;
    case L_EXTRA:
      oled_write_P(PSTR("QWRTZ"), false);
      break;
    default:
      oled_write_P(PSTR("HAEH?"), false);
      break;
  }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

bool oled_task_user(void) {
  oled_set_cursor(0, 1);
  render_logo();

  oled_set_cursor(0, 5);
  oled_write_P(PSTR("     "), false);

  oled_set_cursor(0, 7);
  render_mod_status_gui_alt(get_mods() | get_oneshot_mods());
  render_mod_status_ctrl_shift(get_mods() | get_oneshot_mods());

  oled_set_cursor(0, 14);
  render_layer_state();

  return false;
}

void set_led(uint8_t id, uint8_t val) {
  switch (id) {
    case U_BASE:
      rgblight_sethsv_noeeprom(135, 255, val);
      break;
    case U_FUN:
      rgblight_sethsv_noeeprom(32, 255, val);
      break;
    case U_SYM:
      rgblight_sethsv_noeeprom(0, 255, val);
      break;
    case U_NUM:
      rgblight_sethsv_noeeprom(180, 255, val);
      break;
    case U_MEDIA:
      rgblight_sethsv_noeeprom(60, 255, val);
      break;
    case U_NAV:
      rgblight_sethsv_noeeprom(245, 255, val);
      break;
  }
};

const uint16_t oct_hues[10] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180};

#define MAX_OCT 9

void matrix_scan_user(void) {
  rgblight_config_t rgblight_config;
  rgblight_config.raw = eeconfig_read_rgblight();

  if (!rgblight_config.enable || rgblight_config.mode != 1) {
    return;
  }

  layer_state_t layer = layer_state;
  uint8_t       val   = rgblight_config.val;

  if (layer & (1 << U_FUN)) {
    set_led(U_FUN, val);
  } else if (layer & (1 << U_MEDIA)) {
    set_led(U_MEDIA, val);
  } else if (layer & (1 << U_NAV)) {
    set_led(U_NAV, val);
  } else if (layer & (1 << U_SYM)) {
    set_led(U_SYM, val);
  } else if (layer & (1 << U_NUM)) {
    set_led(U_NUM, val);
  } else {
    set_led(U_BASE, val);
  }
};

void oled_render_boot(bool bootloader) {
  oled_clear();
  oled_set_cursor(0, 0);
  if (bootloader) {
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("WAIT "), false);
    oled_write_P(PSTR("FOR  "), false);
    oled_write_P(PSTR("FIRM-"), false);
    oled_write_P(PSTR("WARE "), false);
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("     "), false);
  } else {
    oled_write_P(PSTR("  R  "), false);
    oled_write_P(PSTR("  E  "), false);
    oled_write_P(PSTR("  B  "), false);
    oled_write_P(PSTR("  O  "), false);
    oled_write_P(PSTR("  O  "), false);
    oled_write_P(PSTR("  T  "), false);
    oled_write_P(PSTR("  I  "), false);
    oled_write_P(PSTR("  N  "), false);
    oled_write_P(PSTR("  G  "), false);
  }

  oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
  if (jump_to_bootloader) {
    // red for bootloader
    rgblight_sethsv_noeeprom(0, 255, 255);
  } else {
    // off for soft reset
    rgblight_sethsv_noeeprom(0, 0, 0);
  }
  rgblight_set();
  oled_render_boot(jump_to_bootloader);

  // false to not process kb level
  return false;
}