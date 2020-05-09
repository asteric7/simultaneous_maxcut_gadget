#include <queue>
#include <iostream>
#include <string>
#include "alpha.h"
#include "rectangles.h"
#include "search.h"

// Hardness of Approximation ratio we want to prove
double target_ratio = 0.878566205784852;

double max_mu = 1; 

// Maximum depth to search to, width of intervals at this depth is
// 2/(2^max_depth).
const int max_depth = 50;


int main(int argc, char **argv) {
  std::cout.precision(15);
  std::cerr.precision(15);
  double err = 10e-12;

  if(argc >= 2) target_ratio  = std::stod(argv[1]);

 
  Rect init(I(err, max_mu-err),I(err, max_mu-err));
  
  std::cout << "Claim : The simultaneous max cut ratio of (G1, G2, G3) is at most "<<target_ratio<<std::endl;

  int res = search_smc(init, target_ratio, max_depth);

  if (res < 1) {
	  std::cerr << "The claim is INCORRECT!\n";
  }
  
  return 0;
  
}
