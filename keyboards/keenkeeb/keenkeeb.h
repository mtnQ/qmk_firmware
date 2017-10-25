#ifndef __KEENKEEB_H__
#define __KEENKEEB_H__

#include "quantum.h"
#include <stddef.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "config.h"
#include "layoutoptions.h"

/**
 * \brief Define the layout used
 */
#define __LAYOUT  (__kk_SPLIT_LSHIFT  ? __ISO : 0) | \
                  (!__kk_SPLIT_RSHIFT ? __EZRS : 0) | \
                  (__kk_1u_LMODS      ? __LMODS : 0) | \
                  (__kk_PLANCK_SPACE  ? __PLNK_S : 0) | \
                  (__kk_1u_RMODS      ? __RMODS : 0)
                  
#define __ISO     (1 << 4) /**< Use split ISO left shift */
#define __EZRS    (1 << 3) /**< Absorb key to left of right shift to make it easier to reach */
#define __LMODS   (1 << 2) /**< Use 1u left modifiers on bottom row */
#define __PLNK_S  (1 << 1) /**< Use Planck-like spacebar setup */
#define __RMODS   (1 << 0) /**< Use 1u right modifiers on bottom row */

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array

#if   (__LAYOUT == 0)
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
       K40,   K41,   K43,         K46,          K48,         K49,   K4B,   K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   KC_NO, K43,   KC_NO, KC_NO, K46,   KC_NO, K48,   K49,   KC_NO, K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__LMODS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
     K40,  K41,  K42,  K43,       K46,          K48,         K49,   K4B,   K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   K42,   K43,   KC_NO, KC_NO, K46,   KC_NO, K48,   K49,   KC_NO, K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__RMODS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
       K40,   K41,   K43,         K46,          K48,       K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   KC_NO, K43,   KC_NO, KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__LMODS | __RMODS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
     K40,  K41,  K42,  K43,       K46,          K48,       K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   K42,   K43,   KC_NO, KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__LMODS | __EZRS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,    K3C,     \
     K40,  K41,  K42,  K43,       K46,          K48,         K49,   K4B,   K4C    \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C }, \
     { K40,   K41,   K42,   K43,   KC_NO, KC_NO, K46,   KC_NO, K48,   K49,   KC_NO, K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__RMODS | __EZRS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,    K3C,     \
       K40,   K41,   K43,         K46,          K48,       K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C }, \
     { K40,   K41,   KC_NO, K43,   KC_NO, KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__LMODS | __RMODS | __EZRS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,    K3C,     \
     K40,  K41,  K42,  K43,       K46,          K48,       K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C }, \
     { K40,   K41,   K42,   K43,   KC_NO, KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__PLNK_S))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
       K40,   K41,   K43,     K44,       K46,       K48,     K49,   K4B,   K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   KC_NO, K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   KC_NO, K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__LMODS | __PLNK_S))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
     K40,  K41,  K42,  K43,   K44,       K46,       K48,     K49,   K4B,   K4C    \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   K42,   K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   KC_NO, K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__PLNK_S | __RMODS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
       K40,   K41,   K43,     K44,       K46,       K48,   K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   KC_NO, K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__LMODS | __PLNK_S | __RMODS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
     K40,  K41,  K42,  K43,   K44,       K46,       K48,   K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   K42,   K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__PLNK_S | __EZRS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,    K3C,     \
       K40,   K41,   K43,     K44,       K46,       K48,     K49,   K4B,   K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C }, \
     { K40,   K41,   KC_NO, K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   KC_NO, K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__LMODS | __PLNK_S | __EZRS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,    K3C,     \
     K40,  K41,  K42,  K43,   K44,       K46,       K48,     K49,   K4B,   K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C }, \
     { K40,   K41,   K42,   K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   KC_NO, K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__PLNK_S | __RMODS | __EZRS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,    K3C,     \
       K40,   K41,   K43,     K44,       K46,       K48,   K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C }, \
     { K40,   K41,   KC_NO, K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__LMODS | __PLNK_S | __RMODS | __EZRS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
         K30,    K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,    K3C,     \
     K40,  K41,  K42,  K43,   K44,       K46,       K48,   K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C }, \
     { K40,   K41,   K42,   K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
       K40,   K41,   K43,         K46,          K48,         K49,   K4B,   K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   KC_NO, K43,   KC_NO, KC_NO, K46,   KC_NO, K48,   K49,   KC_NO, K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO | __LMODS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
     K40,  K41,  K42,  K43,       K46,          K48,         K49,   K4B,   K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   K42,   K43,   KC_NO, KC_NO, K46,   KC_NO, K48,   K49,   KC_NO, K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO | __RMODS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
       K40,   K41,   K43,         K46,          K48,       K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   KC_NO, K43,   KC_NO, KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO | __LMODS | __RMODS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
     K40,  K41,  K42,  K43,       K46,          K48,       K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   K42,   K43,   KC_NO, KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO | __LMODS | __EZRS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,    K3C,     \
     K40,  K41,  K42,  K43,       K46,          K48,         K49,   K4B,   K4C    \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C }, \
     { K40,   K41,   K42,   K43,   KC_NO, KC_NO, K46,   KC_NO, K48,   K49,   KC_NO, K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO | __RMODS | __EZRS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,    K3C,     \
       K40,   K41,   K43,         K46,          K48,       K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C }, \
     { K40,   K41,   KC_NO, K43,   KC_NO, KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO | __LMODS | __RMODS | __EZRS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,    K3C,     \
     K40,  K41,  K42,  K43,       K46,          K48,       K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C }, \
     { K40,   K41,   K42,   K43,   KC_NO, KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO | __PLNK_S))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
       K40,   K41,   K43,     K44,       K46,       K48,     K49,   K4B,   K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   KC_NO, K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   KC_NO, K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO | __LMODS | __PLNK_S))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
     K40,  K41,  K42,  K43,   K44,       K46,       K48,     K49,   K4B,   K4C    \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   K42,   K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   KC_NO, K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO | __PLNK_S | __RMODS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
       K40,   K41,   K43,     K44,       K46,       K48,   K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   KC_NO, K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO | __LMODS | __PLNK_S | __RMODS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C, \
     K40,  K41,  K42,  K43,   K44,       K46,       K48,   K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C }, \
     { K40,   K41,   K42,   K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO | __PLNK_S | __EZRS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,    K3C,     \
       K40,   K41,   K43,     K44,       K46,       K48,     K49,   K4B,   K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C }, \
     { K40,   K41,   KC_NO, K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   KC_NO, K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO | __LMODS | __PLNK_S | __EZRS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,    K3C,     \
     K40,  K41,  K42,  K43,   K44,       K46,       K48,     K49,   K4B,   K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C }, \
     { K40,   K41,   K42,   K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   KC_NO, K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO | __PLNK_S | __RMODS | __EZRS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,    K3C,     \
       K40,   K41,   K43,     K44,       K46,       K48,   K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C }, \
     { K40,   K41,   KC_NO, K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
 
#elif (__LAYOUT == (__ISO | __LMODS | __PLNK_S | __RMODS | __EZRS))
# define LAYOUT_keenkeeb( \
     K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C, \
       K10,   K11,  K12,  K13,  K14,  K15,  K16,  K18,  K19,  K1A,  K1B,   K1C,   \
       K20,   K21,  K22,  K23,  K24,  K25,  K26,  K28,  K29,  K2A,  K2B,   K2C,   \
     K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,    K3C,     \
     K40,  K41,  K42,  K43,   K44,       K46,       K48,   K49,  K4A,  K4B,  K4C  \
 ) { \
     { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C }, \
     { K10,   K11,   K12,   K13,   K14,   K15,   K16,   KC_NO, K18,   K19,   K1A,   K1B,   K1C }, \
     { K20,   K21,   K22,   K23,   K24,   K25,   K26,   KC_NO, K28,   K29,   K2A,   K2B,   K2C }, \
     { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, K3C }, \
     { K40,   K41,   K42,   K43,   K44,   KC_NO, K46,   KC_NO, K48,   K49,   K4A,   K4B,   K4C }  \
 }
#endif

#endif
