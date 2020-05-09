#include "alpha.h"
#include "gaussian.h"


double min(double a, double b)
{
	if(a<b) return a;
	else return b;
}

I alpha_g1(const Rect& X) {
	double rho = -42.0/58.0;	
	return (2.0/0.84)*(X.mu1 - Gamma(X.mu1, X.mu1,I(rho, rho))) ;
}


  
I alpha_g2(const Rect& X) {
	double rho = -42.0/58.0;	
	return (2.0/0.84)*(X.mu2 - Gamma(X.mu2, X.mu2,I(rho, rho ))) ;
}


I alpha_g3(const Rect& X) {
	double q = 0.58;
	double rho = (2*q*q -1)/(2*q*(1-q));
	return (1.0/0.84)*(X.mu1 + X.mu2 - 2.0*Gamma(X.mu1, X.mu2, I(rho,rho))) ;
}

I alpha_smc(const Rect& X) {
	
I a1 = alpha_g1(X);
I a2 = alpha_g2(X);
I a3 = alpha_g3(X);	

// Return the minimum among the three ratios. 
return I(min(min(a1.lower(), a2.lower()), a3.lower()), min(min(a1.upper(), a2. upper()), a3. upper()));

}


