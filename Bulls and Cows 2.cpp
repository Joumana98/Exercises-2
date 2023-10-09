#include "std_lib_facilites.h"

const int N = 4;

void getOption(vector<char>& v);
void getGuess(vector<char>& guess, int n);
int bull(vector<char>v, vector<char> g);
int cow(vector<char>v, vector<char> g);


int main()
{
	bool play;
	cout << "Enter 1 if you want to play and 0 otherwise: ";
	cin >> play;
	cout << endl;
	while (play)
	{
		vector <char> v;
		getOption(v);
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

		cout << "Enter 1 if you want to play and 0 otherwise: ";
		cin >> play;
		cout << endl;
	}

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

void getOption(vector<char>& v)
{
	int seed;
	for (int i = 0; i < N; i++)
	{
		cout << "Enter a random number: ";
		cin >> seed;
		srand(seed);
		v.push_back(static_cast<char>(randint(10) + static_cast<int>('0')));
	}
}