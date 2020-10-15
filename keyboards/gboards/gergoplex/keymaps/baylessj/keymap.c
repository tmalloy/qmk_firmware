/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 */

#include "gergoplex.h"
#include "g/keymap_combo.h"

enum {
    _ALPHA,   // default
    _SPECIAL, // special characters
    _NUMBERS  // numbers/function/motion
};

#define KC_XXXXX   KC_NO
#define KC_ALT_Q   MT(MOD_LALT, KC_Q)
#define KC_L1_A    LT(_SPECIAL, KC_A)
#define KC_L2_S    LT(_NUMBERS, KC_S)
#define KC_L2      MO(_NUMBERS)
#define KC_CTL_CL  MT(MOD_RCTL, KC_SCLN)
#define KC_CTL_Z   MT(MOD_LCTL, KC_Z)
#define KC_LBRKT   LSFT(KC_LBRC)        // {
#define KC_RBRKT   LSFT(KC_RBRC)        // }
#define KC_C_A_D   LCA(KC_DEL)          // Ctrl + Alt + Del
// TODO: add another layer entrypoint for CTRL+ALT+L1 to do multi-cursors in vscode?
#define KC_CMB_TOG CMB_TOG  // A hack to allow KC_-less keycode along with KC_-ful ones


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Alpha layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * | ALT_Q |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |   P   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * | L1_A  | L2_S|  D  |  F  |  G  |      |  H  |  J  |  K  |  L  |CTRL ; |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |   Z   |SUP_X|  C  |  V  |  B  |      |  N  |  M  |  ,  |  .  |   /   |
     * `-------------------------------'      `-------------------------------'
     *               .-----------------.      .-----------------.
     *               | LCTL| SPC | SFT |      | ENTR| TAB |SUPER|
     *               '-----------------'      '-----------------'
     */
    [_ALPHA] = LAYOUT_kc(
    // ,-------------------------------.      ,-------------------------------.
         ALT_Q ,  W  ,  E  ,  R  ,  T  ,         Y  ,  U  ,  I  ,  O  ,   P   ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         L1_A  , L2_S,  D  ,  F  ,  G  ,         H  ,  J  ,  K  ,  L  , CTL_CL,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------| 
         CTL_Z   ,  X  ,  C  ,  V  ,  B  ,         N  ,  M  ,COMMA, DOT , SLSH  ,
    // '-------------------------------'      '-------------------------------'
    //               .-----------------.      .-----------------.
                      LSFT, SPC , BSPC ,        TAB , ENT ,LGUI),
    //               '-----------------'      '-----------------'


    /* Keymap 1: Special characters layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |       |  &  |  *  |  `  |  {  |      |  }  | HOME| UP  | END |   -   
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * | XXXXX |  $  |  %  |  ^  |  (  |      |  )  | LEFT| DOWN| RGHT|   '   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |       |  !  |  @  |  #  |  [  |      |  ]  |     |     |     |   =   |
     * `-------------------------------'      `-------------------------------'
     *               .-----------------.      .-----------------.
     *               | LSFT| SPC | BSPC|      | ENTR| TAB |SUPER|
     *               '-----------------'      '-----------------'
     */
    [_SPECIAL] = LAYOUT_kc(
    // ,-------------------------------.      ,-------------------------------.
         XXXXX , AMPR, ASTR, GRV ,LBRKT,       RBRKT, HOME, UP  , END , MINS  ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         XXXXX , DLR , PERC, CIRC, LPRN,       RPRN , LEFT, DOWN, RGHT, QUOT  ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         XXXXX , EXLM,  AT , HASH, LBRC,       RBRC ,XXXXX,XXXXX,XXXXX,  EQL  ,
    // '-------------------------------'      '-------------------------------'
    //               .-----------------.      .-----------------.
                      LSFT, SPC , DEL ,        TAB , ENT ,LGUI),
    //               '-----------------'      '-----------------'

    /* Keymap 2: Numbers/Function/Motion layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |  ESC  |     |     |     |C_A_D|      |  =  |  7  |  8  |  9  |   -   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |       |XXXXX|     |     |     |      |  \  |  4  |  5  |  6  |   +   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |       |     |     |     |     |      |  0  |  1  |  2  |  3  | ENTR  |
     * `-------------------------------'      `-------------------------------'
     *               .-----------------.      .-----------------.
     *               | LSFT| SPC | BSPC|      | ENTR| TAB |SUPER|
     *               '-----------------'      '-----------------'
     */
    [_NUMBERS] = LAYOUT_kc(
    // ,-------------------------------.      ,-------------------------------.
          ESC  ,XXXXX,XXXXX,XXXXX,C_A_D,        EQL ,  7  ,  8  ,  9  ,  MINS ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         XXXXX ,XXXXX,XXXXX,XXXXX,XXXXX,        BSLS,  4  ,  5  ,  6  ,  PLUS ,
    // |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
         XXXXX ,XXXXX,XXXXX,XXXXX,XXXXX,         0  ,  1  ,  2  ,  3  ,  ENT  ,
    // '-------------------------------'      '-------------------------------'
    //               .-----------------.      .-----------------.
                      LSFT, SPC , BSPC ,        TAB , ENT ,  0 ),
    //               '-----------------'      '-----------------'
};
