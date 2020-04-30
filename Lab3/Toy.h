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
	Toy();
	Toy(string* values);
	void Print();
};

