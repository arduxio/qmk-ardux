// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0
#pragma once

/////////////
// kb2040 qwiic & neopixel support
#ifdef CONVERT_TO_KB2040
#define SOFT_SERIAL_PIN D5
#ifdef ARDUX_LAYER_UNDERGLOW
#define RGB_DI_PIN 17
#ifdef ARDUX_SIZE_40P
#define RGBLIGHT_LED_COUNT 2
#define RGBLED_SPLIT { 1, 1 }
#else
#define RGBLIGHT_LED_COUNT 1
#endif
#endif
#endif

// /////////
// User remixes / tweaks -- these take precidence above all else
#if __has_include("../remixes/boards/crkbd_rev1.h")
#include "../remixes/boards/crkbd_rev1.h"

// //////////
// Standard Definitions
#else
#ifdef ARDUX_HAND_LEFT
#ifdef ARDUX_SIZE_40P
#define F0P_LEADING_NONES
#define F0P_ROW_ONE_MID_NONES
#define F0P_BETWEEN_ROW_ONE_TWO_NONES
#define F0P_ROW_TWO_MID_NONES
#define F0P_BETWEEN_ROW_TWO_THREE_NONES
#define F0P_ROW_THREE_MID_NONES
#define F0P_BETWEEN_ROW_THREE_THUMBS_NONES
#define F0P_THUMB_MID_NONES
#define F0P_TRAILING_NONES
#endif
#define BIG_LEADING_NONES KC_NO,
#define BIG_BETWEEN_ROW_ONE_TWO_NONES KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
#define BIG_BETWEEN_ROW_TWO_THREE_NONES KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
#define BIG_BETWEEN_ROW_THREE_THUMBS_NONES KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
#define BIG_TRAILING_NONES , KC_NO, KC_NO, KC_NO
#endif

#ifdef ARDUX_HAND_RIGHT
#ifdef ARDUX_SIZE_40P
#define F0P_LEADING_NONES
#define F0P_ROW_ONE_MID_NONES
#define F0P_BETWEEN_ROW_ONE_TWO_NONES
#define F0P_ROW_TWO_MID_NONES
#define F0P_BETWEEN_ROW_TWO_THREE_NONES
#define F0P_ROW_THREE_MID_NONES
#define F0P_BETWEEN_ROW_THREE_THUMBS_NONES
#define F0P_THUMB_MID_NONES
#define F0P_TRAILING_NONES
#endif
#define BIG_LEADING_NONES KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
#define BIG_BETWEEN_ROW_ONE_TWO_NONES KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
#define BIG_BETWEEN_ROW_TWO_THREE_NONES KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
#define BIG_BETWEEN_ROW_THREE_THUMBS_NONES KC_NO, KC_NO, KC_NO, KC_NO,
#define BIG_TRAILING_NONES
#endif

#endif
