#include <iostream>
#include <math.h>

#define PI acos(-1)

using namespace std;

double exeFunc(double x) { return sin(x) / (x*x); }

double simpsonMethod(int n, double a, double b)
{
	if (n % 2 != 0) throw invalid_argument("n must be an even number");

	double h = (b - a) / n;

	double result = h / 3;
	double sum = 0;
	for (int i = 0; i <= n; i++)
		if (i == 0 || i == n) sum += exeFunc(a + i * h);
		else
			if (i % 2 == 0) sum += (2 * exeFunc(a + i * h));
			else sum += (4 * exeFunc(a + i * h));
	result *= sum;
	return result;
}

double quoConverg(double s, double s1, double s2) { return (s1 - s) / (s2 - s1); }

double calcError(double s1, double s2) { return abs((s2 - s1) / 15); }

int main()
{
	int n = 8;
	double a = PI / 2, b = PI;

	double s, s1, s2;

	s = simpsonMethod(n, a, b);
	s1 = simpsonMethod(2 * n, a, b);
	s2 = simpsonMethod(4 * n, a, b);

	double qc = quoConverg(s, s1, s2);
	double error = calcError(s1, s2);

	cout << "S:\t" << s << endl;
	cout << "S1:\t" << s1 << endl;
	cout << "S2:\t" << s2 << endl;

	cout << "Qc:\t" << qc << endl;
	cout << "Error:\t" << error << endl;

	return 0;
}