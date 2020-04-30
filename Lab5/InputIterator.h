#pragma once
#include <iterator>
#include "Toy.h"

using namespace std;

class InputIterator
{
	friend class RingContainer;
public:
	Toy* current;
	InputIterator(Toy* first);

	Toy& operator ++ (int);
	Toy& operator ++ ();

	bool operator != (const InputIterator& it);
	bool operator == (const InputIterator& it);

	//Toy& operator* ();
};