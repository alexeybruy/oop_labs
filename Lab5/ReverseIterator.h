#pragma once
#include <iterator>
#include "Toy.h"

using namespace std;

class ReverseIterator
{
	friend class RingContainer;
public:
	Toy* current;

	ReverseIterator(Toy* first);

	Toy& operator ++ (int);
	Toy& operator ++ ();

	bool operator != (const ReverseIterator& it);
	bool operator == (const ReverseIterator& it);

	Toy& operator* ();
};