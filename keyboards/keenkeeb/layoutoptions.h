#ifndef __LAYOUT_OPTIONS_H__
#define __LAYOUT_OPTIONS_H__

/***********************************************************************
 * keenkeeb-specific configuration
 **********************************************************************/
 
/**
 * \brief Set to TRUE if using two 1u keys in place of the 2u left shift; 
 *        FALSE otherwise
 */
#define KEENKEEB_SPLIT_LSHIFT  (FALSE)

/**
 * \brief Set to TRUE if using two 1u keys in place of the 2u right shift; 
 *        FALSE otherwise
 */
#define KEENKEEB_SPLIT_RSHIFT  (TRUE)

/**
 * \brief Set to TRUE if using four 1u keys on the left side of 
 *        bottom row; FALSE if using 1.5-1-1.5
 */
#define KEENKEEB_1u_LMODS      (FALSE)

/**
 * \brief Set to TRUE if using four 1u keys on the right side of 
 *        bottom row; FALSE if using 1.5-1-1.5
 */
#define KEENKEEB_1u_RMODS      (TRUE)

/**
 * \brief Set to TRUE to use a centralized spacebar and two 
 *        raise/lower keys instead of a split spacebar; FALSE if using 
 *        the 2-part split spacebar
 */
#define KEENKEEB_PLANCK_SPACE  (FALSE)

#endif
