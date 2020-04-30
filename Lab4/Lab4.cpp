#pragma warning (disable:4996)
#include <iostream>
#include <fstream> 
#include <stdio.h>

#include "Toy.h"
#include "FileManager.h"

using namespace std;

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

		if (command == "up") {
			manager.OrderUp();
		}

		if (command == "down") {
			manager.OrderDown();
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
