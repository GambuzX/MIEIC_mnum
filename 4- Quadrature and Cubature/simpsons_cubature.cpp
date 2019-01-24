#include <iostream>
#include <math.h>

using namespace std;

double f(double x, double y) { return exp(y - x); }

double simpsons_cubature(int n, double x0, double x1, double y0, double y1)
{
	double hx = (x1 - x0) / n;
	double hy = (y1 - y0) / n;

	double result = hx * hy / 9;

	double sum0 = 0, sum1 = 0, sum2 = 0;

	// SUM 0
	sum0 = f(x0, y0) + f(x0, y1) + f(x1, y0) + f(x1, y1);

	// SUM 1
	for (double x = x0 + hx; x <= x1 - hx; x += hx)
	{
		sum1 += (f(x, y0) + f(x, y1));
	}
	for (double y = y0 + hy; y <= y1 - hy; y += hy)
	{
		sum1 += (f(x0, y) + f(x1, y));
	}

	// SUM 2
	for (double x = x0 + hx; x <= x1 - hx; x += hx)
		for (double y = y0 + hy; y <= y1 - hy; y += hy)
			sum2 += f(x, y);

	result *= (sum0 + 4 * sum1 + 16 * sum2);
	return result;
}

int main()
{
	int n = 4;
	double x0 = 0, x1 = 0.5, y0 = 0, y1 = 0.5;

	double result = simpsons_cubature(n, x0, x1, y0, y1);

	cout << "Result:\t" << result << endl;
	return 0;
}