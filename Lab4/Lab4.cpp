#pragma warning (disable:4996)
#include <iostream>
#include <fstream> 
#include <stdio.h>

#include "Toy.h"
#include "FileManager.h"

using namespace std;


string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

int main()
{	
	FileManager manager;


	while (true) {
		string command;

		cout << endl << "command:" << endl;
		cin >> command;
		cout << endl;

		if (command == "add") {
			Toy* toy = new Toy();

			toy->FillWithConsole();

			manager.Add(toy);
		}

		if (command == "all") {
			manager.Print();
		}

		if (command == "up" || command == "down") {
			string field;

			cin >> field;

			function<bool(Toy, Toy)> predicate;

			if (field == "name") {
				predicate = [](Toy first, Toy second) {
					int first_size = sizeof(first) / sizeof(char);
					int second_size = sizeof(second) / sizeof(char);

					string firstString = convertToString(first.Name, first_size);
					string secondString = convertToString(second.Name, second_size);

					return firstString < secondString;
				};
			}

			if (field == "price") {
				predicate = [](Toy first, Toy second) { return first.Price > second.Price;  };
			}

			if (field == "age") {
				predicate = [](Toy first, Toy second) { return first.MinimalAge > second.MinimalAge;  };
			}

			if (field == "count") {
				predicate = [](Toy first, Toy second) { return first.Count > second.Count;  };
			}

			if (command == "up") {
				manager.OrderUp(predicate);
			}

			if (command == "down") {
				manager.OrderDown(predicate);
			}
		}

	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
