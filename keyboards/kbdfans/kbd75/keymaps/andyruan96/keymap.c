#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_75_ansi(
		KC_ESC, 	KC_F1,		KC_F2, 		KC_F3, 		KC_F4,		KC_F5, 		KC_F6, 		KC_F7, 		KC_F8, 		KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	KC_PSCR, 	KC_INS, 	KC_DEL,
		KC_GRV, 	KC_1, 		KC_2, 		KC_3, 		KC_4,		KC_5, 		KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_MINS, 	KC_EQL, 	KC_BSPC, 				KC_HOME,
		KC_TAB, 	KC_Q, 		KC_W, 		KC_E, 		KC_R, 		KC_T, 		KC_Y, 		KC_U, 		KC_I, 		KC_O, 		KC_P, 		KC_LBRC, 	KC_RBRC, 	KC_BSLS, 				KC_END,
		KC_CAPS, 				KC_A, 		KC_S, 		KC_D, 		KC_F, 		KC_G, 		KC_H, 		KC_J, 		KC_K, 		KC_L, 		KC_SCLN, 	KC_QUOT, 	KC_ENT, 				KC_PGUP,
		KC_LSFT, 				KC_Z, 		KC_X, 		KC_C, 		KC_V, 		KC_B, 		KC_N, 		KC_M, 		KC_COMM, 	KC_DOT, 	KC_SLSH, 	KC_RSFT, 				KC_UP, 		KC_PGDN,
		KC_LCTL,	KC_LGUI, 	KC_LALT, 										KC_SPC, 										KC_RALT, 	MO(1), 		KC_RCTL, 	KC_LEFT, 	KC_DOWN, 	KC_RGHT
	),
	
	[1] = LAYOUT_75_ansi(
		KC_TRNS,	KC_MPRV,	KC_MPLY,	KC_MNXT,	KC_TRNS, 	KC_VOLD,	KC_MUTE, 	KC_VOLU, 	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS, 	KC_TRNS, 	KC_SLCK, 	KC_PAUS,
		KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	RESET, 					KC_NLCK,
		KC_TRNS, 	RGB_TOG, 	RGB_MOD, 	RGB_HUI, 	RGB_HUD, 	RGB_SAI, 	RGB_SAD, 	RGB_VAI, 	RGB_VAD, 	RGB_SPI, 	RGB_SPD, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 				KC_TRNS,
		KC_TRNS, 				RGB_M_P, 	RGB_M_B, 	RGB_M_R, 	RGB_M_SW, 	RGB_M_SN, 	RGB_M_K, 	RGB_M_X, 	RGB_M_G, 	RGB_M_T, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 				KC_TRNS,
		KC_TRNS, 				BL_OFF, 	BL_ON, 		BL_DEC, 	BL_TOGG, 	BL_INC, 	BL_STEP, 	KC_TRNS, 	KC_TRNS,	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 				KC_TRNS, 	KC_TRNS,
		KC_TRNS, 	KC_TRNS, 	KC_TRNS, 										KC_TRNS, 										KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS
	)
};

// Lighting layers
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, 10, 149, 255},		// Coral
	{13, 3, 10, 149, 255}
);
const rgblight_segment_t PROGMEM my_scrolllock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, 212, 70, 221},		// Plum
	{11, 2, 212, 70, 221}
);
const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 6, 49, 178, 255}		// Green
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 2, HSV_WHITE}
);

// Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
	my_scrolllock_layer,
	my_numlock_layer,
    my_layer1_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(3, layer_state_cmp(state, 1));
    return state;
};

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
	rgblight_set_layer_state(1, led_state.scroll_lock);
	rgblight_set_layer_state(2, !led_state.num_lock);	// Indicate when numlock is OFF
    return true;
};
