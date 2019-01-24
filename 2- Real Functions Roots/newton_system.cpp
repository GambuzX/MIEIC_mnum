#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double f1(double x, double y) { return x * x - y - 2; }
double df1x(double x, double y) { return 2 * x; }
double df1y(double x, double y) { return -1; }

double f2(double x, double y) { return -x + y * y - 2; }
double df2x(double x, double y) { return -1; }
double df2y(double x, double y) { return 2 * y; }

void newton_method(double a, double b, double n)
{
	cout << "iter 0: a = " << a << ", b = " << b << endl;
	for (int i = 0; i < n; i++)
	{
		double jacobian = df1x(a,b)*df2y(a,b) - df1y(a,b)*df2x(a,b);
		double hn = f1(a, b) * df2y(a, b) - f2(a, b) * df1y(a, b);
		double kn = df1x(a, b) * f2(a, b) - df2x(a, b) * f1(a, b);

		a -= hn / jacobian;
		b -= kn / jacobian;

		cout << "iter " << i + 1 << ": a = " << a << ", b = " << b << endl;
	}
}

int main()
{
	double a = 1.5, b = 0.8;
	double steps = 4;
	cout << "Newton Method\n";
	newton_method(a, b, steps);
}