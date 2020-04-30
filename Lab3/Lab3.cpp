// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iostream>

#include "Toy.h"
#include "GetNewFromConsole.h"
#include "WriteAll.h"
#include "GetAll.h"

using namespace std;


void InsertSort(Toy* arr, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && arr[j - 1].Price > arr[j].Price; j--) {
			Toy tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
		}
	}
}

int main()
{

	while (true) {
		string command;

		cout << endl << "command:" << endl;
		cin >> command;
		cout << endl;

		if (command == "add") {
			int toysCount = 0;

			Toy* newToy = GetNewFromConsole();
			Toy* allToys = GetAll(toysCount);

			Toy* newToys = new Toy[toysCount + 1];

			for (int i = 0; i < toysCount + 1; i++) {
				if (i != toysCount) {
					newToys[i] = allToys[i];
				}
				else {
					newToys[i] = *newToy;
				}
			}

			WriteAll(newToys, toysCount + 1);
		}

		if (command == "all") {
			int toysCount = 0;

			Toy* allToys = GetAll(toysCount);

			for (int i = 0; i < toysCount; i++) {
				allToys[i].Print();
			}
		}

		if (command == "sort") {
			int toysCount = 0;

			Toy* allToys = GetAll(toysCount);

			InsertSort(allToys, toysCount);

			for (int i = 0; i < toysCount; i++) {
				allToys[i].Print();
			}
		}

		if (command == "task") {
			int toysCount = 0;

			string maxAge;


			while (true) {
				try {
					cout << "minimal age:" << endl;
					cin >> maxAge;

					float age = stof(maxAge);

					Toy* allToys = GetAll(toysCount);

					InsertSort(allToys, toysCount);

					for (int i = 0; i < toysCount; i++) {
						if (allToys[i].MinimalAge > age) {
							allToys[i].Print();
						}
					}

					break;
				}
				catch (...) {

				}
			}
		}
	}
}
