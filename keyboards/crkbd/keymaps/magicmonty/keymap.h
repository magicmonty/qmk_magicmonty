#pragma once

#define U_BASE 0
#define U_EXTRA 1
#define U_NAV 2
#define U_MEDIA 3
#define U_NUM 4
#define U_SYM 5
#define U_FUN 6

#define U_MEDIA_ESC LT(U_MEDIA, KC_ESC)
#define U_NAV_SPC LT(U_NAV, KC_SPC)
#define U_SYM_ENT LT(U_SYM, KC_ENT)
#define U_NUM_BSP LT(U_NUM, KC_BSPC)
#define U_FUN_DEL LT(U_FUN, KC_DEL)

#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO
