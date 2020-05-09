/* Functions for calculating the approximation ratio of the 
 * dictatorship test, alpha, in a given
 * rectangle.
 */
#ifndef __ALPHA_H
#define __ALPHA_H

#include "intervals.h"
#include "rectangles.h"


// Evaluate the approximation ratio for the biases inside a rectangle X
I alpha_g1(const Rect& X);
I alpha_g2(const Rect& X);
I alpha_g3(const Rect& X);
I alpha_smc(const Rect& X);

#endif
