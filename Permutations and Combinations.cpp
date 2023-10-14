// Exercise 10
// Permutations and combinations

#include "std_lib_facilites.h"

double fact(double n);
double permutation(double a, double b);
double combination(double a, double b);

int main()
try {
	double a, b;
	cout << "Enter two numbers: " << endl;
	cin >> a >> b;
	if (a < b) // numbers in the permutations are different
		error("Invalid Input"); // Numbers in permutation cannot exceed the number of possibe choices

	char ch;
	cout << "Enter p or P to calculate permutations, and c or C to calculate combinations: " << endl;
	cin >> ch;

	switch (ch)
	{
	case 'p':
	case 'P':
		cout << "P(" << a << "," << b << ")= " << permutation(a, b) << endl;
		break;
	case 'c':
	case 'C':
		cout << "C(" << a << "," << b << ")= " << combination(a, b) << endl;
		break;
	default:
		error("Invalid Input");
	}


	return 0;
}
catch (exception& e)
{
	cout << e.what();
	return 1;
}

double fact(double n)
{
	double f = 1;
	for (int i = 1; i <= n; i++)
		f = f * i;

	return f;
}

double permutation(double a, double b)
{
	return fact(a) / fact(a - b);
}

double combination(double a, double b)
{
	return permutation(a, b) / fact(b);
}
