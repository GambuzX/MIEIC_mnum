#include <iostream>
#include <iomanip>
#include <math.h>

const double e = 10e-10;

using namespace std;

double f1(double x, double y) { return (2 * x*x - x * y - 5 * x + 1); }
double f2(double x, double y) { return (x + 3 * log(x) - y * y); }

double f1x(double x, double y) { return (4 * x - y - 5); }
double f1y(double x, double y) { return (-1*x); }
double f2x(double x, double y) { return (1 + 3/x); }
double f2y(double x, double y) { return (-2*y); }

int main()
{
	int steps = 20;
	double x = 10;
	double y = -8;
	int step = 1;

	while(true)
	{
		double newx = x - (f1(x, y) * f2y(x, y) - f2(x, y) * f1y(x, y)) / (f1x(x, y) * f2y(x, y) - f2x(x, y) * f1y(x, y));
		double newy = y - (f2(x, y) * f1x(x, y) - f1(x, y) * f2x(x, y)) / (f1x(x, y) * f2y(x, y) - f2x(x, y) * f1y(x, y));

		cout << "Step " << step << ": X= " << setprecision(15) <<  x << ", Y= " << setprecision(15) << y << endl;
		step++;

		if (abs(newx - x) <= e && abs(newy - y) <= e) break;
		else
		{
			x = newx;
			y = newy;
		}
	}
	return 0;
}