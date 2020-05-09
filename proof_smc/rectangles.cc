#include "rectangles.h"

Rect::Rect() {}

Rect::Rect(const I& mu1, const I& mu2): 
  mu1(mu1), mu2(mu2) { }




void Rect::include(const Rect& X) {
	mu1 = hull(mu1, X.mu1);
	mu2 = hull(mu2, X.mu2);
}


void Rect::split(std::queue<Rect> &dest) const {
  std::pair<I, I> sub_mu1 = bisect(mu1);
  std::pair<I, I> sub_mu2 = bisect(mu2);

  Rect(sub_mu1.first, sub_mu2.first).add_to(dest);

      Rect(sub_mu1.first, sub_mu2.second).add_to(dest);

	  Rect(sub_mu1.second, sub_mu2.first).add_to(dest);

	      Rect(sub_mu1.second, sub_mu2.second).add_to(dest);

}

void Rect::add_to(std::queue<Rect> &dest) const {

	dest.push(*this);

}



