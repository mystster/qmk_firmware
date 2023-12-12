// Copyright 2022 Yoichiro Tanaka (@yoichiro)
// SPDX-License-Identifier: GPL-2.0-or-later

// #include QMK_KEYBOARD_H
// #include ".build/obj_yoichiro_lunakey_pico/src/default_keyboard.h"
#include "quantum.h"
#include "process_key_override.h"
#include <quantum\keymap_extras\keymap_japanese.h>
#include <quantum\rgblight\rgblight.h>
#include <quantum\logging\debug.h>

#define LAYOUT_split_3x6_4( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                 L30, L31, L32, L33, R30, R31, R32, R33 \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { KC_NO, KC_NO, L30, L31, L32, L33 }, \
    { R05, R04, R03, R02, R01, R00 }, \
    { R15, R14, R13, R12, R11, R10 }, \
    { R25, R24, R23, R22, R21, R20 }, \
    { KC_NO, KC_NO, R33, R32, R31, R30 } \
  }

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define LOWER TT(_LOWER)
#define RAISE MO(_RAISE)

#define MT_TAB LSFT_T(KC_TAB)
#define MT_MHEN LALT_T(JP_MHEN)
#define MT_SPC LCTL_T(KC_SPC)
#define MT_ENT RSFT_T(KC_ENT)
#define MT_HENK RCTL_T(JP_HENK)

const key_override_t quot_dquot_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, JP_DQUO);
const key_override_t bsls_unds_override =
    ko_make_basic(MOD_MASK_SHIFT, JP_BSLS, JP_UNDS);
const key_override_t scln_coln_override =
    ko_make_basic(MOD_MASK_SHIFT, JP_SCLN, JP_COLN);
const key_override_t bspc_del_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t kcquot_jpquot_override = ko_make_with_layers_and_negmods(
    0, KC_QUOT, JP_QUOT, ~0, (uint8_t)MOD_MASK_SHIFT);

const key_override_t **key_overrides =
    (const key_override_t *[]){&quot_dquot_override, &bsls_unds_override,
                               &scln_coln_override, &bspc_del_override, &kcquot_jpquot_override, NULL};

const uint16_t PROGMEM combo_jk[] = {KC_J, KC_K, COMBO_END};
combo_t                key_combos[] = {
    COMBO(combo_jk, KC_BSPC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_split_3x6_4(
        //+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
        QK_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        //+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
        MT_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, JP_SCLN, KC_QUOT,
        //+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
        KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, JP_COMM, JP_DOT, JP_SLSH, JP_BSLS,
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
        KC_LGUI, MT_MHEN, MT_SPC, LOWER, RAISE, MT_ENT, MT_HENK, KC_RALT
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
        ),
    [_LOWER] = LAYOUT_split_3x6_4(
        //+--------+--------+--------+--------+--------+--------+                 +--------+--------+-  -------+--------+--------+--------+
        JP_TILD, JP_EXLM, JP_AT, JP_HASH, JP_DLR, JP_PERC, JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR, KC_BSPC,
        //+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
        MT_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, RALT_T(KC_RSFT),
        //+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
        _______, JP_MINS, JP_PLUS, JP_EQL, JP_ASTR, JP_SLSH, _______, _______, _______, _______, _______, JP_GRV,
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
        _______, _______, _______, _______, _______, _______, _______, _______
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
        ),

    [_RAISE] = LAYOUT_split_3x6_4(
        //+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
        JP_TILD, JP_EXLM, JP_AT, JP_HASH, JP_DLR, JP_PERC, JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR, KC_BSPC,
        //+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
        _______, JP_MINS, JP_PLUS, JP_EQL, JP_LCBR, JP_RCBR, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, JP_PIPE, JP_GRV,
        //+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
        _______, JP_GRV, JP_PIPE, _______, JP_LBRC, JP_RBRC, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, _______,
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
        _______, _______, LCTL(KC_SPC), _______, _______, _______, _______, _______
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
        ),

    [_ADJUST] = LAYOUT_split_3x6_4(
        //+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
        QK_GESC, AS_DOWN, AS_UP, AS_RPT, AS_ON, AS_OFF, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
        //+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
        _______, _______, _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        //+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
        QK_BOOT, RGB_TOG, AU_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
        _______, _______, _______, _______, _______, _______, _______, _______
        //+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
        )};

const rgblight_segment_t PROGMEM qwerty_layer[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_OFF});
const rgblight_segment_t PROGMEM lower_layer[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_BLUE});
const rgblight_segment_t PROGMEM raise_layer[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_YELLOW});
const rgblight_segment_t PROGMEM adjust_layer[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_RED});

const rgblight_segment_t *const PROGMEM my_rgb_layers[] =
    RGBLIGHT_LAYERS_LIST(qwerty_layer, lower_layer, raise_layer, adjust_layer);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
    rgblight_enable();
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);

    autoshift_disable();
}

void keyboard_post_init_kb(void) {
    debug_enable = true;
    debug_matrix = true;
    debug_keyboard = true;
    keyboard_post_init_user();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t updatedState =
        update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    rgblight_set_layer_state(0, layer_state_cmp(updatedState, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(updatedState, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(updatedState, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(updatedState, _ADJUST));
    return updatedState;
}

float lower_audio[][2] = SONG(Q__NOTE(_A4));
float raise_audio[][2] = SONG(Q__NOTE(_D5));
float adjust_audio[][2] = SONG(Q__NOTE(_A5));
float HENK_audio[][2] = SONG(CAPS_LOCK_ON_SOUND);
float MHEN_audio[][2] = SONG(SCROLL_LOCK_OFF_SOUND);

bool isCtrlPressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
    case LOWER:
        if(record->event.pressed) {
#ifdef AUDIO_ENABLE
            PLAY_SONG(lower_audio);
#endif
        }
        break;
    case RAISE:
        if(record->event.pressed) {
#ifdef AUDIO_ENABLE
            PLAY_SONG(raise_audio);
#endif
        }
        break;
    case MT_HENK:
        if(record->event.pressed) {
#ifdef AUDIO_ENABLE
            PLAY_SONG(HENK_audio);
#endif
        }
        break;
    case MT_MHEN:
        if(record->event.pressed) {
#ifdef AUDIO_ENABLE
            PLAY_SONG(MHEN_audio);
#endif
        }
        break;
    case MOD_LCTL:
    case KC_LCTL:
        if (record->event.pressed)
        {
            dprintf("ctrl pressed");
            isCtrlPressed = true;
        }else{
            dprintf("ctrl released");
            isCtrlPressed = false;
        }
        break;
    case KC_SPC:
        dprintf("Space press or release");
        if(isCtrlPressed) {
            if(record->event.pressed) {
                unregister_code16(KC_LCTL);
                wait_ms(10);
                register_code16(KC_LCTL);
                wait_ms(20);
                register_code16(KC_SPC);
            } else {
                unregister_code16(KC_SPC);
            }
            return false;
        }
        break;
    }
    return true;
}
