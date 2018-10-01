#include<cstdio>
#include"mikkola.h"
#include<cmath>

int main(){

	double e = 0.4;

	printf("Eccentricity = %f\n",e);
	printf("l\tu\tError\n");
	for(double u0=-100*M_PI; u0<=100*M_PI; u0+=M_PI/2000){
		int nc = (int)(u0/(2*M_PI));
		double l = u0 - e*sin(u0-2*M_PI*nc);
		double u = MIKKOLA(l, e);
		double err = fabs((u-u0)/u0);
		printf("%0.15f\t%0.15f\t%0.15e\n",l,u,err);
	}
	return 0;
}
