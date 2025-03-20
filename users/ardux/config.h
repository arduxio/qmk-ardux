// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0

#pragma once

// //////////
// RGB 'stuff' is generally unsupported
#ifdef ARDUX_LAYER_UNDERGLOW
#define RGBLIGHT_LAYERS
#define RGBLIGHT_MAX_LAYERS 32
// disable light on startup / default to avoid the default of 'red' from
// overlapping with our custom layer lighting status
#define RGBLIGHT_DEFAULT_HUE 0
#define RGBLIGHT_DEFAULT_SAT 0
#define RGBLIGHT_DEFAULT_VAL 0
#ifdef ARDUX_SIZE_40P
#define RGBLIGHT_SPLIT
#endif
#endif

// //////////
// Combos Config
#include "layout/layer_ids.h"
#define EXTRA_LONG_COMBOS
#define COMBO_VARIABLE_LEN

// //////////
// 40% ARDUX related
#ifdef ARDUX_SIZE_40P
#define TAPPING_TERM_PER_KEY
// to ensure state stays in sync between split halves
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_ACTIVITY_ENABLE
// Force 'master' to be whichever hand is set as primary/big ardux
#ifdef ARDUX_HAND_LEFT
#define MASTER_LEFT
#endif
#ifdef ARDUX_HAND_RIGHT
#define MASTER_RIGHT
#endif
#endif

// //////////
// Ensure 'master' is set to match handedness of ardux
#ifdef ARDUX_HAND_LEFT
#define MASTER_LEFT
#undef MASTER_RIGHT
#endif
#ifdef ARDUX_HAND_RIGHT
#undef MASTER_LEFT
#define MASTER_RIGHT
#endif

// ////////
// Pimoroni trackball
#ifdef POINTING_DEVICE_ENABLE
#define POINTING_DEVICE_ROTATION_90
#ifdef ARDUX_HAND_LEFT
#define TRACKBALL_LEFT
#endif
#ifdef ARDUX_HAND_RIGHT
#define TRACKBALL_RIGHT
#define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_INVERT_Y
#endif
#endif

// /////////
// Remove Layer count restrictions
#ifdef LAYER_STATE_8BIT
#undef LAYER_STATE_8BIT
#endif
#ifdef MAX_LAYER
#undef MAX_LAYER
#endif

// //////////
// Most of ardux, the WHOLE layout, start here for remixes - this is critical!
#include "layout/_layout.h"
