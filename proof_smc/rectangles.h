/* A class for dealing with rectangles
 */
#ifndef __RECTANGLES_H
#define __RECTANGLES_H

#include "intervals.h"
#include <queue>

class Rect {
public:
	// Two intervals are used to define a rectangle 
	I mu1, mu2;
	Rect();
	Rect(const I& mu1, const I& mu2);
  
	// Sets this rectangle to the smallest rectangle containing itself and X
	void include(const Rect& X);
  
	// Split this rectangle into 4 equal sub-rectangles and
	// add those rectangles to dest
	void split(std::queue<Rect> &dest) const;


private:
	void add_to(std::queue<Rect> &dest) const;
};

#endif
