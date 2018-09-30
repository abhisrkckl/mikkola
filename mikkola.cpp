#include <math.h>
#include "mikkola.h"

template <typename T> int sign(T val) {
    return (T(0) < val) - (val < T(0));
}

/*
 * This is based on [Mikkola 1987].
 *	adsabs.harvard.edu/full/1987CeMec..40..329M
 *
 * Disclaimer : I am not the original author of this code, although I have made significant changes to it.
 *              AFAIK this was written by Manuel Tessmer.
 *			- Abhimanyu
 *
*/


/*
 * Solves the elliptical Kepler equation.
 *
 * l	is mean anomaly	in rad
 * e	is eccentricity
 *
 * Returns the eccentric anomaly u which is the solution of the Kepler equation.
 * 	l = u - e sin(u)
 */
double MIKKOLA(double l, double e){

	if(e<0 || e>=1){
		//fprintf(stderr,"ERROR: The eccentricity of an ellipse must lie within [0,1).\n");
		return NAN;
	}

	constexpr double Pi=M_PI, TwoPi=2*M_PI;

	double ND = (l>=0)	?floor(l/TwoPi)	:ceil(l/TwoPi);

	int sgn = sign(l);
	l=fabs(l);
	if(l > TwoPi) {
		l -= floor(l/TwoPi)*TwoPi;
	}

	int SIGN2 = (l<Pi)	?1	:-1;
	if(SIGN2==-1) {
		l = (TwoPi - l);
	}

	double 	alpha  = (1-e)/(4*e + 0.5),
		alpha3 = alpha*alpha*alpha;
	double 	beta   = (l/2)/(4*e + 0.5),
		beta2  = beta*beta;
    
	double z = (beta>0)	?cbrt(beta + sqrt(alpha3 + beta2))
				:cbrt(beta - sqrt(alpha3 + beta2));

	double	s = (z - alpha/z),
		s5= s*s*s*s*s;
	double 	w = (s - (0.078*s5)/(1 + e)),
		w3= w*w*w;
	
	double E0 = (l + e*(3*w - 4*w3));
	double u = E0 ;
	
	double  su  = sin(u);
	double  cu  = cos(u);
	
	double	fu  = (u - e*su - l),
		f1u = (1 - e*cu),
		f2u = (e*su),
		f3u = (e*cu),
		f4u =-(e*su);

	double	u1 = -fu/ f1u,
		u2 = -fu/(f1u + f2u*u1/2),
		u3 = -fu/(f1u + f2u*u2/2 + f3u*(u2*u2)/6.0),
		u4 = -fu/(f1u + f2u*u3/2 + f3u*(u3*u3)/6.0 + f4u*(u3*u3*u3)/24.0),
		xi = (E0 + u4);
	
	double sol = (SIGN2>0)	?xi	:(TwoPi-xi);
	
	if(sgn<0) {
		sol = -sol;
	}
	
	u = (sol + ND*TwoPi);
	return u;
}

