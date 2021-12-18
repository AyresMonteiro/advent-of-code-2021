#include <iostream>

using namespace std;

int main()
{
	bool start = true;
	int times_increased = 0, previous, current;

	while (!cin.eof())
	{
		cin >> current;

		if (!start)
		{
			times_increased += (current > previous ? 1 : 0);
		}
		else
		{
			start = false;
		}

		previous = current;
	}

	cout << times_increased << endl;

	return 0;
}
