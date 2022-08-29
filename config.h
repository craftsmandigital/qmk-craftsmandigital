



#define COMBO_COUNT 7
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250



// --------------------------------------------------
// Homerow modifier setup. This prevent some rolover effect on Tap hold.
// https://precondition.github.io/home-row-mods#getting-started-with-home-row-mods-on-qmk
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD
// --------------------------------------------------
#