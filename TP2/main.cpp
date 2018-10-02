#include <iostream>
#include <iomanip>

using namespace std;

const double E = 0.001;
const double ZERO_APPROX = 1e-6;

double x_minus_xsquared(double x)
{
	return (x - x*x);
}

void bissectionMethod(double a, double b, double function(double))
{
	double guess;
	double amplitude = b - a;
	int step = 1;
	/* while (amplitude > E)
	{
		guess = (a + b) / 2;
		cout << "Step " << step << ": " << guess << endl;
		if (function(guess) * function(a) < 0)
			b = guess;
		else
			a = guess;

		step++;
		amplitude = b - a;
	}*/
	bool firstGuess = true;;
	while (true)
	{
		double newGuess = (a + b) / 2;
		if (!firstGuess && newGuess == guess) break;
		firstGuess = false;
		guess = (a + b) / 2;
		cout << "Step " << step << ": " << setprecision(10) << guess << endl;
		if (function(guess) * function(a) < 0)
			b = guess;
		else
			a = guess;

		step++;
		amplitude = b - a;
	}
	cout << "Final value: " << guess << endl;
}

void regulaFalsi(double a, double b, int steps, double function(double))
{ 
	double guess;
	// double amplitude = b - a;
	// int step = 1;
	for (int i = 1; i <= steps; i++)
	{
		guess = (a * function(b) - b * function(a)) / (function(b) - function(a));
		cout << "Step " << i << ": " << guess << endl;
		if (function(guess) * function(a) < 0)
			b = guess;
		else
			a = guess;

		// step++;
		// amplitude = b - a;
	}
	cout << "Final value: " << guess << endl;
}

// TODO finish modified regula falsi
void modifiedRegulaFalsi(double a, double b, int steps, double function(double))
{
	double guess;
	int step = 1;
	double Fa = function(a), Fb = function(b);
	while(function(guess) > ZERO_APPROX)
	{
		guess = (a * Fb - b * Fa) / (Fb - Fa);
		cout << "Step " << step << ": " << guess << endl;
		if (function(guess) * function(a) < 0)
		{
			b = guess;
			Fb = function(guess);
		}
		else
		{
			a = guess;
			Fa = function(guess);
		}

		step++;
	}
	cout << "Final value: " << guess << endl;
}

void newtonMethod(double initValue, double func(double))
{
	double guess;
	while (func(guess) > ZERO_APPROX)
	{

	}
}


int main()
{	
	double a, b, steps;
	cout << "Enter interval to use (left right): ";
	cin >> a >> b;
	cout << "Number of steps: ";
	cin >> steps;
	bissectionMethod(a, b, x_minus_xsquared);
}