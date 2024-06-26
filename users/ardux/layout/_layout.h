// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0
#pragma once

// /////////
// User remixes / tweaks -- these take precidence above all else
#if __has_include("remixes/remix_globals.h")
#include "remixes/remix_globals.h"
#endif

// //////////
// ARDUX layer ids (needed everywhere)
#include "layer_ids.h"

// //////////
// Keycode definitons (needed everywhere)
#include "layout/keycodes.h"

// //////////
// Combo definitons
// are included in ../combos.def ; use use the more advanced combo engine germ maintains (is built into qmk core sources)

// //////////
// Tap dance for 40%
#ifdef ARDUX_SIZE_40P
#include "tap_dance.h"
#endif

// //////////
// Pimoroni stuff
#ifdef POINTING_DEVICE_ENABLE
#include "layout/pimoroni.h"
#endif

// //////////
// Board tuning so standard layout/map can be built programatically
#ifdef KEYBOARD_crkbd_rev1
#include "boards/crkbd_rev1.h"
#endif
#ifdef KEYBOARD_gboards_gergo
#include "boards/gboards_gergo.h"
#endif
#ifdef KEYBOARD_ristretto
#include "boards/ristretto.h"
#endif
#ifdef KEYBOARD_draculad
#include "boards/draculad.h"
#endif
#ifdef KEYBOARD_ferris_sweep
#include "boards/ferris_sweep.h"
#endif
#ifdef KEYBOARD_maple_computing_minidox_rev1
#include "boards/minidox_rev1.h"
#endif
#ifdef KEYBOARD_boardsource_microdox
#include "boards/boardsource_microdox.h"
#endif
#ifdef KEYBOARD_ai03_soyuz
#include "boards/ai03_soyuz.h"
#endif
#ifdef KEYBOARD_ardux_thepaintbrush
#include "boards/ardux_thepaintbrush.h"
#endif
#ifdef KEYBOARD_faunchpad
#include "boards/faunchpad.h"
#endif
#ifdef KEYBOARD_geekboards_macropad_v2
#include "boards/geekboards_macropad_v2.h"
#endif
#ifdef KEYBOARD_splitkb_kyria_rev2
#include "boards/splitkb_kyria_rev2.h"
#endif

// //////////
// Include layers last so all overrides and ids are set prior to processing
#include "layers.h"

// //////////
// Keymap generation stuff to use left/right handedness based on qmk compile env selection
// Standard ARDUX layer definitions

// Ardux layout wrapper
#ifdef KEYBOARD_crkbd_rev1
#define LAYOUT_ardux_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#else
#ifdef KEYBOARD_gboards_gergo
#define LAYOUT_ardux_wrapper(...) LAYOUT_gergo(__VA_ARGS__)
#else
#ifdef KEYBOARD_faunchpad
#define LAYOUT_ardux_wrapper(...) LAYOUT_faunch(__VA_ARGS__)
#else
#ifdef KEYBOARD_maple_computing_minidox_rev1
#define LAYOUT_ardux_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)
#else
#ifdef KEYBOARD_boardsource_microdox
#define LAYOUT_ardux_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)
#else
#ifdef KEYBOARD_ai03_soyuz
#define LAYOUT_ardux_wrapper(...) LAYOUT_ortho_5x4(__VA_ARGS__)
#else
#ifdef KEYBOARD_geekboards_macropad_v2
#define LAYOUT_ardux_wrapper(...) LAYOUT_ortho_2x4(__VA_ARGS__)
#else
#define LAYOUT_ardux_wrapper(...) LAYOUT(__VA_ARGS__)
#endif // KEYBOARD_geekboards_macropad_v2
#endif // KEYBOARD_ai03_soyuz
#endif // KEYBOARD_boardsource_microdox
#endif // KEYBOARD_minidox_rev1
#endif // KEYBOARD_faunchpad
#endif // KEYBOARD_gboards_gergo
#endif // KEYBOARD_crkbd_rev1

// Allow proper auto selection of std size via keymaps
#ifdef ARDUX_SIZE_STD
// Allow proper auto selection of left / right via keymaps
#ifdef ARDUX_HAND_LEFT
#define ARDUX_STD_LAYER_BASE ARDUX_STD_LAYER_BASE_LEFT
#define ARDUX_STD_LAYER_NUM ARDUX_STD_LAYER_NUM_LEFT
#define ARDUX_STD_LAYER_SYM ARDUX_STD_LAYER_SYM_LEFT
#define ARDUX_STD_LAYER_PAR ARDUX_STD_LAYER_PAR_LEFT
#define ARDUX_STD_LAYER_NAV ARDUX_STD_LAYER_NAV_LEFT
#define ARDUX_STD_LAYER_CUS ARDUX_STD_LAYER_CUS_LEFT
#define ARDUX_STD_LAYER_MSE ARDUX_STD_LAYER_MSE_LEFT
#endif
#ifdef ARDUX_HAND_RIGHT
#define ARDUX_STD_LAYER_BASE ARDUX_STD_LAYER_BASE_RIGHT
#define ARDUX_STD_LAYER_NUM ARDUX_STD_LAYER_NUM_RIGHT
#define ARDUX_STD_LAYER_SYM ARDUX_STD_LAYER_SYM_RIGHT
#define ARDUX_STD_LAYER_PAR ARDUX_STD_LAYER_PAR_RIGHT
#define ARDUX_STD_LAYER_NAV ARDUX_STD_LAYER_NAV_RIGHT
#define ARDUX_STD_LAYER_CUS ARDUX_STD_LAYER_CUS_RIGHT
#define ARDUX_STD_LAYER_MSE ARDUX_STD_LAYER_MSE_RIGHT
#endif
#endif

// Allow proper auto selection of big size via keymaps
#ifdef ARDUX_SIZE_BIG
// Allow proper auto selection of left / right via keymaps
#ifdef ARDUX_HAND_LEFT
#define ARDUX_BIG_LAYER_BASE ARDUX_BIG_LAYER_BASE_LEFT
#define ARDUX_BIG_LAYER_NUM ARDUX_BIG_LAYER_NUM_LEFT
#define ARDUX_BIG_LAYER_SYM ARDUX_BIG_LAYER_SYM_LEFT
#define ARDUX_BIG_LAYER_PAR ARDUX_BIG_LAYER_PAR_LEFT
#define ARDUX_BIG_LAYER_NAV ARDUX_BIG_LAYER_NAV_LEFT
#define ARDUX_BIG_LAYER_CUS ARDUX_BIG_LAYER_CUS_LEFT
#define ARDUX_BIG_LAYER_MSE ARDUX_BIG_LAYER_MSE_LEFT
#define ARDUX_BIG_LAYER_BIG_SYM ARDUX_BIG_LAYER_BIG_SYM_LEFT
#define ARDUX_BIG_LAYER_BIG_FUN ARDUX_BIG_LAYER_BIG_FUN_LEFT

#endif
#ifdef ARDUX_HAND_RIGHT
#define ARDUX_BIG_LAYER_BASE ARDUX_BIG_LAYER_BASE_RIGHT
#define ARDUX_BIG_LAYER_NUM ARDUX_BIG_LAYER_NUM_RIGHT
#define ARDUX_BIG_LAYER_SYM ARDUX_BIG_LAYER_SYM_RIGHT
#define ARDUX_BIG_LAYER_PAR ARDUX_BIG_LAYER_PAR_RIGHT
#define ARDUX_BIG_LAYER_NAV ARDUX_BIG_LAYER_NAV_RIGHT
#define ARDUX_BIG_LAYER_CUS ARDUX_BIG_LAYER_CUS_RIGHT
#define ARDUX_BIG_LAYER_MSE ARDUX_BIG_LAYER_MSE_RIGHT
#define ARDUX_BIG_LAYER_BIG_SYM ARDUX_BIG_LAYER_BIG_SYM_RIGHT
#define ARDUX_BIG_LAYER_BIG_FUN ARDUX_BIG_LAYER_BIG_FUN_RIGHT
#endif
#endif

// Allow proper auto selection of 40% size via keymaps
#ifdef ARDUX_SIZE_40P
// Allow proper auto selection of left / right via keymaps
#ifdef ARDUX_HAND_LEFT
#define ARDUX_BIG_LAYER_BASE ARDUX_BIG_LAYER_BASE_LEFT
#define ARDUX_BIG_LAYER_NUM ARDUX_BIG_LAYER_NUM_LEFT
#define ARDUX_BIG_LAYER_SYM ARDUX_BIG_LAYER_SYM_LEFT
#define ARDUX_BIG_LAYER_PAR ARDUX_BIG_LAYER_PAR_LEFT
#define ARDUX_BIG_LAYER_NAV ARDUX_BIG_LAYER_NAV_LEFT
#define ARDUX_BIG_LAYER_CUS ARDUX_BIG_LAYER_CUS_LEFT
#define ARDUX_BIG_LAYER_MSE ARDUX_BIG_LAYER_MSE_LEFT
#define ARDUX_BIG_LAYER_BIG_SYM ARDUX_BIG_LAYER_BIG_SYM_LEFT
#define ARDUX_BIG_LAYER_BIG_FUN ARDUX_BIG_LAYER_BIG_FUN_LEFT

#endif
#ifdef ARDUX_HAND_RIGHT
#define ARDUX_BIG_LAYER_BASE ARDUX_BIG_LAYER_BASE_RIGHT
#define ARDUX_BIG_LAYER_NUM ARDUX_BIG_LAYER_NUM_RIGHT
#define ARDUX_BIG_LAYER_SYM ARDUX_BIG_LAYER_SYM_RIGHT
#define ARDUX_BIG_LAYER_PAR ARDUX_BIG_LAYER_PAR_RIGHT
#define ARDUX_BIG_LAYER_NAV ARDUX_BIG_LAYER_NAV_RIGHT
#define ARDUX_BIG_LAYER_CUS ARDUX_BIG_LAYER_CUS_RIGHT
#define ARDUX_BIG_LAYER_MSE ARDUX_BIG_LAYER_MSE_RIGHT
#define ARDUX_BIG_LAYER_BIG_SYM ARDUX_BIG_LAYER_BIG_SYM_RIGHT
#define ARDUX_BIG_LAYER_BIG_FUN ARDUX_BIG_LAYER_BIG_FUN_RIGHT
#endif
#endif
