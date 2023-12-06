#include <iostream>
#include <vector>

using namespace std;

vector<int> getCrabPositionsFromStdin()
{
    vector<int> crab_positions;

    int tmp_int;
    char tmp_char;

    while (!cin.eof())
    {
        cin >> tmp_int;

        crab_positions.push_back(tmp_int);

        cin.get(tmp_char);

        if (tmp_char == EOF || tmp_char == '\n')
        {
            break;
        }
    }

    return crab_positions;
}

int getDifference(int a, int b)
{
    if (a > b)
    {
        return a - b;
    }

    return b - a;
}

int getGreaterPosition(vector<int> crab_positions)
{
    int total_crabs = crab_positions.size();

    int greater_position;

    for (int i = 0; i < total_crabs; i++)
    {
        if (i == 0 || greater_position < crab_positions[i])
        {
            greater_position = crab_positions[i];
        }
    }

    return greater_position;
}

vector<int> getBestFuelCombination(vector<int> crab_positions)
{
    int number_of_crabs = crab_positions.size();
    int total_crab_positions = getGreaterPosition(crab_positions);
    int best_fuel_combination;
    int best_fuel_combination_index;
    vector<int> results;

    for (int i = 0; i < total_crab_positions; i++)
    {
        int fuel_combination = 0;

        for (int j = 0; j < number_of_crabs; j++)
        {
            fuel_combination += getDifference(i, crab_positions[j]);
        }

        if (i == 0 || fuel_combination < best_fuel_combination)
        {
            best_fuel_combination = fuel_combination;
            best_fuel_combination_index = i;
        }
    }

    results.push_back(best_fuel_combination_index);
    results.push_back(best_fuel_combination);

    return results;
}

int getLesser(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    vector<int> crab_positions = getCrabPositionsFromStdin();

    vector<int> results = getBestFuelCombination(crab_positions);

    cout << results[0] << ": " << results[1] << endl;

    return 0;
}