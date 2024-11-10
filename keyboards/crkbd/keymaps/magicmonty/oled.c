#include "modifiers.h"
#include "oled_driver.h"
#include "progmem.h"

void render_logo(void) {
  static const char PROGMEM logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4,
    0x20, 0x20, 0x20, 0x20, 0x20
  };

  oled_write_P(logo, false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
  static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
  static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
  static const char PROGMEM gui_on_1[]  = {0x8d, 0x8e, 0};
  static const char PROGMEM gui_on_2[]  = {0xad, 0xae, 0};
  static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
  static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
  static const char PROGMEM alt_on_1[]  = {0x8f, 0x90, 0};
  static const char PROGMEM alt_on_2[]  = {0xaf, 0xb0, 0};

  // fillers between the modifier icons bleed into the icon frames
  static const char PROGMEM off_off_1[] = {0xc5, 0};
  static const char PROGMEM off_off_2[] = {0xc6, 0};
  static const char PROGMEM on_off_1[]  = {0xc7, 0};
  static const char PROGMEM on_off_2[]  = {0xc8, 0};
  static const char PROGMEM off_on_1[]  = {0xc9, 0};
  static const char PROGMEM off_on_2[]  = {0xca, 0};
  static const char PROGMEM on_on_1[]   = {0xcb, 0};
  static const char PROGMEM on_on_2[]   = {0xcc, 0};

  if (modifiers & MOD_MASK_GUI) {
    oled_write_P(gui_on_1, false);
  } else {
    oled_write_P(gui_off_1, false);
  }
  if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
    oled_write_P(on_on_1, false);
  } else if (modifiers & MOD_MASK_GUI) {
    oled_write_P(on_off_1, false);
  } else if (modifiers & MOD_MASK_ALT) {
    oled_write_P(off_on_1, false);
  } else {
    oled_write_P(off_off_1, false);
  }
  if (modifiers & MOD_MASK_ALT) {
    oled_write_P(alt_on_1, false);
  } else {
    oled_write_P(alt_off_1, false);
  }
  if (modifiers & MOD_MASK_GUI) {
    oled_write_P(gui_on_2, false);
  } else {
    oled_write_P(gui_off_2, false);
  }
  if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
    oled_write_P(on_on_2, false);
  } else if (modifiers & MOD_MASK_GUI) {
    oled_write_P(on_off_2, false);
  } else if (modifiers & MOD_MASK_ALT) {
    oled_write_P(off_on_2, false);
  } else {
    oled_write_P(off_off_2, false);
  }
  if (modifiers & MOD_MASK_ALT) {
    oled_write_P(alt_on_2, false);
  } else {
    oled_write_P(alt_off_2, false);
  }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
  static const char PROGMEM ctrl_off_1[]  = {0x89, 0x8a, 0};
  static const char PROGMEM ctrl_off_2[]  = {0xa9, 0xaa, 0};
  static const char PROGMEM ctrl_on_1[]   = {0x91, 0x92, 0};
  static const char PROGMEM ctrl_on_2[]   = {0xb1, 0xb2, 0};
  static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
  static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
  static const char PROGMEM shift_on_1[]  = {0xcd, 0xce, 0};
  static const char PROGMEM shift_on_2[]  = {0xcf, 0xd0, 0};

  // fillers between the modifier icons bleed into the icon frames
  static const char PROGMEM off_off_1[]   = {0xc5, 0};
  static const char PROGMEM off_off_2[]   = {0xc6, 0};
  static const char PROGMEM on_off_1[]    = {0xc7, 0};
  static const char PROGMEM on_off_2[]    = {0xc8, 0};
  static const char PROGMEM off_on_1[]    = {0xc9, 0};
  static const char PROGMEM off_on_2[]    = {0xca, 0};
  static const char PROGMEM on_on_1[]     = {0xcb, 0};
  static const char PROGMEM on_on_2[]     = {0xcc, 0};

  if (modifiers & MOD_MASK_CTRL) {
    oled_write_P(ctrl_on_1, false);
  } else {
    oled_write_P(ctrl_off_1, false);
  }
  if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
    oled_write_P(on_on_1, false);
  } else if (modifiers & MOD_MASK_CTRL) {
    oled_write_P(on_off_1, false);
  } else if (modifiers & MOD_MASK_SHIFT) {
    oled_write_P(off_on_1, false);
  } else {
    oled_write_P(off_off_1, false);
  }
  if (modifiers & MOD_MASK_SHIFT) {
    oled_write_P(shift_on_1, false);
  } else {
    oled_write_P(shift_off_1, false);
  }
  if (modifiers & MOD_MASK_CTRL) {
    oled_write_P(ctrl_on_2, false);
  } else {
    oled_write_P(ctrl_off_2, false);
  }
  if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
    oled_write_P(on_on_2, false);
  } else if (modifiers & MOD_MASK_CTRL) {
    oled_write_P(on_off_2, false);
  } else if (modifiers & MOD_MASK_SHIFT) {
    oled_write_P(off_on_2, false);
  } else {
    oled_write_P(off_off_2, false);
  }
  if (modifiers & MOD_MASK_SHIFT) {
    oled_write_P(shift_on_2, false);
  } else {
    oled_write_P(shift_off_2, false);
  }
}
