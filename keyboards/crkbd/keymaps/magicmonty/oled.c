#include "action_layer.h"
#include "modifiers.h"
#include "oled_driver.h"
#include "os_detection.h"
#include "graphics.h"
#include "layers.h"

void render_logo(void) {
  oled_write_P(logo, false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
  if (modifiers & MOD_MASK_ALT) {
    oled_write_P(alt_on_1, false);
  } else {
    oled_write_P(alt_off_1, false);
  }

  if ((modifiers & MOD_MASK_ALT) && (modifiers & MOD_MASK_GUI)) {
    oled_write_P(on_on_1, false);
  } else if (modifiers & MOD_MASK_ALT) {
    oled_write_P(on_off_1, false);
  } else if (modifiers & MOD_MASK_GUI) {
    oled_write_P(off_on_1, false);
  } else {
    oled_write_P(off_off_1, false);
  }

  if (modifiers & MOD_MASK_GUI) {
    oled_write_P(gui_on_1, false);
  } else {
    oled_write_P(gui_off_1, false);
  }

  if (modifiers & MOD_MASK_ALT) {
    oled_write_P(alt_on_2, false);
  } else {
    oled_write_P(alt_off_2, false);
  }

  if (modifiers & MOD_MASK_ALT & MOD_MASK_GUI) {
    oled_write_P(on_on_2, false);
  } else if (modifiers & MOD_MASK_ALT) {
    oled_write_P(on_off_2, false);
  } else if (modifiers & MOD_MASK_GUI) {
    oled_write_P(off_on_2, false);
  } else {
    oled_write_P(off_off_2, false);
  }

  if (modifiers & MOD_MASK_GUI) {
    oled_write_P(gui_on_2, false);
  } else {
    oled_write_P(gui_off_2, false);
  }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
  if (modifiers & MOD_MASK_SHIFT) {
    oled_write_P(shift_on_1, false);
  } else {
    oled_write_P(shift_off_1, false);
  }

  if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
    oled_write_P(on_on_1, false);
  } else if (modifiers & MOD_MASK_SHIFT) {
    oled_write_P(on_off_1, false);
  } else if (modifiers & MOD_MASK_CTRL) {
    oled_write_P(off_on_1, false);
  } else {
    oled_write_P(off_off_1, false);
  }

  if (modifiers & MOD_MASK_CTRL) {
    oled_write_P(ctrl_on_1, false);
  } else {
    oled_write_P(ctrl_off_1, false);
  }

  if (modifiers & MOD_MASK_SHIFT) {
    oled_write_P(shift_on_2, false);
  } else {
    oled_write_P(shift_off_2, false);
  }

  if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
    oled_write_P(on_on_2, false);
  } else if (modifiers & MOD_MASK_SHIFT) {
    oled_write_P(on_off_2, false);
  } else if (modifiers & MOD_MASK_CTRL) {
    oled_write_P(off_on_2, false);
  } else {
    oled_write_P(off_off_2, false);
  }

  if (modifiers & MOD_MASK_CTRL) {
    oled_write_P(ctrl_on_2, false);
  } else {
    oled_write_P(ctrl_off_2, false);
  }
}

void render_mod_status(uint8_t modifiers) {
  render_mod_status_ctrl_shift(modifiers);
  render_mod_status_gui_alt(modifiers);
}

void render_os(os_variant_t detected_os) {
  switch (detected_os) {
    case OS_MACOS:
    case OS_IOS:
      oled_write_P(os_mac, false);
      break;
    case OS_WINDOWS:
      oled_write_P(os_win, false);
      break;
    case OS_LINUX:
      oled_write_P(os_linux, false);
      break;
    default:
      oled_write_P(os_mobile, false);
      break;
  }
}

#define L_BASE U_BASE
#define L_MEDIA 1 << U_MEDIA
#define L_NAV 1 << U_NAV
#define L_SYM 1 << U_SYM
#define L_NUM 1 << U_NUM
#define L_FUN 1 << U_FUN
#define L_EXTRA 1 << U_EXTRA

void render_layer(layer_state_t layer_state, layer_state_t default_layer_state) {
  switch (layer_state) {
    case 0:
      switch (default_layer_state) {
        case 1 << U_BASE:
          oled_write_P(layer_soul, false);
          break;
        case L_EXTRA:
          oled_write_P(layer_game, false);
          break;
        case L_NAV:
          oled_write_P(layer_nav, false);
          break;
        case L_MEDIA:
          oled_write_P(layer_media, false);
          break;
        case L_NUM:
          oled_write_P(layer_num, false);
          break;
        case L_SYM:
          oled_write_P(layer_sym, false);
          break;
        case L_FUN:
          oled_write_P(layer_fun, false);
          break;
        default:
          oled_write_P(layer_unknown, false);
          break;
      }
      break;
    case L_EXTRA:
      oled_write_P(layer_game, false);
      break;
    case L_NAV:
      oled_write_P(layer_nav, false);
      break;
    case L_MEDIA:
      oled_write_P(layer_media, false);
      break;
    case L_NUM:
      oled_write_P(layer_num, false);
      break;
    case L_SYM:
      oled_write_P(layer_sym, false);
      break;
    case L_FUN:
      oled_write_P(layer_fun, false);
      break;
    default:
      oled_write_P(layer_unknown, false);
      break;
  }
}

void oled_render_boot(bool bootloader) {
  oled_clear();
  if (bootloader) {
    oled_set_cursor(0, 3);
    oled_write_P(waiting_for_firmware, false);
  }

  oled_render_dirty(true);
}
