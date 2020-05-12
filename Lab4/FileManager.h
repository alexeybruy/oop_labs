#pragma once
#include "Toy.h"
#include <string>
#include <functional>

using namespace std;

class FileManager
{
public:
	void Add(Toy * toy);
	void OrderUp(function<bool(Toy, Toy)> predicate);
	void OrderDown(function<bool(Toy, Toy)> predicate);
	void Print();
	void Order(bool up, function<bool(Toy, Toy)> predicate);
};

