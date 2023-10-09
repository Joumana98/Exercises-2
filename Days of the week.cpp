#include "std_lib_facilites.h"

int checkDay(string s);
void printSum(vector<int> v);

int main()
{
	vector<int>mon;
	vector<int>tues;
	vector<int>wednes;
	vector<int>thurs;
	vector<int>fri;
	vector<int>satur;
	vector<int>sun;

	string day;
	int n;

	int rejected = 0;

	cin >> day;
	while (cin)
	{
		cin >> n;
		if (cin) {
			switch (checkDay(day))
			{
			case 1:
				mon.push_back(n);
				break;
			case 2:
				tues.push_back(n);
				break;
			case 3:
				wednes.push_back(n);
				break;
			case 4:
				thurs.push_back(n);
				break;
			case 5:
				fri.push_back(n);
				break;
			case 6:
				satur.push_back(n);
				break;
			case 7:
				sun.push_back(n);
				break;
			default:
				rejected++;
				cout << "Invalid day of the week!!" << endl;

			}
			cin >> day;
		}
		else
			cout << "Missing value!" << endl;

	}


	cout << "Monday: ";
	printSum(mon);

	cout << "Tuesday: ";
	printSum(tues);

	cout << "Wednesday: ";
	printSum(wednes);

	cout << "Thursday: ";
	printSum(thurs);

	cout << "Friday: ";
	printSum(fri);

	cout << "Saturday: ";
	printSum(satur);

	cout << "Sunday: ";
	printSum(sun);

	cout << "The number of rejected values is: " << rejected << endl;


	return 0;
}

int checkDay(string s)
{
	if (s == "Monday" || s == "mon" || s == "monday")
		return 1;
	else if (s == "Tuesday" || s == "tues" || s == "tuesday")
		return 2;
	else if (s == "Wednesday" || s == "wednes" || s == "wednesday")
		return 3;
	else if (s == "Thursdyday" || s == "thurs" || s == "thursday")
		return 4;
	else if (s == "Friday" || s == "fri" || s == "friday")
		return 5;
	else if (s == "Saturday" || s == "satur" || s == "saturday")
		return 6;
	else if (s == "Sunday" || s == "sun" || s == "sunday")
		return 7;
	else
		return 0;
}

void printSum(vector<int> v)
{
	int sum = 0;
	for (int x : v)
	{
		sum = sum + x;
		cout << x << " ";
	}
	cout << endl;
	cout << "The sum of the elements is: " << sum << endl;
	cout << endl;
}