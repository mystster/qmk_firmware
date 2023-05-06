// Copyright 2022 Yoichiro Tanaka (@yoichiro)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "process_key_override.h"
#include <quantum\keymap_extras\keymap_japanese.h>

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define MT_TAB LALT_T(KC_TAB)
#define MT_ENT LCTL_T(KC_ENT)
#define MT_SPC RCTL_T(KC_SPC)
#define MT_MHEN LSFT_T(JP_MHEN)
#define MT_HENK LSFT_T(JP_HENK)

const key_override_t quot_dquot_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, JP_DQUO);
const key_override_t bsls_unds_override =
    ko_make_basic(MOD_MASK_SHIFT, JP_BSLS, JP_UNDS);
const key_override_t scln_coln_override =
    ko_make_basic(MOD_MASK_SHIFT, JP_SCLN, JP_COLN);
const key_override_t bspc_del_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, JP_EQL);
const key_override_t kcquot_jpquot_override = ko_make_with_layers_and_negmods(
    0, KC_QUOT, JP_QUOT, ~0, (uint8_t)MOD_MASK_SHIFT);

const key_override_t **key_overrides =
    (const key_override_t *[]){&quot_dquot_override, &bsls_unds_override,
                               &scln_coln_override, &bspc_del_override, &kcquot_jpquot_override, NULL};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x6_4(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   QK_GESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   MT_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    JP_SCLN,  KC_QUOT,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    JP_COMM, JP_DOT,  JP_SLSH, JP_BSLS ,
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
                              KC_LGUI, MT_MHEN, LOWER,   MT_ENT,  MT_SPC,  RAISE,   MT_HENK, KC_RALT
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
  ),

  [_LOWER] = LAYOUT_split_3x6_4(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+-  -------+--------+--------+--------+
   JP_TILD, JP_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC,                   JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, KC_BSPC,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   LALT_T(KC_LSFT), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   RALT_T(KC_RSFT),
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
                              _______, _______, _______, _______, _______, _______,  _______, _______
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
  ),

  [_RAISE] = LAYOUT_split_3x6_4(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   JP_TILD, JP_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC,                   JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, KC_BSPC,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, JP_MINS, JP_PLUS, JP_EQL, JP_LCBR, JP_RCBR,                   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, JP_PIPE,  JP_GRV,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, _______, _______, _______, JP_LBRC, JP_RBRC,                   KC_PGUP, KC_HOME, KC_END,  KC_PGDN, _______, _______,
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
                              _______, _______, _______, _______, _______, _______,  _______, _______
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
  ),

  [_ADJUST] = LAYOUT_split_3x6_4(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   QK_BOOT, _______, _______, _______, _______, _______,                   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, _______, _______, _______, _______, _______,                   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
   _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
                              _______, _______, _______, _______, _______, _______,  _______, _______
//+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
