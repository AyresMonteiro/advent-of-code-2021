#include <iostream>
#include <vector>

using namespace std;

// The first part was solved using beautiful OOP concepts, however, to the
// second part we will need some math analysis instead of using large amounts of
// data.

vector<long> readLanternfishTimeToSpawnFromStdin()
{
	// 9 slots because index of vector is the number of days before a new spawn,
	// so, 0 is the slot that generates new lanternfish
	vector<long> timeToSpawn(9, 0);

	long tmp_long;
	char tmp_char;

	while (!cin.eof())
	{
		cin >> tmp_long;

		timeToSpawn[tmp_long]++;

		cin.get(tmp_char);

		if (tmp_char == EOF)
		{
			break;
		}
	}

	return timeToSpawn;
}

long simulate(long days, vector<long> timeToSpawn)
{
	// if vector is not long enough, return -1
	if (timeToSpawn.size() != 9)
	{
		return -1;
	}

	long tmp_long;

	for (long i = 0; i < days; i++)
	{
		// save number of fish that gave birth
		tmp_long = timeToSpawn[0];

		for (long j = 1; j < 9; j++)
		{
			// move slots ahead
			timeToSpawn[j - 1] = timeToSpawn[j];
			timeToSpawn[j] = 0;
		}

		// sum fish that are now borning in 6 days
		timeToSpawn[6] += tmp_long;

		// sum new fish
		timeToSpawn[8] += tmp_long;
	}

	long total = 0;

	for (long fish : timeToSpawn)
	{
		total += fish;
	}

	return total;
}

int main(int argc, char **argv)
{
	vector<long> timeToSpawn = readLanternfishTimeToSpawnFromStdin();

	cout << simulate(256, timeToSpawn) << endl;

	return 0;
}