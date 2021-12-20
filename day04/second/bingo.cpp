#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef struct BingoNumber
{
	int n;
	bool marked;
} BingoNumber;

class Board
{
private:
	vector<vector<BingoNumber>> board_numbers;

public:
	Board()
	{
	}

	Board(vector<vector<BingoNumber>> board_numbers)
	{
		this->board_numbers = board_numbers;
	}

	bool doesAnyRowHaveWon(int actual)
	{
		for (int i = 0; i < 5; i++)
		{
			int counter = 0;

			for (int j = 0; j < 5; j++)
			{
				if (board_numbers[i][j].marked)
				{
					counter++;
					continue;
				}

				if (actual == board_numbers[i][j].n)
				{
					board_numbers[i][j].marked = true;
					counter++;
				}
			}

			if (counter == 5)
			{
				return true;
			}

			counter = 0;
		}

		return false;
	}

	bool doesAnyColumnHaveWon(int actual)
	{
		for (int i = 0; i < 5; i++)
		{
			int counter = 0;

			for (int j = 0; j < 5; j++)
			{
				if (board_numbers[j][i].marked)
				{
					counter++;
					continue;
				}

				if (actual == board_numbers[j][i].n)
				{
					board_numbers[j][i].marked = true;
					counter++;
				}
			}

			if (counter == 5)
			{
				return true;
			}

			counter = 0;
		}

		return false;
	}

	void print()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (board_numbers[i][j].marked)
				{
					cout << "\033[0;93m";
				}
				else
				{
					cout << "\033[0;39m";
				}
				cout << board_numbers[i][j].n << '\t';
			}

			cout << endl;
		}

		cout << endl;
		cout << "\033[0;39m";
	}

	int sumOfUnmarked()
	{
		int sum = 0;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (board_numbers[i][j].marked)
				{
					continue;
				}

				sum += board_numbers[i][j].n;
			}
		}

		return sum;
	}
};

int main()
{
	char c;
	int n, key = 0;

	queue<int> numbers;
	map<int, Board> boards;

	while (c != '\n')
	{
		cin >> n;
		numbers.push(n);
		cin.get(c);
	}

	while (!cin.eof() && c != EOF)
	{
		vector<vector<BingoNumber>> new_board;

		for (int i = 0; i < 5; i++)
		{
			vector<BingoNumber> new_row;

			for (int j = 0; j < 5; j++)
			{
				cin >> n;
				new_row.push_back({n : n, marked : false});
			}

			new_board.push_back(new_row);
		}

		Board next(new_board);

		boards.insert(pair<int, Board>(key, next));
		key++;

		cin.get(c);
	}

	Board last_winner;

	int current, last_number;

	do
	{
		current = numbers.front();
		numbers.pop();

		for (map<int, Board>::iterator it = boards.begin(); it != boards.end();)
		{
			if (it->second.doesAnyRowHaveWon(current) || it->second.doesAnyColumnHaveWon(current))
			{
				last_number = current;
				last_winner = it->second;
				boards.erase(it++);
			}
			else
			{
				it++;
			}
		}
	} while (numbers.size() > 0);

	last_winner.print();

	cout << "Sum of unmarked: " << last_winner.sumOfUnmarked() << endl;
	cout << "Last Number: " << last_number << endl;
	cout << "Answer: " << (last_number * last_winner.sumOfUnmarked()) << endl;

	return 0;
}
