#pragma once
#include <string>

using namespace std;

class Toy
{
public:
	char Name[20];
	int Count;
	float Price;
	float MinimalAge;
	void SetName(string name);
	Toy();
	void Print();
	void FillWithConsole();
};

