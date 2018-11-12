#include <iostream>
#include <math.h>

using namespace std;

const double EPSILON = 10e-6;

double f(double x, double y, double z) { return z * y + x; }
double g(double x, double y, double z) { return z * x + y; }

void euler_method(double a, double b, double x, double y, double z, double h, double & yres, double & zres)
{
	double diff;
	int step = 0;

	do
	{
		double yl = f(x, y, z);
		double zl = g(x, y, z);
		x += h;
		y += h * yl;
		z += h * zl;
		step++;
	} while (a+h*step < (b-10e-6));

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

	euler_method(a, b, x0, y0, z0, h, y, z);
	cout << "Result (h = " << h << "): y = " << y << ", z = " << z << endl;

	euler_method(a, b, x0, y0, z0, h/2, yl, zl);
	cout << "Result (h = " << h/2 << "): y = " << yl << ", z = " << zl << endl;

	euler_method(a, b, x0, y0, z0, h/4, yll, zll);
	cout << "Result (h = " << h/4 << "): y = " << yll << ", z = " << zll << endl;

	cout << endl;

	cout << "Qc y = " << qc(y, yl, yll) << endl;
	cout << "Qc z = " << qc(z, zl, zll) << endl;

	cout << endl;
	
	cout << "Error y = " << error(yl, yll, 1) << endl;
	cout << "Error z = " << error(zl, zll, 1) << endl;


	return 0;
}