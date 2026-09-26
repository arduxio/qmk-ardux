// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0
#pragma once

/*
 *        Left Hand                          Right Hand
 *  ,-------------------.              ,-------------------.
 *  | T4 | T3 | T2 | T1 |   Top row    | T1 | T2 | T3 | T4 |
 *  |----+----+----+----|              |----+----+----+----|
 *  | B4 | B3 | B2 | B1 |  Bottom row  | B1 | B2 | B3 | B4 | 
 *  `-------------------'              `-------------------'
 */

// Base layer for standard Ardux
#ifndef KEY_T1
#define KEY_T1 LT(LAYER_ID_PARENTHETICALS, KC_A)
#endif
#ifndef KEY_T2
#define KEY_T2 KC_R
#endif
#ifndef KEY_T3
#define KEY_T3 KC_T
#endif
#ifndef KEY_T4
#define KEY_T4 LT(LAYER_ID_NUMBERS, KC_S)
#endif
#ifndef KEY_B1
#define KEY_B1 LT(LAYER_ID_SYMBOLS, KC_E)
#endif
#ifndef KEY_B2
#define KEY_B2 KC_Y
#endif
#ifndef KEY_B3
#define KEY_B3 KC_I
#endif
#ifndef KEY_B4
#define KEY_B4 LT(LAYER_ID_CUSTOM, KC_O)
#endif

// Number layer
#ifndef KNUM_T1
#define KNUM_T1 KC_1
#endif
#ifndef KNUM_T2
#define KNUM_T2 KC_2
#endif
#ifndef KNUM_T3
#define KNUM_T3 KC_3
#endif
#ifndef KNUM_T4
#define KNUM_T4 KC_TRNS
#endif
#ifndef KNUM_B1
#define KNUM_B1 KC_4
#endif
#ifndef KNUM_B2
#define KNUM_B2 KC_5
#endif
#ifndef KNUM_B3
#define KNUM_B3 KC_6
#endif
#ifndef KNUM_B4
#define KNUM_B4 KC_NO
#endif

// Navigation layer
#ifndef KNAV_T2
#define KNAV_T2 KC_UP
#endif
#ifndef KNAV_T4
#define KNAV_T4 KC_PGUP
#endif
#ifndef KNAV_B2
#define KNAV_B2 KC_DOWN
#endif
#ifndef KNAV_B4
#define KNAV_B4 KC_PGDN
#endif

#ifdef ARDUX_HAND_LEFT
#ifndef KNAV_T1
#define KNAV_T1 KC_END
#endif
#ifndef KNAV_T3
#define KNAV_T3 KC_HOME
#endif
#ifndef KNAV_B1
#define KNAV_B1 KC_RIGHT
#endif
#ifndef KNAV_B3
#define KNAV_B3 KC_LEFT
#endif
#endif
#ifdef ARDUX_HAND_RIGHT
#ifndef KNAV_T1
#define KNAV_T1 KC_HOME
#endif
#ifndef KNAV_T3
#define KNAV_T3 KC_END
#endif
#ifndef KNAV_B1
#define KNAV_B1 KC_LEFT
#endif
#ifndef KNAV_B3
#define KNAV_B3 KC_RIGHT
#endif
#endif

// Mouse layer
#ifndef KMSE_T1
#define KMSE_T1 KC_BTN1
#endif
#ifndef KMSE_T2
#define KMSE_T2 KC_MS_U
#endif
#ifndef KMSE_T3
#define KMSE_T3 KC_BTN2
#endif
#ifndef KMSE_T4
#define KMSE_T4 KC_WH_U
#endif
#ifndef KMSE_B2
#define KMSE_B2 KC_MS_D
#endif
#ifndef KMSE_B4
#define KMSE_B4 KC_WH_D
#endif

#ifdef ARDUX_HAND_LEFT
#ifndef KMSE_B1
#define KMSE_B1 KC_MS_R
#endif
#ifndef KMSE_B3
#define KMSE_B3 KC_MS_L
#endif
#endif
#ifdef ARDUX_HAND_RIGHT
#ifndef KMSE_B1
#define KMSE_B1 KC_MS_L
#endif
#ifndef KMSE_B3
#define KMSE_B3 KC_MS_R
#endif
#endif

#ifdef ARDUX_SIZE_40P // 40% ardux (off by default)

#ifndef ARDUX_40P_LAYER_ANSI
// ANSI Five column support
#ifdef ARDUX_FIVE_COLUMN
#ifndef LEFT_ANSI_SIX_ONE
#define LEFT_ANSI_SIX_ONE
#endif
#ifndef LEFT_ANSI_SIX_TWO
#define LEFT_ANSI_SIX_TWO
#endif
#ifndef LEFT_ANSI_SIX_THREE
#define LEFT_ANSI_SIX_THREE
#endif
#ifndef RIGHT_ANSI_SIX_ONE
#define RIGHT_ANSI_SIX_ONE
#endif
#ifndef RIGHT_ANSI_SIX_TWO
#define RIGHT_ANSI_SIX_TWO
#endif
#ifndef RIGHT_ANSI_SIX_THREE
#define RIGHT_ANSI_SIX_THREE
#endif
#else
#ifndef LEFT_ANSI_SIX_ONE
#define LEFT_ANSI_SIX_ONE KC_GESC,
#endif
#ifndef LEFT_ANSI_SIX_TWO
#define LEFT_ANSI_SIX_TWO KC_TAB,
#endif
#ifndef LEFT_ANSI_SIX_THREE
#define LEFT_ANSI_SIX_THREE KC_LCTL,
#endif
#ifndef RIGHT_ANSI_SIX_ONE
#define RIGHT_ANSI_SIX_ONE KC_BSPC,
#endif
#ifndef RIGHT_ANSI_SIX_TWO
#define RIGHT_ANSI_SIX_TWO KC_ENT,
#endif
#ifndef RIGHT_ANSI_SIX_THREE
#define RIGHT_ANSI_SIX_THREE MT(MOD_RSFT, KC_QUOT),
#endif
#endif // ARDUX_FIVE_COLUMN

// ANSI Thumb row (handedness changes layout)
#ifdef ARDUX_HAND_LEFT
#ifndef LEFT_NUMBERS
#define LEFT_NUMBERS LT(LAYER_ID_NUMBERS, KC_Q)
#endif
#ifndef LEFT_PARENTHETICALS
#define LEFT_PARENTHETICALS LT(LAYER_ID_PARENTHETICALS, KC_R)
#endif
#ifndef LEFT_CUSTOM
#define LEFT_CUSTOM LT(LAYER_ID_CUSTOM, KC_A)
#endif
#ifndef LEFT_SYMBOLS
#define LEFT_SYMBOLS LT(LAYER_ID_SYMBOLS, KC_F)
#endif
#else
#ifndef LEFT_NUMBERS
#define LEFT_NUMBERS KC_Q
#endif
#ifndef LEFT_PARENTHETICALS
#define LEFT_PARENTHETICALS KC_R
#endif
#ifndef LEFT_CUSTOM
#define LEFT_CUSTOM KC_A
#endif
#ifndef LEFT_SYMBOLS
#define LEFT_SYMBOLS KC_F
#endif
#endif // ARDUX_HAND_LEFT
#ifdef ARDUX_HAND_RIGHT
#ifndef RIGHT_NUMBERS
#define RIGHT_NUMBERS LT(LAYER_ID_NUMBERS, KC_P)
#endif
#ifndef RIGHT_PARENTHETICALS
#define RIGHT_PARENTHETICALS LT(LAYER_ID_PARENTHETICALS, KC_U)
#endif
#ifndef RIGHT_CUSTOM
#define RIGHT_CUSTOM LT(LAYER_ID_CUSTOM, KC_SCLN)
#endif
#ifndef RIGHT_SYMBOLS
#define RIGHT_SYMBOLS LT(LAYER_ID_SYMBOLS, KC_J)
#endif
#else
#ifndef RIGHT_NUMBERS
#define RIGHT_NUMBERS KC_P
#endif
#ifndef RIGHT_PARENTHETICALS
#define RIGHT_PARENTHETICALS KC_U
#endif
#ifndef RIGHT_CUSTOM
#define RIGHT_CUSTOM KC_SCLN
#endif
#ifndef RIGHT_SYMBOLS
#define RIGHT_SYMBOLS KC_J
#endif
#endif // ARDUX_HAND_RIGHT

#ifdef ARDUX_HAND_LEFT
#ifdef ARDUX_TWO_THUMB
#ifndef BOTTOM_ROW_40P_ANSI
#define BOTTOM_ROW_40P_ANSI MO(LAYER_ID_BIG_SYM), KC_SPACE, LT(LAYER_ID_40P_NAVIGATION, KC_SPACE), LT(LAYER_ID_40P_FUNCTION, KC_MINUS)
#endif
#else
#ifndef BOTTOM_ROW_40P_ANSI
#define BOTTOM_ROW_40P_ANSI MO(LAYER_ID_BIG_SYM), KC_LGUI, KC_SPACE, F0P_THUMB_MID_NONES LT(LAYER_ID_40P_NAVIGATION, KC_SPACE), LT(LAYER_ID_40P_FUNCTION, KC_MINUS), TD(TD_AT_EQUAL)
#endif
#endif // ARDUX_TWO_THUMB
#endif // ARDUX_HAND_LEFT

#ifdef ARDUX_HAND_RIGHT
#ifdef ARDUX_TWO_THUMB
#ifndef BOTTOM_ROW_40P_ANSI
#define BOTTOM_ROW_40P_ANSI LT(LAYER_ID_40P_FUNCTION, KC_MINUS), LT(LAYER_ID_40P_NAVIGATION, KC_SPACE), KC_SPACE, MO(LAYER_ID_BIG_SYM)
#endif
#else
#ifndef BOTTOM_ROW_40P_ANSI
#define BOTTOM_ROW_40P_ANSI TD(TD_AT_EQUAL), LT(LAYER_ID_40P_FUNCTION, KC_MINUS), LT(LAYER_ID_40P_NAVIGATION, KC_SPACE), KC_SPACE, KC_LGUI, MO(LAYER_ID_BIG_SYM)
#endif
#endif  //ARDUX_TWO_THUMB
#endif // ARDUX_HAND_RIGHT

#endif // ARDUX_40P_LAYER_ANSI

#endif // ARDUX_SIZE_40P