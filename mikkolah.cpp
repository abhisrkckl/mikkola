#include <math.h>
#include "mikkola.h"


/*
 * This is based on [Mikkola 1987].
 *	adsabs.harvard.edu/full/1987CeMec..40..329M
 *
*/


/*
 * Solves the hyperbolic Kepler equation.
 *
 * l	is mean anomaly	in rad
 * e	is eccentricity
 *
 * Returns the eccentric anomaly u which is the solution of the Kepler equation.
 * 	l = e sinh(u) - u
 */
double MIKKOLAh(double l, double e){		

	if(e<=1){
		return NAN;
	}

	double 	alpha  = (e-1)/(4*e + 0.5),
		alpha3 = alpha*alpha*alpha;
	double 	beta   = (l/2)/(4*e + 0.5),
		beta2  = beta*beta;
    	
	double z = (beta>0)	?cbrt(beta + sqrt(alpha3 + beta2))
				:cbrt(beta - sqrt(alpha3 + beta2));

	double	s = (z - alpha/z),
		s5= s*s*s*s*s,
		ds= 0.071*s5/((1+0.45*s*s)*(1+4*s*s)*e);
	double 	w = s + ds;
	
	double u = 3*log(w+sqrt(1+w*w));
	
	double eshu = e*sinh(u);
	double echu = e*cosh(u);
	
	double	fu  = -u + eshu - l,
		f1u = -1 + echu,  
		f2u = eshu,
		f3u = echu,
		f4u = eshu,
		f5u = echu;

	double	u1 = -fu/ f1u,
		u2 = -fu/(f1u + f2u*u1/2),
		u3 = -fu/(f1u + f2u*u2/2 + f3u*(u2*u2)/6.0),
		u4 = -fu/(f1u + f2u*u3/2 + f3u*(u3*u3)/6.0 + f4u*(u3*u3*u3)/24.0),
		u5 = -fu/(f1u + f2u*u4/2 + f3u*(u4*u4)/6.0 + f4u*(u4*u4*u4)/24.0 + f5u*(u4*u4*u4*u4)/120.0),
		xi = (u + u5);
	
	return xi;
}

std::vector<double> MIKKOLAh(std::vector<double> ls, double e){
	
	int length = ls.size();
	std::vector<double> us(length);

	for(int i=0; i<length; i++){
		us[i] = MIKKOLAh(ls[i],e);
	}

	return us;
}
