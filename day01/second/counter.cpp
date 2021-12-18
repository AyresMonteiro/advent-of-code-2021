#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	bool start = true;
	int times_increased = 0, previous, current;

	queue<vector<int>> windows_queue;
	vector<vector<int>> windows_vector;

	while (!cin.eof())
	{
		if (windows_queue.size() < 3)
		{
			vector<int> temp_vector;
			windows_queue.push(temp_vector);
		}

		cin >> current;

		queue<vector<int>> temp_queue;

		while (!windows_queue.empty())
		{
			vector<int> a_vector = windows_queue.front();
			a_vector.push_back(current);
			temp_queue.push(a_vector);
			windows_queue.pop();
		}

		while (!temp_queue.empty())
		{
			vector<int> a_vector = temp_queue.front();
			windows_queue.push(a_vector);
			temp_queue.pop();
		}

		if (windows_queue.front().size() == 3)
		{
			windows_vector.push_back(windows_queue.front());
			windows_queue.pop();
		}
	}

	for (int i = 0; i < windows_vector.size(); i++)
	{
		current = windows_vector[i][0] + windows_vector[i][1] + windows_vector[i][2];

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
