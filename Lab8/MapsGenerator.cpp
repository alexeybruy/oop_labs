#include "MapsGenerator.h"
#include <vector>

using namespace std;

const int size = 10;

 vector<vector<vector<int>>> MapsGenerator::GetMaps()
 {
	 vector<vector<vector<int>>> maps{
		 First(),
		 Second(),
		 Third(),
		 Fourth(),
		 Fives()
	 };

	 return maps;
 }