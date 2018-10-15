#include <iostream>
#include <math.h>

using namespace std;

double f(double x, double y) { return exp(y - x); }

int main()
{
	double x0 = 0, x1 = 0.5, y0 = 0, y1 = 0.5;

	int n = 2;

	double hx = (x1 - x0) / n;
	double hy = (y1 - y0) / n;

	double result = hx * hy / 4;

	double sum0;



	return 0;
}