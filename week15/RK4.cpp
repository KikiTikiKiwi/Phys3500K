#include<iostream>
#include<cmath>
#include<fstream>
#include<vector>

#include "RK4.h"
#include "function.h"
#include "vector_fwrd.h"

double RK4(double y0, double t0, double tf, int Niter)
{
	double h=(tf-t0)/Niter;
	double k1,k2,k3,k4;
  double a = y0;

	if (t0==tf)
		return y0;

	for (int i=0;i<Niter;i++)
	{
		k1=h*f(t0,a);
		k2=h*f(t0,a+k1/2.);
		k3=h*f(t0,a+k2/2.);
		k4=h*f(t0,a+k3);
		a += k1/6.+k2/3.+k3/3.+k4/6.;
	}

	return a;
}
