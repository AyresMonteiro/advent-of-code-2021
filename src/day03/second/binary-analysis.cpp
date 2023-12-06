#include <iostream>
#include <vector>
#include <map>
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

int get_rating(vector<vector<bool>> binary_array, bool (*condition)(int, int))
{
	int appearances_of_number_one = 0, appearances_of_number_zero = 0;

	map<int, vector<bool>> binary_map;

	for (int i = 0; i < binary_array.size(); i++)
	{
		binary_map.insert(pair<int, vector<bool>>(i, binary_array[i]));
	}

	while (binary_map.size() != 1)
	{
		for (int j = 0; j < binary_array[0].size(); j++)
		{
			for (map<int, vector<bool>>::iterator it = binary_map.begin(); it != binary_map.end(); ++it)
			{
				it->second[j] ? appearances_of_number_one++ : appearances_of_number_zero++;
			}

			if (condition(appearances_of_number_one, appearances_of_number_zero))
			{
				for (map<int, vector<bool>>::iterator it = binary_map.begin(); it != binary_map.end() && binary_map.size() > 1;)
				{
					if (!it->second[j])
					{
						binary_map.erase(it++);
					}
					else
					{
						it++;
					}
				}
			}
			else
			{
				for (map<int, vector<bool>>::iterator it = binary_map.begin(); it != binary_map.end() && binary_map.size() > 1;)
				{
					if (it->second[j])
					{
						binary_map.erase(it++);
					}
					else
					{
						it++;
					}
				}
			}

			appearances_of_number_one = 0;
			appearances_of_number_zero = 0;
		}
	}

	return convert_vector_of_bool_to_int(binary_map.begin()->second);
}

bool oxygen_generator_condition(int times_number_one_appeared, int times_number_zero_appeared)
{
	return (times_number_one_appeared > times_number_zero_appeared) || (times_number_one_appeared == times_number_zero_appeared);
}

bool co2_scrubber_condition(int times_number_one_appeared, int times_number_zero_appeared)
{
	return times_number_one_appeared < times_number_zero_appeared;
}

int get_oxygen_generator_rating(vector<vector<bool>> binary_array)
{
	return get_rating(binary_array, oxygen_generator_condition);
}

int get_co2_scrubber_rating(vector<vector<bool>> binary_array)
{
	return get_rating(binary_array, co2_scrubber_condition);
}

int main()
{
	vector<vector<bool>> binary_array;
	vector<bool> tmp_vector;
	char tmp_char;
	int
		appearances_of_number_one = 0,
		appearances_of_number_zero = 0,
		life_supporting_rate;

	while (!cin.eof())
	{
		cin.get(tmp_char);

		if (tmp_char == '\n')
		{
			binary_array.push_back(tmp_vector);
			tmp_vector.clear();
		}
		else
		{
			tmp_vector.push_back(tmp_char == '0' ? 0 : 1);
		}
	}

	if (tmp_vector.size() > 0)
	{
		if (tmp_vector.size() > binary_array[0].size())
		{
			tmp_vector.pop_back();
		}

		binary_array.push_back(tmp_vector);
		tmp_vector.clear();
	}

	life_supporting_rate = get_oxygen_generator_rating(binary_array) * get_co2_scrubber_rating(binary_array);

	cout << life_supporting_rate << endl;

	return 0;
}
