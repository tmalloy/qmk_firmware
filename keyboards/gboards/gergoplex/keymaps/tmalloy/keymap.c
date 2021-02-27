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
    /* _OVERFLOW, // numbers/function/motion */
    /* _SPECIAL,  // special characters, media keys, etc. */
    /* _DVORAK */
};

//enum custom_keycodes {
//  DVRK = SAFE_RANGE,
//  QWRT,
//};


#define KC_XXXXX   KC_NO
#define KC_ALT_Q   MT(MOD_LALT, KC_Q)
#define KC_ALT_P   MT(MOD_RALT, KC_P)

#define KC_QWRT     DF(_ALPHA)
//#define KC_DVRK     DF(_DVORAK)

#define KC_L1_F     LT(_SYMBOLS, KC_F)
#define KC_L1_J     LT(_SYMBOLS, KC_J)
#define KC_L2_D     LT(_SPECIAL, KC_D)
#define KC_L2_K     LT(_SPECIAL, KC_K)
#define KC_L3_S     LT(_NUMBERS, KC_S)
//#define KC_L2_DVRK  LT(_SPECIAL, KC_DVRK)
//#define KC_L2_QWRT  LT(_SPECIAL, KC_QWRT)
////#define KC_CTL_A    MT(MOD_LCTL, KC_A)
//#define KC_CTL_CL   MT(MOD_LCTL, KC_SCLN)
#define KC_SFT_Z    MT(MOD_LSFT, KC_Z)
#define KC_SFT_SLSH MT(MOD_RSFT, KC_SLSH)
#define KC_LGUI_ENT MT(MOD_LGUI, KC_ENT)
#define KC_CTRL_TAB MT(MOD_LCTL, KC_TAB)

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Alpha layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * | ALT_Q |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  | ALT_P |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * | CTL_A | L3_S| L2_D| L1_F|  G  |      |  H  | L1_J| L2_K|  L  | CTRL_;|
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * | SFT_Z |  X  |  C  |  V  |  B  |      |  N  |  M  |  ,  |  .  | SFT_/ |
     * `-------------------------------'      `-------------------------------'
     *               '-----------------'      '---------------------'
     *               |TAB|CMD_ENT|BSPS |      | SPC | CTRL_TAB|  `  |
     *               '-----------------'      '---------------------'
     */
    [_ALPHA] = LAYOUT_kc(
    // ,-------------------------------.      ,-------------------------------.
         ALT_Q ,  W  ,  E  ,  R  ,  T  ,         Y  ,  U  ,  I  ,  O  , ALT_P ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
           A   , L3_S, L2_D, L1_F,  G  ,         H  , L1_J, L2_K,  L  , SCLN  ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         SFT_Z ,  X  ,  C  ,  V  ,  B  ,         N  ,  M  ,COMMA, DOT ,SFT_SLSH,
    // '-------------------------------'      '-------------------------------'
    //           .---------------------.      .-----------------------.
                   TAB, LGUI_ENT, BSPC ,         SPC , CTRL_TAB , GRV),
    //           '---------------------'      '-----------------------'



    // ~ ?
    /* Keymap 1: Special characters layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |   !   |  @  |  #  |  $  |  %  |      |  ^  |  &  |  *  |  (  |   )   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |   '   |  "  |  _  |  ~  |  `  |      |     |  {  |  }  |  [  |   ]   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |   \   |  |  |     |     |     |      |     |     |     |     |   ?   |
     * `-------------------------------'      `-------------------------------'
     *               .-----------------.      .---------------------.
     *               |TAB|CMD_ENT|BSPS |      | SPC |CTRL_TAB|  `  |
     *               '-----------------'      '---------------------'
     */
    //! @ # $ % ^ & * ( ) [ ] { } - _ = + \ | ` ~ ' "
    // \ | _ ~
    [_SYMBOLS] = LAYOUT_kc(
    // ,-------------------------------.      ,-------------------------------.
         EXLM  , AT  , HASH, DLR , PERC,       CIRC , AMPR, ASTR, LPRN, RPRN  ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         QUOT  , DBQT, UNDS, ENE , GRV ,       MINS ,LBRKT,RBRKT, LBRC, RBRC  ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         BSLS  , PIPE,XXXXX,XXXXX,XXXXX,       XXXXX,XXXXX,XXXXX,XXXXX,  QST  ,
    // '-------------------------------'      '-------------------------------'
    //           .---------------------.      .-----------------------.
                    TAB, LGUI_ENT, BSPC ,         SPC , CTRL_TAB , GRV),
    //           '---------------------'      '-----------------------'

    // ~ ?
    /* Keymap 1: Special characters layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |       |     |     |     |     |      |  +  |  7  |  8  |  9  |   =
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |       |     |     |     |     |      |  -  |  4  |  5  |  6  |   *   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |       |     |     |     |     |      |  0  |  1  |  2  |  3  |   /   |
     * `-------------------------------'      `-------------------------------'
     *               .-----------------.      .----------------------.
     *               |TAB|CMD_ENT|BSPS |      | SPC | CTRL_TAB |  `  |
     *               '-----------------'      '----------------------'
     */
    //! @ # $ % ^ & * ( ) [ ] { } - _ = + \ | ` ~ ' "
    [_NUMBERS] = LAYOUT_kc(
    // ,-------------------------------.      ,-------------------------------.
         XXXXX ,XXXXX,XXXXX,XXXXX,XXXXX,       PLUS ,  7  ,  8  ,  9  ,  EQL ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         XXXXX ,XXXXX,XXXXX,XXXXX,XXXXX,       MINS ,  4  ,  5  ,  6  , ASTR  ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         XXXXX ,XXXXX,XXXXX,XXXXX,XXXXX,         0  ,  1  ,  2  ,  3  , SLSH  ,
    // '-------------------------------'      '-------------------------------'
    //           .---------------------.      .-----------------------.
                    TAB, LGUI_ENT, BSPC ,         SPC , CTRL_TAB , GRV),
    //           '---------------------'      '-----------------------'

    /* Keymap 2: Numbers/Function/Motion layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |       | mute|vol_u|vol_d|     |      |     |     |     |     |       |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |       | last| play| next|     |      | left| down|  up |right|       |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |       |     |     |     |     |      |     |     |     |     |       |
     * `-------------------------------'      `-------------------------------'
     *               '-----------------'      '---------------------'
     *               |TAB|CMD_ENT|BSPS |      | SPC | CTRL_TAB|  `  |
     *               '-----------------'      '---------------------'
     */
    [_SPECIAL] = LAYOUT_kc(
    // ,-------------------------------.      ,-------------------------------.
         XXXXX , MUTE, VOLD, VOLU,XXXXX,       XXXXX,XXXXX,XXXXX,XXXXX, XXXXX ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         XXXXX , MPRV, MPLY, MNXT,XXXXX,        LEFT, DOWN,  UP ,RIGHT, XXXXX ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         XXXXX ,XXXXX,XXXXX,XXXXX,XXXXX,       XXXXX,XXXXX,XXXXX,XXXXX, XXXXX ,
    // '-------------------------------'      '-------------------------------'
    //           .---------------------.      .-----------------------.
                    TAB, LGUI_ENT, BSPC ,         SPC , CTRL_TAB , GRV),
    //           '---------------------'      '-----------------------'


//    // ~ ?
//    /* Keymap 1: Special characters layer
//     *
//     * ,-------------------------------.      ,-------------------------------.
//     * |   !   |  @  |  #  |  $  |  %  |      |  +  |  7  |  8  |  9  |   *
//     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
//     * |   ^   |  &  |  [  |  (  |  {  |      |  -  |  4  |  5  |  6  |   "   |
//     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
//     * |   \   |  |  |  ]  |  )  |  }  |      |  =  |  1  |  2  |  3  |   '   |
//     * `-------------------------------'      `-------------------------------'
//     *               .-----------------.      .-----------------.
//     *               |     |     |  ~  |      |  _  |  0  |     |
//     *               '-----------------'      '-----------------'
//     */
//    //! @ # $ % ^ & * ( ) [ ] { } - _ = + \ | ` ~ ' "
//    [_OVERFLOW] = LAYOUT_kc(
//    // ,-------------------------------.      ,-------------------------------.
//         EXLM  , AT  , HASH, DLR , PERC,       PLUS ,  7  ,  8  ,  9  , ASTR  ,
//    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
//         CIRC  , AMPR, LBRC, LPRN,LBRKT,       MINS ,  4  ,  5  ,  6  , DBQT  ,
//    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
//         BSLS  , PIPE, RBRC, RPRN,RBRKT,        EQL ,  1  ,  2  ,  3  , QUOT  ,
//    // '-------------------------------'      '-------------------------------'
//    //            .--------------------.      .-----------------.
//                    XXXXX, XXXXX,  ENE ,        UNDS , 0 , XXXXX),
//    //            '--------------------'      '-----------------'
//
//    /* Keymap 2: Numbers/Function/Motion layer
//     *
//     * ,-------------------------------.      ,-------------------------------.
//     * |       |     |     |     |     |      |     | mute|vol_u|vol_d|       |
//     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
//     * |       |     |     |     |     |      | left| down|  up |right|       |
//     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
//     * |       |     |     |     |     |      |     | last| play| next|       |
//     * `-------------------------------'      `-------------------------------'
//     *               .-----------------.      .-----------------.
//     *               |     |     |     |      |     |     |     |
//     *               '-----------------'      '-----------------'
//     */
//    [_SPECIAL] = LAYOUT_kc(
//    // ,-------------------------------.      ,-------------------------------.
//         XXXXX ,XXXXX,XXXXX,XXXXX,XXXXX,       XXXXX, MUTE, VOLD, VOLU, XXXXX ,
//    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
//         XXXXX ,XXXXX,XXXXX,XXXXX,XXXXX,        LEFT, DOWN,  UP ,RIGHT, XXXXX ,
//    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
//         XXXXX ,XXXXX,XXXXX,XXXXX,XXXXX,       XXXXX, MPRV, MPLY, MNXT, XXXXX ,
//    // '-------------------------------'      '-------------------------------'
//    //               .-----------------.      .-----------------.
//                      XXXXX,XXXXX,XXXXX,       XXXXX,XXXXX,XXXXX),
//    //               '-----------------'      '-----------------'
//
//    /* Keymap 3: Dvorak
//     *
//     * ,-------------------------------.      ,-------------------------------.
//     * |   '   |  ,  |  .  |  p  |  y  |      |  f  |  g  |  c  |  r  |   l   |
//     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
//     * |   a   |  o  |  e  |  u  |  i  |      |  d  |  h  |  t  | n   |   s   |
//     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
//     * |   ;   |  q  |  j  |  k  |  x  |      |  b  |  m  |  w  |  v  |   z   |
//     * `-------------------------------'      `-------------------------------'
//     *             .-------------------.      .-------------------.
//     *             |L2_ENT|LGUI|L1_BSPC|      |L1_SPC| TAB| L2_GRV|
//     *             '-------------------'      '-------------------'
//     */
//    [_DVORAK] = LAYOUT_kc(
//    // ,-------------------------------.      ,-------------------------------.
//         QUOT , COMMA, DOT ,  P  ,  Y  ,         F  ,  G  ,  C  ,  R  ,   L   ,
//    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
//            A  ,  O  ,  E  ,  U  ,  I  ,         D  ,  H  ,  T  ,  N  ,   S   ,
//    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
//          SCLN ,  Q  ,  J  ,  K  ,  X  ,         B  ,  M  ,  W  ,  V  ,   Z   ,
//    // '-------------------------------'      '-------------------------------'
//    //           .---------------------.      .--------------------.
//                   QWRT, LGUI , L1_BSPC,       L1_SPC, TAB ,L2_GRV),
//    //           '---------------------'      '--------------------'
};
