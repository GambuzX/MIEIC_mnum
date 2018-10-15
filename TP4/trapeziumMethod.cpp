#include <iostream>
#include <math.h>

#define PI acos(-1)

using namespace std;


double exeFunc(double x) { return sin(x) / (x*x); }

double metodoTrapezios(int n, double a, double b)
{
	double h = (b - a) / n;

	double result = h / 2;
	double sum = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i == 0 || i == n) sum += exeFunc(a + i * h);
		else sum += (2 * exeFunc(a + i * h));
	}

	result *= sum;
	return result;
}

double quoConverg(double s, double s1, double s2) { return (s1 - s) / (s2 - s1); }

double calcError(double s1, double s2) { return abs((s2 - s1) / 3); }

int main()
{
	int n = 4;
	double a = PI / 2, b = PI;

	double s, s1, s2;
	
	s = metodoTrapezios(n, a, b);
	s1 = metodoTrapezios(2 * n, a, b);
	s2 = metodoTrapezios(4 * n, a, b);

	double qc = quoConverg(s, s1, s2);
	double error = calcError(s1, s2);

	cout << "S: " << s << endl;
	cout << "S1: " << s1 << endl;
	cout << "S2: " << s2 << endl;

	cout << "Qc: " << qc << endl;
	cout << "Error: " << error << endl;	

	return 0;
}