#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FN
};

/*

 * LEFT HALF
 * R0: SW93  SW94  SW95  SW96  SW97  SW98  SW99  SW100  -
 * R1: SW101 SW102 SW103 SW104 SW105 SW106 SW107 SW108  -
 * R2: SW109 SW110 SW111 SW112 SW113 SW114 SW115 -      -
 * R3: SW116 SW117 SW118 SW119 SW120 SW121 SW122 -      -
 * R4: SW123 SW124 SW125 SW126 SW127 SW128 SW129 -      -
 * R5: SW130 SW131 SW132 SW133 SW134 -     -     -      -
 *
 * RIGHT HALF
 * R0: SW43 SW44 SW45 SW46 SW47 SW48 SW49 SW50 SW51
 * R1: -    SW52 SW53 SW54 SW55 SW56 SW57 SW58 SW59
 * R2: SW60 SW61 SW62 SW63 SW64 SW65 SW66 SW67 SW68
 * R3: -    SW69 SW70 SW71 SW72 SW73 SW74 SW75 SW76
 * R4: -    SW77 SW78 SW79 SW80 SW81 SW82 SW83 SW84
 * R5: -    SW85 SW86 SW87 SW88 SW89 SW90 SW91 SW92
 *
 * SW93 = left encoder push
 * SW51 = right encoder push
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = {

        /*
         * LEFT HALF
         *
         *        Enc   Esc    F1     F2     F3     F4     F5     F6
         *        F13   `      1      2      3      4      5      6
         *        F14   Tab    Q      W      E      R      T
         *        F15   Caps   A      S      D      F      G
         *        F16   Shift  Z      X      C      V      B
         *        F17   Ctrl   GUI    Alt    Space
         */

        { KC_MUTE, KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NO },

        { KC_F13,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_NO },

        { KC_F14,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,   KC_NO },

        { KC_F15,  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_NO,   KC_NO },

        { KC_F16,  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_NO },

        { KC_F17,  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO },


        /*
         * RIGHT HALF
         *
         *        F7     F8     F9     F10    F11    F12    Ins    Del    Enc
         *               7      8      9      0      -      =      Bspc   PgUp
         *        Y      U      I      O      P      [      ]      \      PgDn
         *               H      J      K      L      ;      '      Enter  Home
         *               N      M      ,      .      /      RShift Up     End
         *               Space  RAlt   RGUI   Fn     RCtrl  Left   Down   Right
         */

        { KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,  KC_MUTE },

        { KC_NO,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_PGUP },

        { KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN },

        { KC_NO,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME },

        { KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END },

        { KC_NO,   KC_SPC,  KC_RALT, KC_RGUI, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT }
    },



    [_FN] = {

        { _______, QK_BOOT, _______, _______, _______, _______, _______, _______, KC_NO },

        { _______, _______, _______, _______, _______, _______, _______, _______, KC_NO },

        { _______, _______, _______, _______, _______, _______, _______, KC_NO,   KC_NO },

        { _______, _______, _______, _______, _______, _______, _______, KC_NO,   KC_NO },

        { _______, _______, _______, _______, _______, _______, _______, KC_NO,   KC_NO },

        { _______, _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO,   KC_NO },


        { _______, _______, _______, _______, _______, _______, _______, _______, _______ },

        { KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______ },

        { _______, _______, _______, _______, _______, _______, _______, _______, _______ },

        { KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______ },

        { KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______ },

        { KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______ }
    }
};



bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise){
            tap_code(KC_PGDN);
        }else{
            tap_code(KC_PGUP);
        }
    } else {
        if (clockwise){
            tap_code(KC_VOLU);
        }else{
            tap_code(KC_VOLD);
        }
    } 
    return false;
}


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return rotation;
}

bool oled_task_user(void) {
    oled_write_ln_P(PSTR("KARVE"), false);

    if (is_keyboard_left()) {
        oled_write_ln_P(PSTR("LEFT"), false);
    } else {
        oled_write_ln_P(PSTR("RIGHT"), false);
    }

    if (is_keyboard_master()) {
        oled_write_ln_P(PSTR("MASTER"), false);
    } else {
        oled_write_ln_P(PSTR("SLAVE"), false);
    }

    oled_write_P(PSTR("LAYER "), false);
    oled_write_char('0' + get_highest_layer(layer_state), false);

    return false;
}

#endif
