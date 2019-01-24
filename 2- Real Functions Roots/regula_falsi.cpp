#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double g(double x) { return pow(x, 7) + 0.5 * x - 0.5; }

void regula_falsi(double a, double b, double n)
{
	for (int i = 0; i < n; i++)
	{
		double new_p = (a * g(b) - b * g(a)) / (g(b) - g(a));

		if (new_p * a < 0)
			b = new_p;
		else
			a = new_p;

		cout << "iter " << i + 1 << ": a = " << a << ", b = " << b << endl;
	}
}

int main()
{
	double a = 0;
	double b = 0.8;
	double steps = 4;
	regula_falsi(a, b, steps);

	return 0;
}