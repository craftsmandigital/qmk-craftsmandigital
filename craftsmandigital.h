#pragma once
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers { BASE, MBO, MEDIA, NAV, MOUSE, SYM, NUM, FUN };



/* 



#elseif LAYOUT_split_3x5_3
 */
 
#ifdef LAYOUT_split_3x5_3
#define LAYOUT_miryoku(\
K00,   K01,   K02,   K03,   K04,          K05,   K06,   K07,   K08,   K09,\
K10,   K11,   K12,   K13,   K14,          K15,   K16,   K17,   K18,   K19,\
K20,   K21,   K22,   K23,   K24,          K25,   K26,   K27,   K28,   K29,\
N30,   N31,   K32,   K33,   K34,          K35,   K36,   K37,   N38,   N39\
)\
LAYOUT_split_3x5_3(\
K00,   K01,   K02,   K03,   K04,          K05,   K06,   K07,   K08,   K09,\
K10,   K11,   K12,   K13,   K14,          K15,   K16,   K17,   K18,   K19,\
K20,   K21,   K22,   K23,   K24,          K25,   K26,   K27,   K28,   K29,\
              K32,   K33,   K34,          K35,   K36,   K37\
)
#endif
#ifdef LAYOUT_ortho_4x12
#define LAYOUT_miryoku(\
K00,   K01,   K02,   K03,   K04,                 K05,   K06,   K07,   K08,   K09,\
K10,   K11,   K12,   K13,   K14,                 K15,   K16,   K17,   K18,   K19,\
K20,   K21,   K22,   K23,   K24,                 K25,   K26,   K27,   K28,   K29,\
N30,   N31,   K32,   K33,   K34,                 K35,   K36,   K37,   N38,   N39\
)\
LAYOUT_ortho_4x12(\
KC_NO, K01,   K02,   K03,   K04,   KC_NO, KC_NO, K05,   K06,   K07,   K08,   KC_NO,\
K00,   K11,   K12,   K13,   K14,   KC_NO, KC_NO, K15,   K16,   K17,   K18,   K09,\
K10,   K21,   K22,   K23,   K24,   KC_NO, KC_NO, K25,   K26,   K27,   K28,   K19,\
K20,   KC_NO, KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   KC_NO, KC_NO, K29\
)
#endif











#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)

// Macro stuff
enum custom_keycodes {
	PAREN = SAFE_RANGE,
    BRACKET,
    CURLEY,
	QUOT,
	DQUOT,
	MY_END,
	MY_HOME,
	MY_PASTE,
	MY_COPY,
 	MY_PGUP,
	MY_PGDN,
	MY_GUI_NUM,
	MY_UNDRDO,
	_AA, // Åå
	_AE, // æÆ
	_OE, // øØ
};