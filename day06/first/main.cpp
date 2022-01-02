#include <iostream>
#include "Lanternfish.h"

using namespace std;

LanternfishShoal readLanternfishShoalFromStdin()
{
	vector<Lanternfish> shoal;

	int tmp_int;
	char tmp_char;

	while (!cin.eof())
	{
		cin >> tmp_int;

		shoal.push_back(Lanternfish(tmp_int));

		cin.get(tmp_char);

		if (tmp_char == EOF)
		{
			break;
		}
	}

	return LanternfishShoal(shoal);
}

int main(int argc, char **argv)
{
	LanternfishShoal shoal = readLanternfishShoalFromStdin();

	shoal.simulate(argc > 1 ? atoi(argv[1]) : 80);

	cout << shoal.getCurrentShoal().size() << endl;

	return 0;
}