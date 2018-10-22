#include <iostream>
#include <iomanip>

using namespace std;

double fl(double x, double y) { return x * x + y * y; }

double eulerMethod(double x0, double y0, double xMax, double h)
{
	int step = 1;
	while (x0 < (xMax-0.000001))
	{
		double tempX = x0;
		x0 += h;
		y0 = y0 + h * fl(tempX, y0);
		step++;
	}

	cout << "Solution: " << y0 << endl;
	return y0;
}

double Qc(double S, double Sl, double Sll) { return (Sl - S) / (Sll - Sl); }
double error(double sl, double sll, int order) { return abs(sll - sl)/(pow(2,order)-1); }

int main()
{
	cout << fixed;
	cout.precision(6);
	double xMax = 1.4;
	double x0 = 0, y0 = 0;
	double h = 0.1;

	double S, Sl, Sll;

	S = eulerMethod(x0, y0, xMax, h);
	Sl = eulerMethod(x0, y0, xMax,  h / 2);
	Sll = eulerMethod(x0, y0, xMax, h / 4);

	double qc = Qc(S, Sl, Sll);
	cout << "QC = " << qc << endl;

	double err = error(Sl, Sll, 1);
	cout << "Error = " << err << endl;
	return 0;
}