#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double l(double x) { return -x + 40 * cos(pow(x, 0.5)) + 3; }
double dl(double x) { return -1 - (20 * sin(pow(x, 0.5)) / pow(x, 0.5)); }

void newton(double x, double n)
{
	for (int i = 0; i < n; i++)
	{
		x -= l(x) / dl(x);

		cout << "Step " << i + 1 << ": x = " << x << endl;
	}
}

int main()
{
	double guess = 1.7, steps = 4;
	newton(guess, steps);
	return 0;
}