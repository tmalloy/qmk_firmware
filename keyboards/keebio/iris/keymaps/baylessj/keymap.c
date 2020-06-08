#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _FUNC 1
#define _NUMPAD 2

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
//   LAYER_FUNC,
//   LAYER_NUMPAD,
// };

enum custom_keycodes {
   PLACEHOLDER = SAFE_RANGE,
   M_BRACKET_IN_ANG,
   M_BRACKET_OUT_ANG,
   M_ARROW_LEQL,
   M_ARROW_REQL,
   M_ARROW_RMINUS,
   M_ARROW_LMINUS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
  //└────────┴────────┴────────┴────────┴────────┴────────┴                          ├────────┼────────┼────────┼────────┼────────┴────────┘
                       KC_LSFT, KC_SPC,  KC_BSPC, MO(2),                              KC_LGUI, KC_TAB,  KC_ENT,  KC_RALT
                   // └────────┴────────┴────────┘────────┘                          └────────┴────────┴────────┴────────┘
  ),

  [_FUNC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   M_ARROW_REQL,                  M_ARROW_LEQL, KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   M_ARROW_RMINUS,              M_ARROW_LMINUS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO,   M_BRACKET_IN_ANG,         M_BRACKET_OUT_ANG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F12,
  //└────────┴────────┴────────┴────────┴────────┴────────┴                          ├────────┼────────┼────────┼────────┼────────┴────────┘
                       KC_NO,   KC_NO,   KC_NO,   KC_DEL,                             KC_NO,   KC_NO,   KC_NO,   KC_NO
                   // └────────┴────────┴────────┘────────┘                          └────────┴────────┴────────┴────────┘
  ),

  [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_NO,   KC_NO,   KC_MS_U, KC_NO,   KC_NO,                              KC_NO,   KC_7,    KC_8,    KC_9,    KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,                              KC_NO,   KC_4,    KC_5,    KC_6,    KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_NO,   KC_BTN2, KC_BTN3, KC_BTN1, KC_NO,                              KC_NO,   KC_1,    KC_2,    KC_3,    KC_NO,   KC_F12,
  //└────────┴────────┴────────┴────────┴────────┴────────┴                          ├────────┼────────┼────────┼────────┼────────┴────────┘
                       KC_NO,   KC_NO,   KC_NO,   KC_DEL,                             KC_NO,   KC_NO,   KC_0,   KC_NO
                   // └────────┴────────┴────────┘────────┘                          └────────┴────────┴────────┴────────┘
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
  switch (keycode) {
   //  case QWERTY:
   //    if (record->event.pressed) {
   //      set_single_persistent_default_layer(_QWERTY);
   //    }
   //    return false;
   //    break;
   //  case LAYER_FUNC:
   //    if (record->event.pressed) {
   //      layer_on(_FUNC);
   //      //update_tri_layer(_FUNC, _, _ADJUST);
   //    } else {
   //      layer_off(_FUNC);
   //      //update_tri_layer(_LOWER, _RAISE, _ADJUST);
   //    }
   //    return false;
   //    break;
   //  case RAISE:
   //    if (record->event.pressed) {
   //      layer_on(_NUMPAD);
   //      //update_tri_layer(_LOWER, _RAISE, _ADJUST);
   //    } else {
   //      layer_off(_NUMPAD);
   //      //update_tri_layer(_LOWER, _RAISE, _ADJUST);
   //    }
   //    return false;
   //    break;
    // MACROS
    case M_BRACKET_IN_ANG:  /* <> */                                            
      if (record->event.pressed) {                                              
        SEND_STRING("<>" SS_TAP(X_LEFT));                                       
        return false;                                                           
      }                                                                         
      break; 
   case M_BRACKET_OUT_ANG:  /* >< */                                           
      if (record->event.pressed) {                                              
        SEND_STRING("><" SS_TAP(X_LEFT));                                       
        return false;                                                           
      }                                                                         
      break;                                                                    
   case M_ARROW_LMINUS:  /* <- */                                              
      if (record->event.pressed) {                                              
        SEND_STRING("<-");                                                      
        return false;                                                           
      }                                                                         
      break;                                                                    
   case M_ARROW_RMINUS:  /* -> */                                              
      if (record->event.pressed) {                                              
        SEND_STRING("->");                                                      
        return false;                                                           
      }                                                                         
      break;                                                                    
    case M_ARROW_LEQL:  /* <= */                                                
      if (record->event.pressed) {                                              
        SEND_STRING("<=");                                                      
        return false;                                                           
      }                                                                         
     break;                                                                    
   case M_ARROW_REQL:  /* => */                                                
      if (record->event.pressed) {                                              
        SEND_STRING("=>");                                                      
        return false;                                                           
      }                                                                         
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
