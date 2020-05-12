#pragma once

#include <string>

using namespace std;

class Toy
{
public:
	string Name;
	int Count;
	float Price;
	float MinimalAge;
	Toy* Next;

	Toy();

	void Print();
	void FillWithConsole();

};
