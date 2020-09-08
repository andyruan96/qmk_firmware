#include QMK_KEYBOARD_H

enum custom_keycodes {
	MS_BRICK = SAFE_RANGE,
	MS_CLAW,
	MS_BAT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case MS_BRICK:
			if (record->event.pressed) {
				SEND_STRING(
					SS_DOWN(X_Q) SS_DELAY(150) SS_UP(X_Q)
					SS_DOWN(X_2) SS_DELAY(250) SS_UP(X_2)
					SS_DOWN(X_Q) SS_DELAY(150) SS_UP(X_Q)
					SS_DOWN(X_3) SS_DELAY(250) SS_UP(X_3)
					SS_DOWN(X_Q) SS_DELAY(150) SS_UP(X_Q)
					SS_DOWN(X_4) SS_DELAY(250) SS_UP(X_4)
				);
			}
			break;

		case MS_CLAW:
			if (record->event.pressed) {
				SEND_STRING(
					SS_DOWN(X_Q) SS_DELAY(150) SS_UP(X_Q)
					SS_DOWN(X_W) SS_DELAY(250) SS_UP(X_W)
					SS_TAP(X_LSFT) SS_DELAY(200)
					SS_DOWN(X_E) SS_DELAY(450) SS_UP(X_E)
					SS_DOWN(X_Q) SS_DELAY(100) SS_UP(X_Q)
					SS_DOWN(X_R) SS_DELAY(250) SS_UP(X_R)
				);
			}
			break;

		case MS_BAT:
			if (record->event.pressed) {
				SEND_STRING(
					SS_DOWN(X_Q) SS_DELAY(150) SS_UP(X_Q)
					SS_DOWN(X_S) SS_DELAY(250) SS_UP(X_S)
					SS_DOWN(X_Q) SS_DELAY(150) SS_UP(X_Q)
					SS_DOWN(X_D) SS_DELAY(250) SS_UP(X_D)
					SS_DOWN(X_D) SS_DELAY(500) SS_UP(X_D)
					SS_DOWN(X_D) SS_DELAY(250) SS_UP(X_D)
				);
			}
			break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_75_ansi(
		KC_ESC, 	KC_F1,		KC_F2, 		KC_F3, 		KC_F4,		KC_F5, 		KC_F6, 		KC_F7, 		KC_F8, 		KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	KC_PSCR, 	KC_INS, 	KC_DEL,
		KC_GRV, 	KC_1, 		KC_2, 		KC_3, 		KC_4,		KC_5, 		KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_MINS, 	KC_EQL, 	KC_BSPC, 				KC_HOME,
		KC_TAB, 	KC_Q, 		KC_W, 		KC_E, 		KC_R, 		KC_T, 		KC_Y, 		KC_U, 		KC_I, 		KC_O, 		KC_P, 		KC_LBRC, 	KC_RBRC, 	KC_BSLS, 				KC_END,
		KC_CAPS, 	KC_A, 		KC_S, 		KC_D, 		KC_F, 		KC_G, 		KC_H, 		KC_J, 		KC_K, 		KC_L, 		KC_SCLN, 	KC_QUOT, 	KC_ENT, 							KC_PGUP,
		KC_LSFT, 	KC_Z, 		KC_X, 		KC_C, 		KC_V, 		KC_B, 		KC_N, 		KC_M, 		KC_COMM, 	KC_DOT, 	KC_SLSH, 	KC_RSFT, 							KC_UP, 		KC_PGDN,
		KC_LCTL,	KC_LGUI, 	KC_LALT, 										KC_SPC, 										KC_RALT, 	MO(1), 		KC_RCTL, 	KC_LEFT, 	KC_DOWN, 	KC_RGHT
	),
	
	[1] = LAYOUT_75_ansi(
		_______,	KC_MPRV,	KC_MPLY,	KC_MNXT,	_______, 	KC_VOLD,	KC_MUTE, 	KC_VOLU, 	_______,	_______,	_______,	_______,	_______, 	_______, 	KC_SLCK, 	KC_PAUS,
		_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	RESET, 					KC_NLCK,
		_______, 	RGB_TOG, 	RGB_MOD, 	RGB_HUI, 	RGB_HUD, 	RGB_SAI, 	RGB_SAD, 	RGB_VAI, 	RGB_VAD, 	RGB_SPI, 	RGB_SPD, 	_______, 	_______, 	_______, 				_______,
		_______, 	RGB_M_P, 	RGB_M_B, 	RGB_M_R, 	RGB_M_SW, 	RGB_M_SN, 	RGB_M_K, 	RGB_M_X, 	RGB_M_G, 	RGB_M_T, 	_______, 	_______, 	_______, 							_______,
		_______, 	BL_OFF, 	BL_ON, 		BL_DEC, 	BL_TOGG, 	BL_INC, 	BL_STEP, 	TG(2), 		_______,	_______, 	_______, 	_______, 							_______, 	_______,
		_______, 	_______, 	_______, 										_______, 										_______, 	_______, 	_______, 	_______, 	_______, 	_______
	),

	[2] = LAYOUT_75_ansi(
		_______,	_______,	_______,	_______,	_______, 	_______,	_______, 	_______, 	_______,	_______,	_______,	_______,	_______, 	_______, 	_______, 	_______,
		_______, 	_______, 	MS_BRICK, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 				_______,
		_______, 	_______, 	MS_CLAW, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 				_______,
		_______, 	_______, 	MS_BAT, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______,					 		_______,
		_______,	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______,	_______, 	_______, 	_______, 							_______, 	_______,
		_______, 	_______,	_______, 										_______, 										_______, 	_______, 	_______, 	_______, 	_______, 	_______
	)
};

// Lighting layers
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_MY_BURNT_SIENNA},
	{13, 3, HSV_MY_BURNT_SIENNA}
);
const rgblight_segment_t PROGMEM my_scrolllock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, HSV_MY_HARVEST_GOLD},
	{11, 2, HSV_MY_HARVEST_GOLD}
);
const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 6, HSV_MY_AVOCADO}
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 2, HSV_WHITE}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_MY_MS_ORANGE}
);

// Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
	my_scrolllock_layer,
	my_numlock_layer,
    my_layer1_layer,
	my_layer2_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(3, layer_state_cmp(state, 1));
	rgblight_set_layer_state(4, layer_state_cmp(state, 2));
    return state;
};

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
	rgblight_set_layer_state(1, led_state.scroll_lock);
	rgblight_set_layer_state(2, !led_state.num_lock);	// Indicate when numlock is OFF
    return true;
};
