#include "craftsmandigital.h"

// combos stuff
enum combo_events {
  JK_ESC,
  DF_TAB,
  NAV_TOGLE,
  SYM_TOGLE,
  NUM_TOGLE,
  MOUSE_TOGLE,
  GUI_NUM,
};

// --------------------------------------------------------------------------------
// combos stuff
const uint16_t PROGMEM jk_combo[] =  {LSFT_T(KC_J),		LCTL_T(KC_K),	COMBO_END};
const uint16_t PROGMEM df_combo[] =  {LSFT_T(KC_F), 	LCTL_T(KC_D),	COMBO_END};
const uint16_t PROGMEM nav_combo[] = {LT(NAV, KC_SPC),	LSFT_T(KC_J),	COMBO_END};
const uint16_t PROGMEM sym_combo[] = {LSFT_T(KC_F),		OSL(SYM),		COMBO_END};
const uint16_t PROGMEM num_combo[] = {LSFT_T(KC_F),		LT(NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM mouse_combo[] = {LT(MOUSE, KC_DOT),LSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM gui_num_combo[] = {LCTL_T(KC_K), LALT_T(KC_L), COMBO_END};


combo_t key_combos[] = {
  [JK_ESC] = COMBO(jk_combo, KC_ESC),
  [DF_TAB] = COMBO(df_combo, KC_TAB),
  [NAV_TOGLE] = COMBO(nav_combo, TG(NAV)),
  [SYM_TOGLE] = COMBO(sym_combo, TG(SYM)),
  [NUM_TOGLE] = COMBO(num_combo, TG(NUM)),
  [GUI_NUM] = COMBO(gui_num_combo, MY_GUI_NUM),
  [MOUSE_TOGLE] = COMBO(mouse_combo, TG(MOUSE)),
  // [QW_SFT] = COMBO(qw_combo, KC_LSFT)
  // [SD_LAYER] = COMBO(layer_combo, MO(_LAYER)),
};