#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0 // BASE Layer
#define _FL 1 // Function Layer
#define _ME 2 // Media Layer
#define _CL 3 // Control Layer

// go back to base layer
#define TO_BASE TO(_BL)

// switch to function layer while helde
#define MO_FUNC MO(_FL)

// switch to media layer  while held
#define MEDIA MO(_ME)

// switch to Control layer while helde
#define MO_CTL MO(_CL)

// Function key when held, else ESC
#define ESC_FUN LT(_FL, KC_ESC)

// Hyper (CTRL+ALT+SHIFT+SUPER) when held, TAB when tapped
#define HPR_TAB ALL_T(KC_TAB)

// CTRL when held, ESC when tapped
#define CTL_ESC CTL_T(KC_ESC)

enum custom_keycodes { RGB_RST = SAFE_RANGE };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _BL: Base Layer (Default Layer) */
    [_BL] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, _______, KC_BSPC, KC_INS, HPR_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, ESC_FUN, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, _______, KC_RSFT, KC_UP, KC_LCTL, KC_LGUI, KC_LALT, _______, KC_SPC, KC_SPC, _______, KC_RALT, KC_RCTL, MO_FUNC, KC_LEFT, KC_DOWN, KC_RGHT),

    /* Keymap _FL: Function layer */
    [_FL] = LAYOUT(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, KC_PAUS, _______, _______, _______, _______, _______, _______, MO_CTL, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______, _______, _______, SC_LSPO, _______, _______, _______, _______, _______, _______, _______, MEDIA, _______, _______, _______, _______, SC_RSPC, KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO_FUNC, KC_HOME, KC_PGDN, KC_END),

    /* Keymap _ME: Media layer */
    [_ME] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MEDIA, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT),

    /* Keymap _CL: Control layer */
    [_CL] = LAYOUT(_______, RGB_RST, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_VAI, _______, _______, _______, _______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, _______, _______, MO_CTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAI, _______, _______, _______, _______, RGB_MOD, RGB_MOD, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_HUI)};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_RST:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(206, 255, 255);
            }
            return false;
    }
    return true;
}

enum layer_id {
    LAYER_BASE,
    LAYER_FUNCTION,
    LAYER_MEDIA,
    LAYER_CONTROL,
};

void clueboard_set_led(uint8_t id, uint8_t val) {
    switch (id) {
        case LAYER_BASE:
            rgblight_sethsv_noeeprom(135, 255, val);
            break;
        case LAYER_FUNCTION:
            rgblight_sethsv_noeeprom(32, 255, val);
            break;
        case LAYER_MEDIA:
            rgblight_sethsv_noeeprom(60, 255, val);
            break;
        case LAYER_CONTROL:
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

    if (layer & (1 << _FL)) {
        if (layer & (1 << _ME)) {
            clueboard_set_led(LAYER_MEDIA, val);
        } else if (layer & (1 << _CL)) {
            clueboard_set_led(LAYER_CONTROL, val);
        } else {
            clueboard_set_led(LAYER_FUNCTION, val);
        }
    } else {
        clueboard_set_led(LAYER_BASE, val);
    }
};
