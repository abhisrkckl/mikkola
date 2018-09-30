#include<cstdio>
#include"mikkola.h"
#include<cmath>

int main(){

	double e = 0.4;

	printf("Eccentricity = %f\n",e);
	printf("l\tu\tError\n");
	for(double l=-10; l<=10; l+=0.01){
		double u = MIKKOLA(l, e);
		double err = -e*sin(u)+u-l;
		printf("%0.15f\t%0.15f\t%0.15e\n",l,u,err/u);
	}
	return 0;
}
