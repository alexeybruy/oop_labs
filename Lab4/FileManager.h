#pragma once
#include "Toy.h"
#include <string>

using namespace std;

class FileManager
{
public:
	void Add(Toy * toy);
	void OrderUp();
	void OrderDown();
	void Print();
	void Order(bool up);
};

