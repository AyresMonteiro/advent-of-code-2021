#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef struct Point
{
	unsigned int x, y;
} Point;

typedef pair<Point, Point> Line;
typedef vector<vector<int>> IntegerMatrix;

class CloudMapController
{
private:
	IntegerMatrix cloudMap;

public:
	pair<int, int> getDimensions(vector<Line> lines)
	{
		int max_x = 0, max_y = 0;

		for (Line line : lines)
		{
			if (line.first.x > max_x)
			{
				max_x = line.first.x;
			}

			if (line.second.x > max_x)
			{
				max_x = line.second.x;
			}

			if (line.first.y > max_y)
			{
				max_y = line.first.y;
			}

			if (line.second.y > max_y)
			{
				max_y = line.second.y;
			}
		}

		return pair<int, int>(max_x, max_y);
	}

	void generateMap(vector<Line> lines)
	{
		pair<int, int> dimensions = getDimensions(lines);

		this->cloudMap = IntegerMatrix(dimensions.first + 1, vector<int>(dimensions.second + 1, 0));

		for (Line line : lines)
		{
			insertLineOnCloudMap(line);
		}
	}

	void insertVerticalLineOnCloudMap(Line line)
	{
		if (line.first.y < line.second.y)
		{
			for (int i = line.first.y; i <= line.second.y; i++)
			{
				this->cloudMap[line.first.x][i]++;
			}
		}
		else
		{
			for (int i = line.second.y; i <= line.first.y; i++)
			{
				this->cloudMap[line.first.x][i]++;
			}
		}
	}

	void insertHorizontalLineOnCloudMap(Line line)
	{
		if (line.first.x < line.second.x)
		{
			for (int i = line.first.x; i <= line.second.x; i++)
			{
				this->cloudMap[i][line.first.y]++;
			}
		}
		else
		{
			for (int i = line.second.x; i <= line.first.x; i++)
			{
				this->cloudMap[i][line.first.y]++;
			}
		}
	}

	void insertDiagonalLineOnCloudMap(Line line)
	{
		if (line.first.x < line.second.x && line.first.y < line.second.y)
		{
			for (
				int i = line.first.x, j = line.first.y;
				i <= line.second.x && j <= line.second.y;
				i++, j++)
			{
				this->cloudMap[i][j]++;
			}
		}
		else if (line.first.x < line.second.x && line.first.y > line.second.y)
		{
			for (
				int i = line.first.x, j = line.first.y;
				i <= line.second.x && j >= line.second.y;
				i++, j--)
			{
				this->cloudMap[i][j]++;
			}
		}
		else if (line.first.x > line.second.x && line.first.y < line.second.y)
		{
			for (
				int i = line.first.x, j = line.first.y;
				i >= line.second.x && j <= line.second.y;
				i--, j++)
			{
				this->cloudMap[i][j]++;
			}
		}
		else
		{
			for (
				int i = line.first.x, j = line.first.y;
				i >= line.second.x && j >= line.second.y;
				i--, j--)
			{
				this->cloudMap[i][j]++;
			}
		}
	}

	void insertLineOnCloudMap(Line line)
	{
		bool isVertical = line.first.x == line.second.x;

		if (isVertical)
		{
			insertVerticalLineOnCloudMap(line);
			return;
		}

		bool isHorizontal = line.first.y == line.second.y;

		if (isHorizontal)
		{
			insertHorizontalLineOnCloudMap(line);
			return;
		}

		insertDiagonalLineOnCloudMap(line);
	}

	void printMap()
	{
		for (vector<int> line : this->cloudMap)
		{
			for (int n : line)
			{
				cout << n << " ";
			}

			cout << endl;
		}
	}

	int countOverlaps()
	{
		int overlaps = 0;

		for (vector<int> line : this->cloudMap)
		{
			for (int n : line)
			{
				if (n > 1)
				{
					overlaps++;
				}
			}
		}

		return overlaps;
	}
};

vector<Line> readLinesFromStdin()
{
	char tmp_char;
	unsigned int tmp_int0, tmp_int1;

	vector<Line> lines;

	while (!cin.eof())
	{
		cin >> tmp_int0;

		cin.get(tmp_char);

		if (tmp_char == EOF)
		{
			break;
		}

		cin >> tmp_int1;

		Point start = {x : tmp_int1, y : tmp_int0};

		// getting " -> "
		cin.get(tmp_char);
		cin.get(tmp_char);
		cin.get(tmp_char);
		cin.get(tmp_char);

		cin >> tmp_int0;

		cin.get(tmp_char);

		cin >> tmp_int1;

		Point end = {x : tmp_int1, y : tmp_int0};

		lines.push_back(Line(start, end));
	}

	return lines;
}

int main()
{
	CloudMapController cmc;
	vector<Line> lines = readLinesFromStdin();

	cmc.generateMap(lines);

	cout << cmc.countOverlaps() << endl;

	return 0;
}
