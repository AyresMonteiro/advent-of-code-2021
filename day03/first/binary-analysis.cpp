#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int convert_vector_of_bool_to_int(vector<bool> v)
{
	int n = 0, size = v.size();

	for (int i = 0; i < size; i++)
	{
		if (v[size - i - 1])
		{
			n += pow(2, i);
		}
	}

	return n;
}

int main()
{
	vector<vector<bool>> binary_map;
	vector<bool> tmp_vector, gamma, epsilon;
	char tmp_char;
	int appearances_of_number_one = 0, appearances_of_number_zero = 0, gamma_int, epsilon_int;

	while (!cin.eof())
	{
		cin.get(tmp_char);

		if (tmp_char == '\n')
		{
			binary_map.push_back(tmp_vector);
			tmp_vector.clear();
		}
		else
		{
			tmp_vector.push_back(tmp_char == '0' ? 0 : 1);
		}
	}

	if (tmp_vector.size() > 0)
	{
		binary_map.push_back(tmp_vector);
		tmp_vector.clear();
	}

	for (int j = 0; j < binary_map[0].size(); j++)
	{
		for (int i = 0; i < binary_map.size(); i++)
		{
			if (binary_map[i][j])
			{
				appearances_of_number_one++;
			}
			else
			{
				appearances_of_number_zero++;
			}
		}

		if (appearances_of_number_one > appearances_of_number_zero)
		{
			gamma.push_back(1);
			epsilon.push_back(0);
		}
		else
		{
			gamma.push_back(0);
			epsilon.push_back(1);
		}

		appearances_of_number_one = 0;
		appearances_of_number_zero = 0;
	}

	gamma_int = convert_vector_of_bool_to_int(gamma);
	epsilon_int = convert_vector_of_bool_to_int(epsilon);

	cout << (gamma_int * epsilon_int) << endl;

	return 0;
}
