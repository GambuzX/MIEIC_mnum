#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const double error = 1e-5;

double f(double x, double y) { return sin(y) + y * y / 4 + cos(x) + x * x / 4 - 1; }
double dfx(double x, double y) { return (-1) * sin(x) + x / 2; }
double dfy(double x, double y) { return cos(y) + y / 2; }

void gradient_method(double x0, double y0)
{
	double h = 1;
	double x = x0, y = y0;
	do
	{	
		x0 = x;
		y0 = y;

		x = x0 - h * dfx(x0, y0);
		y = y0 - h * dfy(x0, y0);

		h = (f(x, y) <= f(x0, y0)) ? h * 2 : h / 2;

		cout << "X = " << x << ", Y = " << y << endl;

	} while (abs(x - x0) > error || abs(y - y0) > error);

	cout << "X = " << x << ", Y = " << y << endl;

	return;
}

int main()
{
	double x0 = 0, y0 = 0;

	gradient_method(x0, y0);

	return 0;
}