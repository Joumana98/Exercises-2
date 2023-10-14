#include "std_lib_facilites.h"

void extractDigits(vector<char> v, vector<int>& d);
void printResults(vector<char> c, vector<int> d);

int main()
try {
	vector <char> v;
	cout << "Enter a number: " << endl;

	char c;
	cin >> c;

	int i = 0;
	while (cin)
	{
		v.push_back(c);
		cin >> c;
	}

	vector <int> digits;
	extractDigits(v, digits);
	printResults(v, digits);

	return 0;
}
catch (exception& e) {

	cout << e.what() << endl;
	return 1;

}


void extractDigits(vector<char> v, vector<int>& d)
{
	for (char c : v)
	{
		if (c >= '0' && c <= '9')
			d.push_back(static_cast<int>(c) - static_cast<int>('0'));
		else
			error("Please enter a valid number!");

	}

}

void printResults(vector<char> c, vector<int> d)
{
	if (d.size() > 4)
		error("This program handles numbers with max 4 digits!");

	cout << endl;
	for (char ch : c)
		cout << ch;
	cout << " is ";

	int ones = -1;
	int tens = -1;
	int hundreds = -1;
	int thousands = -1;

	for (int i = d.size() - 1; i >= 0; i--)
	{
		if (i == d.size() - 1)
			ones = d[i];
		else if (i == d.size() - 2)
			tens = d[i];
		else if (i == d.size() - 3)
			hundreds = d[i];
		else if (i == d.size() - 4)
			thousands = d[i];
	}


	if (thousands != -1)
		cout << thousands << " thousands, ";
	if (hundreds != -1)
		cout << hundreds << " hundreds, ";
	if (tens != -1)
		cout << tens << " tens, ";
	if (ones != -1)
		cout << ones << " ones." << endl;

}