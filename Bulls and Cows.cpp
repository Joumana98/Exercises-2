#include "std_lib_facilites.h"

void getGuess(vector<char>& guess, int n);
int bull(vector<char>v, vector<char> g);
int cow(vector<char>v, vector<char> g);


int main()
{
	vector <char> v = { '0','2','3','4' };
	int n = v.size();

	vector <char> guess;
	cout << "Enter your guess (end it with \" | \"): ";
	getGuess(guess, n);


	int bulls = bull(v, guess);
	int cows = 0;
	while (bulls != v.size())
	{
		cout << bulls << " bulls" << " and " << cow(v, guess) << " cows" << endl;
		cout << "Enter your guess again (end it with \" | \"): ";
		getGuess(guess, n);

		bulls = bull(v, guess);

	}
	cout << "Your guess is correct!!" << endl;

	return 0;
}


int bull(vector<char>v, vector<char> g)
{
	int bulls = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (g[i] == v[i])
			bulls++;
	}
	return bulls;
}

int cow(vector<char>v, vector<char> g)
{
	int cows = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < g.size(); j++)
		{
			if (g[j] == v[i] && j != i)
				cows++;
		}
	}

	return cows;

}

void getGuess(vector<char>& guess, int n)
{
	guess.clear();
	for (char temp; cin >> temp;)
	{
		if (temp == '|')
			break;
		else
			guess.push_back(temp);
	}
	cout << endl;
	for (char x : guess)
		cout << x << " ";
	cout << endl;

	if (guess.size() != n)
		error("Wrong length!");

}
