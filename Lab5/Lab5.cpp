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
	first->Name = "asd";

	Toy *second = new Toy();
	second->Name = "asd 2";

	Toy* third = new Toy();
	third->Name = "asd 3";

	Toy* fourth = new Toy();
	fourth->Name = "asd 4";

	RingContainer  container(first, second);

	container.Add(third);
	container.Add(fourth);

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
