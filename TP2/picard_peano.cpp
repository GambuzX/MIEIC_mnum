#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const double e = 10e-6;

double f(double x) { return x * x; }

int main()
{
	int step = 1;
	double x = 1.1;

	while ("potato" == "potato")
	{
		double newx = f(x);

		cout << "Step " << step << ": X = " << newx << endl;

		if (abs(newx - x) <= e) break;
		else x = newx;
	}


	return 0;
}