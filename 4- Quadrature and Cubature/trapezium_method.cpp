#include <iostream>
#include <math.h>
#include <vector>

#define PI acos(-1)

using namespace std;


double f(double x) { return sin(x) / (x*x); }
double h(double x) { return exp(1.5*x); }

double trapezium_method(int n, double a, double b)
{
	double h = (b - a) / n;

	double result = h / 2;
	double sum = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i == 0 || i == n) sum += f(a + i * h);
		else sum += (2 * f(a + i * h));
	}

	result *= sum;
	return result;
}

double trapezium_method_2(double a, double b, double _h)
{
	double n = abs(b - a) / _h;
	double result = 0;
	vector<double> values;
	for (int i = 0; i <= n; i++)
		values.push_back(h(a + _h*i));

	result += values[0] + values[n];
	for (int i = 1; i < n; i++)
		result += 2 * values[i];
	result *= _h / 2;

	cout << "Trapezium result for h = " << _h << ": " << result << endl;
	return result;
}

double quo_conv(double s, double s1, double s2) { return (s1 - s) / (s2 - s1); }

double calc_err(double s1, double s2) { return abs((s2 - s1) / 3); }

int main()
{
	int n = 4;
	double a = PI / 2, b = PI;

	double s, s1, s2;
	
	s = trapezium_method(n, a, b);
	s1 = trapezium_method(2 * n, a, b);
	s2 = trapezium_method(4 * n, a, b);

	double qc = quo_conv(s, s1, s2);
	double error = calc_err(s1, s2);

	cout << "S: " << s << endl;
	cout << "S1: " << s1 << endl;
	cout << "S2: " << s2 << endl;

	cout << "Qc: " << qc << endl;
	cout << "Error: " << error << endl;	

	return 0;
}