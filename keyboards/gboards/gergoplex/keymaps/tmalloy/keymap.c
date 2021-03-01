/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 */

#include "gergoplex.h"
#include "g/keymap_combo.h"

enum {
    _ALPHA,   // default
    _SYMBOLS,
    _SPECIAL,
    _NUMBERS,
    _DVORAK
};

//enum custom_keycodes {
//  DVRK = SAFE_RANGE,
//  QWRT,
//};


#define KC_XXXXX   KC_NO

#define KC_QWRT     DF(_ALPHA)
#define KC_DVRK     DF(_DVORAK)

// qwerty
#define KC_L1_F     LT(_SYMBOLS, KC_F)
#define KC_L1_J     LT(_SYMBOLS, KC_J)
#define KC_L2_D     LT(_SPECIAL, KC_D)
#define KC_L2_K     LT(_SPECIAL, KC_K)
#define KC_L3_S     LT(_NUMBERS, KC_S)
#define KC_SFT_Z    MT(MOD_LSFT, KC_Z)
#define KC_SFT_SLSH MT(MOD_LSFT, KC_SLSH)

//dvorak
#define KC_L1_U     LT(_SYMBOLS, KC_U)
#define KC_L1_H     LT(_SYMBOLS, KC_H)
#define KC_L2_E     LT(_SPECIAL, KC_E)
#define KC_L2_T     LT(_SPECIAL, KC_T)
#define KC_L3_O     LT(_NUMBERS, KC_O)

#define KC_SFT_ESC  MT(MOD_LSFT, KC_ESC)
#define KC_CTL_TAB  MT(MOD_LCTL, KC_TAB)
#define KC_GUI_BSPC MT(MOD_LGUI, KC_BSPC)
#define KC_GUI_SPC  MT(MOD_LGUI, KC_SPC)
#define KC_ALT_ENT  MT(MOD_LALT, KC_ENT)
#define KC_SFT_GRV  MT(MOD_LSFT, KC_GRV)

#define KC_LBRKT    LSFT(KC_LBRC)        // {
#define KC_RBRKT    LSFT(KC_RBRC)        // }
#define KC_PIPE     LSFT(KC_BSLS)        // |
#define KC_ENE      LSFT(KC_GRV)         // ~
#define KC_QST      LSFT(KC_SLSH)        // ?
#define KC_DBQT     LSFT(KC_QUOT)        // "

//#define KC_L2      MO(_SPECIAL)
//#define KC_C_A_D   LCA(KC_DEL)          // Ctrl + Alt + Del

//#define KC_GUIL2   LT(_SPECIAL, KC_LGUI)

// TODO: add another layer entrypoint for CTRL+ALT+L1 to do multi-cursors in vscode?
#define KC_CMB_TOG CMB_TOG  // A hack to allow KC_-less keycode along with KC_-ful ones

// https://github.com/qmk/qmk_firmware/issues/4611
// tmk_core/common/action_layer.h: default_layer_set
//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  static uint16_t fnx_layer_timer;
//  static bool fnx_inverting;
//
//  if (keycode == KC_FNX) {
//    if(record->event.pressed){
//        fnx_layer_timer = timer_read();
//        fnx_inverting = true;
//        register_mods(MOD_BIT(KC_LSFT));
//
//      } else {
//        unregister_mods(MOD_BIT(KC_LSFT));
//
//        if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM && fnx_inverting)
//          layer_invert(NORMAL);
//    }
//    return false;
//  }
//
//  fnx_inverting = false;
//}

//bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//    case KC_ALT_Q:
//        return true;
//    case KC_ALT_P:
//        return true;
//    default:
//        return false;
//    }
//}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Alpha layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |   Q   |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |   P   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |   A   | L3_S| L2_D| L1_F|  G  |      |  H  | L1_J| L2_K|  L  |   ;   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * | SFT_Z |  X  |  C  |  V  |  B  |      |  N  |  M  |  ,  |  .  | SFT_/ |
     * `-------------------------------'      `-------------------------------'
     *      '--------------------------'      '-------------------------'
     *      | GRV | CTL_TAB | GUI_BSPC |      | GUI_SPC | ALT_ENT | ESC |
     *      '--------------------------'      '-------------------------'
     */
    [_ALPHA] = LAYOUT_kc(
    // ,-------------------------------.      ,-------------------------------.
           Q   ,  W  ,  E  ,  R  ,  T  ,         Y  ,  U  ,  I  ,  O  ,   P   ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
           A   , L3_S, L2_D, L1_F,  G  ,         H  , L1_J, L2_K,  L  ,  SCLN ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         SFT_Z ,  X  ,  C  ,  V  ,  B  ,         N  ,  M  ,COMMA, DOT ,SFT_SLSH,
    // '-------------------------------'      '-------------------------------'
    //      .--------------------------.      .--------------------------.
              GRV , CTL_TAB , GUI_BSPC ,        GUI_SPC , ALT_ENT , ESC ),
    //      '--------------------------'      '--------------------------'



    // ~ ?
    /* Keymap 1: Special characters layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |   !   |  @  |  #  |  $  |  %  |      |  ^  |  &  |  *  |  (  |   )   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |   '   |  "  |  _  |  ~  |  `  |      |     |  {  |  }  |  [  |   ]   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |   \   |  |  |     |     |     |      |     |     |     |  ?  |   /   |
     * `-------------------------------'      `-------------------------------'
     *      '--------------------------'      '-------------------------'
     *      | GRV | CTL_TAB | GUI_BSPC |      | GUI_SPC | ALT_ENT | ESC |
     *      '--------------------------'      '-------------------------'
     */
    //! @ # $ % ^ & * ( ) [ ] { } - _ = + \ | ` ~ ' "
    // \ | _ ~
    [_SYMBOLS] = LAYOUT_kc(
    // ,-------------------------------.      ,-------------------------------.
         EXLM  , AT  , HASH, DLR , PERC,       CIRC , AMPR, ASTR, LPRN, RPRN  ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         QUOT  , DBQT, UNDS, ENE , GRV ,       MINS ,LBRKT,RBRKT, LBRC, RBRC  ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         BSLS  , PIPE,XXXXX,XXXXX,XXXXX,       XXXXX,XXXXX,XXXXX, QST ,  SLSH ,
    // '-------------------------------'      '-------------------------------'
    //      .--------------------------.      .--------------------------.
              GRV , CTL_TAB , GUI_BSPC ,        GUI_SPC , ALT_ENT , ESC ),
    //      '--------------------------'      '--------------------------'

    // ~ ?
    /* Keymap 1: Special characters layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |       |     |     |     |     |      |  +  |  7  |  8  |  9  |   =
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |       |     |     |     |     |      |  -  |  4  |  5  |  6  |   *   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |       |     |     |     |     |      |  0  |  1  |  2  |  3  |   .   |
     * `-------------------------------'      `-------------------------------'
     *      '--------------------------'      '-------------------------'
     *      | GRV | CTL_TAB | GUI_BSPC |      | GUI_SPC | ALT_ENT | ESC |
     *      '--------------------------'      '-------------------------'
     */
    //! @ # $ % ^ & * ( ) [ ] { } - _ = + \ | ` ~ ' "
    [_NUMBERS] = LAYOUT_kc(
    // ,-------------------------------.      ,-------------------------------.
         XXXXX ,XXXXX,XXXXX,XXXXX,XXXXX,       PLUS ,  7  ,  8  ,  9  ,  EQL ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         XXXXX ,XXXXX,XXXXX,XXXXX,XXXXX,       MINS ,  4  ,  5  ,  6  , ASTR  ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         XXXXX ,XXXXX,XXXXX,XXXXX,XXXXX,         0  ,  1  ,  2  ,  3  ,  DOT  ,
    // '-------------------------------'      '-------------------------------'
    //      .--------------------------.      .--------------------------.
              GRV , CTL_TAB , GUI_BSPC ,        GUI_SPC , ALT_ENT , ESC ),
    //      '--------------------------'      '--------------------------'

    /* Keymap 2: Numbers/Function/Motion layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |       | mute|vol_u|vol_d|     |      |     |     |     |     |       |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |       | last| play| next|     |      | left| down|  up |right|       |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |       |     |     |     |     |      |     |     |     |     |       |
     * `-------------------------------'      `-------------------------------'
     *      '--------------------------'      '-------------------------'
     *      | GRV | CTL_TAB | GUI_BSPC |      | GUI_SPC | ALT_ENT | ESC |
     *      '--------------------------'      '-------------------------'
     */
    [_SPECIAL] = LAYOUT_kc(
    // ,-------------------------------.      ,-------------------------------.
          QWRT , MUTE, VOLD, VOLU,XXXXX,       XXXXX,XXXXX,XXXXX,XXXXX, XXXXX ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
          DVRK , MPRV, MPLY, MNXT,XXXXX,        LEFT, DOWN,  UP ,RIGHT, XXXXX ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         XXXXX ,XXXXX,XXXXX,XXXXX,XXXXX,       XXXXX,XXXXX,XXXXX,XXXXX, XXXXX ,
    // '-------------------------------'      '-------------------------------'
    //      .--------------------------.      .--------------------------.
              GRV , CTL_TAB , GUI_BSPC ,        GUI_SPC , ALT_ENT , ESC ),
    //      '--------------------------'      '--------------------------'


   /* Keymap 3: Dvorak
    *
    * ,-------------------------------.      ,-------------------------------.
    * |   '   |  ,  |  .  |  p  |  y  |      |  f  |  g  |  c  |  r  |   l   |
    * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
    * |   a   |  o  |  e  |  u  |  i  |      |  d  |  h  |  t  | n   |   s   |
    * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
    * |   ;   |  q  |  j  |  k  |  x  |      |  b  |  m  |  w  |  v  |   z   |
    * `-------------------------------'      `-------------------------------'
    *      '--------------------------'      '-------------------------'
    *      | GRV | CTL_TAB | GUI_BSPC |      | GUI_SPC | ALT_ENT | ESC |
    *      '--------------------------'      '-------------------------'
    */
   [_DVORAK] = LAYOUT_kc(
   // ,-------------------------------.      ,-------------------------------.
         QUOT,COMMA, DOT ,  P  ,  Y  ,         F  ,  G  ,  C  ,  R  ,   L ,
   // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
           A  , L3_O, L2_E, L1_U,  I  ,         D  , L1_H, L2_T,  N  ,   S   ,
   // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         SCLN, Q  ,  J  ,  K  ,  X  ,         B  ,  M  ,  W  ,  V  ,    Z ,
   // '-------------------------------'      '-------------------------------'
   //      .--------------------------.      .--------------------------.
             GRV , CTL_TAB , GUI_BSPC ,        GUI_SPC , ALT_ENT , ESC ),
   //      '--------------------------'      '--------------------------'
};
