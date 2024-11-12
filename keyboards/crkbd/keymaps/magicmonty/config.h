#pragma once

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 300
#define EE_HANDS

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

#ifdef OLED_ENABLE
#  define SPLIT_LAYER_STATE_ENABLE
#  define SPLIT_LED_STATE_ENABLE
#  define SPLIT_MODS_ENABLE
#  define SPLIT_OLED_ENABLE
#  define OLED_TIMEOUT 60000
#  define OLED_FONT_H "keyboards/crkbd/keymaps/magicmonty/glcdfont.c"
#endif
