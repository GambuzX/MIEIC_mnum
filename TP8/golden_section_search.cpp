#include <iostream>
#include <iomanip>

using namespace std;

const double error = 1e-5;
const double A = 0.3819660112;
const double B = 0.6180339887;

double f(double x) { return 0.28*x*x + 0.5*x + 2; }

double golden_section_search_minimum(double x1, double x2, double func(double))
{
	double x3, x4;
	while (abs(x2 - x1) > error)
	{
		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);

		if (func(x3) < func(x4))
			x2 = x4;
		else
			x1 = x3;
	}

	double minimum = x1;
	if (func(x2) < func(minimum)) minimum = x2;
	if (func(x3) < func(minimum)) minimum = x3;
	if (func(x4) < func(minimum)) minimum = x4;

	return minimum;
}

double golden_section_search_maximum(double x1, double x2, double func(double))
{
	double x3, x4;
	while (abs(x2 - x1) > error)
	{
		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);

		if (func(x3) > func(x4))
			x2 = x4;
		else
			x1 = x3;
	}

	double maximum = x1;
	if (func(x2) > func(maximum)) maximum = x2;
	if (func(x3) > func(maximum)) maximum = x3;
	if (func(x4) > func(maximum)) maximum = x4;

	return maximum;
}

int main()
{
	double a = -1, b = 0;

	cout << "Found minimum is " << f(golden_section_search_minimum(a, b, f)) << " for x " << golden_section_search_minimum(a, b, f) << endl;
	cout << "Found maximum is " << f(golden_section_search_maximum(a, b, f)) << " for x " << fixed << setprecision(8) << golden_section_search_maximum(a, b, f) << endl;

	return 0;
}