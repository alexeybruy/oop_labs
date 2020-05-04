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
	Toy* second = new Toy();
	second->Name = "asd 2";
	Toy* third = new Toy();
	third->Name = "asd 3";

	ProcessingCenter<Toy>* processingCenter = new ProcessingCenter<Toy>();

	vector<Toy>* sequence = new vector<Toy>({ *second, *second, *third });

	function<bool(Toy, Toy)> positionPredicate = [](Toy first, Toy second) {
		return (first.Name == second.Name);
	};

	auto result = processingCenter->Pos(&container, sequence, positionPredicate);

	cout << endl << "Position: " << endl;

	for (int i = 0; i < sequence->size(); i++) {
		cout << (*sequence)[i].Name << endl;
	}

	cout << "Result: " << result <<endl;

}

void Distinct(RingContainer& container) {
	ProcessingCenter<Toy> * processingCenter = new ProcessingCenter<Toy>();

	function<bool(Toy, Toy)> distinctPredicate = [](Toy first, Toy second) {
		return (first.Name == second.Name);
	};

	processingCenter->Distinct(&container, distinctPredicate);

	cout << endl << "Distinct: " << endl;

	auto distinctInterator = container.inputBegin();
	auto startInterator = container.inputBegin();

	do {
		cout << (*distinctInterator).Name   << endl;
		distinctInterator++;
	} while (distinctInterator != startInterator);
}

int main()
{
	Toy* first = new Toy();
	first->Name = "asd";
	Toy* second = new Toy();
	second->Name = "asd 2";
	Toy* third = new Toy();
	third->Name = "asd 3";
	Toy* fourth = new Toy();
	fourth->Name = "asd 4";

	Toy* first2 = new Toy();
	first2->Name = "asd";
	Toy* second2 = new Toy();
	second2->Name = "asd 2";
	Toy* second3 = new Toy();
	second3->Name = "asd 2";
	Toy* third2 = new Toy();
	third2->Name = "asd 3";

	RingContainer container(first, second);
	container.Add(third);
	container.Add(fourth);
	container.Add(second2);
	container.Add(second3);
	container.Add(third2);
	container.Add(first2);

	cout <<  "All: " << endl;


	auto iterator = container.inputBegin();
	auto startInterator = container.inputBegin();

	do {
		cout << (*iterator).Name << endl;
		iterator++;
	} while (iterator != startInterator);


	Position(container);
	Distinct(container);

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
