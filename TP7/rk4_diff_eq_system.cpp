#include <iostream>
#include <math.h>

using namespace std;

double f(double x, double y, double z) { return z * y + x; }
double g(double x, double y, double z) { return z * x + y; }

void rk4(double a, double b, double x, double y, double z, double h, double & yres, double & zres)
{
	double diff;
	int step = 0;

	do
	{
		double dy1 = h * f(x, y, z);
		double dz1 = h * g(x, y, z);

		double dy2 = h * f(x + h / 2, y + dy1 / 2, z + dz1 / 2);
		double dz2 = h * g(x + h / 2, y + dy1 / 2, z + dz1 / 2);

		double dy3 = h * f(x + h / 2, y + dy2 / 2, z + dz2 / 2);
		double dz3 = h * g(x + h / 2, y + dy2 / 2, z + dz2 / 2);

		double dy4 = h * f(x + h, y + dy3, z + dz3);
		double dz4 = h * g(x + h, y + dy3, z + dz3);

		x += h;
		y += dy1 / 6 + dy2 / 3 + dy3 / 3 + dy4 / 6;
		z += dz1 / 6 + dz2 / 3 + dz3 / 3 + dz4 / 6;
		step++;
	} while (a + h * step < (b - 10e-6));

	yres = y;
	zres = z;
}

double qc(double s, double sl, double sll) { return (sl - s) / (sll - sl); }
double error(double sl, double sll, int order) { return (sll - sl) / (pow(2, order) - 1); }

int main()
{
	double a = 0, b = 0.5;
	double h = 0.1;
	double x0 = 0, y0 = 1, z0 = 1;

	double y, yl, yll;
	double z, zl, zll;

	rk4(a, b, x0, y0, z0, h, y, z);
	cout << "Result (h = " << h << "): y = " << y << ", z = " << z << endl;

	rk4(a, b, x0, y0, z0, h / 2, yl, zl);
	cout << "Result (h = " << h / 2 << "): y = " << yl << ", z = " << zl << endl;

	rk4(a, b, x0, y0, z0, h / 4, yll, zll);
	cout << "Result (h = " << h / 4 << "): y = " << yll << ", z = " << zll << endl;

	cout << endl;

	cout << "Qc y = " << qc(y, yl, yll) << endl;
	cout << "Qc z = " << qc(z, zl, zll) << endl;

	cout << endl;

	cout << "Error y = " << error(yl, yll, 2) << endl;
	cout << "Error z = " << error(zl, zll, 2) << endl;


	return 0;
}