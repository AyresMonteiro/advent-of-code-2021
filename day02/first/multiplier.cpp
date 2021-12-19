#include <iostream>

using namespace std;

typedef struct Point
{
	int horizontal, depth;
} Point;

int main()
{
	Point point = {horizontal : 0, depth : 0};
	string tmp_string;
	int tmp_number;

	while (!cin.eof())
	{
		cin >> tmp_string;
		cin >> tmp_number;

		if (tmp_string == "forward")
		{
			point.horizontal += tmp_number;
		}
		else if (tmp_string == "up")
		{
			point.depth -= tmp_number;
		}
		else
		{
			point.depth += tmp_number;
		}
	}

	cout << (point.horizontal * point.depth) << endl;

	return 0;
}