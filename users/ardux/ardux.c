// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "ardux.h"

#ifdef POINTING_DEVICE_ENABLE
#include "layout/pimoroni.h"
#endif

// /////////
// User remixes / tweaks -- these take precidence above all else
#if __has_include("layout/remixes/remix_functions.h")
#include "layout/remixes/remix_functions.h"
#endif
// /////////

// /////////
// Caps lock status
bool is_caps_lock_on(void) {
    led_t led_state = host_keyboard_led_state();
    return led_state.caps_lock;
}

// /////////
// Layer underglow
// /////////
#ifdef ARDUX_LAYER_UNDERGLOW
const rgblight_segment_t PROGMEM ardux_big[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_BLUE}
);
const rgblight_segment_t PROGMEM ardux_40p[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_CYAN}
);
const rgblight_segment_t PROGMEM ardux_misc[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM ardux_toggle_key[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM ardux_toggle_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_RED}
);


const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    ardux_big,
    ardux_40p,
    ardux_misc,
    ardux_toggle_key,
    ardux_toggle_layer
);

void update_rgblight_layer_toggle_keys() {
    if (get_mods() & MOD_BIT(KC_LSFT)
            || is_caps_lock_on()) {
        rgblight_set_layer_state(3, true);
    }
    else {
        rgblight_set_layer_state(3, false);
    }
    rgblight_set(); // Flush out led buffers to LEDs
}

bool led_update_user(led_t led_state) {
    update_rgblight_layer_toggle_keys();
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    // this function is called during init, assume its to activate the default layer
    //      which should be one handed mode
    // default layer active on startup
    rgblight_set_layer_state(0, layer_state_cmp(state, LAYER_ID_BASE));
    rgblight_set(); // Flush out led buffers to LEDs
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // big ardux
    if (layer_state_cmp(state, LAYER_ID_BASE)) {
        rgblight_set_layer_state(0, true);
    }
    else {
        rgblight_set_layer_state(0, false);
    }

    // 40% ardux
    if (layer_state_cmp(state, LAYER_ID_40P_BASE)) {
        rgblight_set_layer_state(1, true);
    }
    else {
        rgblight_set_layer_state(1, false);
    }

    // misc (temp layers, etc)
    if (layer_state_cmp(state, LAYER_ID_NUMBERS)
            || layer_state_cmp(state, LAYER_ID_SYMBOLS)
            || layer_state_cmp(state, LAYER_ID_PARENTHETICALS)
            || layer_state_cmp(state, LAYER_ID_CUSTOM)
            || layer_state_cmp(state, LAYER_ID_BIG_SYM) 
            || layer_state_cmp(state, LAYER_ID_40P_NAVIGATION)
            || layer_state_cmp(state, LAYER_ID_40P_FUNCTION)) {
        rgblight_set_layer_state(2, true);
    }
    else {
        rgblight_set_layer_state(2, false);
    }

    // toggle layers (mouse, nav, etc)
    if (layer_state_cmp(state, LAYER_ID_MOUSE)
            || layer_state_cmp(state, LAYER_ID_NAVIGATION)
            || layer_state_cmp(state, LAYER_ID_BIG_FUN)) {
        rgblight_set_layer_state(4, true);
    }
    else {
        rgblight_set_layer_state(4, false);
    }

    rgblight_set(); // Flush out led buffers to LEDs

    return state;
}
#endif

void keyboard_post_init_user(void) {
    // Enable the LED layers
#ifdef ARDUX_LAYER_UNDERGLOW
    rgblight_layers = my_rgb_layers;
    // disable light on startup / default to avoid the default of 'red' from
    //     overlapping with our custom layer lighting status
    // will also auto-off non primary half leds when only primary side of 40% should be lit
    //     when ARDUX_LAYER_UNDERGLOW_ONLY_PRIMARY is specified at compile time
    rgblight_sethsv(HSV_OFF);
    rgblight_set(); // Flush out led buffers to LEDs
#endif

#ifdef POINTING_DEVICE_ENABLE
    pimoroni_trackball_set_rgbw(PIMORONI_RGB, PIMORONI_BRIGHTNESS);
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCK_SHIFT:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LSFT)) {
                    unregister_mods(MOD_BIT(KC_LSFT));
#ifdef ARDUX_LAYER_UNDERGLOW
                    update_rgblight_layer_toggle_keys();
#endif
                }
                else {
                    register_mods(MOD_BIT(KC_LSFT));
#ifdef ARDUX_LAYER_UNDERGLOW
                    update_rgblight_layer_toggle_keys();
#endif
                }
            }
            break;
        case OSM_CTRL:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_BIT(KC_LCTL));
            }
            break;
        case OSM_GUI:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_BIT(KC_LGUI));
            }
            break;
        case OSM_ALT:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_BIT(KC_LALT));
            }
            break;
        case OSM_SHIFT:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            break;

#ifdef POINTING_DEVICE_ENABLE
        case BALL_HUI:
            if (record->event.pressed) {
                ball_increase_hue();
            }
            break;

        case BALL_WHT:
            if (record->event.pressed) {
                cycle_white();
            }
            break;

        case BALL_DEC:
            if (record->event.pressed) {
                decrease_color();
            }
            break;

        case BALL_SCR:
            if (record->event.pressed) {
                set_scrolling = true;
            } else {
                set_scrolling = false;
            }
            break;

        case BALL_NCL:
            record->event.pressed ? register_code(KC_BTN1) : unregister_code(KC_BTN1);
            break;
        case BALL_RCL:
            record->event.pressed ? register_code(KC_BTN2) : unregister_code(KC_BTN2);
            break;
        case BALL_MCL:
            record->event.pressed ? register_code(KC_BTN3) : unregister_code(KC_BTN3);
            break;
#endif
        default:
            break;
    }
    return true;
}
