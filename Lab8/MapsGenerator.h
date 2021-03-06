#pragma once
#include <vector>

using namespace std;

class MapsGenerator
{
public:
	std::vector<std::vector<std::vector<int>>> GetMaps();
private:
	vector<vector<int>> First()
	{
		vector<vector<int>> map
		{
			{1,1,1,0,1,0,0,0,0,0},
			{0,0,0,0,1,0,1,0,0,0},
			{1,0,0,0,1,0,0,0,0,0},
			{0,0,0,0,1,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{1,1,1,0,0,0,0,0,0,1},
			{0,0,0,0,1,0,1,0,0,1},
			{1,1,0,0,0,0,0,0,0,0},
		};

		return map;
	}

	vector<vector<int>> Second()
	{
		vector<vector<int>> map
		{
			{0,0,1,0,0,0,0,1,1,1},
			{0,0,1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0,0,0},
			{1,0,0,1,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,1,0,0,1,1,1,0},
			{0,0,0,1,0,0,0,0,0,0},
			{0,0,0,1,0,0,0,0,1,1},
			{1,0,0,1,0,0,1,0,0,0},
			{0,1,0,0,0,0,0,0,0,0},
		};

		return map;
	}

	vector<vector<int>> Third()
	{
		vector<vector<int>> map
		{
			{0,0,0,0,0,1,0,0,0,1},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,1,1,0,0,1,0},
			{0,0,0,0,0,0,0,0,1,0},
			{0,1,1,0,0,0,0,0,0,0},
			{0,0,0,0,0,1,1,1,0,0},
			{1,0,1,0,0,0,0,0,0,0},
			{1,0,0,0,1,1,1,1,0,0},
			{1,0,0,0,0,0,0,0,0,0},
			{0,0,1,0,0,0,0,0,0,0},
		};

		return map;
	}

	vector<vector<int>> Fourth()
	{
		vector<vector<int>> map
		{
			{1,1,1,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,1,0,0,0,0,0,0,0},
			{0,0,1,0,0,0,1,0,0,0},
			{1,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,1,1,1,1,0},
			{1,0,1,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,1},
			{0,0,0,0,0,0,0,0,0,1},
			{1,1,0,1,1,0,0,0,0,1},
		};

		return map;
	}

	vector<vector<int>> Fives()
	{
		vector<vector<int>> map
		{
			{0,0,0,0,0,0,0,0,0,0},
			{1,0,0,0,1,1,1,0,0,0},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,1,0,0,0,0,1},
			{0,0,1,0,0,0,0,0,0,0},
			{1,0,0,0,0,0,0,0,0,1},
			{0,0,0,0,0,1,1,0,0,1},
			{1,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,1,1,1,1,0,0},
			{0,0,0,0,0,0,0,0,0,0},
		};

		return map;
	}
};

