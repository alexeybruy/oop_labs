#include "WriteAll.h"


#include <iostream>
#include <fstream>
#include <iostream>

#include "Toy.h"

using namespace std;

void WriteAll(Toy* toys, int count) {

	string values = "";

	for (int i = 0; i < count; i++) {
		Toy toy = toys[i];

		values += toy.Name + "&";
		values += to_string(toy.Count) + "&";
		values += to_string(toy.Price) + "&";
		values += to_string(toy.MinimalAge) + "&";

		values += "||";

	};

	ofstream file;

	file.open("data.txt");
	file << values;
	file.close();
}