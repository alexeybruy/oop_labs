#pragma once
#include <iterator>
#include "Toy.h"

using namespace std;

class InputIterator
{
public:
	InputIterator(Toy* first);

	Toy& operator ++ (int);
	Toy& operator ++ ();

	bool operator != (const InputIterator& it);
	bool operator == (const InputIterator& it);

	Toy& operator* ();
private:
	Toy* current;
};