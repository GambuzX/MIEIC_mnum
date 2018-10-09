#include <iostream>
#include <iomanip>

const double e = 10e-5;

using namespace std;

double f(double x, double y) { return sqrt((x*y + 5 * x - 1) / 2); }
double g(double x, double y) { return sqrt(x + 3 * log(x)); }

int main()
{
	double x = 4, y = 4;
	int step = 1;
	while(true)
	{
		double newx = f(x,y);
		double newy = g(x,y);

		cout << "Step " << step << ": X= " << setprecision(15) << newx << ", Y= " << setprecision(15) << newy << endl;
		step++;

		if (abs(newx - x) <= e && abs(newy - y) <= e) break;
		else
		{
			x = newx;
			y = newy;
		}
	}

	return 0;
}