#include <iostream>
#include <math.h>
#include <vector>

#define PI acos(-1)

using namespace std;

double f(double x) { return sin(x) / (x*x); }
double h(double x) { return exp(1.5*x); }

double simpson_method(int n, double a, double b)
{
	if (n % 2 != 0) throw invalid_argument("n must be an even number");

	double h = (b - a) / n;

	double result = h / 3;
	double sum = 0;
	for (int i = 0; i <= n; i++)
		if (i == 0 || i == n) sum += f(a + i * h);
		else
			if (i % 2 == 0) sum += (2 * f(a + i * h));
			else sum += (4 * f(a + i * h));
	result *= sum;
	return result;
}

double simpson_method_2(double a, double b, double _h)
{
	double n = abs(b - a) / _h;
	double result = 0;
	vector<double> values;
	for (int i = 0; i <= n; i++)
		values.push_back(h(a + _h * i));

	result += values[0] + values[n];
	
	for (int i = 1; i < n; i += 2)
		result += 4 * values[i];
	for (int i = 2; i < n; i += 2)
		result += 2 * values[i];

	result *= _h / 3;

	cout << "Simpson result for h = " << _h << ": " << result << endl;
	return result;
}

double quo_conv(double s, double s1, double s2) { return (s1 - s) / (s2 - s1); }

double calc_err(double s1, double s2) { return abs((s2 - s1) / 15); }

int main()
{
	int n = 8;
	double a = PI / 2, b = PI;

	double s, s1, s2;

	s = simpson_method(n, a, b);
	s1 = simpson_method(2 * n, a, b);
	s2 = simpson_method(4 * n, a, b);

	double qc = quo_conv(s, s1, s2);
	double error = calc_err(s1, s2);

	cout << "S:\t" << s << endl;
	cout << "S1:\t" << s1 << endl;
	cout << "S2:\t" << s2 << endl;

	cout << "Qc:\t" << qc << endl;
	cout << "Error:\t" << error << endl;

	return 0;
}