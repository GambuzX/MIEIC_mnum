#include <iostream>
#include <math.h>

using namespace std;

double f(double x, double y) { return exp(y - x); }

double trapeziumCubature(int n, double x0, double x1, double y0, double y1)
{
	double hx = (x1 - x0) / n;
	double hy = (y1 - y0) / n;
	double res=0;

	for (double x = x0; x < (x1-0.00001); x += (2*hx))
	{
		for (double y = y0; y < (y1-0.00001); y += (2*hy))
		{
			double result = 0;

			double sum0 = 0, sum1 = 0, sum2 = 0;

			sum0 = f(x, y) + f(x, y+2*hy) + f(x+2*hx, y) + f(x+ 2 * hx, y+ 2 * hy);
			sum1 = f(x + hx, y) + f(x + hx, y + 2 * hy) + f(x, y + hy) + f(x + 2 * hx, y + hy);
			sum2 = f(x + hx, y + hy);

			result = (sum0 + 2 * sum1 + 4 * sum2);
			res += result;
		}
	}
	res *= (hx * hy) / 4;
	return res;
}

int main()
{
	int n = 4;
	double x0 = 0, x1 = 0.5, y0 = 0, y1 = 0.5;
	double result = trapeziumCubature(n, x0, x1, y0, y1);

	cout << "Result:\t" << result << endl;
	return 0;
}