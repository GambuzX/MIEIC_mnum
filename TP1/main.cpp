#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

long double calculateValue(long double initValue)
{
	for (int i = 1; i <= 25; i++)
		initValue = initValue * i - 1;
	return initValue;
}

int main()
{
	long double initialValue = exp(1) -1 ;
	cout << setprecision(4) << calculateValue(initialValue) << endl;
}
