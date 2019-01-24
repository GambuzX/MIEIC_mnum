#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const double E = 1e-7;

double t(double x) { return x * x*x - 10 * sin(x) + 2.8; }

double m(double x) { return (5 * x - 1) / (x - 1); }

/* Stopping criteria is number of steps */
void bissection(double a, double b, double n)
{
	double new_x;
	for (int i = 0; i < n; i++)
	{
		new_x = (a + b) / 2;
		if (t(new_x) * t(a) < 0)
			b = new_x;
		else
			a = new_x;

		cout << "Step " << i + 1 << ": a = " << a << ", b = " << b << endl;
	}
}

/* Stopping criteria is to have interval smaller than 1e-7 */
void bissection_2(double a, double b)
{
	double new_x;
	do
	{
		new_x = (a + b) / 2;
		if (m(new_x) * m(a) < 0)
			b = new_x;
		else
			a = new_x;

	} while (abs(b - a) > E);

	if (m(a) < m(b))
		cout << "x = " << a << ", f(x) = " << m(a) << endl;
	else
		cout << "x = " << b << ", f(x) = " << m(b) << endl;
}

int main()
{
	double a = 1.5, b = 4.2;
	double steps = 4;
	bissection(a, b, steps);

	cout << endl << endl;

	a = 0; b = 0.5;
	bissection_2(a, b);

	return 0;
}