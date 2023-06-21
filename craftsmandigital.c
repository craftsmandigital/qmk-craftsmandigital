#include "craftsmandigital.h"



uint16_t my_key_pressed_timer = 0;

// --------------------------------------------------------------------------------


// --------------------------------------------------------------------------------
// Leader stuff
/* LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
	
	SEQ_ONE_KEY(KC_X) {
      // Anything you can do in a macro.
	  register_code(KC_LCTL);
      register_code(KC_F4);
      unregister_code(KC_F4);
      unregister_code(KC_LCTL);
      // SEND_STRING(SS_DOWN(KC_LCTL)SS_TAP(KC_F4)SS_UP(KC_LCTL));
    }

    SEQ_ONE_KEY(KC_Q) {	  
	  register_code(KC_LALT);
      register_code(KC_F4);
      unregister_code(KC_F4);
      unregister_code(KC_LALT);
    }
    SEQ_TWO_KEYS(KC_X, KC_X) {
      SEND_STRING(SS_LCTL(SS_LSFT("t")));
    }
  }
} */


void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_X)) {
	    register_code(KC_LCTL);
        register_code(KC_F4);
        unregister_code(KC_F4);
        unregister_code(KC_LCTL);
        // SEND_STRING(SS_DOWN(KC_LCTL)SS_TAP(KC_F4)SS_UP(KC_LCTL));
    } else if (leader_sequence_one_key(KC_Q)) {
	    register_code(KC_LALT);
        register_code(KC_F4);
        unregister_code(KC_F4);
        unregister_code(KC_LALT);
    } else if (leader_sequence_two_keys(KC_X, KC_X)) {
        SEND_STRING(SS_LCTL(SS_LSFT("t")));
    } 
}


// --------------------------------------------------------------------------------
// Macro stuff
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	

    switch (keycode) {
    case PAREN:
        if (record->event.pressed) {
            // when key ( is pressed
            SEND_STRING("()"SS_TAP(X_LEFT));
        }
        break;
    case BRACKET:
        if (record->event.pressed) {
			// when key [ is pressed
            SEND_STRING("[]"SS_TAP(X_LEFT));
        }
        break;
    case CURLEY:
        if (record->event.pressed) {
            // when key { is pressed
            SEND_STRING("{}"SS_TAP(X_LEFT));
        }
        break;
    case QUOT:
        if (record->event.pressed) {
            // when key ' is pressed
            SEND_STRING("''"SS_TAP(X_LEFT));
        }
        break;
    case DQUOT:
        if (record->event.pressed) {
            // when key " is pressed
            SEND_STRING("\"\""SS_TAP(X_LEFT));
        }
        break;
	// The four next keys goes to their extremes on long tapp
	// and do shorter travel on short press
    case MY_END:
        if (record->event.pressed) {
            my_key_pressed_timer = timer_read();
        } else {
			// goes by word to the right when short pressed.
			if (timer_elapsed(my_key_pressed_timer) < LEADER_TIMEOUT) {
				register_code(KC_LCTL);
				tap_code(KC_RGHT);
				unregister_code(KC_LCTL);
			} else {
				// goes to end of line on long press
				tap_code(KC_END);
			}
		}
        break;
		case MY_HOME:
        if (record->event.pressed) {
            my_key_pressed_timer = timer_read();
        } else {
			if (timer_elapsed(my_key_pressed_timer) < LEADER_TIMEOUT) {
				register_code(KC_LCTL);
				tap_code(KC_LEFT);
				unregister_code(KC_LCTL);
			} else {
				tap_code(KC_HOME);
			}
		}
        break;
		case MY_COPY:
        if (record->event.pressed) {
            my_key_pressed_timer = timer_read();
        } else {
			if (timer_elapsed(my_key_pressed_timer) < LEADER_TIMEOUT) {
				register_code(KC_LCTL);
				tap_code(KC_C);
				unregister_code(KC_LCTL);
			} else {
				register_code(KC_LCTL);
				tap_code(KC_A);
				unregister_code(KC_LCTL);
			}
		}
		break;
		case MY_UNDRDO:
        if (record->event.pressed) {
            my_key_pressed_timer = timer_read();
        } else {
			if (timer_elapsed(my_key_pressed_timer) < LEADER_TIMEOUT) {
				register_code(KC_LCTL);
				tap_code(KC_Z);
				unregister_code(KC_LCTL);
			} else {
				register_code(KC_LCTL);
				tap_code(KC_Y);
				unregister_code(KC_LCTL);
			}
		}
        break;
		case MY_PASTE:
        if (record->event.pressed) {
            my_key_pressed_timer = timer_read();
        } else {
			register_code(KC_LCTL);
			if (timer_elapsed(my_key_pressed_timer) < LEADER_TIMEOUT) {
				register_code(KC_LSFT);
				tap_code(KC_V);
				unregister_code(KC_LSFT);
			} else {
				tap_code(KC_V);
			}
			unregister_code(KC_LCTL);
		}
        break;
		case MY_PGDN:
        if (record->event.pressed) {
            my_key_pressed_timer = timer_read();
        } else {
			if (timer_elapsed(my_key_pressed_timer) < LEADER_TIMEOUT) {
				tap_code(KC_PGDN);
			} else {
				register_code(KC_LCTL);
				tap_code(KC_END);
				unregister_code(KC_LCTL);
				
			}
		}
        break;
		case MY_PGUP:
        if (record->event.pressed) {
            my_key_pressed_timer = timer_read();
        } else {
			if (timer_elapsed(my_key_pressed_timer) < LEADER_TIMEOUT) {
				tap_code(KC_PGUP);
			} else {
				register_code(KC_LCTL);
				tap_code(KC_HOME);
				unregister_code(KC_LCTL);
				
			}
		}
		break;
		// Nordic caracter stuff is dependent of autohotkey
		// https://www.thenickmay.com/how-to-expand-text-for-free-with-autohotkey/
		// When keypress is shifted then keypress is different the char "-" becoms a "_"
		// auto hotkey schipt handles this and expand the right nordic character
		case _AA	:	// å Å
		if (record->event.pressed) {
				SEND_STRING("-&a");  // Becomes _&a when shifted
		}
		break;
		case _AE	:	// æ Æ
		if (record->event.pressed) {
				SEND_STRING("-&e");  // Becomes _&e when shifted
		}
		break;
		// case _OE	:	// ø Ø
		// if (record->event.pressed) {
				// SEND_STRING("-&o");  // Becomes _&o when shifted
		// }
		// break;
		case RGUI_T(_OE)	:	// ø Ø
		// This was extremely difficult to program, because of the nature of GUI modifier
		// It is also triggered on tap. luckyly the solution was quite easy. The solution was found on website under:
		// https://github.com/qmk/qmk_firmware/blob/master/docs/mod_tap.md#changing-tap-function.
		// The moust obious solution was something like the website under. 
		// But doestnt work because of the nature of the GUI modifier
		// https://thomasbaart.nl/2018/12/09/qmk-basics-tap-and-hold-actions/#a-workaround-for-mod-tap
		
		if (record->tap.count && record->event.pressed) {
			SEND_STRING("-&o"); // Send KC_DQUO on tap
			return false;        // Return false to ignore further processing of key
		}
		break;

    }
    return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
    case MY_GUI_NUM:
	// This is a oneshotlayer and oneshot modifier at the same time
	// SYM layer and GUI modifier at once.
	// This makes it easy to switch apps in the taskbar in windows 10. 
	// The state before next key pressed is num layer and gui modifier.
	// When user press a nuber key, then it triggers to open or switching to that app in taskbar
        if (record->event.pressed) {
            // layer_on(NUM);
            set_oneshot_layer(NUM, ONESHOT_START);
            clear_oneshot_layer_state(ONESHOT_PRESSED);
			
			set_oneshot_mods(MOD_RGUI);
        } else {
			// clear_oneshot_layer_state(ONESHOT_PRESSED);
		}
        break;

    }

};