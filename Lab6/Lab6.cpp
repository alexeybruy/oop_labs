// Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Toy.h"
#include "RingContainer.h"
#include "ProcessingCenter.h"
#include "ProcessingCenter.cpp"

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;


void Position(RingContainer& container) {
	ProcessingCenter<Toy>* processingCenter = new ProcessingCenter<Toy>();

	cout << endl << "Position: " << endl;

	int itemsCount = 0;

	cin >> itemsCount;

	vector<Toy>* sequence = new vector<Toy>();

	for (int i = 0; i < itemsCount; i++) {
		Toy* item = new Toy();
		item->FillWithConsole();
		sequence->push_back(*item);
	}

	auto result = processingCenter->Pos(&container, sequence, [](Toy first, Toy second) {
		return (first.Name == second.Name);
		});

	cout << endl;

	for (int i = 0; i < sequence->size(); i++) {
		cout << (*sequence)[i].Name << endl;
	}

	cout << endl << "Result: " << result << endl;

}

void Distinct(RingContainer& container) {
	ProcessingCenter<Toy>* processingCenter = new ProcessingCenter<Toy>();

	cout << endl << "Distinct: " << endl;

	processingCenter->Distinct(&container, [](Toy first, Toy second) {
		return (first.Name == second.Name);
		});


	auto distinctInterator = container.inputBegin();
	auto startInterator = container.inputBegin();

	do {
		cout << (*distinctInterator).Name << endl;
		distinctInterator++;
	} while (distinctInterator != startInterator);
}

void Order(RingContainer& container) {
	ProcessingCenter<Toy>* processingCenter = new ProcessingCenter<Toy>();
	cout << endl << "Order: " << endl;

	processingCenter->Order(&container, [](Toy first, Toy second) {
		if (first.Name.compare(second.Name) > 0) {
			return true;
		}

		return false;
		});

	auto orderIterator = container.inputBegin();
	auto startInterator = container.inputBegin();

	do {
		cout << (*orderIterator).Name << endl;
		orderIterator++;
	} while (orderIterator != startInterator);
}

RingContainer* Initialize() {
	Toy* first = new Toy();
	first->Name = "asd1";
	Toy* second = new Toy();
	second->Name = "asd5";

	Toy* third = new Toy();
	third->Name = "asd3";
	Toy* fourth = new Toy();
	fourth->Name = "asd7";

	first->FillWithConsole();
	second->FillWithConsole();

	RingContainer* container = new RingContainer(first, second);

	//container->Add(third);
	//container->Add(fourth);
	int itemsCount;
	cout << endl << "How many items to add?" << endl;
	cin >> itemsCount;

	for (int i = 0; i < itemsCount; i++) {
		Toy* item = new Toy();
		item->FillWithConsole();
		container->Add(item);
	}

	cout << endl << "All: " << endl;


	auto iterator = container->inputBegin();
	auto startInterator = container->inputBegin();

	do {
		cout << (*iterator).Name << endl;
		iterator++;
	} while (iterator != startInterator);

	return container;
}
int main()
{
	RingContainer container = *Initialize();

	//Position(container);
	//Distinct(container);
	Order(container);

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
