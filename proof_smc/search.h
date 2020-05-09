/* Function to prove the claimed hardness of approximation ratio
 * by searching the box [0,1]x[0,1]
 */
#ifndef __SEARCH_H
#define __SEARCH_H

#include "rectangles.h"
#include "alpha.h"

/* Searches the rectangle "initbox" to find a point (mu1, mu2) inside it that gives
 * a ratio (between the soundness and completeness max-cut value) of 
 * at least the target_ratio for all the three graphs G1 G2 G3.
 *
 * Returns:
 * +1 if no such pair (mu1, mu2) is found (i.e. the hardness claim is TRUE)
 *  0 if inconclusive
 * -1 if there exists (mu1, mu2) with ratio at least the target_ratio 
 *    (i.e. the hardness claim is FALSE)
 */
int search_smc(const Rect& initbox, 
		   double target_ratio, int max_depth);

#endif
