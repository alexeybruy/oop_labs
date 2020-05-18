// Lab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>
#include "Toy.h"
#include "ProcessingCenter.cpp"

using namespace std;

deque<Toy>* Initialize() {
	cout << "Hello, how many items to add?" << endl;

	int itemsCount;

	cin >> itemsCount;

	cout << endl;

	deque<Toy>& container = *new deque<Toy>();

	for (auto i = 0; i < itemsCount; i++) {
		Toy* toy = new Toy();
		toy->FillWithConsole();
		container.push_back(*toy);
	}

	cout << endl;


	return &container;
}


void Order(deque<Toy>* container) {

	cout << endl << "Order:" << endl;

	ProcessingCenter<Toy>& processingCenter = *new ProcessingCenter<Toy>();


	function<bool(Toy, Toy)> predicate;

	string field;

	cin >> field;
	
	if (field == "name") {
		predicate = [](Toy first, Toy second) { return first.Name.compare(second.Name) < 0; };
	}

	if (field == "price") {
		predicate = [](Toy first, Toy second) { return first.Price < second.Price;  };
	}

	if (field == "age") {
		predicate = [](Toy first, Toy second) { return first.MinimalAge < second.MinimalAge;  };
	}

	if (field == "count") {
		predicate = [](Toy first, Toy second) { return first.Count < second.Count;  };
	}

	processingCenter.Order(container, predicate);

	auto iterator = container->begin();

	while (iterator != container->end()) {
		(*(iterator++)).Print();
	}
}

deque<Toy>* GetSequence() {
	cout << endl << "Hello, how many items will be in sequence?" << endl;

	int itemsCount;

	cin >> itemsCount;

	cout << endl;

	deque<Toy>& container = *new deque<Toy>();

	for (auto i = 0; i < itemsCount; i++) {
		Toy* toy = new Toy();
		toy->FillWithConsole();
		container.push_back(*toy);
	}

	cout << endl;


	return &container;
}

void Position(deque<Toy>* container) {

	cout << endl << "Position:" << endl;

	ProcessingCenter<Toy>& processingCenter = *new ProcessingCenter<Toy>();

	auto sequence = GetSequence();

	auto position = processingCenter.Pos(container, sequence,[](Toy first, Toy second) {
		return (first).Name == (second).Name;
		});

	cout << "Position result:" << position << endl;
}



void Distinct(deque<Toy>* container) {

	cout << endl << "Distinct:" << endl;

	ProcessingCenter<Toy>& processingCenter = *new ProcessingCenter<Toy>();

	processingCenter.Distinct(container, [](Toy first, Toy second) {
		return (first).Name == (second).Name;
		});

	auto iterator = container->begin();

	while (iterator != container->end()) {
		(*(iterator++)).Print();
	}
}

int main()
{
	auto container = Initialize();


	while (true) {

		string command;

		cout << endl << "command:" << endl;
		cin >> command;
		cout << endl;

		if (command == "position") {
			Position(container);
		}

		if (command == "distinct") {
			Distinct(container);
		}

		if (command == "order") {
			Order(container);
		}

		cout << endl << endl;
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
