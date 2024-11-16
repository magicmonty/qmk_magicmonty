#include <stdint.h>
#include "action_layer.h"
#include "os_detection.h"

void render_mod_status(uint8_t modifiers);
void render_logo(void);
void render_os(os_variant_t detected_os);
void render_layer(layer_state_t layer_state, layer_state_t default_layer_state);
void oled_render_boot(bool bootloader);
