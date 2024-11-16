// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "keyboard.h"
#include "keycodes.h"
#include "oled_driver.h"
#include "rgblight.h"
#include "os_detection.h"
#include "keymap_german.h"

#include "keymap.h"
#include "oled.h"
#include "graphics.h"

#include "quantum.h"
#include "process_tap_dance.h"
#include QMK_KEYBOARD_H

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
       KC_ESC,   KC_Q,          KC_W,          KC_L,            KC_D,          KC_P,                                KC_K,       KC_M,          KC_U,          KC_Z,           KC_SCLN,       KC_LBRC,
    //|---------+--------------+--------------+----------------+--------------+-----------|                        |-----------+--------------+--------------+---------------+--------------+---------|
       KC_QUOT,  KC_A,          LALT_T(KC_S),  LCTL_T(KC_R),    LSFT_T(KC_T),  KC_G,                                KC_F,       LSFT_T(KC_N),  LCTL_T(KC_E),  LALT_T(KC_I),   KC_O,          KC_J,
    //|---------+--------------+--------------+----------------+--------------+-----------|                        |-----------+--------------+--------------+---------------+--------------+---------|
       XXXXXXX,  KC_MINS,       ALGR_T(KC_Y),  KC_X,            KC_C,          KC_V,                                KC_B,       KC_H,          KC_DOT,        ALGR_T(KC_COMM), DE_SLSH,       KC_LGUI,
    //|---------+--------------+--------------+----------------+--------------+-----------+--------|   |-----------+-----------+--------------+--------------+---------------+--------------+---------|
                                                                MEDIA,         U_NAV_SPC,  KC_TAB,      U_SYM_ENT,  U_NUM_BSP,  U_FUN_DEL
                                                             //`--------------+-----------+--------|   |-----------+-----------+-------------'
  ),

  [U_EXTRA] = LAYOUT_split_3x6_3(
    //,---------+--------------+--------------+--------------+--------------+-----------.                           ,-----------+--------------+--------------+----------------+-----------------+---------.
       KC_ESC,   KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,                                   KC_Y,       KC_U,          KC_I,          KC_O,            KC_P,             KC_LBRC,
    //|---------+--------------+--------------+--------------+--------------+-----------|                           |-----------+--------------+--------------+----------------+-----------------+---------|
       XXXXXXX,  KC_A,          LALT_T(KC_S),  LCTL_T(KC_D),  LSFT_T(KC_F),  KC_G,                                   KC_H,       LSFT_T(KC_J),  LCTL_T(KC_K),  LALT_T(KC_L),    KC_SCLN,          KC_QUOT,
    //|---------+--------------+--------------+--------------+--------------+-----------|                           |-----------+--------------+--------------+----------------+-----------------+---------|
       XXXXXXX,  KC_Z,          ALGR_T(KC_X),  KC_C,          KC_V,          KC_B,                                   KC_N,       KC_M,          KC_COMM,       ALGR_T(KC_DOT),  DE_SLSH,          KC_LGUI,
    //|---------+--------------+--------------+--------------+--------------+-----------+-----------|   |-----------+-----------+--------------+--------------+----------------+-----------------+---------|
                                                              MEDIA,         U_NAV_SPC,  KC_TAB,         U_SYM_ENT,  U_NUM_BSP,  U_FUN_DEL
                                                           //`--------------+-----------+-----------|   |-----------+-----------+--------------'
    ),

  [U_NAV] = LAYOUT_split_3x6_3(
    //,--------+--------------+---------+------------------+-----------------+---------.                      ,---------+---------+---------+---------+---------+---------.
       XXXXXXX, TD(U_TD_BOOT), XXXXXXX,  TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),  XXXXXXX,                         U_RDO,    U_PST,    U_CPY,    U_CUT,    U_UND,    KC_BSPC,
    //|--------+--------------+---------+------------------+-----------------+---------|                      |---------+---------+---------+---------+---------+---------|
       XXXXXXX, KC_LGUI,       KC_LALT,  KC_LCTL,           KC_LSFT,          XXXXXXX,                         CW_TOGG,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,
    //|--------+--------------+---------+------------------+-----------------+---------|                      |---------+---------+---------+---------+---------+---------|
       XXXXXXX, XXXXXXX,       KC_ALGR,  TD(U_TD_U_NUM),    TD(U_TD_U_NAV),   XXXXXXX,                         KC_INS,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_LGUI,
    //|--------+--------------+---------+------------------+-----------------+---------+---------|   |--------+---------+---------+---------+---------+---------+---------|
                                                                  XXXXXXX,          XXXXXXX,  XXXXXXX,      KC_ENT,  KC_BSPC,  KC_DEL
                                                               //`-----------------+---------+---------|   |--------+---------+---------'
    ),

  [U_MEDIA] = LAYOUT_split_3x6_3(
    //,---------+---------+---------+------------------+------------------+---------.                       ,---------+---------+---------+---------+---------+---------.
       XXXXXXX,  XXXXXXX,  XXXXXXX,  TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   XXXXXXX,                          RGB_TOG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_VAI,  KC_BSPC,
    //|---------+---------+---------+------------------+------------------+---------|                       |---------+---------+---------+---------+---------+---------|
       XXXXXXX,  KC_LGUI,  KC_LALT,  KC_LCTL,           KC_LSFT,           XXXXXXX,                          XXXXXXX,  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  XXXXXXX,
    //|---------+---------+---------+------------------+------------------+---------|                       |---------+---------+---------+---------+---------+---------|
       XXXXXXX,  XXXXXXX,  KC_ALGR,  TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA), XXXXXXX,                           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LGUI,
    //|---------+---------+---------+------------------+------------------+---------+---------|   |---------+---------+---------+---------+---------+---------+---------|
                                                        XXXXXXX,           XXXXXXX,  XXXXXXX,      KC_MSTP,  KC_MPLY,  KC_MUTE
                                                     //`------------------+---------+---------|   |---------+---------+---------'
    ),

  [U_NUM] = LAYOUT_split_3x6_3(
    //,---------+--------+------+------+--------+---------.                       ,---------+-----------------+------------------+---------+--------------+--------------.
       XXXXXXX,  XXXXXXX, KC_7,  KC_8,  KC_9,    DE_QUOT,                          DE_DQUO,  TD(U_TD_U_BASE),  TD(U_TD_U_EXTRA),  XXXXXXX,  TD(U_TD_BOOT), KC_BSPC ,
    //|---------+--------+------+------+--------+---------|                       |---------+-----------------+------------------+---------+--------------+--------------|
       XXXXXXX,  DE_SCLN, KC_4,  KC_5,  KC_6,    DE_EQL,                           XXXXXXX,  KC_LSFT,          KC_LCTL,           KC_LALT,  KC_LGUI,       XXXXXXX,
    //|---------+--------+------+------+--------+---------|                       |---------+-----------------+------------------+---------+--------------+--------------|
       XXXXXXX,  DE_GRV,  KC_1,  KC_2,  KC_3,    DE_BSLS,                          XXXXXXX,  TD(U_TD_U_NUM),   TD(U_TD_U_NAV),    KC_ALGR,  XXXXXXX,       KC_LGUI,
    //|---------+--------+------+------+--------+---------+---------|   |---------+---------+-----------------+------------------+---------+--------------+--------------|
                                        KC_DOT,  KC_0,     DE_MINS,      XXXXXXX,  XXXXXXX,  XXXXXXX
                                     //`--------+---------+---------|   |---------+---------+-----------------'
    ),


  [U_SYM] = LAYOUT_split_3x6_3(
    //,---------+---------+---------+---------+----------+----------.                       ,---------+-----------------+------------------+---------+---------+---------.
       DE_MINS,  DE_PLUS,  DE_AMPR,  DE_ASTR,  DE_QUES,   DE_LBRC,                           DE_RBRC,  TD(U_TD_U_BASE),  TD(U_TD_U_EXTRA),  XXXXXXX,  XXXXXXX,  KC_BSPC,
    //|---------+---------+---------+---------+----------+----------|                       |---------+-----------------+------------------+---------+---------+---------|
       XXXXXXX,  DE_COLN,  DE_DLR,   DE_PERC,  DE_CIRC,   DE_LCBR,                           DE_RCBR,  KC_LSFT,          KC_LCTL,           KC_LALT,  KC_LGUI,  XXXXXXX,
    //|---------+---------+---------+---------+----------+----------|                       |---------+-----------------+------------------+---------+---------+---------|
       XXXXXXX,  DE_TILD,  DE_EXLM,  DE_AT,    DE_HASH,   DE_LPRN,                           DE_RPRN,  TD(U_TD_U_SYM),   XXXXXXX,           KC_ALGR,  XXXXXXX,  KC_LGUI,
    //|---------+---------+---------+---------+----------+----------+---------|   |---------+---------+-----------------+------------------+---------+---------+---------|
                                               DE_UNDS,   DE_PIPE,   DE_LABK,      XXXXXXX,  XXXXXXX,  XXXXXXX
                                            //`----------+----------+---------|   |---------+---------+-----------------'
    ),

  [U_FUN] = LAYOUT_split_3x6_3(
    //,---------+--------+-------+-------+--------+---------.                      ,---------+-----------------+------------------+---------+---------+---------.
       XXXXXXX,  KC_F12,  KC_F7,  KC_F8,  KC_F9,   KC_PSCR,                         XXXXXXX,  TD(U_TD_U_BASE),  TD(U_TD_U_EXTRA),  XXXXXXX,  XXXXXXX,  KC_BSPC,
    //|---------+--------+-------+-------+--------+---------|                      |---------+-----------------+------------------+---------+---------+---------|
       XXXXXXX,  KC_F11,  KC_F4,  KC_F5,  KC_F6,   KC_SCRL,                         XXXXXXX,  KC_LSFT,          KC_LCTL,           KC_LALT,  XXXXXXX,  XXXXXXX,
    //|---------+--------+-------+-------+--------+---------|                      |---------+-----------------+------------------+---------+---------+---------|
       XXXXXXX,  KC_F10,  KC_F1,  KC_F2,  KC_F3,   KC_PAUS,                         XXXXXXX,  TD(U_TD_U_FUN),   TD(U_TD_U_MEDIA),  KC_ALGR,  XXXXXXX,  KC_LGUI,
    //|---------+--------+-------+-------+--------+---------+--------|   |---------+---------+-----------------+------------------+---------+---------+---------|
                                          KC_APP,  KC_SPC,   KC_TAB,      XXXXXXX,  XXXXXXX,  XXXXXXX
                                       //`--------+---------+--------|   |---------+---------+-----------------'
    )
};

// clang-format on

// shift functions

// const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

// const key_override_t **key_overrides = (const key_override_t *[]){&capsword_key_override, NULL};

// OLED

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

bool oled_task_user(void) {
  if (is_keyboard_left()) {
    oled_set_cursor(0, 1);
    render_layer(layer_state, default_layer_state);
  } else {
    oled_set_cursor(0, 1);
    render_logo();
  }

  oled_set_cursor(0, 6);
  render_mod_status(get_mods() | get_oneshot_mods());

  oled_set_cursor(0, 12);

  if (is_keyboard_master()) {
    render_os(detected_host_os());
  }

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
