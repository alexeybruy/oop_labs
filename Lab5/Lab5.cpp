// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <iterator>
#include "RingContainer.h"

using namespace std;

int main()
{
	Toy* first = new Toy();
	first->FillWithConsole();

	Toy *second = new Toy();
	second->FillWithConsole();

	RingContainer container(first, second);

	cout << "How many items to add?" << endl;

	int count = 0;

	cin >> count;

	for (int i = 0; i < count; i++) {
		Toy* item = new Toy();
		item->FillWithConsole();

		container.Add(item);
	}

	cout << "inputIterator: " << endl;

	auto inputIterator = container.inputBegin();

	for (int i = 0; i < 10; i++) {
		cout << inputIterator.current->Name << endl;

		inputIterator++;
	}

	cout << endl << "reverseIterator: " << endl;

	auto reverseIterator = container.reverseBegin();

	for (int i = 0; i < 10; i++) {
		cout << reverseIterator.current->Name << endl;

		reverseIterator++;
	}

	system("pause");
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
