#include <iostream>
#include "search.h"

const size_t MAX_QSIZE = 100000000;


int search_smc(const Rect& initbox, 
		   double target_ratio, int max_depth) {
	std::queue<Rect> Q[2];
	Q[0].push(initbox);
	std::cout << "Searching in box (" << initbox.mu1 <<  ", " << initbox.mu2 <<  ")\n";

	double worst_lb = 0;
	double worst_ub = 0;
	int tot_inspected = 0;
	int inconclusive = 0;

	for (int level = 0; !Q[level % 2].empty(); ++level) {
		int cur_level_inspected = 0;
		int cur_level_size = Q[level % 2].size();
		Rect curbox = Rect(I(), I());

		while (!Q[level % 2].empty()) {
			Rect X = Q[level % 2].front();
			Q[level % 2].pop();

			I a = alpha_smc(X);
			if (a.lower() > target_ratio) {
				std::cerr << "ERROR: found good biases. ---> ";
				std::cerr << " mu1 in " << X.mu1  <<", mu2 in  "<< X.mu2 << "\n";
				std::cerr << "Best simultaneous max cut approximation ratio lies in: " << a.lower() << " up to " << a.upper() << "\n";
				return -1;
			}

			worst_lb = std::max(worst_lb, a.lower());
			++tot_inspected;
			if (++cur_level_inspected % 50000 == 0) {
				std::cout << "Level " << level << ": " << cur_level_size << " cases, " << (100.0*cur_level_inspected/cur_level_size) << "% done. Next level: " << Q[(level+1)%2].size() << ".          \r";
			}
			curbox.include(X);
		
			
			if (a.upper() <= target_ratio) {
				worst_ub = std::max(worst_ub, a.upper());
				// ==> Upper bound strong enough, done!
				continue;
			}
			if (level == max_depth || Q[(level+1)%2].size() > MAX_QSIZE) {
				std::cout << "Inconclusive case at:\n  (" << X.mu1 << ", " << X.mu2 << ")\n";
				++inconclusive;
				continue;
			}
			X.split(Q[(level+1)%2]);
		}
		std::cout << "Level " << level << ": " << cur_level_size << " cases. ";
		std::cout << "LB: " << worst_lb << ". UB: " << worst_ub << ". ";
		std::cout << "Bbox: (" << curbox.mu1 << "," << curbox.mu2 << ")\n";
	}
	
	std::cout << "Search complete. ";
	std::cout << "A total of " << tot_inspected << " cases were inspected\n";

	if (inconclusive) {
		std::cerr << "Of these, " << inconclusive << " were inconclusive\n";
		return 0;
	}
	std::cout << "The claim is CORRECT!\n";
	std::cout << "Best simultaneous max cut approximation ratio: LB:" << worst_lb << ". UB: " << worst_ub << ".\n";
	std::cout << "\n";
	return 1;
}

